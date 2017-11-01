/*
Author -- Adam Engelhart

--car.cpp

Car Class functions:
default constructor --> fills car object with default values
constructor with parameters --> fills car object with user input values --> performs checks on relevant input
print --> function to print car info
isLarger --> compares the engine volume to a car passed as parameter. returns true if larger and false if not.
isOlder --> compares the year to a car passed as parameter. returns true if older and false if not.
*/

#include <iostream>
#include <string>
#include "Car.h"


Car::Car(): m_make("Ford"), m_model("Focus"), m_year(2017), m_engineVolume(1600), m_color("White\0")
{}

Car::Car(const std::string make, const std::string model, unsigned year, unsigned engineVolume, std::string color)
{
	unsigned index = 0;

	const int minEngineVolume = 1400;
	const int maxEngineVolume = 3000;
	const int maxColorLength = 9;
	const int minColorLength = 3;
	const int maxYear =  2017;
	const int minYear =  1980;

	if (year > maxYear || year < minYear)
	{
		std::cout << "Year must be in the range " << minYear << "-" << maxYear << ". (Default set - "<<maxYear<<")"<<std::endl;
		year = maxYear;
	}
	if (engineVolume < minEngineVolume || engineVolume > maxEngineVolume)
	{
		std::cout << "Engine volume must be in the range " << minEngineVolume << "-" << maxEngineVolume << ". (Default set - " << minEngineVolume << ")" << std::endl;
		engineVolume = minEngineVolume;
	}
	if (color.length() > maxColorLength || color.length() < minColorLength)
	{
		std::cout << "Length of color string must be between " << minColorLength << "-" << maxColorLength << ". (Default set - White)" << std::endl;
		color = "White";
	}
	m_make = make;
	m_model = model;
	m_year = year;
	m_engineVolume = engineVolume;
	for (index = 0; index < color.length(); index++)
	{
       m_color[index] = color[index];
	}
	m_color[ index ] = '\0';
}

void Car::print() const
{
	std::cout << "Make: " << m_make << "\nModel: " << m_model << "\nYear: "<<m_year<<"\nEngine Volume: " << m_engineVolume << "\nColor: " << m_color << std::endl<<std::endl;
}

bool Car::isOlder( const Car &car2 ) const
{
	return car2.m_year < m_year;
}
bool Car::isLarger( const Car &car2 ) const
{
	return car2.m_engineVolume < m_engineVolume;
}

const Car& Car::getOlder(const Car &car1, const Car &car2) const
{
	return car1.isOlder(car2) ? car1 : car2;
}

const Car& Car::getLarger(const Car &car1, const Car &car2) const
{
	return car1.isLarger(car2) ? car1 : car2;
}