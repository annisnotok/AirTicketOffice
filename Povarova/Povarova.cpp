#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include <set>
#include <map>

using namespace std;

Passenger select_passenger(int);
Flight select_flight(int);

stack <Passenger> passengers, passengersBuff;
stack <Flight> flights, flightsBuff;
stack <Ticket> tickets, ticketsBuff;
Passenger rnd_passenger;
Flight rnd_flight;
int hour = 0, min = 0, total_profit = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string line;
    //читаем данные из файла и заносим пассажиров в стек
    ifstream inPassengers("passengers.txt"); 
    if (inPassengers.is_open())
    {
        while (getline(inPassengers, line))
        {
            char str[255];
            strcpy_s(str, line.c_str());
            char* token1 = NULL;
            char* next_token1 = NULL;
            token1 = strtok_s(str, " ", &next_token1);
            Passenger p;
            p.setSurname(token1);
            p.setName(strtok_s(NULL, " ", &next_token1));
            p.setPatronymic(strtok_s(NULL, " ", &next_token1));
            p.setBirthday(strtok_s(NULL, " ", &next_token1));
            p.setPassport(strtok_s(NULL, " ", &next_token1));
            p.setNationality(strtok_s(NULL, " ", &next_token1));
            p.setGender(strtok_s(NULL, " ", &next_token1));
            passengers.push(p);
        }
    }
    inPassengers.close();
    //читаем данные их файла и заносим рейсы в стек
    ifstream inFlights("flights.txt");
    if (inFlights.is_open())
    {
        while (getline(inFlights, line))
        {
            char str[255];
            strcpy_s(str, line.c_str());
            char* token1 = NULL;
            char* next_token1 = NULL;
            token1 = strtok_s(str, " ", &next_token1);
            Flight f;
            f.setId(token1);
            f.setDepartureCity(strtok_s(NULL, " ", &next_token1));
            f.setArrivalCity(strtok_s(NULL, " ", &next_token1));
            f.setDepartureAirport(strtok_s(NULL, " ", &next_token1));
            f.setArrivalAirport(strtok_s(NULL, " ", &next_token1));
            f.setDepartureTime(strtok_s(NULL, " ", &next_token1));
            f.setArrivalTime(strtok_s(NULL, " ", &next_token1));
            f.setAirline(strtok_s(NULL, " ", &next_token1));
            flights.push(f);
        }
    }
    inFlights.close();
    //цикл работы авиакассы
    ofstream outTickets("tickets.txt");
    int count = 0;//кол-во проданных билетов
    while (hour != 24) { 
        min += rand() % 60;
        if (hour <= 9) {
            if (min >= 60) {
                hour++; min = min - 60;
                if (hour >= 24) { break; }
            }
            if (min <= 9) {
                outTickets << "Билет куплен в 0" << hour << ":0" << min << "\n";
            }
            else {
                outTickets << "Билет куплен в 0" << hour << ":" << min << "\n";
            }
        }
        else {
            if (min >= 60) {
                hour++; min = min - 60;
                if (hour >= 24) { break; }
            }
            if (min <= 9) {
                outTickets << "Билет куплен в " << hour << ":0" << min << "\n";
            }
            else {
                outTickets << "Билет куплен в " << hour << ":" << min << "\n";
            }
        }
        rnd_passenger = select_passenger(rand());
        rnd_flight = select_flight(rand());
        Ticket ticket;
        ticket.setNumber(to_string(++count));
        ticket.setId(rnd_flight.getId());
        ticket.setDepartureCity(rnd_flight.getDepartureCity());
        ticket.setArrivalCity(rnd_flight.getArrivalCity());
        ticket.setDepartureAirport(rnd_flight.getDepartureAirport());
        ticket.setArrivalAirport(rnd_flight.getArrivalAirport());
        ticket.setDepartureTime(rnd_flight.getDepartureTime());
        ticket.setArrivalTime(rnd_flight.getArrivalTime());
        ticket.setAirline(rnd_flight.getAirline());
        ticket.setName(rnd_passenger.getName());
        ticket.setSurname(rnd_passenger.getSurname());
        ticket.setPatronymic(rnd_passenger.getPatronymic());
        ticket.setBirthday(rnd_passenger.getBirthday());
        ticket.setPassport(rnd_passenger.getPassport());
        ticket.setNationality(rnd_passenger.getNationality());
        ticket.setGender(rnd_passenger.getGender());
        ticket.setPrice(rand() % 15000 + min * 10);
        tickets.push(ticket);
        total_profit += ticket.getPrice();
        print_ticket(outTickets, ticket);
    }

    ticketsBuff = tickets;

    outTickets << "Выручка за 24 часа работы составила " << total_profit<< " (руб.)" << endl;
    outTickets << "Общее количество приобретённых билетов за 24 часа составило " << count << " (шт.)" << endl;

    //Подсчет проданных билетов по направлениям и нахождение самого популярного рейса
    int k = 0; //переменная для подсчета повторений
    string popular_flight;
    multiset <string> mst;  

    for (int i = 0; i < count; i++) {
        mst.insert(tickets.top().getId());   
        tickets.pop();
    }
    multiset<string>::iterator it = mst.begin();
    
    for (; it != mst.end(); it++)  
    {
        if (mst.count(*it) > k) {
            k = mst.count(*it);
            popular_flight = *it;
        }
    }
    outTickets << "Самый популярный рейс: " << popular_flight << " (Количество повторений - " << k << ")" << endl;

    tickets = ticketsBuff;
    outTickets << "\nКоличество проданных билетов по направлениям: " << endl;
    map<string, int> mp; 
    string massiv[255];
    for (int i = 0; i < count; i++) {
        massiv[i] = tickets.top().getId();  
        tickets.pop();
    }
    for (int j = 0; j < count; j++)
        mp[massiv[j]]++;

    map<string, int>::iterator b, e; 
    b = mp.begin(); e = mp.end();
    for (; b != e; ++b) {
        outTickets << "По направлению " << b->first << " было продано " << b->second << " билетов" << endl; 
    }
    tickets = ticketsBuff;
    //Вывод билета для клиента
    string ticketNumber, passengerSurname;
