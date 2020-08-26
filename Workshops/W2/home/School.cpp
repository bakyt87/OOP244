
#include <iostream>
#include <cstring>
#include "utils.h"
#include "School.h"
#include "Subject.h"

using namespace std;
namespace sdds
{

	void read(School& Sch) 
	{

	char Arr[61];//local array for name of school
		cout << "Please enter the name of the school:\n> ";
		const char errorMessage[]= "Name is too long, only 60 characters allowed!\nRedo Entry : ";
	read(Arr, 61, errorMessage);// reading the name
		Sch.m_name = new char[strlen(Arr) + 1]; // dynamically allocating memory 
        strcpy(Sch.m_name, Arr);//copying name to member
		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		const char ErrorMess[] = "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ";
	read(Sch.m_noOfSubjects, 2, 50, ErrorMess); //reading the input
		Sch.m_subjects = new Subject[Sch.m_noOfSubjects]; // dynamically allocating the subjects array 
		for (int i = 0; i < Sch.m_noOfSubjects; i++)  // loop untill the number of subjects
		{
			cout << i + 1 << ") ------------------------------\n";
			read(Sch.m_subjects[i]); //reading each subject
		}
    }
	int report(const School& Sch) 
	{
		int num = 0;
		cout << Sch.m_name << endl; // name of school
		cout << "Subject Enrollments" << endl;
		for (int i = 0;i < Sch.m_noOfSubjects;i++) //loop through the subjects
		    { 
			num+=report(Sch.m_subjects[i]); //add return value 1 by 1 to a total
			}
		cout << "Total enrollment: " << num << endl;
		return num;
	}
	void freeMem(School& Sch) 
	{
		delete[] Sch.m_name; //deallocating the name of school
                Sch.m_name = nullptr;
		for(int i = 0; i < Sch.m_noOfSubjects; i++) //looping through the subject
		{
			freeMem(Sch.m_subjects[i]);
		}
		delete[] Sch.m_subjects;
                Sch.m_subjects = nullptr;
	}

		

}

