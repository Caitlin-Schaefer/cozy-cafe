#include "Cookie.h"

#include "CafeItem.h"
#include "Food.h"
//default constructor for cookie
Cookie::Cookie():Food("Default Cookie",8.0,5,{{"Butter",2},{"Full Cream Milk",1},{"Chocolate Powder",1},{"Chocolate Cake Mix",1}}),isVegan(false),weight(5.0){
  price = calculatePrice();
  makeTime = get_time();
}
//custom constructor that uses passed in values
Cookie::Cookie(bool isVegan, double weight):Food("Custom Cookie",8.0,5,{{"Butter",2},{"Full Cream Milk",1},{"Chocolate Powder",1},{"Chocolate Cake Mix",1}}),isVegan(isVegan),weight(weight){
  price = calculatePrice();
  makeTime = get_time();
}

//calculates time taken to make cookie
double Cookie::get_time() const {
  double time = weight * 0.2;
  return time;
}

//demonstrates polymorphism where calculate price function has been overidden and provided with a different method
double Cookie::calculatePrice() {
  double final_pricing = 3;
  if (isVegan == true) {
    final_pricing += 2.0;
  }
  if (weight > 5 && weight < 10) {
    final_pricing *=0.25;
  } else if (weight > 15 && weight < 20) {
    final_pricing *=0.5;
  } else if (weight > 25 && weight < 30) {
    final_pricing *=0.75;
  }
  return final_pricing;
};

void Cookie::sell(Player* player) {
  cout << "Sold a cookie for $" << this->price << endl;
  player->addCoins(this->price);
  cout << "Current coins: "<<player->get_coins()<<endl;
  draw();
}

void Cookie::draw() {
  cout<<
  "   ,-. \n"
  "_ (*_*)_\n"
  "(_  o  _) \n"
  "  / o | \n"
  " (_/ |_) \n"
  <<endl;
};
