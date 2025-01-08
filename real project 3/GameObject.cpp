// #include "GameObject.h"
// #include <iostream>
// #include <string>
// #include "utilities.h"
// using namespace std;

// //GameObject implementations
// GameObjects::GameObjects(string name) : mname(name)
// {}
// GameObjects::~GameObjects()
// {}

// int GameObjects::row() { return mrow; }
// int GameObjects::col() { return mcol; }

// //weapons
// Weapons::Weapons(string name, int dex, int dam) : GameObjects(name), mdex(dex), mdam(dam)
// {}
// Weapons::~Weapons()
// {}

// int Weapons::dex() { return mdex; }
// int Weapons::dam() { return mdam; }

// //maces
// Maces::Maces(string name, int dex, int dam) : Weapons( "mace", 0, 2)
// {}
// Maces::~Maces()
// {}

// //swords
// ShortSwords::ShortSwords(string name, int dex, int dam) : Weapons("short sword", 0, 2)
// {}
// ShortSwords::~ShortSwords()
// {}

// LongSwords::LongSwords(string name, int dex, int dam) : Weapons("long sword", 2, 4)
// {}
// LongSwords::~LongSwords()
// {}

// //magic weapons
// MagicAxes::MagicAxes(string name, int dex, int dam) : Weapons("magic axe", 5, 5)
// {}
// MagicAxes::~MagicAxes()
// {}

// MagicFangs::MagicFangs(string name, int dex, int dam) : Weapons("magic fangs", 3, 2)
// {}
// MagicFangs::~MagicFangs()
// {}