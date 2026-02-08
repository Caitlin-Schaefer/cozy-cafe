#ifndef CAKE_H
#define CAKE_H
#include <iostream>
#include <string>

#include "Food.h"
using namespace std;

class Cake : public Food {
 protected:
  Player player;

 private:
  int length;
  int width;
  int height;
  string flavour;

 public:
  Cake();
  Cake(int length, int width, int height);
  double calculatePrice() override;
  double get_time() const override;
  void sell(Player* player) override;
  void draw() override;
};
#endif