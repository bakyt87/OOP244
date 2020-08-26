// Figurine.h
#ifndef SDDS_FIGURINE_H__
#define SDDS_FIGURINE_H__
#include <iostream>

namespace sdds {

	const int MAX_NAME_LEN = 20;
	const double DEFAULT_PRICE = 25.25;

	class Figurine {
		char m_name[MAX_NAME_LEN + 1];
		char* m_pose;
		double m_price;
	public:
		Figurine();
		Figurine(const char* name, const char* pose, double price);
		Figurine(const Figurine& F);
		~Figurine();

		void setName(const char* name);
		void setPose(const char* pose);
		void setPrice(double price);
		
		std::ostream& display() const;
		void setToSafeEmptyState();
		bool isEmpty()const;
		operator bool()const;


	};
}

#endif // !