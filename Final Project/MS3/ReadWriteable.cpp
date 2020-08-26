#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
using namespace std;
#include "ReadWriteable.h"
namespace sdds {


	ostream& operator<<(ostream& os, const ReadWriteable& A) {
		
		A.write(os);
		
		return os;
	}

	istream& operator>>(istream& is, ReadWriteable& B) {
		
		B.read(is);
		
		return is;
	}



}