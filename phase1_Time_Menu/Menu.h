/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   class Menu{
      char* m_text;
      int m_noOfSel;
   public:
      Menu(const char* text, int NoOfSelections);
      virtual ~Menu();
      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;
      std::ostream& display(std::ostream& ostr = std::cout)const;
      int& operator>>(int& Selection);
   };
}
#endif // !SDDS_MENU_H_
