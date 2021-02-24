/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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

#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
  
   CovidPatient::CovidPatient(): Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const
   {
	   return 'C';
   }

   std::ostream& CovidPatient::csvWrite(std::ostream& ostr) const
   {
	   return Patient::csvWrite(ostr);
   }

   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
	   if (Patient::fileIO())
	   {
		   csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr) << endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr)
   {
	   if (Patient::fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }
	   return istr;
   }

}