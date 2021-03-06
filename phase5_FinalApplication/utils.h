/* ----------------------------------------------------------
Final Project Milestone 1

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
----------------------------------------------------------- */

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    int getInt();
    int getTime(); // returns the time of day in minutes

    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                       // all the files which include: "utils.h" 
                       //(you will learn this in detail in oop345)

    //This template will be used to remove a Patient from the lineup when admitted.
    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size)
    {
        delete array[index];
        for (int j = index; j < size; j++)
        {
            array[j] = array[j + 1];
        }
        size--;
    }
}
#endif // !SDDS_UTILS_H_