#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>

#include "CafeItem.h"
using namespace std;
// The Order class stores a list of cafe Items.
class Order {
 private:
  CafeItem** itemList;
  int length;

 public:
  Order();
  Order(CafeItem** itemList, int length);
  int get_length();
  void set_length(int length);
  CafeItem** get_itemList();
  void set_itemList(CafeItem** itemList);
  void generateOrder(const vector<CafeItem*>& availableItems);
  int getTotalPrice();  // returns the total price of
                        // all items in the order
  void printOrder();    // prints the cafe items in the item list
  ~Order();
};
#endif