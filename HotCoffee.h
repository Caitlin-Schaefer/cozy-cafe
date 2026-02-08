#ifndef HOTCOFFEE_H
#define HOTCOFFEE_H
#include <iostream>
#include <string>

#include "Drink.h"
#include "Player.h"
using namespace std;

class HotCoffee : public Drink {
 protected:
  bool withExtraShot;
  string milkType;

 public:
  HotCoffee();
  HotCoffee(string drinkSize, bool withExtraShot, string milkType);
  double calculatePrice() override;
  void sell(Player* player) override;
  void draw() override;
};
#endif  // HOTCOFFEE_H