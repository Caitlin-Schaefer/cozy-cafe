#include "IcedCoffee.h"

#include <iostream>
#include <string>
using namespace std;

// Default Constructor
IcedCoffee::IcedCoffee() {
  name = "Iced Coffee";
  price = 4.50;
  drinkSize = "Small";
  withSyrup = false;
  syrupFlavour = "None";
  unlocked = true;
}

// Parameterised Constructor for IcedCoffee
IcedCoffee::IcedCoffee(string drinkSize, bool withSyrup, string syrupFlavour) {
  this->drinkSize = drinkSize;
  this->withSyrup = withSyrup;
  this->syrupFlavour = withSyrup ? syrupFlavour : "None";
  this->name = "Iced Coffee";
  this->price = 4.50;
  this->unlocked = true;
}
// Calculates the price of the Iced Coffee based on its size, and if it has
// Syrup Function inherited from the Drinks class.
double IcedCoffee::calculatePrice() {
  double finalPrice = price;
  if (drinkSize == "Medium") {
    finalPrice += 1.0;
  } else if (drinkSize == "Large") {
    finalPrice += 2.0;
  }
  if (withSyrup) {
    finalPrice += 0.80;
  }
  return finalPrice;
}
// Function sells the Iced Coffee and increases the user's money (coins) based
// on the total cost of the item.
void IcedCoffee::sell(Player* player) {
  double totalPrice = calculatePrice();
  player->set_coins(player->get_coins() + totalPrice);
  cout << "Sold an Iced Coffee (" << drinkSize << ") ";
  if (withSyrup) {
    cout << "with " << syrupFlavour << " syrup ";
  } else {
    cout << "with no syrup ";
  }
  cout << "for $" << totalPrice << endl;
  player->addCoins(totalPrice);
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}

// Function prints the item when its ready for the customer to collect
void IcedCoffee::draw() {
  cout << "             / / \n"
          "            / /  \n"
          "           / /   \n"
          "      .-''/ /-.  \n"
          "      |'-----'|  \n"
          "      |-.....-|  \n"
          "      |       |  \n"
          "      |       |  \n"
          "      |       |  \n"
          "      |       |  \n"
          "     .`'-----'`"
       << endl;
}