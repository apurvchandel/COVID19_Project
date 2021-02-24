/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Author	Lilian Shi
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
Date: 11/11/2020
----------------------------------------------------------- */

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds
{
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
    };
    // helper operator << and >> prototypes
    std::istream& operator>>(std::istream&, Time&);
    std::ostream& operator<<(std::ostream&, const Time&);
}

#endif // !SDDS_TIME_H

