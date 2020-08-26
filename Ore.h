	// Ore.h
	#ifndef SDDS_ORE_H__
    #define SDDS_ORE_H__
	#include <iostream>
	#include <cstring>
	#include <iomanip>


	namespace sdds {

		const double DEFAULT_WEIGHT = 300.50;
		const int DEFAULT_PURITY = 20;
		const int CLASS_LEN = 30;

		class Ore {
			double m_weight;
			int m_purity;
			char m_classification[CLASS_LEN+1];
		public:
			Ore();
			Ore(double weight, int purity,const char* classification="Unknown");
			virtual ~Ore();
			bool refine();
			std::ostream& display(std::ostream& os) const;
			std::istream& input(std::istream& is);
			bool isEmpty()const;

		};
	
		std::ostream& operator<<(std::ostream& os, const Ore& ore);
		std::istream& operator>>(std::istream& os, Ore& ore);

		}
	#endif