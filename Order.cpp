#include "Order.h"

#include <ctime>
#include <iostream>
#include <vector>

#include "CafeItem.h"
using namespace std;
Order::Order() {
  itemList = nullptr;
  length = 0;
}
Order::Order(CafeItem** itemList, int length) {
  this->itemList = itemList;
  this->length = length;
}
int Order::get_length() { return this->length; }
void Order::set_length(int length) { this->length = length; }
CafeItem** Order::get_itemList() { return this->itemList; }

void Order::generateOrder(const vector<CafeItem*>& availableItems) {
  if (availableItems.empty()) {
    this->itemList = nullptr;
    this->length = 0;
    cout << "Generated " << this->length << " items in order.\n";
    return;
  }
  srand(time(0));
  int numItems = 1 + rand() % min(2, (int)availableItems.size());
  this->length = numItems;
  // Allocates an array of CafeItem* pointers
  this->itemList = new CafeItem*[numItems];

  for (int i = 0; i < numItems; i++) {
    int index = rand() % availableItems.size();
    // Assigns the pointer
    this->itemList[i] = availableItems[index];
  }
}
void Order::set_itemList(CafeItem** itemList) { this->itemList = itemList; }
int Order::getTotalPrice() {
  int totalPrice = 0;
  for (int i = 0; i < this->length; i++) {
    totalPrice += this->itemList[i]->calculatePrice();
  }
  return totalPrice;
}
void Order::printOrder() {
  for (int i = 0; i < this->length; i++) {
    itemList[i]->display();
  }
}
Order::~Order() { delete[] this->itemList; }