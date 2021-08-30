#pragma once
#include <string>

using namespace std;

class Passenger
{
	string 
		name, 
		surname, 
		patronymic,
		birthday,
		passport,
		nationality,
		gender;
public:
	Passenger();
	~Passenger();
	void setName(string);
	void setSurname(string);
	void setPatronymic(string);
	void setBirthday(string);
	void setPassport(string);
	void setNationality(string);
	void setGender(string);
	string getName();
	string getSurname();
	string getPatronymic();
	string getBirthday();
	string getPassport();
	string getNationality();
	string getGender();
};





