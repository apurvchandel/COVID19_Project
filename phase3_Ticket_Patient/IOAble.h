/* Citation and Sources...
Final Project Milestone 2
Module: IOAble.h
Filename: IOAble.h
Version 0.9
Author	Lilian Shi
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/14  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
Date: 11/15/2020
----------------------------------------------------------- */

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds
{
	class IOAble {
	public:
		// pure virtual functions
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() = 0;
	};
	// helper operator << and >> prototypes
	std::istream& operator>>(std::istream&, IOAble&);
	std::ostream& operator<<(std::ostream&, const IOAble&);
}
#endif // !SDDS_IOABLE_H_
