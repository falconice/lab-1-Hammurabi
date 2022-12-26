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
  // —брос до показателей первого уровн€
  //
  // acre wheat people
  this->wheat.WheatStart(2800);
  this->people.PeopleStart(100);
  this->acre.AcreStart(1000);

  // set players name??
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
  // счтьывние ответов пользовател€
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
  //+ если выйти, то сохран€ем в файл и выходим
  //+ если продолжить то созран€ем файлы и  идем дальше;
  std::cout << "\n «акончить игру?";
  std::cout << "\n 1. «акончить игру и сохранить файлы. ";
  std::cout << "\n 2. ѕродолжить игру и сохранить файлы. ";
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
  std::cout << "\n      I beg to report to you "
            << "\n           In Year " << round << ",\n";
  // was
  std::cout << "        Plague ? -> " << people.WasPlague() << ". \n      "
            << people.GetStarvation(wheat.GetWheatQuantity())
            << " people starved, \n            And\n      Rats destroyed "
            << wheat.GetDestroyedWheat(people.GetPopulation())
            << "  wheat.\n\n  "
            << people.GetNewcommers(wheat.GetWheatPerAcre(),
                                    wheat.GetWheatQuantity())
            << " new people moved to the city. ";
  // now
  std::cout << "\n  Now the city population is  " << people.GetPopulation()
            << "!\n"
            << "   Harvested " << wheat.GetWheatPerAcre()
            << " bushels  per acre. \n\n";

  // wealth
  std::cout << "   You have " << wheat.GetWheatQuantity()
            << " bushels of wheat.\n"
            << "     The city owns " << acre.GetAcreQuantity() << " acres.\n"
            << "Now price of one acre is " << acre.GetAcrePrice()
            << " wheat per acre.\n";
}
void Game::ReadPlayerInput() {
  float tmp;
  // Enter the Info
  std::cout << "\n\nEnter the numbers";
  std::cout << "\nHow many acres you want to buy?";
  std::cin >> tmp;
  acre.ArcesWantToBuy(tmp);

  std::cout << "\nHow many acres you want to sell?";
  std::cin >> tmp;
  acre.ArcesWantToSell(tmp);
  std::cout << "\nHow many wheat you want to use as food?";
  std::cin >> tmp;
  wheat.WheatToFeed(tmp);

  std::cout << "\nHow many acres you want to use for planting the wheat?";
  std::cin >> tmp;
  acre.ArcesWantToPlant(tmp);
}

void Game::CalculateStats() {}
