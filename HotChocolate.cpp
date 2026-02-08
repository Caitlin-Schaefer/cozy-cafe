#include "HotChocolate.h"

#include <iostream>
#include <string>

#include "Player.h"
using namespace std;

// Default Constructor for HotChocolate
HotChocolate::HotChocolate() {
  name = "Hot Chocolate";
  price = 4.50;
  drinkSize = "Small";
  numMarshmellow = 0;
  unlocked = true;
}
// Parameterised Constructor for Hot Chocolate
HotChocolate::HotChocolate(string drinkSize, int numMarshmellow) {
  name = "Hot Chocolate";
  price = 4.50;
  this->drinkSize = drinkSize;
  this->numMarshmellow = numMarshmellow;
  unlocked = true;
}
// Overrides the virtual function inherited from the drinks class, to calculate
// the price of the Hot Chocolate based on its size and number of marshmellows
double HotChocolate::calculatePrice() {
  double finalPrice = price;
  if (drinkSize == "Medium") {
    finalPrice += 1.0;
  } else if (drinkSize == "Large") {
    finalPrice += 2.0;
  }
  finalPrice += 0.5 * numMarshmellow;
  return finalPrice;
}

// Function sells the Hot Chocolate and increases the user's money (coins) by
// the total cost of the item.
void HotChocolate::sell(Player* player) {
  double totalPrice = calculatePrice();
  player->set_coins(player->get_coins() + totalPrice);
  cout << "Sold Hot Chocolate with " << numMarshmellow << " Marshmellows for $"
       << totalPrice << endl;
  player->addCoins(price);
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}
// Function prints the item when its ready for the customer to collect
void HotChocolate::draw() {
  cout << "         )  (                                          \n"
          "       (   ) )                                        \n"
          "       ) ( (                                          \n"
          "       _______)_                                      \n"
          "    .-'---------|    _____________,-.___     _        \n"
          "   ( C|/////////|    |____       { {]_]_]   [_]      \n"
          "    '-./////////|    |___ `-----.| |]_]_]_    . `    \n"
          "      '_________'    |   `-----._ } }_]_]_]_   ,     \n"
          "       '-------'     |_____________| |]_]_]_] , `    \n"
       << endl;
}