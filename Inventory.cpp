#include "Inventory.h"

#include <iostream>
#include <iomanip>
#include <limits>

#include "Ingredient.h"
#include "Player.h"
using namespace std;
#include <cmath>
// Default Constructor
Inventory::Inventory() {
  maxStock = 100;
  currentStock = 0;
  initializeStock();
}
Inventory::Inventory(int maxStock) {
  this->currentStock = 0;
  this->maxStock = maxStock;
  initializeStock();
}

void Inventory::initializeStock() {
  stock.insert(new Ingredient("Full Cream Milk", 10, 5));
  stock.insert(new Ingredient("Almond Milk", 5, 6));
  stock.insert(new Ingredient("Lactose Free Milk", 5, 6));
  stock.insert(new Ingredient("Oat Milk", 5, 6));
  stock.insert(new Ingredient("Ice", 15, 1));
  stock.insert(new Ingredient("Marshmellows", 7, 3));
  stock.insert(new Ingredient("Coffee Beans", 10, 7));
  stock.insert(new Ingredient("Strawberry Syrup", 6, 4));
  stock.insert(new Ingredient("Chocolate Cake Mix", 4, 8));
  stock.insert(new Ingredient("Red Velvet Cake Mix", 4, 8));
  stock.insert(new Ingredient("Butter", 10, 3));
  stock.insert(new Ingredient("Tomatoes", 5, 2));
  stock.insert(new Ingredient("Lettuce", 5, 3));
  stock.insert(new Ingredient("Chicken", 5, 10));
  stock.insert(new Ingredient("Bread", 10, 3));
}

void Inventory::initaliseBaselineIngredients() {
  struct IngredientData {
    string name;
    int amount;
    int price;
  };

  IngredientData baselineIngredients[] = {{"Full Cream Milk", 10, 5},
                                          {"Almond Milk", 5, 6},
                                          {"Lactose Free Milk", 5, 6},
                                          {"Oat Milk", 5, 6},
                                          {"Ice", 15, 1},
                                          {"Marshmellows", 7, 3},
                                          {"Coffee Beans", 10, 7},
                                          {"Strawberry Syrup", 6, 4},
                                          {"Chocolate Cake Mix", 4, 8},
                                          {"Red Velvet Cake Mix", 4, 8},
                                          {"Butter", 10, 3},
                                          {"Tomatoes", 5, 2},
                                          {"Lettuce", 5, 3},
                                          {"Chicken", 5, 10},
                                          {"Bread", 10, 3}};

  int baselineCount = sizeof(baselineIngredients) / sizeof(IngredientData);
  for (int i = 0; i < baselineCount; i++) {
    Ingredient* ingredient = new Ingredient();
    ingredient->set_name(baselineIngredients[i].name);
    ingredient->set_amount(baselineIngredients[i].amount);
    ingredient->set_price(baselineIngredients[i].price);
    this->addIngredient(ingredient);
  }
}

void Inventory::addIngredient(Ingredient* newIngredient) {
  if (!newIngredient) return;

  for (auto s : stock) {
    if (s->get_name() == newIngredient->get_name()) {
      s->increase_amount(newIngredient->get_amount());
      return;
    }
  }

  // If the new ingredient is not found, a new space is added for it
  if (stock.size() - 1 < maxStock) {
    stock.insert(newIngredient);
  } else {
    cout << "Inventory is full! Cannot add more ingredients.\n";
    delete newIngredient;  // avoids memory leak
  }
}

