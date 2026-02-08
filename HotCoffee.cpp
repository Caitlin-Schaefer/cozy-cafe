#include "HotCoffee.h"

#include <iostream>
#include <string>
using namespace std;

// Default Constructor
HotCoffee::HotCoffee() {
  name = "Hot Coffee";
  price = 4.0;
  drinkSize = "Small";
  withExtraShot = false;
  milkType = "Full Cream";
  unlocked = true;
}

// Parameterised Constructor for Hot Coffee
HotCoffee::HotCoffee(string drinkSize, bool withExtraShot, string milkType) {
  this->drinkSize = drinkSize;
  this->withExtraShot = withExtraShot;
  this->milkType = milkType;
  this->name = "Hot Coffee";
  this->price = 4.0;
  this->unlocked = true;
}

// Calculates the price of the Hot Coffee based on its size, and if it has an
// Extra Shot or different milk type from "Full Creamn" milk.
// Function inherited from the Drinks class.
double HotCoffee::calculatePrice() {
  double finalPrice = price;

  // Drink Size Pricing Additions
  if (drinkSize == "Medium") {
    finalPrice += 1.0;
  } else if (drinkSize == "Large") {
    finalPrice += 2.0;
  }
  // Extra Shot Pricing Additions
  if (withExtraShot) {
    finalPrice += 0.80;
  }
  // Different Milk Type Pricing
  if (milkType == "Soy" || milkType == "Oat" || milkType == "Almond" ||
      milkType == "Lactose Free") {
    finalPrice += 1.0;
  }
  return finalPrice;
}

// Function sells the Hot Coffee and increases the user's money (coins) based on
// the total cost of the item.
void HotCoffee::sell(Player* player) {
  double totalPrice = calculatePrice();
  player->set_coins(player->get_coins() + totalPrice);
  cout << "Sold a Hot Coffee (" << drinkSize << ") with " << milkType
       << " milk";
  if (withExtraShot) {
    cout << " and an extra shot";
  }
  cout << " for $" << totalPrice << endl;
  player->addCoins(totalPrice);
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}

// Function prints the item when its ready for the customer to collect
void HotCoffee::draw() {
  cout << "         )  (        \n"
          "       (   ) )       \n"
          "       ) ( (         \n"
          "       _______)_     \n"
          "    .-'---------|    \n"
          "   ( C|/////////|    \n"
          "    '-./////////|    \n"
          "      '_________'    \n"
          "       '-------'     \n"
       << endl;
}