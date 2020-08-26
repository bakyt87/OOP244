#ifndef SDDS_REPORTUTILS_H__
#define SDDS_REPORTUTILS_H__

#include <iostream>

		namespace sdds {	
			std::ostream& line(int len, char ch);
			void read(int& val, int min, int max, const char* errorMessage = "");
			void read(char* str, int len, const char* errorMessage = "");
		}

#endif