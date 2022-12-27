#pragma once
class Acre {
 public:
  Acre();
  void AcreStart(int start);
  void GenerateAcrePrice();

  float GetAcreQuantity();
  float GetAcrePrice();

  void ArcesWantToBuy(float buy);
  void ArcesWantToSell(float sell);

  void UpdateAcreQuantity();

 private:
  float acre_quantity_;
  float acre_price_;
  float buy_acres_;
  float sell_acres_;
};
