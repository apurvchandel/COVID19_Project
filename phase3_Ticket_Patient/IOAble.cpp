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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
	IOAble::~IOAble()
	{

	}

	std::istream& operator>>(std::istream& is, IOAble& ioa)
	{
		ioa.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const IOAble& ioa)
	{
		ioa.write(os);
		return os;
	}
}