#include <iostream>

#include "Game.h"

int main() {
  std::cout << "Welcome to Cozy Cafe!" << std::endl;

  Game game;  // Create the game instance

  // Optional: prompt player if ready (depending on your Game logic)
  game.playerReadyPrompt();

  // Start the main game loop
  game.run();

  std::cout << "Thanks for playing Cozy Cafe! Goodbye!" << std::endl;
  return 0;
}
