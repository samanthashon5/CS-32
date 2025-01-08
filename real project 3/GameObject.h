// #ifndef GAMEOBJECT_H
// #define GAMEOBJECT_H
// #include <string>

// class GameObjects
// {
// public:
//  GameObjects(std::string name);
//  virtual ~GameObjects();

//  std::string name();

//  void pickup();
//  void occupy();

// private:
//  std::string mname;
// };

// //Weapons
// class Weapons: public GameObjects
// {
// public:
//  Weapons(std::string name, int dex, int dam);
//  virtual ~Weapons();

//  int dex();
//  int dam();

//  virtual std::string action() = 0;
//  virtual int dbonus() = 0;
//  virtual int damage() = 0;

// private:
//  int mdex = 0;
//  int mdam = 0;
// };

// class Maces: public Weapons
// {
// public:
//  Maces(std::string name, int dex, int dam);
//  virtual ~Maces();
//  //dexterity bonus 0 damage amt 2
// };

// class ShortSwords: public Weapons
// {
// public:
//  ShortSwords(std::string name, int dex, int dam);
//  virtual ~ShortSwords();
//  //dexterity bonus 0 damage amt 2
// };

// class LongSwords: public Weapons
// {
// public:
//  LongSwords(std::string name, int dex, int dam);
//  virtual ~LongSwords();
//  //dexterity bonus 2 damage amt 4
// };

// class MagicAxes: public Weapons
// {
// public:
//  MagicAxes(std::string name, int dex, int dam);
//  virtual ~MagicAxes();
//  //dexterity bonus 5 damage amt 5
// };

// class MagicFangs: public Weapons
// {
// public:
//  MagicFangs(std::string name, int dex, int dam);
//  virtual ~MagicFangs();
//  //dexterity bonus 3 damage amt 2
//  void sleep();
// };

// // //Scrolls
// // class Scrolls: public GameObjects
// // {
// // public:
// //  Scrolls(Temple* t, int r, int c);
// //  virtual ~Scrolls();
// //  void read();
// //  virtual void spell() = 0;
// // };

// // class Teleportation: public Scrolls
// // {
// // public:
// //  Teleportation(Temple* t, int r, int c);
// //  virtual ~Teleportation();
// //  //randomly move player to another place not occupied by wall or monster
// //  virtual void spell();
// // };

// // class ImpArm: public Scrolls
// // {
// // public:
// //  ImpArm(Temple* t, int r, int c);
// //  virtual ~ImpArm();
// //  //increase player's armor points by random inteer from 1 to 3
// //  virtual void spell();
// // };

// // class RseStrg: public Scrolls
// // {
// // public:
// //  RseStrg(Temple* t, int r, int c);
// //  virtual ~RseStrg();
// //  //increase player's strength by a random integer from 1 to 3
// //  virtual void spell();
// // };

// // class EnHlth: public Scrolls
// // {
// // public:
// //  EnHlth(Temple* t, int r, int c);
// //  virtual ~EnHlth();
// //  //player's max hit point value increased by random integer from 2 to 8
// //  virtual void spell();
// // };

// // class EnDex: public Scrolls
// // {
// // public:
// //  EnDex(Temple* t, int r, int c);
// //  virtual ~EnDex();
// //  //player's dexterity increased by 1
// //  virtual void spell();
// // };

// #endif




