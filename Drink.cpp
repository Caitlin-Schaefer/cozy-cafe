#include "Drink.h"

#include <iostream>
#include <string>
using namespace std;

// Default constructor for Drink //
Drink::Drink() {
  drinkSize = "Small";
  name = "Sample Drink";
  price = 3.0;
  unlocked = true;
}
// Constructor with parameters for drink to initialise name, price and the drink
// size//
Drink::Drink(string name, double price, string drinkSize) {
  this->name = name;
  this->price = price;
  this->drinkSize = drinkSize;
  this->unlocked = true;
}
// Override the pure virtual function calculatePrice(), inherited from the
// CafeItem class to calculate the drink price //
double Drink::calculatePrice() {
  if (drinkSize == "Small") {
    return price;
  } else if (drinkSize == "Medium") {
    return price + 1.0;
  } else if (drinkSize == "Large") {
    return price + 2.0;
  } else {
    return price;
  }
}
// Displays a visual representation of the ordered drink //
void Drink::draw() {
  cout << "Drawing Drink: " << name << "(" << drinkSize << ")" << endl;
}

// Sell's the drink and outputs the final price to the user on the console //
void Drink::sell(Player* player) {
  double finalPrice = calculatePrice();
  cout << "Sold " << name << " (" << drinkSize << ") for $" << finalPrice
       << endl;
  player->addCoins(finalPrice);
}
