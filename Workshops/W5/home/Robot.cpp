	// Robot.cpp

	#define _CRT_SECURE_NO_WARNINGS

	#include <iostream>
	#include <cstring>
	#include "Robot.h"
	#include "Parts.h"

	using namespace std;
	namespace sdds {

		Robot::Robot() {
			nickname[0] = '0';
			durability = 0;
			legs = Legs();
			arms = Arms();
		}
		Robot::Robot(const char* name, int armforce, int legSpeed, int durab) {
			if (name == nullptr) {
				nickname[0] = '0';
			}
			else {

				strncpy(nickname, name, NICK_MAX_LEN);
				nickname[NICK_MAX_LEN + 1] = '\0';

			}

			if (strlen(name) > NICK_MAX_LEN) {
				name = new char[strlen(name) + 1];
			}
			if (durab < 1) {
				durability = 100;

			}
			else {
				durability = durab;
			}
			arms = Arms(armforce);
			
			legs = Legs(legSpeed);
		}
		Robot::~Robot() {
			//delete []nickname;

	//nickname == nullptr;
		}

		ostream& Robot::display() {
			if (nickname[0] != '0') {
				cout << "***Robot Summary***" << endl;
				cout << "Nickname: " << nickname << endl;
				cout << "Arm Power: " << arms.getForce() << endl;
				cout << "Durability: " << durability << endl;
				cout << "Legs: " << legs.getSpeed() << endl;

			}
			else {

				cout << "This Robot isn't operational" << endl;
			}
			return cout;
		}
		Robot::operator bool() const {

			return (durability <= 0);
		}

		Arms Robot::getArms() const {

			return arms;
		}
		Legs Robot::getLegs() const {

			return legs;
		}

		Robot& Robot::operator-=(int minus) {


			durability -= minus;
			if (durability < 1) {
				
				durability = 0;
			}
			return *this;
		}
		
		void box(Robot& Robot1, Robot& Robot2)
		{
			cout << "Attempting to begin a Robot boxing match" << endl;


			if (Robot1.durability == 0 || Robot2.durability == 0)
			{
				cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
			}
			else
			{
				cout << "Both participants are operational... beginning the bout" << endl;
				while (Robot1.durability > 0 && Robot2.durability > 0)
				{
					if (Robot1.getLegs().getSpeed() > Robot2.getLegs().getSpeed())
					{
						Robot2 -= Robot1.getArms().getForce();
					}
					if (Robot2.durability > 0)
					{
						Robot1 -= Robot2.getArms().getForce();
					}
					else if (Robot2.getLegs().getSpeed() > Robot1.getLegs().getSpeed())
					{
						Robot1 -= Robot2.getArms().getForce();
					}
					if (Robot2.durability > 0)
					{
						Robot2 -= Robot1.getArms().getForce();
					}
					if (Robot1.durability > 0 && Robot2.durability > 0)
					{
						break;
					}
				}

				cout << "The bout has concluded... the winner is: " << endl;
				if (Robot1.durability > Robot2.durability) {
					Robot1.display();
				}
				else {
					Robot2.display();
				}

	
			}
		}

	}
	