game: main.cpp CafeItem.cpp Cake.cpp Customer.cpp Drink.cpp Game.cpp HotChocolate.cpp \
	HotCoffee.cpp IcedCoffee.cpp Ingredient.cpp Inventory.cpp Milkshake.cpp Order.cpp Player.cpp \
	Day.cpp Food.cpp Cookie.cpp Quiche.cpp Sandwich.cpp


	g++ -std=c++11 main.cpp CafeItem.cpp Cake.cpp Customer.cpp Drink.cpp Game.cpp \
	HotChocolate.cpp HotCoffee.cpp IcedCoffee.cpp Ingredient.cpp Inventory.cpp Milkshake.cpp \
	Order.cpp Player.cpp Day.cpp Food.cpp Cookie.cpp Quiche.cpp Sandwich.cpp 
	-o game
all: game

clean:
	rm -f game
