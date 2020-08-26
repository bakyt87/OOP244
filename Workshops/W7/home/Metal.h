// Metal.h
#ifndef SDDS_METAL_H__
#define SDDS_METAL_H__
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Ore.h"


namespace sdds {
	const double DEFAULT_MOHS = 2.5;
	const int NAME_LEN = 10;
	class Metal: public Ore {

		char* m_name;
		double m_mohs;
	public:
		Metal();
		Metal(double met_weight, int met_purity, const char* met_class, const char* met_name, double met_mohs);
		~Metal();
		void refine();
		std::ostream& display(std::ostream& os)const;
		std::istream& input(std::istream& is);
		
	};
	std::ostream& operator<<(std::ostream& os, const Metal& met);
	std::istream& operator>>(std::istream& is, Metal& met);


}
#endif