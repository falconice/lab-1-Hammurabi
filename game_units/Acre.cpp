#include "Acre.h"

#include <time.h>

#include <iostream>

Acre::Acre() {
  // default
  acre_quantity_ = 1000;
}

float Acre::GetAcreQuantity() {
  return this->acre_quantity_;
}

void Acre::GenerateAcrePrice() {
  srand(time(0));
  // random price from 17 to 26
  acre_price_ = (rand() % 26) + 17;
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
