// Pen.h
#ifndef _PEN_H_
#define _PEN_H_
#include <iostream>
#include "WriteInstrument.h"


namespace sdds {
	const int INK_MAX = 50;
	class Pen : public WriteInstrument {
		char* m_style;
		int m_ink;
	public:
		Pen();
		Pen(const char*, int);
		virtual ~Pen();
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual std::ostream& display(std::ostream& os) const;
	};

}
#endif