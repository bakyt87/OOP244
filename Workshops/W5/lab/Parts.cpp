	// Parts.cpp

	#define _CRT_SECURE_NO_WARNINGS

	#include <iostream>
	#include <cstring>
	#include "Robot.h"
	#include "Parts.h"

	using namespace std;
	namespace sdds {
	
	Arms::Arms() {
		
		setEmpty();
		}
	Arms::Arms(int armsForce) {
		if (armsForce < 1) {
			m_force = MIN_FORCE;
		}
		else {
			m_force = armsForce;
		}
	}
	Arms::~Arms() {
	
		m_force=0;
	}
	int Arms::getForce() const {
	
		return m_force;
	}
	Arms& Arms::operator++() {
		m_force += 10;
		return *this;
	}
	Arms Arms::operator++(int x) {
		Arms temp = *this;
		++(*this);
		return temp;

	}

	Arms& Arms::operator+=(int armsForce) {
		m_force += armsForce;
		if (m_force < 1) {
		m_force = 0;
		}
		return *this;
	}




	void Arms::setEmpty(){
       
		m_force = 0;
		}

    }

