
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "PubRecord.h"
#include "ReadWriteable.h"
#include "Utils.h"
#include "Date.h"
#include "Book.h"
using namespace std;
namespace sdds {


	Book::Book()  {
          m_ISBN=0;
          m_ID=0;
                
}

	Book::Book(const Book& copy) : PubRecord(copy) {

		m_ISBN = copy.m_ISBN;
		m_ID = copy.m_ID;
                due=copy.due;

	}
        Book::~Book(){}

	Book& Book::operator=(const Book& assign) {
		if (this != &assign) {
			PubRecord::operator = (assign);
			m_ISBN = assign.m_ISBN;
			m_ID = assign.m_ID;
                        due=assign.due;
		}
		return *this;
	}
	char Book::recID()const {
		char b = 'B';
		return b;
	}
	double Book::memberId()const {
		return m_ID;
	}
	void Book::checkIn() {
		m_ID = 0;
		cout << m_ISBN << " checked in!" << endl;
	}


	void Book::checkOut() {

		int id;
		cout << "Entere Member id: ";
		sdds::read(id, 10000, 99999, "Invalid Member ID, Enter again: ");
                                                                                          // m_ID = id;
		Date today; //today's date

		//get return date
		bool error;
		do {
			error = false;
			do {

				cout << "Enter return date: ";

				due.read();// enter a date
				//bad date entered
				if (due.errCode() != 0)
				{
					cout << due.dateStatus() << "." << endl;
				}

			} while (due.errCode() != 0);

			//calculate number of days
			int days = due - today;

			if (days < 0)
			{
				cout << "Please enter a future date.";
				error = true;
			}

			if (days > 30) {
				cout << "The return date must be earlier than 30 days away from today." << endl;
				error = true;
			}
		} while (error);
                m_ID=id;
	}

         Date Book::returnDue()const{
           return due;
}


	istream& Book::read(istream& is) {
		char book[41] = "";
		int shelf;
		int id;
		long long isbn;


		//read from console
		if (mediaType() == SDDS_CONSOLE) {
			m_ID = 0;

			cout << "Book Name: ";
			sdds::read(book, 40, "Book name too long, Enter again: ");
			name(book);
			cout << "ISBN: ";
			readlong(m_ISBN, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: ");
			cout << "Shelf Number: ";
			readShelfNo();
		}
		// read from file
		else if (mediaType() == SDDS_FILE) {


			is.getline(book, 40, '\t');

			
			is >> isbn;
			is.ignore();
			is >> shelf;
			is.ignore();
			is >> id;
			if (id == 0) {
				is.ignore();
				name(book);
				m_ISBN = isbn;
				shelfNo(shelf);
				m_ID = id;
                                
			}
			else
			{
				is.ignore();
				is >> due;
				name(book);
				m_ISBN = isbn;
				shelfNo(shelf);
				m_ID = id;
                               
			}
		}
		return is;
	}
	ostream& Book::write(ostream& os)const {



		//write to console
		if (mediaType() == SDDS_CONSOLE) {
                      if(memberId()==0){
			os << setw(41) << left << name() << m_ISBN << "  " << shelfNo();
                         }
			else if (memberId() != 0) {
				os<< setw(41) << left << name() << m_ISBN << "  " << shelfNo() << " " << memberId() << "   " << returnDue();
			}
		}


			//write to file
			else if (mediaType() == SDDS_FILE) {
                               if(memberId()==0){
				os << recID() << name() << "\t" << m_ISBN << "\t" << shelfNo() << "\t" << memberId();
                                }
				else if (memberId() != 0) {
					os<< recID() << name() << "\t" << m_ISBN << "\t" << shelfNo() << "\t" << memberId() << "\t" << returnDue();
				}
				os << endl;
			}
			
		return os;
	}
}