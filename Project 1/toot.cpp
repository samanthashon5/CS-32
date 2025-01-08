// toot.cpp

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;               // max number of rows in a city
const int MAXCOLS = 30;               // max number of columns in a city
const int MAXTOOTERS = 125;           // max number of Tooters allowed
const int INITIAL_PLAYER_HEALTH = 12;

const int UP      = 0;
const int DOWN    = 1;
const int LEFT    = 2;
const int RIGHT   = 3;
const int NUMDIRS = 4;

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class City;  // This is needed to let the compiler know that City is a
             // type name, since it's mentioned in the Tooter declaration.

class Tooter
{
  public:
        // Constructor
    Tooter(City* cp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();

  private:
    City* m_city;
    int   m_row;
    int   m_col;
};

class Player
{
  public:
        // Constructor
    Player(City *cp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    int  health() const;
    bool isPassedOut() const;

        // Mutators
    void  preach();
    void  move(int dir);
    void  getGassed();

  private:
    City* m_city;
    int   m_row;
    int   m_col;
    int   m_health;
    int   m_age;
};

class City
{
  public:
        // Constructor/destructor
    City(int nRows, int nCols);
    ~City();

        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    bool    isPlayerAt(int r, int c) const;
    int     tooterCount() const;
    int     nTootersAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;

        // Mutators
    bool addTooter(int r, int c);
    bool addPlayer(int r, int c);
    void preachToTootersAroundPlayer();
    void moveTooters();

  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Tooter* m_tooters[MAXTOOTERS];
    int     m_nTooters;

      // Helper functions
    bool isInBounds(int r, int c) const;
};

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nTooters);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
};

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
int randInt(int min, int max);
void clearScreen();

///////////////////////////////////////////////////////////////////////////
//  Tooter implementation
///////////////////////////////////////////////////////////////////////////

