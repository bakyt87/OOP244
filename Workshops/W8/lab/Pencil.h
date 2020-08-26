// Pencil.h
#ifndef _PENCIL_H_
#define _PENCIL_H_
#include <iostream>
#include "WriteInstrument.h"

namespace sdds {
	const int HB_MAX = 2;
	const int GRAPHITE_MAX = 100;

	class Pencil: public WriteInstrument{
		char m_HB_scale[HB_MAX+1];
		int m_graphite;
	public:
		Pencil();
		Pencil(const char*, int);
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual std::ostream& display(std::ostream& os) const;

	};


}
#endif