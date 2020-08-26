#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "PubRecord.h"
#include "ReadWriteable.h"
#include "Magazine.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Magazine::Magazine() {
            m_volume=0;
           m_issueNum=0; 

}

	Magazine::Magazine(const Magazine& copy) : PubRecord(copy) {

		m_volume = copy.m_volume;
		m_issueNum = copy.m_issueNum;
	}
	Magazine& Magazine:: operator=(const Magazine& assign) {
		if (this != &assign) {
			PubRecord::operator=(assign);
			m_volume = assign.m_volume;
			m_issueNum = assign.m_issueNum;

		}
		return *this;
	}
         Magazine::~Magazine(){}

	char  Magazine::recID()const {
		char m = 'M';
		return m;
	}
	void  Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	istream& Magazine::read(istream& is) {
		char mag[41] = "";

		int shelf;
		int volume;
		int issue;
		//read from console
		if (mediaType() == SDDS_CONSOLE) {

			cout << "Magazine Name: ";
			sdds::read(mag, 40, "Magazine name too long, Enter again: ");
			name(mag);
			int volume;
			cout << "Volume: ";
			sdds::read(volume, 1, 99, "Invalid Volume number, Enter again: ");
			m_volume = volume;
			int issue;
			cout << "Issue: ";
			sdds::read(issue, 1, 99, "Invalid Issue number, Enter again: ");
			m_issueNum = issue;

			cout << "Shelf Number: ";
			readShelfNo();

		}
		//read from file
		else if (mediaType() == SDDS_FILE) {

			is.getline(mag, 40, '\t');
	
			is >> volume;
			is.ignore();
			is >> issue;
			is.ignore();
			is >> shelf;
			is.ignore(1000, '\n');
			if (!is.fail()) {
				m_issueNum = issue;
				m_volume = volume;
				name(mag);
				shelfNo(shelf);
			}
		}
		return is;
	}
	ostream& Magazine::write(ostream& os)const {

	

			if (mediaType() == SDDS_CONSOLE) {
os.setf(ios::left);
os.width(41);
os.fill(' ');
os <<name();
os << "       ";
os.width(2);
os.setf(ios::right);
os.fill('0');
os<< m_volume;
os<< "(";
os.width(2);
os.setf(ios::right);
os.fill('0');
os<< m_issueNum;
os<< ")"<<"  " << shelfNo();
os.unsetf(ios::right);
os.fill(' ');
			}
			else if (mediaType() == SDDS_FILE) {
				os << recID() << name() << "\t" << m_volume << "\t" << m_issueNum << "\t" << shelfNo() <<endl;
			}
		return os;
	}
}
	
