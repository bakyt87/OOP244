// WriteInstrument.h
#ifndef _WRITEINSTRUMENT_H_
#define _WRITEINSTRUMENT_H_
#include <iostream>

namespace sdds {
	class WriteInstrument {
	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char*)=0;
		virtual void refill(int)=0;
		virtual bool filled() const=0;
		virtual std::ostream& display(std::ostream& os) const=0;
	};
}


#endif
