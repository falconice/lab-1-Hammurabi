#include "People.h"

#include <time.h>

#include <iostream>

People::People() : population_(0), starvation_(0), newcomers_(0), plague_(0){};

void People::PeopleStart(int start) {
  this->population_ = start;
}
int People::GetPopulation() {
  return this->population_;
}

int People::GetStarvation(float wheat_quantity) {
  CalculateStarvation(wheat_quantity);
  return this->starvation_;
}
int People::GetNewcommers(int wheat_per_acre, float wheat) {
  GenerateNewcommers(wheat_per_acre, wheat);
  return newcomers_;
}
void People::CalculateStarvation(float wheat) {
  if (wheat > (20 * population_)) {
    this->starvation_ = 0;
  } else {
    this->starvation_ = -1 * (wheat - (20 * population_)) / 20;
  }
}
void People::GenerateNewcommers(int wheat_per_acre, float wheat) {
  newcomers_ = starvation_ / 2 + (5 - wheat_per_acre) * wheat / 600 + 1;
}
void People::GeneratePlague() {
  srand(time(0));
  plague_ = (15 >= (1 + (rand() % 100)));
  // TODO:check generation
  if (plague_) {
    population_ = population_ / 2;
  }
}
bool People::WasPlague() {
  GeneratePlague();
  return plague_;
};
