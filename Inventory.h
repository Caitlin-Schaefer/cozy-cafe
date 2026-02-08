#ifndef INVENTORY_H
#define INVENTORY_H
#include <unordered_set>

#include "Ingredient.h"

class Player;  // Forward declaration of class Player

// The Inventory class stores the Ingredients that the player owns.
class Inventory {
 private:
  unordered_set<Ingredient*>
      stock;     // The list of Ingredients owned by the player.
  int maxStock;  // The maximum number of different Ingredients that will be in
                 // the stockList
  int currentStock;  // The number of Ingredients currently unlocked by the
                     // player

 public:
  Inventory();
  Inventory(int maxStock);
  void initializeStock();
  void initaliseBaselineIngredients();
  void addIngredient(Ingredient* newIngredient);  // unlock a new ingredient
  int buy(Player* player, string IngredientName,
          int quantity);  // buy an ingredient, 1 not succsessful, 0 sucsessfull
  int use(string IngredientName,
          int amount);    // use an ingredient, 1 not sucsessfull, 0 sucsessfull
  void printInventory();  // print a list of ingredients and the amount owned
  void askUserBuy(Player* player);
  ~Inventory();
};
#endif
