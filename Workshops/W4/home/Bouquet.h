#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H
#include <iostream>
#include <cstring>
#include "Flower.h"



namespace sdds {
	int const MESS_MAX_LEN = 25;

	int const MAX_FLOWERS = 3;

	class Bouquet {
		double b_price;
	
		char* b_message;
	
		Flower* b_flowers;
	
		int b_flowerCount;
		
	public:

		Bouquet();
		
		

		Bouquet(const Flower* flowers, int flowerCount= MAX_FLOWERS, const char* message="Congratulations");
		
		~Bouquet();
		
	

		void setEmpty();

		const char* message() const;

		double price() const;


		bool isEmpty()const;
		
		void setMessage(const char* prompt);


		void discardBouquet();

		void arrangeBouquet();

		std::ostream& display() const;

		void flushKeyboard()const;


	};
}
#endif