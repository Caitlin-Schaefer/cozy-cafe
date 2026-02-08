#include "CafeItem.h"

#include <iostream>
#include <string>

#include "Player.h"
using namespace std;

// The function CafeItem, sets the attribute isUnlocked to false //
CafeItem::CafeItem() : name("Unknown"), price(0.0), unlocked(false) {}

// Constructor to set the name. The price can be set in the derived cllasses
// (Food and Drink)
CafeItem::CafeItem(string name) : name(name), price(0.0), unlocked(false) {}

// Function returns the items name
string CafeItem::getName() const { return name; }

// This function unlocks menu items
void CafeItem::unlock() {
  unlocked = true;
  cout << name << " has been unlocked!\n" << endl;
}

bool CafeItem::getUnlockedStatus() const { return unlocked; }
// This display function displays the state of the object, their adjusted price
// and unique ingredients.
void CafeItem::display() {
  cout << "Item: " << name << " | Price: " << price << " coins.\n";
}
// This function sells cafe items and increases the user's money (coins).
void CafeItem::sell(Player* player) {
  double totalPrice = calculatePrice();
  player->set_coins(player->get_coins() + totalPrice);
  cout << "Sold Item for $" << totalPrice << endl;
  player->addCoins(price);
}
// The virtual draw() function draws different cafe items when they are ready
// for the customer to collect.
void CafeItem::draw() { cout << "Drawing CafeItem" << name << endl; }

// Virtual Deconstructor to allow proper clean up in the subclasses
CafeItem::~CafeItem() {}
