#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include <iostream>
using namespace std;
#include "Menu.h"
#include "Utils.h"

namespace sdds {


	MenuItem::MenuItem(const char* description) {
		if (description != nullptr) {
			m_description = new char[strlen(description) + 1];
			strcpy(m_description, description);
		}
		else {
			m_description = nullptr;
		}
	}
	MenuItem::operator bool()const {
		return m_description != nullptr;
	}
	MenuItem::operator const char* () const
	{
		return this->m_description;
	}

	MenuItem::~MenuItem() {
		delete[] m_description;
		m_description = nullptr;
	}
	bool MenuItem::isEmpty()const {
		return m_description == nullptr || m_description[0] =='\0';
	}
	ostream& MenuItem::display(ostream& os) const {
		if (!isEmpty()) {
			os << m_description;
		}
		return os;

	}
	Menu::Menu() : m_title(""), m_menuItems{ nullptr }  {
		m_numOfItems = 0;
	}

	Menu::Menu(const char* title) : m_title(title), m_menuItems{ nullptr } {
		m_numOfItems = 0;

	}
	Menu::~Menu() {
		for (unsigned int i = 0; i < m_numOfItems; i++) {
			delete[] m_menuItems[i];
		}
	}
	ostream& Menu::displayTitle(ostream& os)const {
		if (!m_title.isEmpty()) {
			m_title.display(os);
			
		}
		return os;
	}
	ostream& Menu::displayMenu(ostream& os)const {
		
		if (!m_title.isEmpty()) {
			m_title.display(os)<< ":" << endl;

		}
		
		os.setf(ios::right);
		
		for (unsigned int i = 0; i < m_numOfItems; i++) {
			os.width(1);
			os.fill();
			os << " " << i + 1 << "- ";
			m_menuItems[i]->display() << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;
	}
	Menu::operator bool()const {

		return (m_numOfItems != 0);

	}



	Menu& Menu::operator<<(const char* description) {
		if (m_numOfItems < MAX_MENU_ITEMS) {
			m_numOfItems++;
			m_menuItems[m_numOfItems - 1] = new MenuItem(description);

		}
		return *this;
	}
	unsigned int Menu::getSelection() {
		unsigned int num;

		displayMenu();
		read(num, 0, m_numOfItems, "Invalid Selection, try again: ");
		return num;

	}
	unsigned int Menu::operator~() {

		return getSelection();

	}

	Menu::operator unsigned int()const {

		return m_numOfItems;
	}
	const char* Menu::operator[](unsigned int index) const {
		while (index > m_numOfItems) {
			index -= m_numOfItems;
		}
		return m_menuItems[index]->m_description;
	}

	ostream& operator<<(ostream& os, const Menu& RO) {
		RO.displayTitle();
		return os;
	}
	void Menu::clearBuffer()const {
		while (cin.get() != '\n');
	}

}