#include "Game.h"

#include <time.h>

#include <cstdlib>
#include <iostream>

Game::Game() {
  round_ = 0;
  want_to_exit_ = 0;
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
  //
  // acre wheat people
  this->wheat.WheatStart(2800);
  this->people.PeopleStart(100);
  this->acre.AcreStart(1000);

  // set players name??
  // startRound  NextRound(round);
  round_ = 1;

  NextRound(round_);
}
void Game::Play() {
  // while round >=10
  while (round_ <= 10) {
    if (round_ == 0) {
      NewGame();
    } else {
      NextRound(round_);
    };

    round_ += 1;
  }

  // TODO: count final stats
  // TODO:  show result & end the game
}
void Game::NextRound(int round_number) {
  // просчет данных введенных + исходных
  /* if (round_number >= 2) {

   } else {
     wheat.GenerateWheatPerAcre();
     wheat.GenerateDestroyedWheat(people.GetPopulation());
     people.CalculateStarvation(wheat.GetWheatQuantity());
     people.GenerateNewcommers(wheat.GetWheatPerAcre(),
                               wheat.GetWheatQuantity());
     acre.GenerateAcrePrice();
   }*/
  CalculateNextStats();
  //  а потом
  // вывод данных
  DisplayStats();
  // счтьывние ответов пользователя
  ReadPlayerInput();
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
  std::cin >> want_to_exit_;

  switch (want_to_exit_) {
    case 1:
      std::cout << "\n EXIT. ";
      // save + cout
      // exit + cout
      break;
    case 2:
      std::cout << "\n Continue. ";
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
            << "\n           In Year " << round_ << ",";
  // was
  if (people.WasPlague()) {
    std::cout << " \nA horrible plague struck! Half the population died.";
  }
  std::cout << "\n       " << people.GetStarvation()
            << " people starved, \n              And\n    Rats destroyed "
            << wheat.GetDestroyedWheat() << "  wheat.\n\n  "
            << people.GetNewcommers() << " new people moved to the city. ";
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
  int wheat_all;
  int max_buy_;
  int max_sell_;
  int max_feed_;
  int max_wheat_for_plant;

  wheat_all = wheat.GetWheatQuantity();
  max_buy_ = wheat_all / acre.GetAcrePrice();
  max_sell_ = acre.GetAcreQuantity();
  max_feed_ = 20 * people.GetPopulation();

  float tmp;
  // Enter the Info
  std::cout << "\n\nNow, please, enter ";

  while (true) {
    std::cout << "\nHow many acres you want to buy? You can buy from 0 to "
              << max_buy_ << std::endl;
    std::cin >> tmp;

    if (CheckTransaction(tmp, max_buy_) &&
        CheckTransaction(acre.GetAcrePrice() * tmp, wheat_all)) {
      acre.ArcesWantToBuy(tmp);
      wheat_all = wheat_all - (tmp * acre.GetAcrePrice());
      std::cout << "OK.Next...";
      break;
    } else {
      std::cout << "Wrong input. Please enter the correct number...\n";
      continue;
    }
  }

  while (true) {
    std::cout << "\nHow many acres you want to sell? You can sell from 0 to "
              << max_sell_ << std::endl;
    std::cin >> tmp;

    if (CheckTransaction(tmp, max_sell_)) {
      acre.ArcesWantToSell(tmp);
      wheat_all = wheat_all + (tmp * acre.GetAcrePrice());
      std::cout << "OK.Next...";
      break;
    } else {
      std::cout << "Wrong input. Please enter the correct number...\n";
      continue;
    }
  }

  while (true) {
    std::cout << "\nHow many wheat you want to use as food? Each citizen needs "
                 "20 wheat a year, so for all your people "
                 "you need "
              << max_feed_ << std::endl;
    std::cin >> tmp;

    if (CheckTransaction(tmp, max_feed_)) {
      wheat.WheatToFeed(tmp);
      max_wheat_for_plant = 2 * (wheat_all - wheat.GetFoodWheat());
      std::cout << "OK.Next...";
      break;
    } else {
      std::cout << "Wrong input. Please enter the correct number...\n";
      continue;
    }
  }

  while (true) {
    std::cout
        << "\nHow many acres do you wish to plant with seed? You can plant "
        << max_wheat_for_plant << " acres.  " << std::endl;
    std::cin >> tmp;

    if (CheckTransaction(tmp, max_wheat_for_plant) &&
        CheckTransaction(tmp, wheat_all) &&
        CheckTransaction(tmp, 10 * people.GetPopulation()) &&
        CheckTransaction(tmp, acre.GetAcreQuantity())) {
      wheat.ArcesWantToPlant(tmp / 2);
      std::cout << "OK.Next...";
      break;
    } else {
      std::cout << "Wrong input. Please enter the correct number...\n";
      continue;
    }
  }
}

bool Game::CheckTransaction(int input, int max) {
  if (input > -1 && input <= max) {
    return true;
  } else {
    return false;
  }
}

void Game::CalculateNextStats() {
  if (round_ <= 1) {
    wheat.GenerateWheatPerAcre();
    wheat.GenerateDestroyedWheat(people.GetPopulation());
    people.CalculateStarvation(wheat.GetWheatQuantity());
    people.GenerateNewcommers(wheat.GetWheatPerAcre(),
                              wheat.GetWheatQuantity());
    acre.GenerateAcrePrice();
  } else {
    // Подсчет /// Update For NExt lv
    // UpdateWheat
    int harvested;
    if ((10 * people.GetPopulation()) > acre.GetAcreQuantity()) {
      harvested = acre.GetAcreQuantity();
    } else {
      harvested = (10 * people.GetPopulation());
    }

    // GenerateWheatPErAcre tut dolzhno bit
    wheat.GenerateWheatPerAcre();
    wheat.UpdateWheatQuantity(harvested, people.GetPopulation());

    wheat.GenerateDestroyedWheat(people.GetPopulation());

    // UpdatePopulation
    people.UpdatePopulation(wheat.GetWheatPerAcre(), wheat.GetWheatQuantity());
    people.CalculateStarvation(wheat.GetWheatQuantity());
    people.GenerateNewcommers(wheat.GetWheatPerAcre(),
                              wheat.GetWheatQuantity());

    // UpdateAcreQuantity
    acre.UpdateAcreQuantity();
    acre.GenerateAcrePrice();
  }
}
