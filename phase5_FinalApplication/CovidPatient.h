/* ----------------------------------------------------------
Final Project Milestone 4

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {	
    class CovidPatient: public Patient{
	public:
		//default constructor
		CovidPatient();
		char type()const;
		//pure virtual function overwrites.
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
    };
}
#endif // !SDDS_COVIDPATIENT_H_



