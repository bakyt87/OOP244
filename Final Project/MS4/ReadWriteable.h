#ifndef READWRITEABLE_H__
#define READWRITEABLE_H__
#include <iostream>

namespace sdds {

	class ReadWriteable {
	public:
		virtual	std::istream& read(std::istream& is = std::cin)=0;
		virtual std::ostream& write(std::ostream& os = std::cout)const=0;


	};
	std::ostream& operator<<(std::ostream& os, const ReadWriteable&);
	std::istream& operator>>(std::istream& is, ReadWriteable&);


}




#endif

