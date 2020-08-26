// Parts.h
#ifndef SDDS_PARTS_H__
#define SDDS_PARTS_H__


namespace sdds {
	const int MIN_FORCE = 50;
	
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
}

#endif