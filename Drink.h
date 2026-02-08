#ifndef DRINK_H
#define DRINK_H
#include <string>
using namespace std;
#include "CafeItem.h"
#include "Player.h"

// Class Drink inherits from CafeItem //
class Drink : public CafeItem {
 protected:
  string drinkSize;

 public:
  // Defualt constructor for drink//
  Drink();
  // Constructor with parameters for drink to initialise name, price and the
  // drink size//
  Drink(string name, double price, string drinkSize);
  // override the pure virtual function calculatePrice(), inherited from the
  // CafeItem class to calculate the drink price //
  double calculatePrice() override;
  // Displays a visual representation of the ordered drink //
  void draw() override;
  // Sell's the drink and outputs the final price to the user on the console //
  void sell(Player* player) override;
};
#endif