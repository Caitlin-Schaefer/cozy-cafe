#include <iostream>

#include "CafeItem.h"  // assuming you have this
#include "Drink.h"
#include "Food.h"
#include "HotCoffee.h"
#include "Ingredient.h"
#include "Player.h"

using namespace std;

int main() {
  cout << "=== Starting Cozy Cafe Game Test ===\n";

  // Create player with name "Bob"
  Player player("Bob");

  cout << "Player name: " << player.get_name() << "\n";

  // Initialize inventory with baseline ingredients
  player.get_Inventory().initaliseBaselineIngredients();

  // Display starting stats and inventory
  player.displayStats();

  // Simulate purchasing ingredients
  cout << "\nSimulating purchase of 3 Full Cream Milk...\n";
  Ingredient* newIngredient = new Ingredient("Full Cream Milk", 5, 3);
  player.get_Inventory().addIngredient(newIngredient);

  cout << "\nSimulating purchase of 2 Chocolate Syrup...\n";
  newIngredient = new Ingredient("Chocolate Syrup", 8, 2);
  player.get_Inventory().addIngredient(newIngredient);

  player.displayStats();

  // Simulate using ingredients
  cout << "\nUsing 5 Ice...\n";
  player.get_Inventory().use("Ice", 5);

  cout << "\nUsing 20 Coffee Beans (should fail)...\n";
  player.get_Inventory().use("Coffee Beans", 20);

  player.displayStats();

  // Unlock a menu item (dummy example)
  cout << "\nUnlocking new item: HotCoffee\n";
  HotCoffee* hotCoffee = new HotCoffee();
  player.unlockItem(hotCoffee);

  // Save game
  cout << "\nSaving game...\n";
  player.saveGame1();

  // Change player state
  player.set_name("Alice");
  player.set_coins(100);
  player.set_CurrentDay(3);

  cout << "\nModified Player name: " << player.get_name() << "\n";

  // Load game back (restores previous state)
  cout << "\nLoading game...\n";
  player.loadGame1();

  cout << "Player name after load: " << player.get_name() << "\n";
  cout << "Coins after load: " << player.get_coins() << "\n";
  cout << "Day after load: " << player.get_CurrentDay() << "\n";

  player.displayStats();

  cout << "\n=== End of Test ===\n";

  return 0;
}
