#ifndef SDDS_PARKINGSPOT_H__
#define SDDS_PARKINGSPOT_H__
#include <iostream>

namespace sdds {
	
	struct ParkingSpot {
		char plate[8];
		char* makeModel;
	};

	void setEmpty(ParkingSpot& P);
	bool isEmpty(const ParkingSpot& P);
    void freeSpot(ParkingSpot& P);
    void print(const ParkingSpot& P);
    void parkCar(ParkingSpot& park);

}
#endif