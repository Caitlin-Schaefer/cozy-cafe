#include "Food.h"

#include <iostream>
#include <string>

#include "CafeItem.h"
#include "Ingredient.h"
#include "Player.h"
using namespace std;

Food::Food() : CafeItem(), makeTime(0) {};
Food::~Food() {}

Food::Food(string name, double price, double makeTime, std::vector<std::pair<std::string, int>> required_ingredients) { //it dereferences the vector
  this->name = name;
  this->price = price;
  this->makeTime = makeTime;
  this->required_ingredients = required_ingredients;
}

double Food::get_time() const { return makeTime; }
double Food::calculatePrice() { return 0.0; }

void Food::sell(Player* player) {
  cout << "Sold " << name << "with time: " << get_time() << "for $"
       << calculatePrice() << endl;
  player->addCoins(price);
}

void Food::draw() { cout << "Drawing Food: " << name << endl; }