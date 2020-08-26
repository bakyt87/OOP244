#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
#include "ParkingSpot.h"
#include "ParkingLot.h"

using namespace std;

namespace sdds {


	void setEmpty(ParkingSpot& P) {
		P.plate[0] = 0;
		P.makeModel = nullptr;
	}
	bool isEmpty(const ParkingSpot& P) {

		if (P.makeModel == nullptr) 
			return true;
		
		else 
		    return false;
	
    }
	
	void freeSpot(ParkingSpot& P) {
		delete[] P.makeModel;
		setEmpty(P);


}
	void print(const ParkingSpot& P) {
      //if(isEmpty(P))
		cout << P.makeModel <<", plate number: " << P.plate << endl;
	}
	

 void parkCar(ParkingSpot& park) {
		char Arr[60];
		cout << "Make and Model: ";
		char errorMessage[] = "Too long, Make and model must be shorter than 60 characters\nRedo Enry: ";
      read(Arr, 60, errorMessage);
      park.makeModel = new char[strlen(Arr) + 1];
		strcpy(park.makeModel, Arr);
      cout << "License Plate: ";
      read(park.plate, 8, "Too long, the error message goes here. ");
	}

}