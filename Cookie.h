#include "Food.h"
#ifndef COOKIE_H
#define COOKIE_H

class Cookie:public Food{
    //a cookie has private attributes weight and whether it needs to be vegan
    private:
    bool isVegan;
    double weight;

    public:
    Cookie();
    Cookie(bool isVegan, double weight);
    double calculatePrice() override;
    double get_time() const override;
    void sell(Player* player) override;
    void draw() override;
};
#endif
