// Figurine.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Figurine.h"


using namespace std;
namespace sdds {


	Figurine::Figurine() {
		
		setToSafeEmptyState();
		m_copy = false;
	}
	Figurine::Figurine(const char* name, const char* pose, double price) {
		if (name == nullptr || name[0] == '\0' || pose == nullptr || pose[0] == '\0') {

			setToSafeEmptyState();

		}
		else {
			setName(name);
			setPrice(price);
                        setPose(pose);
                        m_copy=false;
		}
	}
		Figurine::Figurine(const Figurine& copy){
                  setName(copy.m_name);
                  setPrice(copy.m_price);
		if(copy.isEmpty()){
		m_pose = nullptr;
              }  else {
				setPose(copy.m_pose);
			}
			
				m_copy = true;
			}

		Figurine::~Figurine() {
		
			delete[] m_pose;
		}

		void Figurine::setName(const char* name) {
			if(strlen(name)>MAX_NAME_LEN){
			strncpy(m_name, name, MAX_NAME_LEN);
			m_name[MAX_NAME_LEN] = '\0';
                } else {
                        strncpy(m_name, name, strlen(name) +1);
                        m_name[strlen(name)]= '\0';
                }

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
			
			return (m_name == nullptr || m_name[0] == '\0'); 
				
			
		}
		ostream& Figurine::display() const 
		{
			if (isCopy() && isEmpty())
			{
				cout << "This Figurine has not yet been sculpted" << endl;
				cout << "This is a replica of emptiness" << endl;
			}
			else if (isEmpty() && !isCopy()) {
					cout << "This Figurine has not yet been sculpted" << endl;
				
			}
			else if(!isEmpty() && isCopy()){
				cout << "Figurine Details" << endl;
				cout << "Name: " << m_name << endl;
				cout << "Pose: " << m_pose << endl;
				cout.precision(2);
				cout << fixed << "Price: " << m_price << endl;
				cout << "This is a replica" << endl;
			}
			else if (!isEmpty() && !isCopy()) {
				cout << "Figurine Details" << endl;
				cout << "Name: " << m_name << endl;
				cout << "Pose: " << m_pose << endl;
				cout.precision(2);
				cout << fixed << "Price: " << m_price << endl;
				
			}
		return cout;
		}

		void Figurine::setToSafeEmptyState() {

			m_name[0] = '\0';
			m_pose = nullptr;
			m_price = 0;
		}
		bool Figurine::isEmpty()const {
			
			return (m_pose == nullptr || m_pose[0] == '\0'); 
				
			}
			
		
	Figurine& Figurine:: operator=(const Figurine& copyAs) {
			if (this != &copyAs)
			{
				setPrice(copyAs.m_price);

				setName(copyAs.m_name);



				if (copyAs.isEmpty()) {
					m_pose = nullptr;
				}
				else {
                                        delete[] m_pose;
					setPose(copyAs.m_pose);
				}
				m_copy = true;

			}

			return *this;
		
			}		
		bool Figurine::isCopy() const {
             return m_copy;
			
		}
		const char* Figurine::Name()const {
			return m_name;
		}
		const char* Figurine::Pose()const {
			return m_pose;
		}
		double Figurine::Price()const {
			return m_price;
		}

		bool operator==(const Figurine& copy1, const Figurine& copy2) {

			bool result = false;
			if (copy1.Name() == copy2.Name() && copy1.Pose() == copy2.Pose() && copy1.Price() == copy2.Price()) {
				result = true;
				}
			return result;
		}

	}