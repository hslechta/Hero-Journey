/*
 * Weapon.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon() {
	// Initializes a placeholder weapon for Version 0
	set_name("Weapon");
	set_damage(2);
	set_range(2);
	set_health(10);
}

Weapon::~Weapon() {
}

void Weapon::Display() {
	// Displays the stats of a weapon
	cout << "Name: " << get_name() << endl;
	cout << "Damage: " << get_damage() << endl;
	cout << "Range: " << get_range() << endl;
	cout << "Health: " << get_health() << endl << endl;
}

