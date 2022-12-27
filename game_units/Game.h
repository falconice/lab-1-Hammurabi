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

  // Menu:
  //  NewGame
  //  Load from File
  //  Exit
  //
  //  OR
  //  Save
  //  Exit
  //
  //  NewGame()
  //  NextRound()
  //
  //
  //   SaveToFile()
  //

 private:
  int round;
  int want_to_exit;
  Acre acre;
  People people;
  Wheat wheat;
};
