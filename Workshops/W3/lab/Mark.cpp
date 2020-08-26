#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {

	void Mark::flushKeyboard()const {
		while (cin.get() != '\n');
	}
	void Mark::set(int displayMode) {
		m_displayMode = displayMode;
	}
	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}
	bool Mark::isEmpty()const {
		if (m_mark <= 0)
			return true;
		else
			return false;
	}
	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
	}
	int Mark::percent()const {

		return int((m_mark / m_outOf) * 100 + 0.5);

	}
	//divides m_mark by m_outOf them multiplies it by 100 and ads 0.5 to it.Then it will cast the outcome to an integer and returns it.
	double Mark::rawValue()const {

		return(m_mark / m_outOf);

	}
	//This function reads the mark in following format :
		//mark / out of, for example : 30 / 50 or 20 / 20 and returns true if successful and If it cannot read the any part of the mark it will fail and return false.
			//To do this read first prints the prompt argument.Then it will read a double into m_mark, ignore one character and then read an integer into m_outOf.Afterwards it will check if the “cin” object has failed or not.If “cin” has failed, it will clear cin, set the Mark object to empty and return false.
			//In any case before returning anything read will flush the keyboard.
	//returns the result of m_mark divided by m_outOf.
	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			success = false;

		}
		flushKeyboard();
		return success;

	}


	ostream& Mark::display() const {
		if (isEmpty()) {
			cout << "Empty Mark object!";

		}
		else if (m_displayMode == DSP_RAW)
			cout << rawValue();
		else if (m_displayMode == DSP_PERCENT)
			cout << "%" << percent();
		else if (m_displayMode == DSP_ASIS)
			cout << m_mark << "/" << m_outOf;
		else if (m_displayMode == DSP_UNDEFINED)
			cout << "Display mode not set!";
		else
			cout << "Invalid Mark Display setting";
		return cout;
	}
	
}