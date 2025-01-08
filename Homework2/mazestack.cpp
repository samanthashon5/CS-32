#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Coord
        {
          public:
            Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
            int r() const { return m_row; }
            int c() const { return m_col; }
          private:
            int m_row;
            int m_col;
        };

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack <Coord> istack;

    istack.push(Coord(sr,sc));
    if(sr == er && sc == ec)
    {
        return true;
    }

    maze[sr][sc] = '#';

    while(!istack.empty())
    {
        Coord x = istack.top();
        istack.pop();
        int r = x.r();
        int c = x.c();

        if(r == er && c == ec)
        {
            return true;
        }

        if(maze[r][c + 1] == '.')
        {
            istack.push(Coord(r,c + 1));
            maze[r][c + 1] = '#';
        }

        if(maze[r + 1][c] == '.')
        {
            istack.push(Coord(r +1,c));
            maze[r + 1][c] = '#';
        }

        if(maze[r][c - 1] =='.')
        {
            istack.push(Coord(r,c - 1));
            maze[r][c - 1] = '#';
        }

        if(maze[r - 1][c] =='.')
        {
            istack.push(Coord(r - 1,c));
            maze[r - 1][c] = '#';
        }
    }
    return false;
}

