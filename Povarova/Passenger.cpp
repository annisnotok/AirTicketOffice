#include "Passenger.h"
#include <iostream>

Passenger::Passenger()
{
	//cout << "Был вызван конструктор по умолчанию класса пассажир" << endl;
}

Passenger::~Passenger()
{
	//cout << "Был вызван деструктор класса пассажир" << endl;
}

void Passenger::setName(string n)
{
	name = n;
}

void Passenger::setSurname(string s)
{
	surname = s;
}

void Passenger::setPatronymic(string p)
{
	patronymic = p;
}

void Passenger::setBirthday(string b)
{
	birthday = b;
}

void Passenger::setPassport(string p)
{
	passport = p;
}

void Passenger::setNationality(string n)
{
	nationality = n;
}

void Passenger::setGender(string g)
{
	gender = g;
}

string Passenger::getName()
{
	return name;
}

string Passenger::getSurname()
{
	return surname;
}

string Passenger::getPatronymic()
{
	return patronymic;
}

string Passenger::getBirthday()
{
	return birthday;
}

string Passenger::getPassport()
{
	return passport;
}

string Passenger::getNationality()
{
	return nationality;
}

string Passenger::getGender()
{
	return gender;
}

