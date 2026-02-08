#include "Customer.h"
#include "Order.h"
#include <iostream>
using namespace std;
Customer::Customer(){}
Customer::Customer(string name, Order* order){
    this->name = name;
    this->order = order;
}
string Customer::get_name(){return this->name;}
void Customer::set_name(string name){this->name = name;}
Order* Customer::get_order(){return this->order;}
void Customer::set_order(Order* order){this->order = order;}
void Customer::print(){
    cout<<"=====ORDER====="<<endl;
    cout<<"Hello, my name is "<<this->name<<"!"<<endl;
    cout<<"May I please order:"<<endl;
    order->printOrder();
    cout<<endl;
}