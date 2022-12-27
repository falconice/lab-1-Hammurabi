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

int People::GetStarvation() {
  return this->starvation_;
}
int People::GetNewcommers() {
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
  newcomers_ = (starvation_ / 2 + (5 - wheat_per_acre) * wheat / 600) + 1;

  if (newcomers_ < 0) {
    newcomers_ = 0;
  }
  if (newcomers_ > 50) {
    newcomers_ = 50;
  }
}
void People::GeneratePlague() {
  srand(time(0));
  plague_ = (15 >= (1 + (rand() % 100)));

  if (plague_) {
    population_ = population_ / 2;
  }
}
void People::UpdatePopulation(int wheat_per_acre, float wheat) {
  GeneratePlague();
  population_ = population_ - starvation_;
  population_ = population_ + newcomers_;
}
bool People::WasPlague() {
  return plague_;
};
