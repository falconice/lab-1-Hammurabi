#pragma once
class People {
 public:
  People();

  int GetPopulation();
  void CalculateStarvation(float wheat);
  int GenerateNewcommers(int per_acre, float wheat);
  void GeneratePlague();

 private:
  int population_;
  int starvation_;
  int newcomers_;
  bool plague_;
};
