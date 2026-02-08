#include "Game.h"

#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
using namespace std;

// Constructor initialises the game state flags
Game::Game() {
  isPlayerReady = false;
  userPlayAgain = false;
  loadSavedGame = false;
  this->player = new Player; //create a new player object
  this->day = Day(player); //create a new day object
}

// Function Asks user if they are ready to start the game
void Game::playerReadyPrompt() {
  // Clears Terminal
  system("clear");
  cout << "====== Welcome to Cozy Cafe =====" << endl;
  cout << "A place where your understanding of real-world business will be "
          "developed in a low-stakes environment!"
       << endl;
  cout << "===================================================================="
          "========================================"
       << endl;
  string input;
  while (true) {
    cout << "Are you ready to commence the game? (yes/no): ";
    cin >> input;
    // If the user inputs 'yes', or a variation of agreeance, isPlayerReady is
    // set to true and the loop is broken.
    if (input == "yes" || input == "Yes" || input == "YES" || input == "y" ||
        input == "Y") {
      isPlayerReady = true;
      break;
      // If the user inputs 'no', or a variation of non-agreeance, the
      // isPlayerReady remains set to false, and loops again
    } else if (input == "no" || input == "NO" || input == "N" || input == "n" ||
               input == "N" || input == "nope" || input == "Nope" ||
               input == "NOPE") {
      bool isPlayerReady = false;
      cout << "Take your time. Let me know when you are ready." << endl;
    }  // Handles invalid input from the user
    else {
      cout << "Invalid input. Please enter yes or no" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

// Function displays the game's main menu
void Game::displayMainMenu() {
  // Clears terminal
  system("clear");
  cout << "==== Welcome to Cozy Cafe ====" << endl;
  cout << "===================================================================="
          "======================="
       << endl;
  // Game Instructions
  cout << "Game Instructions: " << endl;
  cout << "- Take Customer Orders, and Prepare Cafe Items \n";
  cout << "- Earn Coins (money) through serving Customers and selling Cafe "
          "Items.\n";
  cout << "- At the end of each day, manage inventory through purchasing "
          "ingredients in the store.\n";
  cout << "- Unlocked new items at the end of each day. \n";
  cout << "- Users have the ability to both save, and reload the game between "
          "days."
       << endl;
  cout << "===================================================================="
          "======================="
       << endl;
  cout << "Game Menu: " << endl;
  cout << "1. Start a New Game" << endl;
  cout << "2. Reload a Saved Game" << endl;
  cout << "3. Exit Game" << endl;
  cout << "Enter you choice (1-3): " << endl;
  cout << "===================================================================="
          "======================="
       << endl;
}

// Functions for Game Logic

// Function used to determines if the user wishes to begin a new game, or load a
// previous game
void Game::newOrLoad() {
  string choice;
  bool flag = true;

  while (flag) {
    cout << "New or Load Game? (new/load): ";
    cin >> choice;

    // Convert User input to lower case
    for (int i = 0; i < choice.length(); ++i) {
      tolower(choice[i]);
    }

    // New game logic
    if (choice == "new") {
      // Starts a new game
      flag = false;
      string playerName;

      cout << "Enter your name: ";
      cin >> playerName;
      
      // Creates a new Player with the Users name
      this->player->set_name(playerName);
      system("clear");
      cout << "Welcome, " << playerName << "! Starting a new game...\n";
      // Waits for 3 seconds before loading the next screen
      this_thread::sleep_for(chrono::seconds(3));
      break;

      // Loads saved game logic
    } else if (choice == "load") {
      string slot;
      cout << "Enter save slot to load game (1-3): ";
      cin >> slot;

      if (st.count(slot) && (slot == "1" || slot == "2" || slot == "3")) {
        if (loadGame(slot)) {
          cout << "\nGame Loaded Successfully from Slot " << slot << ".\n";
          break;
        }
        flag = false;
      } else {
        cout << "Invalid Slot Number or game has not been saved. Please Enter "
                "Either 1, 2 or "
                "3 \n";
      }
    } else {
      cout << "Invalid input. Please type 'new' or 'load'. \n";
    }
  }
}

// Function loads the game data from the given save slot
bool Game::loadGame(string slot) {
  if (!st.count(slot)) {
    cout << "Invalid, Never Saved." << endl;
    return false;
  }

  if (slot == "1") {
    player->loadGame1();
    return true;
  } else if (slot == "2") {
    player->loadGame2();
    return true;
  } else if (slot == "3") {
    player->loadGame3();
    return true;
  } else {
    cout << "Game never saved." << endl;
  }
  return false;
}

// Function Saves the Game Data to the given Save Slot
bool Game::saveGame(string slot) {
  // If we already have a save slot, dont override
  // set will only store values that have not been set yet
  if (st.count(slot)) {
    cout << "Already saved in this slot, cannot overwrite" << endl;
    return false;
  }
  // insert the value into the set because we havent found it yet
  st.insert(slot);
  if (slot == "1") {
    player->saveGame1();
    return true;
  } else if (slot == "2") {
    player->saveGame2();
    return true;
  } else if (slot == "3") {
    player->saveGame3();
    return true;
  } else {
    cout << "Game never saved." << endl;
  }
  return false;
}

// Function starts or resumes the game after new/load selection
// (1 day per iteration)
void Game::startGame() {
  system("clear");
  cout << "Starting the game... \n";
  string input;
  while (true) {
    cout << "Day " << day.get_day()+1 << ": \n";
    day.new_day();
    day.run_day();
    system("clear");

    // Displays the players statistics (coins, current day, and current
    // inventory)
    player->displayStats();
    inventory.askUserBuy(player);

    // Asks the player if they wish to continue playing or save the game
    char choice;

    while (true) {
      if(day.get_day() == 5){
        system("clear");
        day.set_day(0);
        cout << "Congrats! You've completed 5 days of Cozy Cafe 🥳" << endl;
        cout << "Thank you for playing with us :) " << endl;
        cout<<"(enter)"<<endl;
        cin.get();
        cin.get();

        return;
      }
      
      cout << "Would you like to continue to the next day? (y/n): ";
      cin >> choice;

      if (choice == 'y' || choice == 'Y') {
        system("clear");
        // Continues the game onto the next day
        player->nextDay();
        day.new_day();
        day.run_day();
        player->displayStats();
        inventory.initializeStock();
        inventory.askUserBuy(player);

        this_thread::sleep_for(chrono::seconds(3));
        system("clear");
        player->displayStats();
        this_thread::sleep_for(chrono::seconds(3));
        
      } else if (choice == 'n' || choice == 'N') {
        string slot;
        cout << "Enter save slot to save progress (1-3): ";
        cin >> slot;

        if (!st.count(slot) && (slot == "1" || slot == "2" || slot == "3")) {
          if (saveGame(slot)) {
            cout << "Game saved successfully to slot " << slot << ".\n";
          }
        }

        // Exits the game loop after saving the users progress
        return;

      } else {
        cout << "Invalid input. Please enter 'y' or 'n'.\n";
      }
    }
  }
}

// Function responsible for running the game application
void Game::run() {
  // Asks the user if they are ready to play
  playerReadyPrompt();
  // If the player isn't ready, this loop with exit the game early.
  while (!isPlayerReady) {
    playerReadyPrompt();
  }

  system("clear");

  // Main menu loop
  while (true) {
    displayMainMenu();

    string choice;
    cin >> choice;

    if (choice == "1") {
      // Handles new or load game function
      newOrLoad();
      // Starts or resumes (re-loads) the game loop
      startGame();
    } else if (choice == "2") {
      string slot;
      cout << "Enter save slot to load (1-3): ";
      cin >> slot;

      if (st.count(slot) && (slot == "1" || slot == "2" || slot == "3")) {
        if (loadGame(slot)) {
          cout << "Game loaded successfully. \n";
          startGame();
        }
      } else {
        cout << "Game never saved." << endl;
      }

    } else if (choice == "3") {
      cout << "Thank you for playing with us :) " << endl;
      cout << "Exiting the Game. Goodbye! \n";
      system("clear");
      // Exits the run loop and ends the program
      return;
    }
  }
}
