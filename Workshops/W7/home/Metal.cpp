	// Metal.cpp
	#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	#include <cstring>
	#include <iomanip>
	#include "Metal.h"


	using namespace std;

	namespace sdds {

		Metal::Metal() {
			m_name = nullptr;
			m_mohs = -1;
		}


		Metal::Metal(double weight, int purity, const char* classification, const char* met_name, double met_mohs):Ore(weight, purity, classification) {
			if (met_name==nullptr || met_name[0]==0) {
				m_name = nullptr;
			}
			else {
				m_name = new char[strlen(met_name) + 1];
				strcpy(m_name, met_name);
			
			if (met_mohs > 0) {
				m_mohs = met_mohs;
			}
			else {
				m_mohs = DEFAULT_MOHS;
			}
			
			}

	    }
		Metal:: ~Metal() {
			delete[] m_name;
		}
		void Metal::refine() {
			if (Ore::refine()) {
				m_mohs += 1;
		}
		}
		ostream& Metal::display(ostream& os)const {
			if (m_name==nullptr) {
				os << "This metal is imaginary" << endl;
			}
			else {
				os << "Name: "<<m_name << endl;
				Ore::display(os);
				os << "Mohs: "<< m_mohs << endl;
            }
			return os;
		}
		istream& Metal::input(istream& is) {
			char t_name[NAME_LEN];
			double t_mohs;
			cout << "Enter a value for this metal's name: ";
			is.clear();
			is.getline(t_name, NAME_LEN + 1);
			if (m_name != nullptr) {
				delete[] m_name;
			}
                m_name = new char[strlen(t_name) + 1];
				strcpy(m_name, t_name);


				cout << "Enter a value for this metal's mohs: ";
				is.clear();

				is >> t_mohs;
				if (t_mohs > 0) {
					m_mohs = t_mohs;

				}
				else {
					m_mohs = DEFAULT_MOHS;
				}

				Ore::input(is);
				is.ignore(1000, '\n');
			
			return is;
		}
		ostream& operator<<(ostream& os, const Metal& met) {
			cout << "Metal" << endl;
			met.display(os);
			return os;
		}
		istream& operator>>(istream& is, Metal& met) {
			met.input(is);
			return is;
		}


		
	}