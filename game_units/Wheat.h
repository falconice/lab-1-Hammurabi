#pragma once
class Wheat {
 public:
  Wheat();
  float GetWheatPerAcre();
  float GetDestroyedWheat();

 private:
  float wheat_per_acre_;
  float all_wheat_;  // ??
  float destroyed_wheat_;
  float food_wheat_;  // from user
};
