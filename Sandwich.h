#include "Food.h"
#ifndef SANDWICH_H
#define SANDWICH_H

class Sandwich:public Food{
    //A sandwich has private attributes breadtype and whether it needs to be toasted
    //it also inherits makeTime and ingredients from the food class
    private:
    bool toasted;
    string breadType;

    public:
    //default constructor for sandwich
    Sandwich();
    Sandwich(bool toasted, string breadType);
    double calculatePrice() override;
    double get_time() const override;
    void sell(Player* player) override;
    void draw() override;
};
#endif