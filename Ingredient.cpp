#include "Ingredient.h"

#include <iostream>
using namespace std;
// Constructors, and getters and setters for the Ingredient class.
Ingredient::Ingredient() {
  this->name = "";
  this->price = 0;
  this->amount = 0;
}
Ingredient::Ingredient(string name, int price, int amount) {
  this->name = name;
  this->price = price;
  this->amount = amount;
}
int Ingredient::get_price() { return this->price; }
string Ingredient::get_name() { return this->name; }
int Ingredient::get_amount() { return this->amount; }
void Ingredient::set_price(int price) { this->price = price; }
void Ingredient::set_name(string name) { this->name = name; }
void Ingredient::set_amount(int amount) { this->amount = amount; }
void Ingredient::increase_amount(int amount) { this->amount += amount; }
void Ingredient::decrease_amount(int amount) { this->amount -= amount; }