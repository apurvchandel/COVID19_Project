/* ----------------------------------------------------------
Final Project Milestone 3

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds
{
	class Patient :public IOAble {
		char* p_name;
		int p_OHIP;
		Ticket* p_ticket;
		bool p_IOflag;
	public:
		//constructor, if int and bool is not provided, default 0 and false will be passed
		Patient(int ticketNum = 0, bool IOflag = false);
		//copy constructor and assignment are not allowed
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		//destructor
		~Patient();
		//member functions
		virtual char type()const = 0;		//Pure Virtual Function type()
		bool fileIO()const;
		void fileIO(bool IOflag);
		bool operator==(const char t)const;
		bool operator==(const Patient&)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		//pure virtual function overwrites.
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PATIENT_H_
