
#include <iostream>
#include <cstring>
#include <iomanip>
#include "utils.h"
#include "Subject.h"

using namespace std;
namespace sdds 
{


	// reads an integer from console the integer referenced by "val"
	// argument.
	// if the user enters an invalid integer or values outside of the 
	// boundries set by "min" or "max" , this function flushes the 
	//keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable integer

	// reads a C style string from console up to "len" characters into the
	// the string pointed by the "str" pointer
	// if the user enters more than "len" characters, this function
	// flushes the keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable string

    void read(char* m_subjectName) 
	{//1st read overload function(receives pointer char.)
	
		cout << "Enter subject name: ";
		const char errorMessage[] = "Name is too long, only 70 characters allowed!\nRedo Entry: ";
		read(m_subjectName, 71, errorMessage);//call the function in utils
	} 

	void read(int& m_noOfSections) 
	{
		cout << "Enter number of sections: ";
		const char ErrorMess[] = "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ";
		read(m_noOfSections,1, 10, ErrorMess);
	}
	void read(int Section[], int m_noOfSections) 
	{
		cout << "Enter the number of students in each one of the " << m_noOfSections << " sections:"<<endl;
		const char ErrorMess[] = "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ";
		for(int i = 0; i <m_noOfSections; i++) 
		{
		cout << i + 1 << ": ";
		read(Section[i], 5, 35, ErrorMess);
		}
	}
	void read(Subject& Sub)
	{
		char arr[71];
		read(arr);
		Sub.m_subjectName = new char[71];
		
		strcpy(Sub.m_subjectName, arr);

		Sub.m_noOfSections = new int[1];
		read(*Sub.m_noOfSections);
	
		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);

	}
	int report(const Subject& S) 
	{
		int sum=0;
		for (int i = 0; i < *S.m_noOfSections; i++) 
		{
			cout << S.m_noOfStdsInSecs[i];
			sum += S.m_noOfStdsInSecs[i];
			if (i < *S.m_noOfSections - 1) 
				cout << ",";
		}
			cout << endl << S.m_subjectName << ": " << sum<<endl;
			return sum;
		
	}
	void freeMem(Subject & S) {
		delete[] S.m_noOfSections;
		delete[] S.m_noOfStdsInSecs;
		delete[] S.m_subjectName;
	}
}