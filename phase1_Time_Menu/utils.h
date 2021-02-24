/* Citation and Sources...
Final Project Milestone 1
Module: util
Filename: util.h
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


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   int getInt();
   int getTime(); // returns the time of day in minutes

   extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                      // all the files which include: "utils.h" 
                      //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_

