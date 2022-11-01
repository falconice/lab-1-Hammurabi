// Hammurabi-try1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>



using namespace std;

int main()
{
	int round = 0;

	int population = 100;
	float wheat = 2800.0;
	float acre = 1000.0;

	int starvation = 0;
	int moved = 0;

	bool plague = false;

	float destroyedWheat = 0.0;
	float acrePrice = 0.0;

	float	buyAcres = 0.0, sellAcres = 0.0, foodWheat = 0.0, plantAcres = 0.0;

	srand(time(0));

	int wheatPerAcre = 0;

	while (round <= 10) {
		wheatPerAcre = (rand() % 6) + 1;
		destroyedWheat = ((rand() % 7)/100.0f)*wheat;
		wheat -= destroyedWheat;
	
		
		//Потребление бушелей
		if (20 * population >= wheat) {
			starvation = population-((20*population-wheat)/20); 
			if (starvation > 0.45 * population) {
				cout << "game over. 45%+ died of starvation";
			}
		}
		else {
			starvation = 0;
		};

		cout << "\n\n\nINFORMATION OF ROUND №";
		cout << round
			<< "\n Died from starvation " << starvation
			<< "\n Moved to the city " << moved
			<< "\n Plague " << plague
			<< "\n Population " << population
			<< "\n All wheat " << wheat
			<< "\n Wheat per acre " << wheatPerAcre
			<< "\n Wheat destroyed by rats " << destroyedWheat
			<< "\n Acres " << acre
			<< "\n Price of 1 acre " << acrePrice;

		cout << "\n\nEnter the numbers";
		cout << "\nHow many acres you want to buy?";
		cin >> buyAcres;
		cout << "\nHow many acres you want to sell?";
		cin >> sellAcres;
		cout << "\nHow many wheat you want to use as food?";
		cin >> foodWheat;
		cout << "\nHow many acres you want to use for planting the wheat?";
		cin >> plantAcres;

		//Prepare for next round





		round += 1;
	}


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
