#ifndef SDDS_FLOWER_H
#define SDDS_FLOWER_H
#include <iostream>
#include <cstring>

namespace sdds {
	int const NAME_MAX_LEN = 25;
	int const COL_MAX_LEN = 15;

	class Flower {
		char* f_name;
		//This is a char pointer that is used to store the name of the flower.
		char* f_colour;
		//This is a char pointer that is used to store the colour of the flower.
		double f_price;
		//This is a double value that is the price of the flower.

	public:

		Flower();
		Flower(const char* name, const char* colour, double price);
		~Flower();
		const char* name() const;



		//This is a query function that returns the name of the Flower.

		const char* colour() const;
		//This is a query function that returns the colour of the Flower.

		double price() const;
		//This is a query function that returns the price of the Flower.

		bool isEmpty()const;
		//returns true if the Flower object is Empty and false otherwise.

		void setEmpty();
		//Sets the Flower object into a safe empty state.
		void setName(const char* prompt);

		void setName(const char* name, int len);

		void setColour(const char* prompt);
		
		void setColour(const char* colour, int len);

		void setPrice(double price);

		

		void setFlower();

		void setPrice(const char* prompt);

		std::ostream& display() const;
	};




}
#endif