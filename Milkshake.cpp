#include "Milkshake.h"

#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Milkshake::Milkshake() {
  name = "Milkshake";
  price = 4.50;
  drinkSize = "Small";
  extraWhippedCream = false;
  flavour = "Vanilla";
  unlocked = true;
}

// Parameterised Constructor for Milkshake
Milkshake::Milkshake(string drinkSize, bool extraWhippedCream, string flavour) {
  this->drinkSize = drinkSize;
  this->extraWhippedCream = extraWhippedCream;
  this->flavour = flavour;
  this->name = flavour + " Milkshake";
  this->price = 4.50;  // Base Price for Milkshake
  this->unlocked = true;
}

// Calculates the price of the Milkshake based on its size, and if it has Extra
// Whipped Cream. Function inherited from the Drinks class.
double Milkshake::calculatePrice() {
  double finalPrice = price;
  if (drinkSize == "Medium") {
    finalPrice += 1.0;
  } else if (drinkSize == "Large") {
    finalPrice += 2.0;
  }
  if (extraWhippedCream) {
    finalPrice += 0.5;
  }
  return finalPrice;
}

// Function sells the Milkshake and increases the user's money (coins) based on
// the total cost of the item.
void Milkshake::sell(Player* player) {
  double totalPrice = calculatePrice();
  player->set_coins(player->get_coins() + totalPrice);
  cout << "Sold a " << flavour << " Milkshake (" << drinkSize << "), for $ "
       << totalPrice << endl;
  if (extraWhippedCream) {
    cout << " with extra whipped cream." << endl;
  } else {
    cout << " with no extra whipped cream." << endl;
  }
  player->addCoins(totalPrice);
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}

// Function prints the item when its ready for the customer to collect
void Milkshake::draw() {
  cout << "          /(             \n"
          "          (/)      //    \n"
          "         (~//)    //     \n"
          "        (//~//)  //      \n"
          "        (~//~//)//       \n"
          "       (//~//~//)        \n"
          "      `||-||-||-||       \n"
          "        |-|--|-|         \n"
          "         ||--||          \n"
          "         ||||||          \n"
          "        /__||__A        \n"
       << endl;
}