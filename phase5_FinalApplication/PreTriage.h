/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author	Lilian Shi
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/30  Preliminary release
2020/12/03	Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Name: Lilian Shi
Email: lshi53@myseneca.ca
ID: 109261206
Date: 12/03/2020
----------------------------------------------------------- */

#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "Patient.h"
#include "Menu.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
namespace sdds {
   const int maxNoOfPatients = 100;
   class PreTriage {
      Time 
         m_averCovidWait, 
         m_averTriageWait;
      Patient* m_lineup[maxNoOfPatients]{};
      char* m_dataFilename{};
      int m_lineupSize = 0;
      Menu m_appMenu, m_pMenu;
      void reg();
      void admit();
      const Time getWaitTime(const Patient& p)const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      void load();
      int indexOfFirstInLine(char type) const;
   public:
      PreTriage(const char* dataFilename);
      ~PreTriage();
      void run(void);
   };
}
#endif // !SDDS__H_
