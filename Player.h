#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "CafeItem.h"
#include "Ingredient.h"
#include "Inventory.h"

class Player {
 private:
  int coins;
  int currentDay;
  string name;
  Inventory inventory;
  vector<string> menu;
  vector<string> unlockedMenu;

 public:
  Player();
  Player(const string& playerName);
  void loadGameFromFile(const string& filename);
  void saveGameToFile(const string& filename);
  void loadGame1();
  void loadGame2();
  void loadGame3();
  void saveGame1();
  void saveGame2();
  void saveGame3();
  void displayInstructions();
  void nextDay();
  void addCoins(int amount);
  void unlockItem(string newItem);
  string get_name() const;
  int get_CurrentDay() const;
  int get_coins() const;
  void set_name(const string& playerName);
  void set_CurrentDay(int day);
  void set_coins(int amount);
  void set_unlockedMenu(vector<string> unlockedMenu);
  Inventory& get_Inventory();
  vector<string> get_menu();
  vector<string> get_unlockedMenu() const;
  void purchaseIngredients();
  void displayStats();
};

#endif  // PLAYER_H
