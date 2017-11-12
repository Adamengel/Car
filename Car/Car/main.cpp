/*
Author: Adam Engelhart

*/

#include <iostream>

#include "Car.h"

using namespace std;
using namespace myCar;

int main()
{
	string make;
	string model;
	unsigned year;
	unsigned engineVolume;
	string color;

	cout << "Enter Car Info\nMake: ";
	cin >> make;
	cout << "Model: ";
	cin >> model;
	cout << "Year: ";
	cin >> year;
	while (std::cin.fail()) {
		std::cout << "Error! Year must be positive number" << std::endl;
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cin >> year;
	}
	cout << "Engine Volume: ";
	cin >> engineVolume;
	while (std::cin.fail()) {
		std::cout << "Error! Engine Volume must be positive number" << std::endl;
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cin >> engineVolume;
	}
	cout << "Color: ";
	cin >> color;

	Car myCar(make, model, year, engineVolume, color);
	Car myCar2;
	Car myCar3(myCar2);

	myCar.getLarger(myCar, myCar2).print();
	myCar.getOlder(myCar, myCar2).print();

	system("pause");
	return 0;
}