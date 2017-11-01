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
#include <assert.h>
#include "Car.h"


#define MIN_ENGINE_VOLUME 1400
#define MAX_ENGINE_VOLUME 3000
#define MAX_COLOR_LENGTH 9
#define MIN_COLOR_LENGTH 3
#define MAX_YEAR 2017
#define MIN_YEAR 1980

Car::Car(): m_make("Ford"), m_model("Focus"), m_year(2017), m_engineVolume(1600), m_color("White\0")
{}

Car::Car(std::string make, std::string model, unsigned year, unsigned engineVolume, std::string color)
{
	unsigned index = 0;
	bool error_flag = false;

	if (year > MAX_YEAR || year < MIN_YEAR)
	{
		std::cout << "Year must be in the range " << MIN_YEAR << "-" << MAX_YEAR << ". (Default set - "<<MAX_YEAR<<")"<<std::endl;
		year = MAX_YEAR;
	}
	if (engineVolume < MIN_ENGINE_VOLUME || engineVolume > MAX_ENGINE_VOLUME)
	{
		std::cout << "Engine volume must be in the range " << MIN_ENGINE_VOLUME << "-" << MAX_ENGINE_VOLUME << ". (Default set - " << MIN_ENGINE_VOLUME << ")" << std::endl;
		engineVolume = MIN_ENGINE_VOLUME;
	}
	if (color.length() > MAX_COLOR_LENGTH || color.length() < MIN_COLOR_LENGTH)
	{
		std::cout << "Length of color string must be between " << MIN_COLOR_LENGTH << "-" << MAX_COLOR_LENGTH << ". (Default set - White)" << std::endl;
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

void Car::print()
{
	std::cout << "Make: " << m_make << "\nModel: " << m_model << "\nYear: "<<m_year<<"\nEngine Volume: " << m_engineVolume << "\nColor: " << m_color << std::endl<<std::endl;
}

bool Car::isOlder( Car &car2 )
{
	return car2.m_year < m_year;
}
bool Car::isLarger( Car &car2 )
{
	return car2.m_engineVolume < m_engineVolume;
}