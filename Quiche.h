#include "Food.h"
#ifndef QUICHE_H
#define QUICHE_H

class Quiche:public Food{
    //a quiche has private attributes radius and height
    private:
    int radius;
    int height;

    public:
    Quiche();
    Quiche(int radius, int height);
    double calculatePrice() override;
    double get_time() const override;
    void sell(Player* player) override;
    void draw() override;
};
#endif
