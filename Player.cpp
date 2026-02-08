#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Cookie.h"
#include "Ingredient.h"
using namespace std;

// Default constructor
Player::Player() {
  coins = 50;
  currentDay = 1;
  name = "Player";
  inventory.initaliseBaselineIngredients();
  this->menu = {"HotCoffee", 
                "HotChocolate",
                "Milkshake", 
                "IcedCoffee", 
                "Quiche", 
                "Cake", 
                "Cookie", 
                "Sandwich"};
  
  }
Player::Player(const string& playerName) {
  coins = 50;
  currentDay = 1;
  name = playerName;
  inventory.initaliseBaselineIngredients();
  this->menu = {"HotCoffee", 
    "HotChocolate",
    "Milkshake", 
    "IcedCoffee", 
    "Quiche", 
    "Cake", 
    "Cookie", 
    "Sandwich"};
}
void Player::loadGameFromFile(const string& filename) {
  ifstream load(filename);
  if (!load.is_open()) {
    cout << "Error: Could not open " << filename << " for loading." << endl;
    return;
  }

  string line;
  // Loads the player's name
  getline(load, name);
  // Loads the coins
  getline(load, line);
  coins = stoi(line);
  // Loads the current day
  getline(load, line);
  currentDay = stoi(line);

  // Inventory is re-initialised after the game loads so the inventory is not
  // empty
  inventory.initaliseBaselineIngredients();

  load.close();
  cout << "Game Successfully Loaded from " << filename << "." << endl;
}

// Function to save a game to a specific save file
void Player::saveGameToFile(const string& filename) {
  ofstream save(filename);
  if (!save.is_open()) {
    cout << "Error: Could not open " << filename << " for saving." << endl;
    return;
  }

  if (coins < 0) {
    coins = 0;
  }

  // Saves the name, coins and current day
  save << name << endl;
  save << coins << endl;
  save << currentDay << endl;

  save.close();
  cout << "Game Successfully Saved to " << filename << "." << endl;
}

// Slot-based load functions
void Player::loadGame1() { loadGameFromFile("save1.txt"); }
void Player::loadGame2() { loadGameFromFile("save2.txt"); }
void Player::loadGame3() { loadGameFromFile("save3.txt"); }

// Slot-based Save Functions
void Player::saveGame1() { saveGameToFile("save1.txt"); }
void Player::saveGame2() { saveGameToFile("save2.txt"); }
void Player::saveGame3() { saveGameToFile("save3.txt"); }

// Display Game Function and Instructuons
void Player::displayInstructions() {
  cout << "Welcome to Cozy Cafe!\n" << endl;
  cout << "Serve Customers, Earn Coins, and Unlock Menu Items!" << endl;
  cout << "All while developing your business understanding!" << endl;
  cout << "Game Rules and Instructions: " << endl;
  cout << "- Take Customer Orders, and Prepare Cafe Items \n";
  cout << "- Earn Coins (money) through serving Customers and selling Cafe "
          "Items.\n";
  cout << "- At the end of each day, manage inventory through purchasing "
          "ingredients in the store.\n";
  cout << "- Unlocked new items at the end of each day. \n";
  cout << "- Users have the ability to both save, and reload the game between "
          "days."
       << endl;
  cout << "===================================================================="
          "=======================" << endl;
  cout << "" << endl;
}

// Function increments and prints the current day
void Player::nextDay() {
  currentDay++;
  cout << "Day " << currentDay
       << " begins. Let's Open the Cafe and Serve some Customers!" << endl;
}

// Function adds coins to the user's total when they serve a customer
void Player::addCoins(int amount) { coins += amount; }
// Function adds a new menu Item to the unlocked items list
void Player::unlockItem(string newItem) {
  unlockedMenu.push_back(newItem);
  cout << "Unlocked a New Item: "<<newItem<<endl;
}

// Getters for name, coins and current day:
string Player::get_name() const { return name; }
int Player::get_coins() const { return coins; }
int Player::get_CurrentDay() const { return currentDay; }

// Setters for name, coins and current day:
void Player::set_name(const string& playerName) { name = playerName; }
void Player::set_CurrentDay(int day) { currentDay = day; }
void Player::set_coins(int amount) { coins = amount; }
void Player::set_unlockedMenu(vector<string> unlockedMenu){
  this->unlockedMenu = unlockedMenu;
}
// Function returns the reference to the player's inventory
Inventory& Player::get_Inventory() { return inventory; }

// Fuction gets all the items
vector<string> Player::get_menu() { return menu; }

// Function gets all the Unlocked Items
vector<string> Player::get_unlockedMenu() const {  return unlockedMenu; }

// Function allows the user to purchase ingredients at the end of each day
void Player::purchaseIngredients() {
  cout << "\nWelcome to the Market!" << endl;
  cout << "You have " << coins << " coins. \n";
  // Vector containing the items avalible in the market
  vector<string> availableItems = {"Full Cream Milk",
                                   "Almond Milk",
                                   "Lactose Free Milk",
                                   "Oat Milk",
                                   "Chocolate Powder",
                                   "Ice",
                                   "Marshemellows",
                                   "Coffee Beans",
                                   "Chocolate Syrup",
                                   "Strawberry Syrup",
                                   "Chocolate Cake Mix",
                                   "Vannila Cake Mix",
                                   "Red Velvet Cake Mix",
                                   "Butter",
                                   "Tomatoes",
                                   "Lettuce",
                                   "Chicken",
                                   "Bread"};
  // Vector of the item prices
  vector<double> prices = {2, 3, 3, 3, 3, 2, 1, 2, 4, 3, 3,
                           3, 3, 3, 3, 2, 2, 1, 2, 4, 2};

  // If the User wishes to purchase ingredients from the market, they are able
  // to enter the number of items, otherwise, if they wish to purchase no
  // items, they can enter 0 and it will return to the home screen
  while (true) {
    bool flag3 = true;
    
    string input;
    while (flag3 == true) {
      cout << "Enter the number of items to buy (0 to exit): ";
      cin >> input;

      if (stoi(input) < availableItems.size()) flag3 = false;
    }

    int numItems = stoi(input);
    // If the user enters the number 0, the while loop is broken and the
    // player exits out of the market function and back to the game.
    if (input == "0") break;

    string qtyInput;
    bool flag2 = true;

    while (flag2 == true) {
      cout << "How many units of " << availableItems[numItems - 1] << "? ";
      cin >> qtyInput;

      if (stoi(qtyInput) < availableItems.size()) flag2 = false;
    }

    int totalCost = stoi(qtyInput) * prices[numItems - 1];
    if (totalCost > coins) {
      cout << "Not enough coins. You have " << coins << ".\n";
      continue;
    }

    // Buys the ingredient (decreases the coins), and adds it to the inventory
    // quantity
    Ingredient* ingredient = new Ingredient(
        availableItems[numItems - 1], prices[numItems - 1], stoi(qtyInput));

    inventory.addIngredient(ingredient);
    coins -= totalCost;
    cout << "Purchased " << qtyInput << " of " << availableItems[numItems - 1]
         << " for " << totalCost << " coins.\n";
    cout << "Remaining coins: " << coins << "\n";
  }
}

// Display's the users game statistics at the end of each day
void Player::displayStats() {
  cout << "\n === " << name << "'s End of Day Stats ===" << endl;
  cout << "Coins: " << coins << endl;
  cout << "Current Day: " << currentDay << endl;
  cout<<endl;
  cout<<"(enter)"<<endl;
  cin.get();
  system("clear");
  inventory.printInventory();
  cout << "_________________________\n" << endl;
}

