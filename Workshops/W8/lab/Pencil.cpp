// Pencil.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Pencil.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {

	Pencil::Pencil() {
		m_HB_scale[0]='\0';
		m_graphite = 0;
	}
	Pencil::Pencil(const char* scale, int graph) {
		if (scale == nullptr || scale[0] == 0) {
			m_HB_scale[0]='\0';
			m_graphite = 0;
		}
		else {
			strncpy(m_HB_scale, scale, HB_MAX+1);
			m_HB_scale[HB_MAX] = '\0';
		}
			if (graph < 1 || graph > GRAPHITE_MAX) {
				m_graphite = GRAPHITE_MAX;
		}else {
				m_graphite = graph;
		}
	}
	void Pencil::write(const char* text) {
		int num=0;
		char space = ' ';
		int size = strlen(text);
		
		if (m_graphite > 0) {
			cout << "Writing out the following: " << text << " with a Pencil!" << endl;

			for (int i = 0; i < size; i++) {
				if (text[i] == space) 
					num++;
				
			}
			m_graphite -= (num * 5);
			
			if (m_graphite < 0) {

				m_graphite = 0;
}
			
			}else if (m_graphite == 0) {

				cout << "We can't write without graphite!" << endl;

			}
		
	}
	void Pencil::refill(int graphite) {
		m_graphite += graphite;
		if (m_graphite > GRAPHITE_MAX) {
			m_graphite = GRAPHITE_MAX;
		}
		cout << "Refilling the pencil with graphite" << endl;
	}
	bool Pencil::filled() const {
		return m_graphite != 0;
	}
	ostream& Pencil::display(ostream& os) const {
		if (m_HB_scale[0] == '\0') {
			cout << "This is an empty Pencil" << endl;
		}
		else {
			cout << "Pencil Details" << endl;
			cout << "HB Value: " << m_HB_scale << endl;
			cout << "Graphite Remaining: " << m_graphite << endl;

		}
		return os;
	}
}