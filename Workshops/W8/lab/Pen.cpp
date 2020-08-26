// Pen.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Pen.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {

Pen::	Pen() {
	m_style = nullptr;
	m_ink = 0;
	}
Pen::Pen(const char* style, int ink) {
	if (style == nullptr) {
		m_style=nullptr;
		
	}else{
		m_style = new char[strlen(style) + 1];
		strcpy(m_style, style);
	}
	if (ink<1 || ink>INK_MAX) {
		m_ink = INK_MAX;
	}
	else {
		m_ink = ink;
	}
}
Pen::~Pen() {
	delete[] m_style;
   }
void Pen::write(const char* text) {
	int num=0;
	char space = ' ';
	int size = strlen(text);
	if (m_ink != 0) {
		cout << "Writing out the following: " << text << " with a Pen!" << endl;

		for (int i = 0; i <size ; i++) {
			if (text[i] != space)
				num++;
		}
			m_ink =- (num * 2);
			
			if (m_ink < 0) {
				m_ink = 0;
		
	  }
	}
	else if (m_ink == 0) {

		cout << "We can't write without ink!" << endl;

	}
}
void Pen::refill(int ink) {
	m_ink = ink;
	if (m_ink > INK_MAX) {
		m_ink = INK_MAX;
	}
	cout << "Refilling the pen with ink" << endl;
	}
bool Pen::filled() const {
	return m_ink != 0;
	}
ostream& Pen::display(ostream& os) const {
	if (m_style == nullptr) {
		cout << "This is an empty Pen" << endl;
	}
	else {
		cout << "Pen Details" << endl;
		cout << "Style: " << m_style << endl;
		cout << "Ink Remaining: " << m_ink << endl;

	}
	return os;
	}
}