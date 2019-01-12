#ifndef STRUC_H
#define STRUC_H
#include <string>
#include <vector>

struct weapon
{
  std::string wepName;
  int strength;
};

struct player
{
  std::string name;
  int health;
  std::vector<weapon> inventory;
};

class struc
{
  public:
    struc();
    ~struc();
    void strucMain();
    void pointerBasics(player *p);
  private:
  protected:
    player pointy;
};

#endif //STRUC_H
