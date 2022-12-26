#include "Acre.h"

#include <time.h>

#include <iostream>

Acre::Acre()
    : acre_quantity_(0),
      acre_price_(0),
      buy_acres_(0),
      sell_acres_(0),
      plant_acres_(0){};

void Acre::AcreStart(int start) {
  // default
  this->acre_quantity_ = start;
}

float Acre::GetAcreQuantity() {
  return this->acre_quantity_;
}

void Acre::GenerateAcrePrice() {
  srand(time(0));
  // random price from 17 to 26
  acre_price_ = 17 + (rand() % 9);
}

float Acre::GetAcrePrice() {
  GenerateAcrePrice();
  return this->acre_price_;
}

void Acre::ArcesWantToBuy(float buy) {
  buy_acres_ = buy;
  acre_quantity_ = +buy_acres_;
}

void Acre::ArcesWantToSell(float sell) {
  sell_acres_ = sell;
  acre_quantity_ = -sell_acres_;
}

void Acre::ArcesWantToPlant(float plant) {
  plant_acres_ = plant;
}
