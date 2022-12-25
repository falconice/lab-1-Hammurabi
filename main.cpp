// Hammurabi-try1.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <time.h>

#include <iostream>


using namespace std;

int main() {
 
  string load = "continue";

  while (round <= 10 && load != "exit") {
  
    wheat -= destroyed_wheat;

    // Потребление бушелей??
    if (20 * population >= wheat) {
      starvation = population - ((20 * population - wheat) / 20);
      if (starvation > 0.45 * population) {
        cout << "game over. 45%+ died of starvation";
      }
    } else {
      starvation = 0;
    };


    // Prepare for next round

    round += 1;
  }
}