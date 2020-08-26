#ifndef _SDDS_MAGAZINE_H_
#define _SDDS_MAGAZINE_H_
#include <iostream>
#include "ReadWriteable.h"
#include "Utils.h"
#include "Date.h"
#include "PubRecord.h"


namespace sdds {
	class Magazine : public PubRecord{

		int m_volume;
		int m_issueNum;
	public:
		Magazine();
		Magazine(const Magazine&);
		Magazine& operator=(const Magazine&);
                virtual ~Magazine();
		 char recID() const;
		 void checkIn();
		 void checkOut();
		 std::istream& read(std::istream& is=std::cin);
		 std::ostream& write(std::ostream& os=std::cout)const;


};






}

#endif