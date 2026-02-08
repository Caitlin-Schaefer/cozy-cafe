#ifndef DAY_H
#define DAY_H

#include <vector>
#include "CafeItem.h"
#include "Customer.h"
#include "Inventory.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Day{
    private:
    Player* player; //the player 
    int num_day; //the day
    Customer* customers; //the line of customers for each day, reset daily
    
    public:
    Day();
    Day(Player* player);
    int get_day();
    void set_day(int day);
    int new_day(); //increases the day counter, increases difficulty per day
    int run_day();
    Customer* generate_customers(); //generates a list of cutomers
    Order* generate_order(); //gives random order to customer
    ~Day();
};
#endif