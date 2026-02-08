#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
using namespace std;
// Ingredient class, stores name and price of ingredients.
// Has getters and setters for price and name. Has constructors.
class Ingredient {
 private:
  int price;    // price of ingredient
  string name;  // name of ingredient
  int amount;   // amount owned
 public:
  Ingredient();
  Ingredient(string name, int price, int amount);
  int get_price();
  void set_price(int price);
  string get_name();
  void set_name(string name);
  int get_amount();
  void set_amount(int amount);
  void increase_amount(int amount);
  void decrease_amount(int amount);
};
#endif