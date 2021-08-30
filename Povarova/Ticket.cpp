#include "Ticket.h"
#include "Flight.h"
#include "Passenger.h"
#include <iostream>

Ticket::Ticket()
{
	price = 0;
}

Ticket::~Ticket()
{
}

void Ticket::setNumber(string n)
{
	number = n;
}

void Ticket::setPrice(int p)
{
	price = p;
}

int Ticket::getPrice()
{
	return price;
}

string Ticket::getNumber()
{
	return number;
}




