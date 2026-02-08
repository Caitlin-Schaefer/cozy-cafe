#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "Day.h"
#include "Inventory.h"
#include "Order.h"
#include "Player.h"
using namespace std;

class Game {
 private:
  unordered_set<string> st;
  Player* player; //used to handle player logic 
  Day day; //used to handle day logic
  Customer customer;
  Order order;
  Inventory inventory;

  bool isPlayerReady;
  bool userPlayAgain;
  bool loadSavedGame;

 public:
  Game();
  
  // Functions for User Interaction
  void playerReadyPrompt();
  void displayMainMenu();
  void displayInstructions();

  // Functions for Loading/Saving game progress
  bool loadGame(string slot);
  bool saveGame(string slot);

  // Functions for Game play
  void newOrLoad();
  void startGame();

  // Main Game Loop
  void run();
};
#endif  // GAME_H
