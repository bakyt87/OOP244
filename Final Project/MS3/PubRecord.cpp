 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "PubRecord.h"
#include "ReadWriteable.h"
using namespace std;
namespace sdds {
	void PubRecord:: name(const char* pubName) {
		if (pubName != nullptr) {
			m_pubName = new char[strlen(pubName) + 1];
			strcpy(m_pubName, pubName);
		}
	}
	const char* PubRecord::name() const{
		return m_pubName;
	}

	PubRecord::PubRecord():m_pubName(nullptr), m_shelfNum(0), m_typeMedia(SDDS_CONSOLE) {}
	PubRecord::PubRecord(const PubRecord& copy) {
		  m_shelfNum = copy.m_shelfNum;
                 
                 m_typeMedia = copy.m_typeMedia;
                
		
                if (copy.m_pubName != nullptr) {
			m_pubName = new char[strlen(copy.m_pubName) + 1];
			strcpy(m_pubName, copy.m_pubName);
		}
		else {
			m_pubName = nullptr;
		}
              
		
	}
	PubRecord:: ~PubRecord() {
		delete[] m_pubName;
		m_pubName = nullptr;
	}
	PubRecord& PubRecord::operator=(const PubRecord& assign) {
		if (this != &assign) {
			
			delete[] m_pubName;
			if (assign.m_pubName != nullptr) {
				m_pubName = new char[strlen(assign.m_pubName) + 1];
				strcpy(m_pubName, assign.m_pubName);
			}
			else {
				m_pubName = nullptr;
			}
			m_shelfNum = assign.m_shelfNum;
		}
		return *this;
	}
	int PubRecord::mediaType(int mediaType) {
		m_typeMedia = mediaType;
		return m_typeMedia;
	}
	int PubRecord::mediaType()const {
	
		return m_typeMedia;
	}
	int PubRecord::shelfNo()const {
		
		return m_shelfNum;
	}
	void PubRecord::readShelfNo() {
		sdds::read(this->m_shelfNum, 100, 999, "Invalid Shelf Number, Enter again: ");
	}


	
	bool PubRecord::operator==(char str1)const {
		return  str1 == recID();
	}

	bool PubRecord::operator==(const char* str) const
	{
		return strstr(m_pubName,str);
	}

	

	PubRecord::operator bool()const {
		return m_pubName != nullptr;
	}
}