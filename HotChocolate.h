#ifndef HOTCHOCOLATE_H
#define HOTCHOCOLATE_H
#include <iostream>
#include <string>

#include "Drink.h"
using namespace std;

class HotChocolate : public Drink {
 protected:
  int numMarshmellow;

 public:
  HotChocolate();
  HotChocolate(string drinkSize, int numMarshmellow);
  double calculatePrice() override;
  void draw() override;
  void sell(Player* player) override;
};
#endif  // HOTCHOCOLATE_H