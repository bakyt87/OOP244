// Parts.h
#ifndef SDDS_PARTS_H__
#define SDDS_PARTS_H__


namespace sdds {
	const int MIN_FORCE = 50;
	const int MIN_SPEED = 25;
	
	class Arms {
		int m_force;
	public:
		Arms();
		
		Arms(int armsForce);
		
		~Arms();

        int getForce() const;

		Arms& operator++();

		Arms operator++(int);

		Arms& operator+=(int);
		
		void setEmpty();
	};

	
	class Legs {
		
		int m_speed;
		
	public:

		Legs();

		Legs(int speed);

		int getSpeed() const;
		
		Legs& operator-=(int minus);
		
		};
	bool operator>(const Legs&, const Legs&);

	bool operator<(const Legs&, const Legs&);

	bool operator>(const Arms&, const Arms&);

	bool operator<(const Arms&, const Arms&);

}

#endif