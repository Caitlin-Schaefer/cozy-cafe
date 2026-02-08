#ifndef ICEDCOFFEE_H
#define ICEDCOFFEE_H
#include <iostream>
#include <string>

#include "Drink.h"
#include "Player.h"
using namespace std;

class IcedCoffee : public Drink {
 protected:
  bool withSyrup;
  string syrupFlavour;

 public:
  IcedCoffee();
  IcedCoffee(string drinkSize, bool withSyrup, string syrupFlavour);
  double calculatePrice() override;
  void sell(Player* player) override;
  void draw() override;
};
#endif