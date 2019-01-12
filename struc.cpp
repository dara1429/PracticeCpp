#include "struc.h"
#include <iostream>
using namespace std;

struc::struc()
{
  //init
}

struc::~struc()
{
  //deinit
}

void struc::strucMain()
{
  weapon dragonDagger;
  dragonDagger.wepName = "Dragon Dagger";
  dragonDagger.strength = 24;

  weapon runeLongsword;
  runeLongsword.wepName = "Rune Longsword";
  runeLongsword.strength = 16;

  cout << dragonDagger.wepName << " : " << dragonDagger.strength << endl;

  player guy;
  guy.name = "Guy";
  guy.health = 50;
  guy.inventory.push_back(dragonDagger);
  guy.inventory.push_back(runeLongsword);

  cout << "Name : " << guy.name << endl;
  cout << "Health : " << guy.health << endl;
  cout << "Weapons : " << endl;
  for(int i = 0; i < guy.inventory.size(); i++)
  {
    cout << guy.inventory[i].wepName << endl;
  }

  cout << "--------------------" << endl;
  pointerBasics(&pointy);
  cout << pointy.name << endl;
  cout << pointy.inventory[0].wepName << " : " << pointy.inventory[0].strength << endl;

  return;
}

void struc::pointerBasics(player *p)
{
  p->name = "Mark";
  p->health = 90;
  weapon e;
  p->inventory.push_back(e);
  p->inventory[0].wepName = "Excalibur";
  p->inventory[0].strength = 99;

  //* vs direct vs &
  cout << p->name << endl; //reference to name of player
  cout << &p->name << endl; //address of name of player
  cout << "---------------------" << endl;
  return;
}
