// Figurine.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Figurine.h"


using namespace std;
namespace sdds {


	Figurine::Figurine() {
		
		setToSafeEmptyState();
	}
	Figurine::Figurine(const char* name, const char* pose, double price) {
		if (name == nullptr || name[0] == '\0' || pose == nullptr || pose[0] == '\0') {

			setToSafeEmptyState();

		}
		else {
			//if (strlen(name) > MAX_NAME_LEN) 
				strncpy(m_name, name, MAX_NAME_LEN);
				m_name[MAX_NAME_LEN] = '\0';
			

			m_pose = new char[strlen(pose) + 1];
			strcpy(m_pose, pose);

			if (price < 1) 
				m_price = DEFAULT_PRICE;
			
			else 
				m_price = price;
			
		}
	}
		Figurine::Figurine(const Figurine& F) {
		if(!F.isEmpty()){
			strncpy(m_name, F.m_name, MAX_NAME_LEN);
			m_price = F.m_price;
			m_pose = new char[strlen(F.m_pose) + 1];
				strcpy(m_pose, F.m_pose);
			}
			else {
				m_pose = nullptr;
			}
}
		Figurine::~Figurine() {
		
			delete[] m_pose;
		}

		void Figurine::setName(const char* name) {
			
			strncpy(m_name, name, MAX_NAME_LEN);
			m_name[MAX_NAME_LEN] = '\0';


		}
		void Figurine::setPose(const char* pose) {

			m_pose = new char[strlen(pose) + 1];
			strcpy(m_pose, pose);

		}
		void Figurine::setPrice(double price) {
			if (price < 1) {
				m_price = DEFAULT_PRICE;
			}
			else {
				m_price = price;
			}

		}
		Figurine:: operator bool()const {
			bool result = false;
			if (m_name == nullptr || m_name[0] == '\0') {
				result = true;
			}
			return result;

		}
		ostream& Figurine::display() const {
			if (isEmpty()) {
				cout << "This Figurine has not yet been sculpted" << endl;
			}
			else {
				cout << "Figurine Details" << endl;
				cout << "Name: " << m_name << endl;
				cout << "Pose: " << m_pose << endl;
				cout.precision(2);
				cout <<fixed<< "Price: "<< m_price << endl;
			}
			return cout;
		}

		void Figurine::setToSafeEmptyState() {

			m_name[0] = '\0';
			m_pose = nullptr;
			m_price = 0;
		}
		bool Figurine::isEmpty()const {
			bool result = false;
			if ( m_pose == nullptr || m_pose[0] == '\0') {
				result = true;
			}
			return result;
		}

	}