Tooter::Tooter(City* cp, int r, int c)
 : m_city(cp), m_row(r), m_col(c)
{
    if (cp == nullptr)
    {
        cout << "***** A Tooter must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "***** Tooter created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
}

int Tooter::row() const
{
    return m_row;
}

int Tooter::col() const
{
    return m_col;
}

void Tooter::move()
{
      // Attempt a move in a random direction; if it can't move, don't move.
      // If player is there, don't move.
    int dir = randInt(0, NUMDIRS-1);  // dir is now UP, DOWN, LEFT, or RIGHT
    int r = m_row;
    int c = m_col;
    m_city->determineNewPosition(r, c, dir);
    if ( ! m_city->isPlayerAt(r, c))
    {
        m_row = r;
        m_col = c;
    }
}

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(City* cp, int r, int c)
 : m_city(cp), m_row(r), m_col(c), m_health(INITIAL_PLAYER_HEALTH), m_age(0)
{
    if (cp == nullptr)
    {
        cout << "***** The player must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

int Player::age() const
{
    return m_age;
}

int Player::health() const
{
    return m_health;
}

bool Player::isPassedOut() const
{
    return m_health <= 0;
}

void Player::preach()
{
    m_age++;
    m_city->preachToTootersAroundPlayer();
}

void Player::move(int dir)
{
    m_age++;
    int r = m_row;
    int c = m_col;
    if (m_city->determineNewPosition(r, c, dir))
    {
          // If there are no Tooters in the new position
        if (m_city->nTootersAt(r, c) == 0)
        {
            m_row = r;
            m_col = c;
        }
    }
}

void Player::getGassed()
{
    m_health--;
}

///////////////////////////////////////////////////////////////////////////
//  City implementations
///////////////////////////////////////////////////////////////////////////

City::City(int nRows, int nCols)
 : m_rows(nRows), m_cols(nCols), m_player(nullptr), m_nTooters(0)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** City created with invalid size " << nRows << " by "
             << nCols << "!" << endl;
        exit(1);
    }
}

City::~City()
{
    for (int k = 0; k < m_nTooters; k++)
        delete m_tooters[k];
    delete m_player;
}

int City::rows() const
{
    return m_rows;
}

int City::cols() const
{
    return m_cols;
}

Player* City::player() const
{
    return m_player;
}

bool City::isPlayerAt(int r, int c) const
{
    return m_player != nullptr  &&
           m_player->row() == r  &&  m_player->col() == c;
}

int City::tooterCount() const
{
    return m_nTooters;
}

int City::nTootersAt(int r, int c) const
{
    int count = 0;
    for (int k = 0; k < m_nTooters; k++)
    {
        const Tooter* tp = m_tooters[k];
        if (tp->row() == r  &&  tp->col() == c)
            count++;
    }
    return count;
}

bool City::determineNewPosition(int& r, int& c, int dir) const
{
    switch (dir)
    {
      case UP:     if (r <= 1)      return false; else r--; break;
      case DOWN:   if (r >= rows()) return false; else r++; break;
      case LEFT:   if (c <= 1)      return false; else c--; break;
      case RIGHT:  if (c >= cols()) return false; else c++; break;
      default:     return false;
    }
    return true;
}

void City::display() const
{
      // Position (row,col) in the city coordinate system is represented in
      // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
        // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';

        // Indicate each Tooter's position
    for (int k = 0; k < m_nTooters; k++)
    {
        const Tooter* tp = m_tooters[k];
        char& gridChar = grid[tp->row()-1][tp->col()-1];
        switch (gridChar)
        {
          case '.':  gridChar = 'T'; break;
          case 'T':  gridChar = '2'; break;
          case '9':  break;
          default:   gridChar++; break;  // '2' through '8'
        }
    }

        // Indicate player's position
    if (m_player != nullptr)
    {
          // Set the char to '@', unless there's also a Tooter there
          // (which should never happen), in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }

        // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

        // Write message, Tooter, and player info
    cout << "There are " << m_nTooters << " unconverted Tooters remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isPassedOut())
            cout << "The player has passed out." << endl;
        else
            cout << "The player's health level is " << m_player->health() << endl;
    }
}

bool City::addTooter(int r, int c)
{
    if ( ! isInBounds(r, c))
        return false;

      // Don't add a Tooter on a spot with a player
    if (m_player != nullptr  &&  m_player->row() == r  &&  m_player->col() == c)
        return false;

      // Dynamically allocate a new Tooter and add it to the city
    if (m_nTooters == MAXTOOTERS)
        return false;
    m_tooters[m_nTooters] = new Tooter(this, r, c);
    m_nTooters++;
    return true;
}

bool City::addPlayer(int r, int c)
{
    if ( ! isInBounds(r, c))
        return false;

      // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;

      // Don't add a player on a spot with a Tooter
    if (nTootersAt(r, c) > 0)
        return false;

      // Dynamically allocate new Player and add it to the city
    m_player = new Player(this, r, c);
    return true;
}

void City::preachToTootersAroundPlayer()
{
      // Preach to Tooters orthogonally or diagonally adjacent to player.  If a
      // Tooter is converted, then since the order of the Tooters in the array
      // doesn't matter, we can replace the converted Tooter we remove from the
      // game by the last one in the array.
    if (m_player == nullptr)
        return;

    for (int k = 0; k < m_nTooters; )
    {
        Tooter* tp = m_tooters[k];
        int rowdiff = tp->row() - m_player->row();
        int coldiff = tp->col() - m_player->col();

          // if orthogonally or diagonally adjacent and conversion succeeds
        if (rowdiff >= -1  &&  rowdiff <= 1  &&
            coldiff >= -1  &&  coldiff <= 1  &&
            randInt(1, 3) <= 2)  // 2/3 probability
        {
            delete m_tooters[k];
            m_tooters[k] = m_tooters[m_nTooters-1];
            m_nTooters--;
        }
        else
            k++;
    }
}

void City::moveTooters()
{
    for (int k = 0; k < m_nTooters; k++)
    {
        Tooter* tp = m_tooters[k];
        tp->move();
        if (m_player == nullptr)
            continue;
        int rowdiff = tp->row() - m_player->row();
        int coldiff = tp->col() - m_player->col();
          // if orthogonally adjacent
        if  ((rowdiff == 0  &&  (coldiff == 1  ||  coldiff == -1))  ||
             (coldiff == 0  &&  (rowdiff == 1  ||  rowdiff == -1)) )
            m_player->getGassed();
    }
}

bool City::isInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols);
}

