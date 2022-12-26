// Hammurabi-try1.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <time.h>

#include <iostream>

#include "game_units/Game.h"

using namespace std;

int main() {
  Game MyGame;
  MyGame.NewGame();
  MyGame.DisplayStats();
}
