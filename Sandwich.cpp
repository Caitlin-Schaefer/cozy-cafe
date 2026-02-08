#include "Sandwich.h"
#include "Food.h"
#include "Inventory.h"
#include "CafeItem.h"

    Sandwich::Sandwich():Food("Default sandwich",11.9,0.5, {{"Bread",2},{"Tomato",1},{"Bread",1},{"Lettuce",1},{"Chicken",1}}),toasted(false),breadType("Wholemeal"){
        price = calculatePrice();
        makeTime = get_time();
    }

    Sandwich::Sandwich(bool toasted, string breadType):Food("Custom sandwich",11.9,0.5,{{"Bread",2},{"Tomato",1},{"Bread",1},{"Lettuce",1},{"Chicken",1}}),toasted(toasted),breadType(breadType){
        price = calculatePrice();
        makeTime = makeTime;
    }
    double Sandwich::calculatePrice() {
        double final_pricing = 10; //set the standard price to 10 coins;
        if (toasted == true){
            final_pricing += 0.2;
        }if (breadType == "wholegrain"){
            final_pricing += 0.5;
        }
        return final_pricing;
    };

    double Sandwich::get_time() const {
        double time = 1;
        if (toasted == true){
            time = time + 1;
        } else {
            time = time;
        }
        return time;
    };

    void Sandwich::sell(Player* player) {
        cout << "Sold Sandwich for $" << this->price << endl;
        player->addCoins(this->price);
        cout << "Current coins: "<<player->get_coins()<<endl;
        draw();
}

    void Sandwich::draw() {
        cout<<
"                    _.---._    \n"
"                _.-~       ~-._    \n"
"            _.-~               ~-._    \n"
"        _.-~                       ~---._  \n"
"    _.-~                                 ~|    \n"
" .-~                                    _.;    \n"
" :-._                               _.-~./     \n"
" }-._~-._                   _..__.-~_.-~ )     \n"
" `-._~-._~-._              /   ...-~H.-~   \n"
"     ~-nad.._|.        _.-~ .::::  //  \n"
"         ~-. |`--...--~ _.-~__...==~   \n"
"            |.`--...---+-~~~~~ \n"
"              ~-..----~    \n"
        <<endl;
    };