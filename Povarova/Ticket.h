#pragma once
#include "Flight.h"
#include "Passenger.h"
#include <string>
#include <iomanip>

using namespace std;

class Ticket : public Passenger, public Flight
{
	string number;
	int price;
public:
	Ticket();
	~Ticket();
	void setNumber(string);
	int getPrice();
	string getNumber();
	void setPrice(int);
	template <typename T> friend void print_ticket(T&, Ticket&);
};

template <typename T>
void print_ticket(T& stream, Ticket& t)
{

	stream << "__________________________________________________________________________________________________________________" << endl;
	stream << endl;
	stream << setw(20) << "Номер заказа " + t.getNumber() << setw(50) << "Совместно с компанией " + t.getAirline() << setw(30) << "Рейс " + t.getId() << endl;
	stream << endl;
	stream << setw(12) << "Пассажир: " << setw(26) << t.getSurname() + " " + t.getName() + " " << t.getPatronymic() << setw(48) << t.getDepartureCity() + " - " << t.getArrivalCity() << endl;
	stream << setw(20) << "Паспортные данные:" << setw(11) << t.getPassport() << setw(65) << t.getArrivalAirport() + " - " << t.getDepartureAirport() << endl;
	stream << setw(18) << "Национальность: " << setw(10) << t.getNationality() << setw(68) << t.getArrivalTime() + " - " << t.getDepartureTime() << endl;
	stream << setw(17) << "Дата рождения: " << setw(15) << t.getBirthday() << endl;
	stream << setw(7) << "Пол: " << setw(21) << t.getGender() << endl;
	stream << endl;
	stream << setw(20) << "Стоимость билета " << t.getPrice() << " руб." << endl;
	stream << "__________________________________________________________________________________________________________________" << endl;
	stream << endl;
}

