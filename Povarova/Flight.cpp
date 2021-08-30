#include "Flight.h"
#include <iostream>

Flight::Flight()
{
	//cout << "Был вызван конструктор по умолчанию класса рейс" << endl;
}

Flight::~Flight()
{
	//cout << "Был вызван деструктор класса рейс" << endl;
}

void Flight::setId(string i)
{
	id = i;
}

void Flight::setDepartureCity(string s)
{
	departureCity = s;
}

void Flight::setArrivalCity(string s)
{
	arrivalCity = s;
}

void Flight::setDepartureAirport(string s)
{
	departureAirport = s;
}

void Flight::setArrivalAirport(string s)
{
	arrivalAirport = s;
}

void Flight::setDepartureTime(string s)
{
	departureTime = s;
}

void Flight::setArrivalTime(string s)
{
	arrivalTime = s;
}

void Flight::setAirline(string s)
{
	airline = s;
}

string Flight::getId()
{
	return id;
}

string Flight::getDepartureCity()
{
	return departureCity;
}

string Flight::getArrivalCity()
{
	return arrivalCity;
}

string Flight::getDepartureAirport()
{
	return departureAirport;
}

string Flight::getArrivalAirport()
{
	return arrivalAirport;
}

string Flight::getDepartureTime()
{
	return departureTime;
}

string Flight::getArrivalTime()
{
	return arrivalTime;
}

string Flight::getAirline()
{
	return airline;
}

