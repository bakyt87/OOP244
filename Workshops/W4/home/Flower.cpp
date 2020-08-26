#define _CRT_SECURE_NO_WARNINGS		


#include <iostream>
#include <cstring>
#include "utils.h"
#include "Flower.h"


using namespace std;

namespace sdds {
	Flower::Flower() {
		setEmpty();
	}

	Flower::Flower(const char* name, const char* color, double price) {

		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0.0;
		if (strcmp(name, "") != 0 && name != nullptr && strcmp(color, "") != 0 && color != nullptr)
		{
			int nam, col;
			nam = strlen(name);
			col = strlen(color);
			f_name = new char[nam + 1];
			strcpy(f_name, name);
			f_colour = new char[col + 1];
			strcpy(f_colour, color);
			f_price = price;
		}
		else {
			setEmpty();
		}
	}
	Flower::~Flower() {

		if (f_name == nullptr && f_colour == nullptr)
		{
			cout << "An unknown flower has departed..." << endl;
		}
		else {
			cout << f_colour << " " << f_name << " has departed..." << endl;

			delete[] f_name;
			delete[] f_colour;
		}
	}

	const char* Flower::name() const {

		return f_name;
	}

	//This is a query function that returns the name of the Flower.


	const char* Flower::colour() const {

		return f_colour;
	}
	//This is a query function that returns the colour of the Flower.


	double Flower::price() const {

		return f_price;
	}
	//This is a query function that returns the price of the Flower.


	bool Flower::isEmpty() const {
		if (f_price == 0.0) {
			return true;
		}
		else {
			return false;
		}
	}
	//returns true if the Flower object is Empty and false otherwise.



	void Flower::setEmpty() {
		f_name = nullptr;

		f_colour = nullptr;

		f_price = 0.0;
	}
	void Flower::setName(const char* prompt) {
		f_name = new char[26];
		const char* errorMessage = "A flower's name is limited to 25 characters... Try again: ";
		cout << prompt;
		read(f_name, 25, errorMessage);
	}

	void Flower::setColour(const char* prompt) {
		f_colour = new char[16];
		const char* errorMessage = "A flower's colour is limited to 15 characters... Try again: ";
		cout << prompt;
		read(f_colour, 15, errorMessage);

	}

	void Flower::setPrice(const char* prompt) {
		int ok = 0;
		cout << prompt;
		do
		{
			cin >> f_price;
			if (f_price < 0) {
				ok = 1;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "A flower's price is a non-negative number... Try again: ";
			}
			else {
				ok = 0;
			}
		} while (ok == 1);

	}



	void Flower::setFlower() {
		cout << "Beginning the birth of a new flower..." << endl;
		char prompt[31];
		strcpy(prompt, "Enter the flower's name... : ");
		setName(prompt);
		char prompt1[32];
		strcpy(prompt1, "Enter the flower's colour... : ");
		setColour(prompt1);
		char prompt2[32];
		strcpy(prompt2, "Enter the flower's price... : ");
		setPrice(prompt2);
		cout << "The flower's current details..." << endl;
		display();
	}


	ostream& Flower::display() const {
		if (!isEmpty()) {
			cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;

		}
		else {

			cout << "This is an empty flower..." << endl;
		}
		return cout;

	}
	
	void Flower::setName(const char* name, int len) { 
		f_name = new char[len + 1];
		strcpy(f_name, name);
	}
	
	void Flower::setColour(const char* colour, int len) {
	    f_colour = new char[len + 1];
		strcpy(f_colour, colour);
	}
	
	void Flower::setPrice(double price) {
		if (price > 0)
			f_price = price;
		else
		{
			f_price = 1;

		}
		
		
	}
	

	

	


}