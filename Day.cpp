#include "Day.h"

#include <cstdlib>  //used for rand()
using namespace std;
#include <iostream>

#include "CafeItem.h"
#include "Customer.h"
#include "HotCoffee.h"
#include "HotChocolate.h"
#include "Milkshake.h"
#include "IcedCoffee.h"
#include "Cake.h"
#include "Quiche.h"
#include "Cookie.h"
#include "Sandwich.h"

Day::Day(){}
Day::Day(Player* player) {
  this->player = player; 
  this->num_day = 0; 
  this->player->set_unlockedMenu({"HotCoffee", "HotChocolate", "Milkshake"}); //setting unlocked menu in preperation for day 1
}

// returns current day
int Day::get_day() { return num_day; }
void Day::set_day(int day){this->num_day = day;}

// prepares a new day, unlocks one item menu and generates custmers
int Day::new_day() {
  
  num_day += 1; //increase day counter 

  player->unlockItem(player->get_menu()[num_day+2]); //unlock one item from the menu
  this->customers = generate_customers();
  cout<<"(enter)"<<endl;
  cin.get();
  cin.get();
  
  cout<<"CAFE MENU:"<<endl; //print menu
  for(int i=0; i<num_day+3; i++){
    cout<<player->get_unlockedMenu()[i]<<endl;
  }cout<<"(enter)"<<endl;
  cin.get();
  return 0;
}

// increases number of customers as day increase
Customer* Day::generate_customers() {
  int num_customer = 2 * num_day;
  Customer* customers = new Customer[num_customer];

  //same vector must be used so has to be static
  static std::vector<std::string> customer_names = {"Olivia", "Amelia", "Charlotte", "Emma", "Mia", "Sophia", "Isabella", "Ava", "Evelyn", "Harper", "Luna"};

  // loop through each customer and add a random order to them
  for (int i = 0; i < num_customer; i++) {
    int random_name = rand() % customer_names.size();
    customers[i].set_name(customer_names[random_name]);
    customers[i].set_order(generate_order());       // generate order for each customer
  }
  return customers;
}
// generates random orders for each customer
Order* Day::generate_order() {
  Order* order = new Order; //create a new order
  int length = 0;
  length = num_day + 1;
  CafeItem** items = new CafeItem*[length];
  string item;
  for(int i=0; i<length; i++){ 
    item = player->get_unlockedMenu()[rand() % (num_day +3)]; //select random item from unlocked menu
    if(item == "HotCoffee"){
      items[i] = new HotCoffee();
    } else if(item == "HotChocolate"){
      items[i] = new HotChocolate();
    } else if(item == "Milkshake"){
      items[i] = new Milkshake();
    } else if(item == "IcedCoffee"){
      items[i] = new IcedCoffee();
    } else if(item == "Cake"){
      items[i] = new Cake();
    } else if(item == "Cookie"){
      items[i] = new Cookie();
    } else if(item == "Sandwich"){
      items[i] = new Sandwich();
    } else if(item == "Quiche"){
      items[i] = new Quiche();
    }
  } order->set_length(length);
  order->set_itemList(items);
  return order;
}



int Day::run_day(){
  for(int i=0; i<(num_day*2); i++){
    customers[i].print();
    cout<<endl;
    string accept;
    cout<<"Accept this order? (y,n) :";
    cin>> accept;
    cout<<endl;
    cin.get();
    if(accept == "y"){
      for(int j=0; j<num_day+1; j++){
        customers[i].get_order()->get_itemList()[j]->sell(player);
        cout<<"(enter)"<<endl;
        cin.get();
        cout<<endl;
      }
    } system("clear");
  }
  return 0;
}

Day::~Day(){
  delete[] customers;
}