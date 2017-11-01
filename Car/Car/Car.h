/*
Author -- Adam Engelhart

--car.h

Car Class:
m_make --> string value for car manufacturer
m_model--> string value for car model
m_year--> unsigned int value for year of creation
m_engineVolume--> unsigned int value for volume of engine
m_color[ 10 ] --> character array of size ten for color of car

Car Class methods:
default constructor --> fills car object with default values
constructor with parameters --> fills car object with user input values --> performs checks on relevant input
print --> function to print car info
isLarger --> compares the engine volume to a car passed as parameter. returns true if larger and false if not.
isOlder --> compares the year to a car passed as parameter. returns true if older and false if not.
*/

#pragma once
#include <string>

class Car 
{
private:
	std::string m_make;
	std::string m_model;
	unsigned m_year;
	unsigned m_engineVolume;
	char m_color[ 10 ];

public:
	Car();
	Car(std::string make, std::string model, unsigned year, unsigned engineVolume, std::string color);
	void print();
	bool isOlder( Car &car2 );
	bool isLarger(Car &car2 );
};