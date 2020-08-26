#ifndef SDDS_SUBJECT_H__
#define SDDS_SUBJECT_H__

namespace sdds {
	struct Subject {
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};

	void read(int studentsNum[], int numOfStudents);
	void read(char* m_subjectName);
	void read(int& m_noOfSections);
	void read(Subject& S);
	// print the data kept in Subject S
	int report(const Subject& S);
	// free the memory allocations pointed by Subject S
	void freeMem(Subject& Sub);

	
}
#endif 