///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nTooters)
{
    if (nTooters < 0)
    {
        cout << "***** Cannot create Game with negative number of Tooters!" << endl;
        exit(1);
    }
    if (nTooters > MAXTOOTERS)
    {
        cout << "***** Trying to create Game with " << nTooters
             << " Tooters; only " << MAXTOOTERS << " are allowed!" << endl;
        exit(1);
    }
    if (rows == 1  &&  cols == 1  &&  nTooters > 0)
    {
        cout << "***** Cannot create Game with nowhere to place the Tooters!" << endl;
        exit(1);
    }

        // Create city
    m_city = new City(rows, cols);

        // Add a player
    int rPlayer = randInt(1, rows);
    int cPlayer = randInt(1, cols);
    m_city->addPlayer(rPlayer, cPlayer);

      // Populate with Tooters
    while (nTooters > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
          // Don't put a Tooter where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_city->addTooter(r, c);
        nTooters--;
    }
}

Game::~Game()
{
    delete m_city;
}

void Game::play()
{
    m_city->display();
    Player* p = m_city->player();
    if (p == nullptr)
        return;

    while ( ! p->isPassedOut()  &&  m_city->tooterCount() > 0)
    {
        cout << "Move (u/d/l/r//q): ";
        string action;
        getline(cin,action);
        if (action.size() == 0)  // player preaches
            p->preach();
        else
        {
            switch (action[0])
            {
              default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
              case 'q':
                return;
              case 'u':
              case 'd':
              case 'l':
              case 'r':
                p->move(decodeDirection(action[0]));
                break;
            }
        }
        m_city->moveTooters();
        m_city->display();
    }
    if (p->isPassedOut())
        cout << "You lose." << endl;
    else
        cout << "You win." << endl;
}

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir)
{
    switch (dir)
    {
      case 'u':  return UP;
      case 'd':  return DOWN;
      case 'l':  return LEFT;
      case 'r':  return RIGHT;
    }
    return -1;  // bad argument passed in!
}

  // Return a uniformly distributed random int from min to max, inclusive
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rdv;
    static default_random_engine generator(rdv());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementation
///////////////////////////////////////////////////////////////////////////

// YOU MAY MOVE TO ANOTHER FILE ALL THE CODE FROM HERE TO THE END OF THIS FILE,
// BUT BE SURE TO MOVE *ALL* THE CODE AS IS; DON'T REMOVE OR MODIFY ANY #IFDEF,
// ETC.  THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++/g31/g32 UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.  (The Xcode output window doesn't have the capability
// of being cleared.)

#ifdef _WIN32  //  Windows

#pragma warning(disable : 4005)
#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                                                        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <map>
#include <algorithm>
#include <thread>
#include <future>
#include <chrono>
#include <cstdlib>
#include <cassert>
using namespace std;

class StreambufSwitcher
{
  public:
    StreambufSwitcher(ios& dest, streambuf* sb,
                    ios::iostate exceptions = ios::goodbit)
     : dest_stream(dest), oldsb(dest.rdbuf(sb)), oldex(dest.exceptions())
    { dest_stream.exceptions(exceptions); }
    StreambufSwitcher(ios& dest, ios& src)
     : StreambufSwitcher(dest, src.rdbuf(), src.exceptions())
    {}
    ~StreambufSwitcher()
    { dest_stream.rdbuf(oldsb); dest_stream.exceptions(oldex); }
  private:
    ios& dest_stream;
    streambuf* oldsb;
    ios::iostate oldex;
};

map<void*, size_t> allocMap;
bool recordaddrs = false;

inline bool isRecordedSize(size_t n)
{
    return n == sizeof(Tooter)  ||  n == sizeof(Player);
}

void* operator new(size_t n)
{
    void* p = malloc(n);
    fill_n(static_cast<char*>(p), n, 0xca);
    if (recordaddrs  &&  isRecordedSize(n))
    {
        recordaddrs = false;
        allocMap.insert(make_pair(p, n));
        recordaddrs = true;
    }
    return p;
}

void unrecordaddr(void* p)
{
    recordaddrs = false;
    auto it = allocMap.find(p);
    if (it != allocMap.end())
    {
        fill_n(static_cast<char*>(p), it->second, 0xcb);
        allocMap.erase(it);
    }
    recordaddrs = true;
}

