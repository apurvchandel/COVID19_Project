/* ----------------------------------------------------------
Final Project Milestone 3

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
#define MAXLEN 50
using namespace std;
namespace sdds
{
	//constructor
	Patient::Patient(int ticketNum, bool IOflag)
	{
		p_ticket = new Ticket(ticketNum);
		p_IOflag = IOflag;
		p_name = nullptr;
		p_OHIP = 0;
	}
	//destructor, deallocate dynamic memory
	Patient::~Patient()
	{
		delete[] p_name;
		p_name = nullptr;
		delete p_ticket;
		p_ticket = nullptr;
	}
	//returns the member file IO flag
	bool Patient::fileIO() const
	{
		return p_IOflag;
	}
	//modifier that receives a Boolean value to set the member fileIO flag
	void Patient::fileIO(bool IOflag)
	{
		p_IOflag = IOflag;
	}
	//compare the current object with an incoming single character and return true 
	//if the single character is the same as the return value of the pure virtual type member function
	bool Patient::operator==(const char t) const
	{
		return this->type() == t;
	}
	//compare the current object to another patient and return true 
	//if the type of the current patient is the same as the type of the other patient
	bool Patient::operator==(const Patient& p) const
	{
		return this->type() == p.type();
	}
	//Sets the time of the ticket of the patient to the current time
	void Patient::setArrivalTime()
	{
		p_ticket->resetTime();
	}
	//If the patient is casted to the Time type it should return the time of the ticket
	Patient::operator Time() const
	{
		return p_ticket->operator sdds::Time();
	}
	//returns the number of the ticket
	int Patient::number() const
	{
		return p_ticket->number();
	}
	//Inserts values into the ostream in a comma-separated format
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << this->type() << "," << p_name << "," << p_OHIP << ",";
		p_ticket->csvWrite(ostr);
		return ostr;
	}
	//extracts all the values in the same order as the csvWrite function, except for the type
	std::istream& Patient::csvRead(std::istream& istr)
	{
		char name[MAXLEN + 1] = { '\0' };
		int OHIP = 0;
		//always dealloacate the dynamic memory before assign any value
		delete[] p_name;
		p_name = nullptr;
		istr.getline(name, MAXLEN + 1, ',');
		//if the name read from csvFile is longer than maximum length
		//make sure clear the buffer, and manually assign the null terminator for p_name
		if (strlen(name) == MAXLEN)
		{
			p_name = new char[MAXLEN + 1];
			strncpy(p_name, name, MAXLEN + 1);
			p_name[MAXLEN] = '\0';
			istr.clear();
			istr.ignore(200, ',');
		}
		else
		{
			p_name = new char[strlen(name) + 1];
			strncpy(p_name, name, strlen(name) + 1);
		}
		istr >> OHIP;
		if (OHIP >= 100000000 && OHIP <= 999999999)
		{
			p_OHIP = OHIP;
		}
		istr.clear();
		istr.ignore(200, ',');
		p_ticket->csvRead(istr);
		return istr;
	}
	//Inserts the patient information into the ostream to be displayed on the console
	std::ostream& Patient::write(std::ostream& ostr) const
	{
		return p_ticket->write(ostr) << endl << p_name << ", OHIP: " << p_OHIP;
	}
	//Extracts the ticket information from the console using istream
	std::istream& Patient::read(std::istream& istr)
	{
		char name[MAXLEN + 1] = { '\0' };
		int OHIP = 0;
		//always dealloacate the dynamic memory before assign any value
		delete[] p_name;
		//make sure only read maxmium length of chars, clear the buffer
		cout << "Name: ";
		istr.get(name, MAXLEN + 1, '\n');
		istr.clear();
		istr.ignore(2000, '\n');
		p_name = new char[strlen(name) + 1];
		strcpy(p_name, name);
		cout << "OHIP: ";
		OHIP = getInt();
		while (OHIP < 100000000 || OHIP > 999999999)
		{
			cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
			OHIP = getInt();
		}
		p_OHIP = OHIP;
		return istr;
	}
}