ticket_print:
    cout << "Для печати билета введите номер рейса(XXXXXX): " << endl;
    cin >> ticketNumber;
    cout << "Также введите фамилию, на которую оформлен билет: " << endl;
    cin >> passengerSurname;
    Ticket t;
    while (!tickets.empty()) {
        if ((tickets.top().getId() == ticketNumber) && (tickets.top().getSurname() == passengerSurname)) {
            t = tickets.top(); break;
        }
        else tickets.pop();
    }
    tickets = ticketsBuff;
    if (!t.getId().empty()) {
        print_ticket(cout, t);
    }
    else {
        cout << "Билет не найден. Возможно, Вы ввели неверные данные. Попробуйте еще раз." << endl;
        goto ticket_print;
    }

}

Passenger select_passenger(int r)
{
    Passenger p;
    int rnd = r % 30;
    passengersBuff = passengers;
    for (int i = 0; i < 30; i++) {
        if (i != rnd) {
            passengers.pop();
        }
        else if (i == rnd) {
            p = passengers.top();
        }
        if (passengers.empty()) {           //если стэк закончился то заполняем его теми же значениями 
            passengers = passengersBuff;
        }
    };
    passengers = passengersBuff;
    return p;
}

Flight select_flight(int r)
{
    Flight f;
    int rnd = r % 8;
        flightsBuff = flights;
    for (int i = 0; i < 8; i++) {
        if (i != rnd) {
            flights.pop();
        }
        else if (i == rnd) {
            f = flights.top();
        }
        if (flights.empty()) {           //если стэк закончился то заполняем его теми же значениями 
            flights = flightsBuff;
        }
    }
    flights = flightsBuff;
    return f;
}
