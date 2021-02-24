/* ----------------------------------------------------------
Final Project Milestone 1

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "utils.h"
#include "Time.h"
#include "Menu.h"
using namespace std;
namespace sdds {
	Menu::Menu(const char* text, int NoOfSelections)
	{
		m_text = new char[strlen(text) + 1];
		strcpy(m_text, text);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		ostr << m_text << endl;
		ostr << "0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display(cout);
		Selection = getInt();
		while (Selection < 0 || Selection > m_noOfSel)
		{
			cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
			Selection = getInt();
		} 
		return Selection;
	}

}