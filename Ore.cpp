		// Ore.cpp
		#define _CRT_SECURE_NO_WARNINGS
		#include <iostream>
		#include <cstring>
		#include <iomanip>
		#include "Ore.h"

		using namespace std;

		namespace sdds {

			Ore::Ore(){
				m_weight=0.0;
				m_purity=0;
				m_classification[0]=0;
			
			}
			
			Ore::Ore(double weight, int purity, const char* classification) {
				if (weight < 1) {
					m_weight = DEFAULT_WEIGHT;
				}
				else {
					m_weight = weight;
				}
				if (purity < 1 || purity > 100) {
					m_purity = DEFAULT_PURITY;
				}
				else {
					m_purity = purity;

				}
			
				strncpy(m_classification, classification, CLASS_LEN);
				
			}
			Ore::~Ore() {

				m_classification[0]=0;
			}

			bool Ore::refine() {
				bool result=true;
				if (m_purity == 100) {
					cout << "Can no longer be refined" << endl;
					result = false;
				}
				else {
				    m_weight -= 20;
					m_purity += 10;
					
				if (m_purity > 100) {
					m_purity = 100;
				}
				}
                return result;

			}
			ostream& Ore::display(ostream& os) const {
				if (isEmpty()) {
					os << "This ore is imaginary" << endl;

				}
				else {
					os << fixed << setprecision(2);
					os << "Weight: " << m_weight << endl;
					os << "Purity: " << m_purity << endl;
					os << "Classification: " << m_classification << endl;
				}
				return os;
			}
			istream& Ore::input(istream& is) {
				double t_weight;
				int t_purity;
				char t_classification[CLASS_LEN];
				cout << "Enter a value for this ore's weight: ";
				is >> t_weight;
				cout << "Enter a value for this ore's purity: ";
				is >> t_purity;
				cout << "Enter a classification for the ore (MAX 30 chars): ";
				is.ignore(1000, '\n');
				
				is >> t_classification;

				if (t_weight < 1) {
					m_weight = t_weight;
				}
				else {
					m_weight = t_weight;
				}
				if (t_purity < 1 || t_purity > 100) {
					m_purity = DEFAULT_PURITY;
				}
				else {
					m_purity = t_purity;

			    }
				
				strncpy(m_classification, t_classification, CLASS_LEN);
			
				return is;
			}


			ostream& operator<<(ostream& os, const Ore& ore) {

				cout << "Ore" << endl;
				ore.display(os);
				return os;
			}
			istream& operator>>(istream& is, Ore& ore) {
				ore.input(is);
				return is;
			}


			bool Ore::isEmpty()const {

				return m_classification[0]==0;
			}
		
		
		}