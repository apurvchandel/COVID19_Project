/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "utils.h"
#include "PreTriage.h"

using namespace std;
namespace sdds {
	//Registers a new patient in certain formatting
	void PreTriage::reg()
	{
		int selection = -99;
		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			do
			{
				m_pMenu.display();
				cin >> selection;
				switch (selection)
				{
				default:
					break;
				case 1: m_lineup[m_lineupSize] = new CovidPatient();
					break;
				case 2: m_lineup[m_lineupSize] = new TriagePatient();
					break;
				case 0: 
					break;
				}
			} while (selection < 0 || selection > 2);
			if (selection == 1 || selection == 2)
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}

	//Calls the next patient in line to be admitted to the COVID test centre or Triage centre
	void PreTriage::admit()
	{
		char type;
		int selection = -99;
		do
		{
			m_pMenu.display();
			cin >> selection;
			switch (selection)
			{
			case 1: type = 'C';
				break;
			case 2: type = 'T';
				break;
			case 0: 
				break;
			default: break;
			}
		} while (selection < 0 || selection > 2);
		if (selection == 1 || selection == 2)
		{
			int index = indexOfFirstInLine(type);
			if (index != -1)
			{
				cout << endl;
				cout << "******************************************" << endl;
				cout << "Calling for " << *m_lineup[index];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);	
				removePatientFromLineup(index);
			}
		}
	}

	//Receives a constant Patient Reference and returns the total estimated wait time for that type of Patient (COVID or Triage)
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int waitCount = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->operator==(p)) waitCount++;
		}
		return Time(waitCount);
	}

	//Receives the reference of the admitting patient and adjusts the average wait time of that type of patient base on the admittance time of the patient.
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'T')
		{
			m_averTriageWait = ((getTime() - p.operator sdds::Time()) + (m_averTriageWait * (p.number() - 1))) / p.number();
		}
		else if (p.type() == 'C')
		{
			m_averCovidWait = ((getTime() - p.operator sdds::Time()) + (m_averCovidWait * (p.number() - 1))) / p.number();
		}
	}

	//Using the removeDynamicElement template in utils.h removes a Patient form the line up at a specific index and also removes it from memory.
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	//Loads the average wait times and the patient records from the data file and stores them in the m_lineup array.
	void PreTriage::load()
	{
		ifstream fileIn;
		fileIn.open(m_dataFilename);
		cout << "Loading data..." << endl;
		Patient* patientPtr = nullptr;
			fileIn >> m_averCovidWait;
			fileIn.ignore(100,',');
			fileIn >> m_averTriageWait;
			fileIn.ignore(100,'\n');
			for (int i = 0; i < maxNoOfPatients && !fileIn.eof(); i++)
			{
				patientPtr = nullptr;
				char type = '\0';
				type = fileIn.get();
				fileIn.ignore(100,',');
				if (type == 'C')
				{
					patientPtr = new CovidPatient();
				}
				else if (type == 'T')
				{
					patientPtr = new TriagePatient();
				}
				if (patientPtr != nullptr)
				{
					patientPtr->fileIO(true);
					patientPtr->csvRead(fileIn);
					patientPtr->fileIO(false);
					m_lineup[i] = patientPtr;
					m_lineupSize++;
				}
				fileIn.ignore(200,'\n');
			}
			if (fileIn && !fileIn.eof())
			{
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}
			if (m_lineupSize == 0)
			{
				cout << "No data or bad data file!" << endl <<endl;
			}
			else
			{
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
	}

	//Finds the index of the first patient in line which matches the type argument
	int PreTriage::indexOfFirstInLine(char type) const
	{
		bool done = false;
		int index = -1;
		for (int i = 0; i < m_lineupSize && !done; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				index = i;
				done = true;
			}
		}
		return index;
	}

	//Constructor: PreTriage is constructed using a Cstring for a file name that will be used as the data file for the module. This name will be kept dynamically in the m_dataFilename member variable.
	PreTriage::PreTriage(const char* dataFilename) :
		m_averCovidWait(15),
		m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_dataFilename = nullptr;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	//Destructor: overwriting the content of the file if it already exists, display in the screen also save it to file
	PreTriage::~PreTriage()
	{
		ofstream fileOut(m_dataFilename);
		fileOut << m_averCovidWait << "," << m_averTriageWait << endl;
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: ";
		m_averCovidWait.write(cout) << endl;
		cout << "   Triage: ";
		m_averTriageWait.write(cout) << endl;
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			m_lineup[i]->csvWrite(fileOut) << endl;
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout) << endl;
		}
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;
	}

	//display m_appMenu and get the selection for registration or admitting or exit 
	void PreTriage::run(void)
	{
		int selection = -99;
		do
		{
			m_appMenu.display();
			cin >> selection;
			switch (selection)
			{
			case 1: reg();
				break;
			case 2: admit();
				break;
			case 0: 
				break;
			default: break;
			}
		} while (selection != 0);
	}
}
