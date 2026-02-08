#include "Quiche.h"
#include "Food.h"
#include "CafeItem.h"

    Quiche::Quiche():Food("Default Quiche",13.4,6,{{"Tomato",3},{"Full Cream Milk",1},{"Chicken",3}}),radius(5),height(5){
        price = calculatePrice();
        makeTime = get_time();
    }

    Quiche::Quiche(int radius, int height):Food("Custom Quiche",13.4,6,{{"Tomato",3},{"Full Cream Milk",1},{"Chicken",3}}),radius(radius),height(height){
        price = calculatePrice();
        makeTime = get_time();
    }

    double Quiche::get_time() const {
        double volume = 3.14 * radius * radius * height;
        double time = volume * 1.5;
        return time;
    }
    double Quiche::calculatePrice() {
        double final_pricing = 8; //standard, for radius 10 height 5
        if (radius == 15 && height == 6){
            final_pricing *= 0.5;
        } else if (radius == 20 && height == 7){
            final_pricing *= 0.75;
        }
        return final_pricing;
    }

    void Quiche::sell(Player* player) {
        cout << "Sold Quiche for $ " << this->price << endl;
        player->addCoins(this->price);
        cout << "Current coins: "<<player->get_coins()<<endl;
        draw();
    }

    void Quiche::draw() {
        cout <<
        
"        _,..---..,_    \n"
"    ,-'`    .'.    `'-,    \n"
"   ((      '.'.'      ))   \n"
"    `'-.,_   '   _,.-'`    \n"
"      `|  `'''''`  /`  \n"
"        `''-----''`'   \n"
        <<endl; 
    };
