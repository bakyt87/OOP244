#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20u;
	class Menu;

	class MenuItem {
		friend class Menu;
		char* m_description;


		MenuItem(const char* description = "");
		MenuItem(const MenuItem&) = delete;

		virtual ~MenuItem();
		operator bool() const;
		operator const char* ()const;


		void operator=(const MenuItem&) = delete;
		bool isEmpty()const;
		std::ostream& display(std::ostream& os = std::cout)const;

	};
	class Menu {
		MenuItem m_title;
		MenuItem* m_menuItems[MAX_MENU_ITEMS];
		unsigned int m_numOfItems;
	public:
		Menu();
		Menu(const char* title);
		virtual ~Menu();
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		std:: ostream&  displayTitle(std::ostream& os=std::cout)const;
		std::ostream& displayMenu(std::ostream& os = std::cout)const;
		operator bool()const;
		void clearBuffer()const;
		Menu& operator<<(const char*);
		unsigned int getSelection();
		unsigned int operator~();
		operator unsigned int()const;
		const char* operator[](unsigned int index) const;

	};
	std::ostream& operator<<(std::ostream& os, const Menu& RO);




}
#endif

