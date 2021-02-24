/* ----------------------------------------------------------
Final Project Milestone 4

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
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


