#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Order.h"
using namespace std;

//The Customer class has a name and an order. 
class Customer{
    private:
        string name;
        Order* order; 
    public:
        Customer();
        Customer(string name, Order* order);
        string get_name();
        void set_name(string name);
        Order* get_order();
        void set_order(Order* order);
        void print();
};
#endif