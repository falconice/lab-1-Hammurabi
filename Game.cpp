#include "Game.h"

#include <time.h>

#include <cstdlib>
#include <iostream>
Game::Game() {
  round = 0;
  want_to_exit = 0;
}
void Game::Start() {
  // New
  //    NewGame();
  // Play
  //   Play();
  // Load from file
  // Save to file
  // Exit
  //    DoYouWantToExit();
}
void Game::NewGame() {
  // Сброс до показателей первого уровня
  // set players name
  // startRound  NextRound(round);
  round = 1;
}
void Game::Play() {
  // while round >=10
  while (round < 10) {
    if (round == 1) {
      // NewGame
    } else {
      NextRound(round);
    };
  }

  // TODO: count final stats
  // TODO:  show result & end the game
}
void Game::NextRound(int round_number) {
  //  а потом
  // вывод данных
  // DisplayStats();
  // счтьывние ответов пользователя
  // ReadPlayerInput();
  // просчет данных введенных + исходных
  // CalculateStats();
  // спросить про выход
  // DoYouWantToExit();
}
void Game::DoYouWantToExit() {
  // в конце каждого раунда
  //+ спросить
  //+ продолжать или выйти
  //+ если выйти, то сохраняем в файл и выходим
  //+ если продолжить то созраняем файлы и  идем дальше;
  std::cout << "\n Закончить игру?";
  std::cout << "\n 1. Закончить игру и сохранить файлы. ";
  std::cout << "\n 2. Продолжить игру и сохранить файлы. ";
  std::cin >> want_to_exit;

  switch (want_to_exit) {
    case 1:
      // save + cout
      // exit + cout
      break;
    case 2:
      // save + cout
      // continue round+=1;
      break;

    default:
      std::cout << "\n Error. Unknown command. ";
      break;
  }
}

void Game::DisplayStats() {
  std::cout << "\n\n\nINFORMATION OF ROUND №";
  std::cout << round << "\n Died from starvation " << starvation
            << "\n Moved to the city " << moved << "\n Was plague  " << plague
            << "\n Population " << population << "\n All wheat " << wheat
            << "\n Wheat per acre " << wheat_per_acre
            << "\n Wheat destroyed by rats " << destroyed_wheat
            << "\n Acres in city" << acre << "\n Price of 1 acre "
            << acre_price;
}
void Game::ReadPlayerInput() {
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

void Game::CalculateStats() {
  wheat -= destroyed_wheat;

  // Потребление бушелей??
  if (20 * population >= wheat) {
    starvation = population - ((20 * population - wheat) / 20);
    if (starvation > 0.45 * population) {
      cout << "game over. 45%+ died of starvation";
    }
  } else {
    starvation = 0;
  };
}
