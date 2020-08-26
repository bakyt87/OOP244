// Robot.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Robot.h"
#include "Parts.h"

using namespace std;
namespace sdds {

	Robot::Robot() {
		nickname[0]='0';
		durability = 0;
                arms = Arms();
    }
	Robot::Robot(const char* name, int armforce, int durab) {
		if (name == nullptr) {
			nickname[0] = '0';
		}
		else {
			
			strncpy(nickname,name,NICK_MAX_LEN);
			nickname[NICK_MAX_LEN + 1] = '\0';

		}

		if (strlen(name) > NICK_MAX_LEN) {
			name = new char[strlen(name) + 1];
		}
		if (durab < 1) {
			durability = 100;

		}
		else {
			durability=durab;
		}
		arms = Arms(armforce);
            
	}
	Robot::~Robot() {
		//delete []nickname;
		
//nickname == nullptr;
	}

	ostream& Robot::display() {
		if (nickname[0] != '0') {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			
		}
		else {
			
			cout << "This Robot isn't operational" << endl;
		}
		return cout;
	}
	Robot::operator  bool() const {
   
		return (durability<=0);
	}
	
		

	
	

}