#if __cplusplus >= 201402L  &&  ! defined(__clang__)
// Unless clang is supplied the -fsized-deallocation flag, it will
// not call the C++14/17 sized operator delete.

void operator delete(void* p) noexcept
{
    free(p);
}

void operator delete(void* p, size_t n) noexcept
{
    if (recordaddrs  &&  isRecordedSize(n))
        unrecordaddr(p);
    operator delete(p);
}
#else
void operator delete(void* p) noexcept
{
    if (recordaddrs)
        unrecordaddr(p);
    free(p);
}
#endif

void testone(int n)
{
    StreambufSwitcher sso(cout, cerr);

    switch (n)
    {
                     default: {
        cout << "Bad argument" << endl;
            } break; case  1: {
        City c(10, 18);
        c.addPlayer(2, 2);
        Tooter t(&c, 5, 17);
        assert(t.row() == 5  &&  t.col() == 17);
            } break; case  2: {
        bool movedr = false;
        bool movedl = false;
        bool stayed = false;
        for (int k = 0; k < 150; k++)
        {
            City c(1, 30);
            c.addPlayer(1, 1);
            Tooter t(&c, 1, 29);
            assert(t.row() == 1  &&  t.col() == 29);
            for (int n = 0; n < 2; n++)
            {
                int oldc = t.col();
                t.move();
                assert(t.row() == 1  &&  t.col() <= 30);
                int d = t.col() - oldc;
                switch (d)
                {
                  case  0:  stayed = true; break;
                  case  1:  movedr = true; break;
                  case -1:  movedl = true; break;
                  default:  assert(false);
                }
            }
        }
        assert(movedr  &&  movedl  &&  stayed);
            } break; case  3: {
        bool movedd = false;
        bool movedu = false;
        bool stayed = false;
        for (int k = 0; k < 150; k++)
        {
            City c(20, 1);
            c.addPlayer(1, 1);
            Tooter t(&c, 19, 1);
            assert(t.row() == 19  &&  t.col() == 1);
            for (int n = 0; n < 2; n++)
            {
                int oldr = t.row();
                t.move();
                assert(t.col() == 1  &&  t.row() <= 20);
                int d = t.row() - oldr;
                switch (d)
                {
                  case  0:  stayed = true; break;
                  case  1:  movedd = true; break;
                  case -1:  movedu = true; break;
                  default:  assert(false);
                }
            }
        }
        assert(movedd  &&  movedu  &&  stayed);
            } break; case  4: {
        City c(20, 20);
        c.addPlayer(1, 1);
        Tooter t(&c, 12, 12);
        for (int k = 0; k < 8; k++)
        {
            int oldr = t.row();
            int oldc = t.col();
            t.move();
            assert((t.row() == oldr  &&  abs(t.col() - oldc) == 1)  ||
                   (t.col() == oldc  &&  abs(t.row() - oldr) == 1));
        }
            } break; case  5: {
        const int dr[NUMDIRS+1] = { -1,  0,  1,  0,  0 };
        const int dc[NUMDIRS+1] = {  0,  1,  0, -1,  0 };
        for (int k = 0; k < NUMDIRS; k++)
        {
            int nvisits[NUMDIRS+1] = { 0 };
            for (int n = 0; n < 100; n++)
            {
                City c(20, 20);
                c.addPlayer(10, 10);
                int oldr = 10 - dr[k];
                int oldc = 10 - dc[k];
                Tooter t(&c, oldr, oldc);
                t.move();
                int rdiff = t.row() - oldr;
                int cdiff = t.col() - oldc;
                int i;
                for (i = 0; i < NUMDIRS+1; i++)
                {
                    if (rdiff == dr[i]  &&  cdiff == dc[i])
                    {
                        nvisits[i]++;
                        break;
                    }
                }
                assert(i < NUMDIRS+1);
            }
            for (int i = 0; i < NUMDIRS+1; i++)
                assert(k == i ? nvisits[i] == 0 : nvisits[i] > 1);
        }
            } break; case  6: {
        City c(10, 20);
        Player p(&c, 2, 3);
        assert(p.row() == 2  &&  p.col() == 3  &&  !p.isPassedOut());
            } break; case  7: {
        City c(10, 20);
        Player p(&c, 2, 3);
        for (int k = 0; k < 12; k++)
        {
            assert(!p.isPassedOut());
            p.getGassed();
        }
        assert(p.isPassedOut());
            } break; case  8: {
        City c(10, 20);
        Player p(&c, 2, 3);
        for (int k = 0; k < 12; k++)
        {
            assert(p.health() == 12 - k);
            p.getGassed();
        }
        assert(p.isPassedOut());
            } break; case  9: {
        City c(10, 18);
        c.addPlayer(10, 17);
        Player* pp = c.player();
        pp->move(RIGHT);
        assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
        pp->move(DOWN);
        assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
        pp->move(RIGHT);
        assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
            } break; case 10: {
        City c(10, 18);
        c.addPlayer(2, 1);
        Player* pp = c.player();
        pp->move(UP);
        assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
        pp->move(LEFT);
        assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
        pp->move(UP);
        assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
            } break; case 11: {
        City c(10, 20);
        c.addPlayer(8, 12);
        Player* pp = c.player();
        pp->move(UP);
        assert(pp->row() == 7  &&  pp->col() == 12);
        pp->move(DOWN);
        assert(pp->row() == 8  &&  pp->col() == 12);
        pp->move(LEFT);
        assert(pp->row() == 8  &&  pp->col() == 11);
        pp->move(RIGHT);
        assert(pp->row() == 8  &&  pp->col() == 12);
            } break; case 12: {
        City c(10, 18);
        c.addPlayer(5, 7);
        c.addTooter(3, 7);
        c.addTooter(4, 9);
        c.addTooter(6, 8);
        c.addTooter(5, 6);
        Player* pp = c.player();
        pp->move(UP);
        assert(pp->row() == 4  &&  pp->col() == 7  &&  !pp->isPassedOut());
        pp->move(UP);
        assert(pp->row() == 4  &&  pp->col() == 7  &&  !pp->isPassedOut());
        pp->move(RIGHT);
        assert(pp->row() == 4  &&  pp->col() == 8  &&  !pp->isPassedOut());
        pp->move(RIGHT);
        assert(pp->row() == 4  &&  pp->col() == 8  &&  !pp->isPassedOut());
        pp->move(DOWN);
        assert(pp->row() == 5  &&  pp->col() == 8  &&  !pp->isPassedOut());
        pp->move(DOWN);
        assert(pp->row() == 5  &&  pp->col() == 8  &&  !pp->isPassedOut());
        pp->move(LEFT);
        assert(pp->row() == 5  &&  pp->col() == 7  &&  !pp->isPassedOut());
        pp->move(LEFT);
        assert(pp->row() == 5  &&  pp->col() == 7  &&  !pp->isPassedOut());
            } break; case 13: {
        City c(10, 18);
        c.addPlayer(3, 9);
        c.addTooter(4, 9);
        assert(c.tooterCount() == 1);
        for (int k = 0; k < 100  &&  c.tooterCount() == 1; k++)
            c.player()->preach();
        assert(c.tooterCount() == 0);
            } break; case 14: {
        City c(10, 18);
        c.addPlayer(3, 9);
        assert(c.tooterCount() == 0);
        for (int k = 1; k <= 20; k++)
        {
            c.addTooter(3, 8);
            c.addTooter(3, 10);
            assert(c.tooterCount() == 2 * k);
        }
        int prevct = c.tooterCount();
        for (int k = 0; k < 100  &&  prevct > 0; k++)
        {
            c.player()->preach();
            int ct = c.tooterCount();
            assert(ct <= prevct);
            prevct = ct;
        }
        assert(prevct == 0);
            } break; case 15: {
        City c(10, 18);
        c.addPlayer(3, 9);
        c.addTooter(2, 9);
        assert(c.nTootersAt(2, 9) == 1);
        for (int k = 0; k < 100  &&  c.nTootersAt(2, 9) == 1; k++)
            c.player()->preach();
        assert(c.nTootersAt(2, 9) == 0);
            } break; case 16: {
        City c(2, 3);
        c.addPlayer(1, 2);
        c.addTooter(1, 3);
        c.addTooter(2, 2);
        ostringstream oss;
        streambuf *sb = cout.rdbuf(oss.rdbuf());
        c.display();
        cout.rdbuf(sb);
        string s = oss.str();
        assert(s.find(".@T") != string::npos  &&  s.find(".T.") != string::npos);
            } break; case 17: {
        City c(2, 3);
        c.addPlayer(1, 2);
        for (int k = 1; k <= 8; k++)
            c.addTooter(1, 3);
        c.addTooter(2, 2);
        ostringstream oss;
        streambuf *sb = cout.rdbuf(oss.rdbuf());
        c.display();
        cout.rdbuf(sb);
        string s = oss.str();
        assert(s.find(".@8") != string::npos);
            } break; case 18: {
        City c(2, 3);
        c.addPlayer(1, 2);
        for (int k = 1; k <= 10; k++)
            c.addTooter(1, 3);
        c.addTooter(2, 2);
        ostringstream oss;
        streambuf *sb = cout.rdbuf(oss.rdbuf());
        c.display();
        cout.rdbuf(sb);
        string s = oss.str();
        assert(s.find(".@9") != string::npos);
            } break; case 19: {
        City c(10, 18);
        c.addPlayer(3, 9);
        int prevct[3];
        for (int dr = -1; dr <= 1; dr++)
        {
            if (dr == 0)
                continue;
            for (int k = 0; k < MAXTOOTERS/2; k++)
                assert(c.addTooter(3+dr, 9));
            prevct[1+dr] = c.nTootersAt(3+dr, 9);
            assert(prevct[1+dr] == MAXTOOTERS/2);
        }
        bool anyleft = true;
        for (int k = 0; k < 100  &&  anyleft; k++)
        {
            anyleft = false;
            c.preachToTootersAroundPlayer();
            for (int dr = -1; dr <= 1; dr++)
            {
                if (dr == 0)
                    continue;
                int ct = c.nTootersAt(3+dr, 9);
                assert(ct <= prevct[1+dr]);
                prevct[1+dr] = ct;
                if (ct > 0)
                    anyleft = true;
            }
        }
        assert(!anyleft);
            } break; case 20: {
        City c(10, 18);
        c.addPlayer(3, 9);
        int prevct[3][3];
        for (int dr = -1; dr <= 1; dr++)
          for (int dc = -1; dc <= 1; dc++)
          {
            if (dr == 0  &&  dc == 0)
                continue;
            for (int k = 0; k < MAXTOOTERS/8; k++)
                assert(c.addTooter(3+dr, 9+dc));
            prevct[1+dr][1+dc] = c.nTootersAt(3+dr, 9+dc);
            assert(prevct[1+dr][1+dc] == MAXTOOTERS/8);
          }
        bool anyleft = true;
        for (int k = 0; k < 100  &&  anyleft; k++)
        {
            anyleft = false;
            c.preachToTootersAroundPlayer();
            for (int dr = -1; dr <= 1; dr++)
              for (int dc = -1; dc <= 1; dc++)
              {
                if (dr == 0  &&  dc == 0)
                    continue;
                int ct = c.nTootersAt(3+dr, 9+dc);
                assert(ct <= prevct[1+dr][1+dc]);
                prevct[1+dr][1+dc] = ct;
                if (ct > 0)
                    anyleft = true;
              }
        }
        assert(!anyleft);
            } break; case 21: {
        int n = 0;
        for (int k = 0; k < 600; k++)
        {
            City c(10, 18);
            c.addPlayer(3, 9);
            assert(c.tooterCount() == 0);
            c.addTooter(3, 10);
            assert(c.tooterCount() == 1);
            c.preachToTootersAroundPlayer();
            if (c.tooterCount() == 0)
                n++;
        }
        assert(n >= 355 &&  n <= 445);
            } break; case 22: {
        City c(10, 18);
        c.addPlayer(3, 9);
        for (int k = 0; k < MAXTOOTERS; k++)
            assert(c.addTooter(2, 9));
        assert(!c.addTooter(2, 9));
        assert(c.tooterCount() == MAXTOOTERS);
        for (int n = 64; n > 0; n /= 2)
        {
            for (int k = 0; k < 100  &&  c.tooterCount() >= n; k++)
                c.preachToTootersAroundPlayer();
            assert(c.tooterCount() < n);
            for (int k = 0; k < MAXTOOTERS  &&  c.tooterCount() < MAXTOOTERS; k++)
                assert(c.addTooter(2, 9));
            assert(c.tooterCount() == MAXTOOTERS);
        }
            } break; case 23: {
        const int dr[NUMDIRS] = { -1,  0,  1,  0 };
        const int dc[NUMDIRS] = {  0,  1,  0, -1 };
        City c(12, 18);
        c.addPlayer(1, 1);
        const int r[3] = { 3, 6, 9 };
        const int v[3] = { 4, 7, 10 };
        for (int k = 0; k < 3; k++)
            c.addTooter(r[k], v[k]);
        c.moveTooters();
        for (int k = 0; k < 3; k++)
        {
            int ct[2] = { 0 };
            for (int n = 0; n < NUMDIRS; n++)
            {
                int m = c.nTootersAt(r[k]+dr[n], v[k]+dc[n]);
                assert(m == 0  ||  m == 1);
                ct[m]++;
            }
            assert(ct[0] == 3  &&  ct[1] == 1);
        }
            } break; case 24: {
        bool gassed = false;
        for (int n = 0; n < 20; n++)
        {
            City c(10, 20);
            c.addPlayer(5, 9);
            for (int k = 0; k < 11; k++)
                c.addTooter(5, 11);
            c.preachToTootersAroundPlayer();
            c.moveTooters();
            int h = c.player()->health();
            if (h < 12)
                gassed = true;
            assert(c.nTootersAt(5, 10) == 12 - h);
        }
        assert(gassed);
            } break; case 25: {
        bool gassed = false;
        for (int n = 0; n < 20; n++)
        {
            City c(10, 20);
            c.addPlayer(5, 9);
            for (int k = 0; k < 9; k++)
                c.addTooter(5, 10);
            assert(c.player()->health() == 12);
            c.moveTooters();
            int h = c.player()->health();
            if (h < 12)
                gassed = true;
            assert(c.nTootersAt(5, 10) == 12 - h);
        }
        assert(gassed);
            } break; case 26: {
        for (int n = 0; n < 20; n++)
        {
            City c(1, 20);
            c.addPlayer(1, 2);
            for (int k = 0; k < 11; k++)
                c.addTooter(1, 1);
            assert(c.player()->health() == 12);
            c.moveTooters();
            assert(c.player()->health() == 12-11);
            assert(c.nTootersAt(1, 1) == 11);
        }
            } break; case 27: {
        int n;
        for (n = 0; n < 2; n++)
        {
            City c(10, 20);
            c.addPlayer(5, 9);
            for (int k = 0; k < MAXTOOTERS; k++)
                c.addTooter(5, 11);
            assert(c.player()->health() == 12  &&  ! c.player()->isPassedOut());
            c.moveTooters();
            if (c.player()->health() <= 0  &&  c.player()->isPassedOut())
                break;
        }
        assert(n != 2);
            } break; case 28: {
        recordaddrs = true;
        int oldn = allocMap.size();
        {
            City c(10, 20);
            int oldn2 = allocMap.size();
            assert(oldn2 >= oldn);
            c.addPlayer(4, 3);
            c.addTooter(5, 6);
            c.addTooter(5, 7);
            c.addTooter(5, 8);
            assert(allocMap.size() == oldn2 + 4);
        }
        assert(allocMap.size() == oldn);
        recordaddrs = false;
            } break; case 29: {
        recordaddrs = true;
        int oldn = allocMap.size();
        {
            City c(10, 20);
            int oldn2 = allocMap.size();
            assert(oldn2 >= oldn);
            c.addPlayer(4, 3);
            assert(allocMap.size() == oldn2 + 1);
            for (int k = 0; k < MAXTOOTERS; k++)
                c.addTooter(4, 4);
            assert(allocMap.size() == oldn2 + 1 + MAXTOOTERS);
            for (int k = 0; k < 100  &&  c.nTootersAt(4, 4) > 0; k++)
            {
                c.preachToTootersAroundPlayer();
                assert(allocMap.size() == oldn2 + 1 + c.nTootersAt(4, 4));
            }
            assert(c.nTootersAt(4, 4) == 0);
        }
        assert(allocMap.size() == oldn);
        recordaddrs = false;
            } break;
    }
}

int main()
{
    cout << "Enter test number (1-29): ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
}