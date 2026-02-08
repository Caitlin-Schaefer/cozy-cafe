#ifndef FOOD_H
#define FOOD_H
#include "CafeItem.h"
#include "Ingredient.h"
#include "Player.h"
#include <vector>
#include <string>

//
class Food : public CafeItem {
 protected:
  double makeTime;
  //dynamic array (vector) where each element is a pair with a string and integer (an ingredient and its amount)
  std::vector<std::pair<std::string, int>> required_ingredients;

 public:
  // default constructor for food
  Food();
  virtual ~Food();

  Food(string name, double price, double makeTime, std::vector<std::pair<std::string, int>> required_ingredients); 

  // pure virtual function that does nothing in the abstract class
  virtual double calculatePrice() override;

  // gets the time
  virtual double get_time() const = 0;
  void sell(Player* player) override;
  void draw() override;
};
#endif