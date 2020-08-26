// RobotSquad.h
#ifndef SDDS_ROBOTSQUAD_H__
#define SDDS_ROBOTSQUAD_H__

#include <iostream>
#include <cstring>
#include "Parts.h"
#include "Robot.h"


namespace sdds {
	const int MAX_NAME = 10;
	class RobotSquad {
		char m_name[MAX_NAME + 1];
		int m_count;
		Robot* Robots;
	public:
		RobotSquad();

		RobotSquad(const char* squadName);

        ~RobotSquad(); 
		
		bool isEmpty()const;

		void setEmpty();
	
        RobotSquad& operator+=(Robot roster);

		RobotSquad& operator--();

		std::ostream& display() const;

		Robot* getRoster();

	};
}

#endif