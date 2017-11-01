/*
Author: Adam Engelhart

*/

#include <iostream>

#include "Car.h"

using namespace std;

Car getOlder(Car &car1, Car &car2)
{
	return car1.isOlder(car2) ? car1 : car2;
}

Car getLarger(Car &car1, Car &car2)
{
	return car1.isLarger(car2) ? car1 : car2;
}

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

	getLarger(myCar, myCar2).print();
	getOlder(myCar, myCar2).print();

	system("pause");
	return 0;
}