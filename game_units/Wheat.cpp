#include "Wheat.h"

#include <time.h>

#include <iostream>

Wheat::Wheat()
    : wheat_per_acre_(0), all_wheat_(0), destroyed_wheat_(0), food_wheat_(0) {}

void Wheat::WheatStart(int start) {
  this->all_wheat_ = start;
}

void Wheat::GenerateWheatPerAcre() {
  this->wheat_per_acre_ = 1 + (rand() % 6);
}

int Wheat::GetWheatPerAcre() {
  GenerateWheatPerAcre();
  return wheat_per_acre_;
}

void Wheat::GenerateDestroyedWheat(int population) {
  float rnd = (0 + (rand() % 700)) / 10000;
  float all_wheat_after_harvest = all_wheat_ + wheat_per_acre_ * population;
  this->destroyed_wheat_ = rnd * all_wheat_after_harvest;
}

float Wheat::GetDestroyedWheat(int population) {
  GenerateDestroyedWheat(population);
  return destroyed_wheat_;
}

float Wheat::GetWheatQuantity() {
  return all_wheat_;
}

void Wheat::WheatToFeed(float feedWheat) {
  this->all_wheat_ = feedWheat;
}
