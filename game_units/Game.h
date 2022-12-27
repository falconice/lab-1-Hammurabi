#include "Acre.h"
#include "People.h"
#include "Wheat.h"
#pragma once
class Game {
 public:
  Game();
  void Start();
  void NewGame();
  void Play();
  void NextRound(int round_number);
  void DoYouWantToExit();

  void DisplayStats();
  void ReadPlayerInput();

  bool CheckTransaction(int input, int max);
  void CalculateNextStats();

 private:
  unsigned int round_;
  unsigned int want_to_exit_;
  Acre acre;
  People people;
  Wheat wheat;
};
