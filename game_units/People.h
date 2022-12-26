#pragma once
class People {
 public:
  People();
  void PeopleStart(int start);

  int GetPopulation();
  int GetStarvation(float wheat_quantity);
  int GetNewcommers(int wheat_per_acre, float wheat);
  bool WasPlague();

  void CalculateStarvation(float wheat);
  void GenerateNewcommers(int wheat_per_acre, float wheat);
  void GeneratePlague();

 private:
  int population_;
  int starvation_;
  int newcomers_;
  bool plague_;
};
