#pragma once
class People {
 public:
  People();
  void PeopleStart(int start);

  int GetPopulation();
  int GetStarvation();
  int GetNewcommers();
  bool WasPlague();

  void CalculateStarvation(float wheat);
  void GenerateNewcommers(int wheat_per_acre, float wheat);
  void GeneratePlague();

  void UpdatePopulation(int wheat_per_acre, float wheat);

 private:
  int population_;
  int starvation_;
  int newcomers_;
  bool plague_;
};
