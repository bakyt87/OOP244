#ifndef _SDDS_PUBRECORD_H_
#define _SDDS_PUBRECORD_H_
#include <iostream>
#include "ReadWriteable.h"
#include "Utils.h"
#include "Date.h"

namespace sdds {

	const int SDDS_CONSOLE = 1;
	const int SDDS_FILE = 2;

	class PubRecord : public ReadWriteable {
	public:
		virtual char recID()const=0;
	private:
		char* m_pubName;
		int m_shelfNum;
		int m_typeMedia;
	protected:
		void name(const char*);
	    const char* name()const;
		void shelfNo(int value);
	public:
		PubRecord();
		PubRecord(const PubRecord& copy);
		virtual ~PubRecord();
		virtual void checkIn()=0;
		virtual void checkOut()=0;
		PubRecord& operator=(const PubRecord& assign);
		int mediaType(int);
		int mediaType()const;
		int shelfNo()const;
		void readShelfNo();
		bool operator==(char)const;
		bool operator==(const char*)const;
		operator bool()const;
    };









}







#endif
