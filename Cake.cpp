#include "Cake.h"
#include "Food.h"

#include <iostream>
#include <string>
using namespace std;

// Default constructor of Cake that sets the default size, flavour and price //
Cake::Cake():Food("Default Cake",8.0,5,{{"Butter",3},{"Full Cream Milk",3},{"Chocolate Cake Mix",2}}) {
  length = 4;
  width = 4;
  height = 3;
  flavour = "Chocolate";
  unlocked = true;
}
// Constructor with parameters for Cake, sets the flavour, name, price and
// unlocks the item of the cake //
Cake::Cake(int length, int width, int height) :Food("Custom Cake",10.0,7,{{"Butter",3},{"Full Cream Milk",3},{"Vanilla Cake Mix",2}}){
  this->length = length;
  this->width = width;
  this->height = height;
  this->flavour = "Vanilla";
  this->unlocked = true;
}
// Calculates the price of the cake based on its volume //
double Cake::calculatePrice() {
  int volume = length * width * height;
  return price + 0.5 * volume;
}
// Returns the preparation time of the cake, scaled by its volume (based on the
// cake size) //
double Cake::get_time() const { return (length * width * height) * 0.4; }

// Prints the cake was sold, its name and the price //
void Cake::sell(Player* player) {
  cout << "Sold " << name << " (" << flavour << ") for $" << calculatePrice()
       << endl;
  player->addCoins(calculatePrice());
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}

// Prints a visual representation of the cake sold //
void Cake::draw() {
  cout << "                 _____\n"
          "         _..--'''@   @'''--.._\n"
          "       .'   @_/-//--->/>'/ @  '.\n"
          "      (  @  /_<//<'/----------^-)\n"
          "      |'._  @     //|###########|\n"
          "      |~  ''--..@|',|}}}}}}}}}}}|\n"
          "      |  ~   ~   |/ |###########|\n"
          "      | ~~  ~   ~|./|{{{{{{{{{{{|\n"
          "       '._ ~ ~ ~ |,/`````````````\n"
          "          ''--.~.|/"
       << endl;
}