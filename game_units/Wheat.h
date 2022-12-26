#pragma once
class Wheat {
 public:
  Wheat();
  void WheatStart(int start);
  void GenerateWheatPerAcre();
  int GetWheatPerAcre();

  void GenerateDestroyedWheat(int population);
  float GetDestroyedWheat(int population);
  float GetWheatQuantity();
  void WheatToFeed(float feedWheat);

 private:
  int wheat_per_acre_;
  float all_wheat_;  // ??
  float destroyed_wheat_;
  float food_wheat_;  // from user
};
