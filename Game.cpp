#include "Game.h"

#include <time.h>

#include <cstdlib>
#include <iostream>
Game::Game() { NewGame(); }
void Game::NewGame() {
  population = 100;
  wheat = 2800.0;
  acre = 1000.0;
};
void Game::GameStart() {
  PrepareForNewRound();
  PlayRound();
}
void Game::PrepareForNewRound() {
  round = 0;

  starvation = 0;
  buy_acres = 0.0;
  sell_acres = 0.0;
  food_wheat = 0.0;
  plant_acres = 0.0;

  RandomGenerate();
};

void Game::RandomGenerate() {
  srand(time(0));
  acre_price = 0.0;  ///!!
  wheat_per_acre = (rand() % 6) + 1;
  destroyed_wheat = ((rand() % 7) / 100.0f) * wheat;
  newcomers = 0;///!!

  plague = false;///!!
};

void Game::PlayRound() {
  RandomGenerate();
  DisplayInfo();
  ReadPlayerData();
  CheckExit();
};
void Game::DisplayInfo() {
  std::cout << "\n\n\nINFORMATION OF ROUND ¹";
  std::cout << round << "\n Died from starvation " << starvation
            << "\n Moved to the city " << moved << "\n Was plague  " << plague
            << "\n Population " << population << "\n All wheat " << wheat
            << "\n Wheat per acre " << wheat_per_acre
            << "\n Wheat destroyed by rats " << destroyed_wheat
            << "\n Acres in city" << acre << "\n Price of 1 acre "
            << acre_price;
}
void Game::CheckExit() {
  // Want to play or continue playig?
  std::string load = "continue";
  std::cout << "\n Continue or exit : ";
  std::cin >> load;

  if (load == "exit") {
    std::cout << "Exit game";
  } else if (load == "continue") {
    PlayRound();
  } else {
    std::cout << "Wrong command!";
  }
}

void Game::ReadPlayerData() {
  // Enter the Info
  std::cout << "\n\nEnter the numbers";
  std::cout << "\nHow many acres you want to buy?";
  std::cin >> buy_acres;
  std::cout << "\nHow many acres you want to sell?";
  std::cin >> sell_acres;
  std::cout << "\nHow many wheat you want to use as food?";
  std::cin >> food_wheat;
  std::cout << "\nHow many acres you want to use for planting the wheat?";
  std::cin >> plant_acres;
}
void Game::GameCicle(){


};
