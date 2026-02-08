#ifndef CAFEITEM_H
#define CAFEITEM_H
#include <string>

using namespace std;

// Forward Declaration of Player class
class Player;

class CafeItem {
 protected:
  double price;
  string name;
  bool unlocked = false;
  Player* player;

 public:
  CafeItem();
  CafeItem(string name);
  virtual string getName() const;
  // Unlocks items
  void unlock();
  // Returns the status of a cafe item (unlocked/not unlocked)
  bool getUnlockedStatus() const;
  // Calculates the price of the item
  virtual double calculatePrice() = 0;
  // Displays the item information (name, price)
  void display();
  // Sells the item and adds coins to the player
  virtual void sell(Player* player);
  // Virtual draw method to display te item visually.
  virtual void draw();
  virtual ~CafeItem();
};
#endif  // CAFEITEM_H
