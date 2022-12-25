#pragma once
class Game {
 public:
  Game();
  void NewGame();
  void GameStart();
  void PrepareForNewRound();
  void RandomGenerate();
  void PlayRound();
  void DisplayInfo();
  void CheckExit();
  void ReadPlayerData();
  void GameCicle();

  // SaveToFile()

 private:
  int round;  // game

  int population;    // people
  int newcomers;     // people
  float starvation;  // people
  bool plague;       // people

  int wheat_per_acre;     // wheat
  float wheat;            // wheat
  float destroyed_wheat;  // wheat
  float food_wheat;       // wheat

  float acre;
  float acre_price;
  float buy_acres;
  float sell_acres;
  float plant_acres;
};
