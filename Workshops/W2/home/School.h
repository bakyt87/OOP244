#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__

namespace sdds {

	struct School {
		int m_noOfSubjects;//int veriable to hold the num of subs
		struct Subject* m_subjects; // to store subs offered by school
		char* m_name;//holds the name of the school

	};
	void read(School& Sch);
	int report(const School& Sch);
	void freeMem(School& Sch);
}
#endif