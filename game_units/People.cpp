#include "People.h"

#include <time.h>

#include <iostream>

People::People() {}
int People::GetPopulation() {
  return this->population_;
}
void People::CalculateStarvation(float wheat) {
  if (wheat > (20 * population_)) {
    this->starvation_ = 0;
  } else {
    this->starvation_ = -1 * (wheat - (20 * population_)) / 20;
  }
}
int People::GenerateNewcommers(int per_acre, float wheat) {
  newcomers_ = starvation_ / 2 + (5 - per_acre) * wheat / 600 + 1;
  return newcomers_;
}
void People::GeneratePlague() {
  srand(time(0));
  plague_ = (15 >= (1 + (rand() % 100)));
  // TODO:check generation
  if (plague_) {
    population_ = population_ / 2;
  }
};
