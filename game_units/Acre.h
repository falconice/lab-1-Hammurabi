#pragma once
class Acre {
 public:
  Acre();
  float GetAcreQuantity();
  void GenerateAcrePrice();
  void ArcesWantToBuy(float buy);
  void ArcesWantToSell(float sell);
  void ArcesWantToPlant(float plant);

 private:
  float acre_quantity_;
  float acre_price_;
  float buy_acres_;
  float sell_acres_;
  float plant_acres_;
};
