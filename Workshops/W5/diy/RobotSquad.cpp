// RobotSquad.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "RobotSquad.h"
#include "Robot.h"
#include "Parts.h"

using namespace std;
namespace sdds {


	RobotSquad::RobotSquad() {

		setEmpty();
	}

	RobotSquad::RobotSquad(const char* squadName) {
                setEmpty();

		strncpy(m_name, squadName, MAX_NAME);

	}

	RobotSquad::~RobotSquad() {

		delete[] Robots;
		Robots = nullptr;
	}
	bool RobotSquad::isEmpty()const {
		bool ok;
		if (Robots == nullptr || m_count == 0) {
			ok = true;
		}
		else {
			ok = false;
		}
		return ok;
	}
	void RobotSquad::setEmpty() {
		strcpy(m_name, "No Name");
		Robots = nullptr;
		m_count = 0;
	}

	RobotSquad& RobotSquad::operator+=(Robot roster) {

		Robot squad[3];
		for (int i = 0; i < m_count; i++) {

			squad[i] = Robots[i];
		}
		
		delete[] Robots;
	
		Robots = new Robot[m_count+1];

		for (int j = 0; j < m_count; j++) {
			Robots[j] = squad[j];
		}
		Robots[m_count] = roster;
		m_count++;
        return *this;
		}

	ostream& RobotSquad::display() const {

		if (isEmpty()) {

			cout << "Squad **" << m_name << "** has no members" << endl;
		}
		else {
			cout << "***Squad Summary***"<<endl;
			cout << "Name: " << m_name << endl;
			cout << "Roster Count: " << m_count << endl;
			cout << "Roster:" << endl;
			for (int i = 0; i < m_count; i++) {
				Robots[i].display();
			}
		}
		return cout;
	}
	RobotSquad& RobotSquad::operator--() {
		if (!isEmpty()) {
			if (m_count>1) {
				Robot copy[10];
				for (int i = 0; i < m_count - 1; i++) {
					copy[i] = Robots[i];
				}
				delete[] Robots;
				Robots = new Robot[m_count];
				for (int j = 0; j < m_count; j++) {
					Robots[j] = copy[j];
				}
				m_count--;
			}
			else {
				delete[] Robots;
				setEmpty();
			}
		}
		else{
			cout << "This squad **" << m_name << "** has no members or is uninitialized. Can't do --."<<endl;
}
		return *this;

	}
	Robot* RobotSquad::getRoster() {

		return Robots;
	}
}

	
