#ifndef SDDS_PARKINGLOT_H__
#define SDDS_PARKINGLOT_H__
#include "ParkingSpot.h"

namespace sdds {
	
	
	
	struct ParkingLot {
		int m_noOfSpots;
		ParkingSpot* m_Pspot;
	};

	void openParking(ParkingLot& Lot, int noOfSpots);
	void setEmpty(ParkingLot& Lot);
	bool isEmpty(const ParkingLot& Lpt);
    void openParking(ParkingLot& Lot, int noOfSpots);
    int  parkCar(ParkingLot& Lot);
    bool returnCar(ParkingLot& Lot, int spotNo);
    void closeParking(ParkingLot& Lot);


}
#endif 