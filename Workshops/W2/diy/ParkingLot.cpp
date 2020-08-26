#include <iostream>
#include <cstring>
#include "ParkingSpot.h"
#include "ParkingLot.h"
#include "utils.h"
using namespace std;
namespace sdds {
	
    void setEmpty(ParkingLot& Lot) {
		Lot.m_noOfSpots = 0;
		Lot.m_Pspot = nullptr;
	}
	bool isEmpty(const ParkingLot& Lot) {
		
		if (Lot.m_Pspot == nullptr)
			return true;
		return false;
	}

	void openParking(ParkingLot& Lot, int noOfSpots) {
		Lot.m_noOfSpots = noOfSpots;
		Lot.m_Pspot = new ParkingSpot[Lot.m_noOfSpots];
		for (int i = 0; i < noOfSpots; i++)
			setEmpty(Lot.m_Pspot[i]);

	}
	int parkCar(ParkingLot& Lot)
	{
		for (int i = 0; i < Lot.m_noOfSpots; i++)
		{
			if (isEmpty(Lot.m_Pspot[i]))
			{
				parkCar(Lot.m_Pspot[i]);
				return i;
			}
		}
		return -1;
			
	}
	
		bool returnCar(ParkingLot& Lot, int spotNo) {

			if ((spotNo >= 0 && spotNo < Lot.m_noOfSpots) && !isEmpty(Lot.m_Pspot[spotNo]))
			{
				cout << "Returning ";
				print(Lot.m_Pspot[spotNo]);
				freeSpot(Lot.m_Pspot[spotNo]);
				return true;
			}
		        else 
				      return false;
		}
	void closeParking(ParkingLot& Lot) {
		for (int i = 0; i < Lot.m_noOfSpots; i++) {
			if (!isEmpty(Lot.m_Pspot[i])) {
				returnCar(Lot, i);
			}
		}
		setEmpty(Lot);
   }
}