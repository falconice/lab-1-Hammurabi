#pragma once
class Wheat {
 public:
  Wheat();
  void WheatStart(int start);
  void GenerateWheatPerAcre();
  int GetWheatPerAcre();
  int GetFoodWheat();

  void GenerateDestroyedWheat(int population);
  int GetDestroyedWheat();
  int GetWheatQuantity();
  void WheatToFeed(float feedWheat);

  void ArcesWantToPlant(int plant);
  void UpdateWheatQuantity(int harvested_acres, int population);

 private:
  int wheat_per_acre_;
  int all_wheat_;
  int destroyed_wheat_;
  int food_wheat_;
  int plant_acres_;
};
