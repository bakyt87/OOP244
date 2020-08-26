// Robot.h
// Robot.h

#ifndef SDDS_ROBOT_H__
#define SDDS_ROBOT_H__

#include <iostream>
#include <cstring>
#include "Parts.h"

namespace sdds {

	const int NICK_MAX_LEN = 10;

	class Robot {
		char nickname[NICK_MAX_LEN + 1];

		int durability;

		Arms arms;

		Legs legs;

	public:
		Robot();

		Robot(const char* name, int armforce, int legSpeed, int durab);

	

		std::ostream& display();

		operator bool() const;

		Arms getArms() const;

		Legs getLegs() const;

		Robot& operator-=(int);



		friend void box(Robot&, Robot&);
	};


}

#endif