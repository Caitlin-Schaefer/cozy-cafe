#ifndef MILKSHAKE_H
#define MILKSHAKE_H
#include <iostream>
#include <string>
using namespace std;

#include "Drink.h"
#include "Player.h"

class Milkshake : public Drink {
 private:
  bool extraWhippedCream;
  string flavour;

 public:
  Milkshake();
  Milkshake(string drinkSize, bool extraWhippedCream, string flavour);
  double calculatePrice() override;
  void sell(Player* player) override;
  void draw() override;
};
#endif  // MILKSHAKE_H