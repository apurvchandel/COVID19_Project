/* ----------------------------------------------------------
Final Project Milestone 1

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{

	Time& Time::reset()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hh = m_min / 60;
		int mm = m_min % 60;
		if (hh < 10)
		{
			ostr << setfill('0') << setw(2) << hh << ":";
		}
		else
		{
			ostr << hh << ":";
		}
		if (mm < 10)
		{
			ostr << setfill('0') << setw(2) << mm;
		}
		else
		{
			ostr << mm;
		}
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hh;
		int mm;
		char col;
		istr >> hh >> col >> mm;
		if (istr.fail() || col != ':')
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			m_min = 60 * hh + mm;
		}
		return istr;
	}

	Time::operator int() const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min < D.m_min)
		{
			m_min = m_min + 24 * 60 - D.m_min;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}

	//This operator-overload overloads the binary minus operator between two Time objects.
	Time Time::operator-(const Time& ROperand)
	{
		Time LOperand = *this;
		LOperand -= ROperand;
		return LOperand;
	}

	// helper operator << and >> prototypes
	std::istream& operator>>(std::istream& is, Time& t)
	{
		t.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Time& t)
	{
		t.write(os);
		return os;
	}

}