// Function asks the user if they wish to purchase anything from the Market
void Inventory::askUserBuy(Player* player) {
  bool flag5 = true;
  string input;
  if (stock.empty()) return;
  while (flag5) {
    cout << "You have " << player->get_coins() << " coins left." << endl;
    cout << "Would you like to purchase anything from the store? (yes/no): ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <--- flush newline!

    // If the user input's "no", the user exits the market and is directed back
    // to the main game loop.
    if (input == "no") {
      return;
      // if the user input's "yes", the market items and prices are printed.
    } else if (input == "yes") {
      flag5 = false;
    }
  }
  bool flag6 = true;
  Ingredient* ig = nullptr;
  string val;
  while (flag6 == true) {
    cout << "What item would you like to purchase? ";
    getline(cin, val);

    for (auto s : stock) {
      if (s->get_name() == val) {
        ig = s;
        flag6 = false;
      }
    }
    cout << endl;
  }
  system("clear");

  cout << "Name: " << ig->get_name() << endl;
  cout << "Price: " << ig->get_price() << " coins each" << endl << endl;

  string qtyStr;
  int qty = 0;
  bool fg = true;
  while (fg) {
    cout << "How many " << ig->get_name()
         << " would you like to buy? You can afford a maximum of "
         << floor((double)player->get_coins() / ig->get_price()) << ": ";
    getline(cin, qtyStr);

    try {
      qty = stoi(qtyStr);
      fg = false;
    } catch (invalid_argument const& e) {
      cout << "Invalid input. Please enter a number.\n";
      fg = true;
      continue;  // restart the loop
    } catch (out_of_range const& e) {
      cout << "The number you entered is too large.\n";
      fg = true;
      continue;
    }
  }

  // When the user enters a valid input, the buy function is called
  buy(player, ig->get_name(), qty);
}

int Inventory::buy(Player* player, string IngredientName, int quantity) {
  // find the location of the Ingredient in our array
  Ingredient* stk = nullptr;

  for (auto item : stock) {
    if (item && item->get_name() == IngredientName) {
      stk = item;
      break;
    }
  }

  if (stk != nullptr) {
    stock.erase(stk);
  } else {
    cout << IngredientName << " is not an unlocked ingredient" << endl;
    cout << endl;
    return 1;
  }
  int totalCost = stk->get_price() * quantity;

  // Checks if the player has enough coins
  if (player->get_coins() < totalCost) {
    cout << "You don't have enough coins to buy " << quantity << " "
         << IngredientName << "!" << endl;
    return 1;
  }

  // Deducts coins and increases ingredient amount
  player->set_coins(player->get_coins() - totalCost);

  stk->increase_amount(quantity);
  cout << "You bought " << quantity << " " << IngredientName << "(s) for "
       << totalCost << " coins." << endl;
  cout << "You now have " << player->get_coins() << " coins left." << endl;

  stk->increase_amount(quantity);

  stock.insert(stk);
  return 0;
}

int Inventory::use(string IngredientName, int amount) {
  // find the location of the Ingredient in our array
  Ingredient* stk = nullptr;

  for (auto item : stock) {
    if (item && item->get_name() == IngredientName) {
      stk = item;
      break;
    }
  }
  if (stk != nullptr) {
    stock.erase(stk);
  } else {
    cout << IngredientName << " is not an unlocked ingredient" << endl;
    cout << endl;
    return 1;
  }

  if (stk->get_amount() > amount) {
    stk->decrease_amount(amount);
    cout << "You have used " << amount << " " << stk->get_name() << endl;
    cout << endl;
  } else {
    cout << "Error" << endl;
    cout << "You only have " << stk->get_amount() << " " << stk->get_name()
         << ". You cannot use " << amount << ". No stock has been subtracted."
         << endl;
    cout << endl;
  }
  stock.insert(stk);
  return 0;
}

// Function prints the users current inventory, including the ingredient names
// and amount and coins in a table format
void Inventory::printInventory() {
  cout << endl;
  cout << "========== Inventory ==========\n" << endl;

  // Header
  cout << left << setw(25) << "Ingredient Name" << setw(10) << "Amount"
       << setw(10) << "Price" << endl;
  cout << string(45, '-') << endl;  // Horizontal line

  // Content rows
  for (auto s : stock) {
    cout << left << setw(25) << s->get_name() << setw(10) << s->get_amount()
         << setw(10) << s->get_price() << endl;
  }

  cout << endl;
}

Inventory::~Inventory() {
  for (int i = 0; i < currentStock; ++i) {
    // delete stock[i];
  }
  // delete[] this->stock;
}
