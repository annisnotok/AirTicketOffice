#pragma once
#include <string>

using namespace std;

class Flight
{
	string
		id,
		departureCity,
		arrivalCity,
		departureAirport,
		arrivalAirport,
		departureTime,
		arrivalTime,
		airline;
public:
	Flight();
	~Flight();
	void setId(string);
	void setDepartureCity(string);
	void setArrivalCity(string);
	void setDepartureAirport(string);
	void setArrivalAirport(string);
	void setDepartureTime(string);
	void setArrivalTime(string);
	void setAirline(string);
	string getId();
	string getDepartureCity();
	string getArrivalCity();
	string getDepartureAirport();
	string getArrivalAirport();
	string getDepartureTime();
	string getArrivalTime();
	string getAirline();
};



