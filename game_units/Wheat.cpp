#include "Wheat.h"

#include <time.h>

#include <iostream>

Wheat::Wheat()
    : wheat_per_acre_(0),
      all_wheat_(0),
      destroyed_wheat_(0),
      food_wheat_(0),
      plant_acres_(0) {}

void Wheat::WheatStart(int start) {
  this->all_wheat_ = start;
}

void Wheat::GenerateWheatPerAcre() {
  srand(time(0));
  this->wheat_per_acre_ = 1 + (rand() % 6);
}

int Wheat::GetWheatPerAcre() {
  return wheat_per_acre_;
}

int Wheat::GetFoodWheat() {
  return this->food_wheat_;
}

void Wheat::GenerateDestroyedWheat(int population) {
  srand(time(0));
  float rnd = (1 + (rand() % 700)) / 10000.0f;

  this->destroyed_wheat_ = rnd * all_wheat_;
}

int Wheat::GetDestroyedWheat() {
  return this->destroyed_wheat_;
}

int Wheat::GetWheatQuantity() {
  return all_wheat_;
}

void Wheat::WheatToFeed(float feedWheat) {
  this->food_wheat_ = feedWheat;
}

void Wheat::ArcesWantToPlant(int plant) {
  this->plant_acres_ = plant;
}

void Wheat::UpdateWheatQuantity(int harvested_acres, int population) {
  all_wheat_ = all_wheat_ - food_wheat_;
  all_wheat_ = all_wheat_ - plant_acres_;

  all_wheat_ = all_wheat_ + (harvested_acres * GetWheatPerAcre());

  all_wheat_ = all_wheat_ - destroyed_wheat_;
}
