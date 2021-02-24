/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.1
Author	Lilian Shi
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/23  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
Date: 11/23/2020
----------------------------------------------------------- */

#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
   class TriagePatient: public Patient{
	   char* symptoms;
   public:
	   //default constructor
	   TriagePatient();
	   char type()const;
	   //destructor
	   ~TriagePatient();
	   //pure virtual function overwrites.
	   std::ostream& csvWrite(std::ostream& ostr)const;
	   std::istream& csvRead(std::istream& istr);
	   std::ostream& write(std::ostream& ostr)const;
	   std::istream& read(std::istream& istr);
   };

}
#endif // !SDDS_


