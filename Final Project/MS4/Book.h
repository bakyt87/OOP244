#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_
#include <iostream>
#include "ReadWriteable.h"
#include "Utils.h"
#include "Date.h"
#include "PubRecord.h"

namespace sdds {
	class Book : public PubRecord, public Date {

		long long m_ISBN;
		int m_ID;
		Date due;
	public:
		Book();
		Book(const Book&);
		Book& operator=(const Book&);
                virtual ~Book();
		char recID()const;
		double memberId()const;
                Date returnDue()const;
		void checkIn();
		void checkOut();
		std::istream& read(std::istream& is=std::cin);
		std::ostream& write(std::ostream& os=std::cout)const; 
	};
}
#endif