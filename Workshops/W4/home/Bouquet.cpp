		#define _CRT_SECURE_NO_WARNINGS		

		#include <iostream>
		#include <cstring>
		#include "utils.h"
		#include "Flower.h"
		#include "Bouquet.h"

		using namespace std;
		using namespace sdds;

		namespace sdds
		{

			Bouquet::Bouquet() {
				setEmpty();
			}


			Bouquet::Bouquet(const Flower* flowers, int flowerCount, const char* message) {

				if (flowers != nullptr)
				{
					b_flowerCount = flowerCount;
					b_flowers = new Flower[b_flowerCount];

					double sum = 0;

					for (int i = 0; i < b_flowerCount; i++) {
						
						sum += flowers[i].price();

						b_flowers[i].setName(flowers[i].name(), strlen(flowers[i].name()));
						
						b_flowers[i].setPrice(flowers[i].price());

						b_flowers[i].setColour(flowers[i].colour(), strlen(flowers[i].colour()));

					}
					b_message = new char[strlen(message) + 1];
					strcpy(b_message, message);
					b_price = sum;
				}

			}
			Bouquet::~Bouquet() {
				if (!isEmpty()) {
					cout << "A bouquet has departed with the following flowers..." << endl;
				}
				else {
					cout << "An unknown bouquet has departed..." << endl;
				}
				delete[] b_flowers;
				b_flowers = nullptr;
				delete[] b_message;
				b_message = nullptr;
			}
                          void Bouquet::flushKeyboard()const {
				while (cin.get() != '\n');
			}

			void Bouquet::setEmpty() {

				b_flowers = nullptr;
				b_message = nullptr;
				b_price = 0;
				b_flowerCount = 0;


				
			}
			const char* Bouquet::message() const {
				return b_message;

			}
			double Bouquet::price() const {
				return b_price;
			}
			bool Bouquet::isEmpty()const {
				return(b_flowers == nullptr);
			}

			void Bouquet::setMessage(const char* prompt) {

				const char* errorMessage = "A bouquets's message (non-empty) is limited to 30 characters... Try again: ";
				char message[31];
				cout << prompt;
				read(message, 30, errorMessage);
				b_message = new char[strlen(message) + 1];
				strcpy(b_message, message);

			}
			void Bouquet::discardBouquet() {
				cout << "Discarding the current bouquet..." << endl;
				delete[] b_flowers;
				delete[]b_message;
				setEmpty();
			}

			void Bouquet::arrangeBouquet() {

				cout << "Arranging a new bouquet..." << endl;

				char answer[2] = { '0' };

				if (!isEmpty()) {

					cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";

					do {

						answer[0] = cin.get();
                                                
                                                 

						while (cin.get() != '\n');

					} while (!(answer[0] == 'Y' || answer[0] == 'N') && cout << "The decision is either Y or N... Try again: ");

					if (answer[0] == 'N')

						cout << "No new arrangement performed..." << endl;

					else

						discardBouquet();
				}
				if (answer[0] == 'Y' || isEmpty()) {
                                        

					cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";

					read(b_flowerCount, 1, MAX_FLOWERS, "The valid range is 1-3... Try again: ");

					b_flowers = new Flower[b_flowerCount];

					b_price = 0.0;

					for (int i = 0; i < b_flowerCount; i++) {

						b_flowers[i].setFlower();
                                                   flushKeyboard();
						b_price += b_flowers[i].price();
					}

					cout << "A bouquet has been arranged..." << endl;

					setMessage("Enter a message to send with the bouquet...: ");
				}
			}

				ostream& Bouquet::display() const {
					if (isEmpty()) {
						cout << "This is an empty bouquet..." << endl;
					}
					else {
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "This bouquet worth " << price() << " has the following flowers..." << endl;
						for (int i = 0; i < b_flowerCount; i++) {
							b_flowers[i].display();

						}
						cout << "with a message of: " << b_message << endl;
					}

					return cout;
				}



			}
		