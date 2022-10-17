/*
 * Stick.cpp
 *
 *  Created on: Oct 4, 2022
 *      Author: HMS
 */

#include "Stick.h"

Stick::Stick() {
	// Initializes the stick, a very basic type of weapon
	set_name("Large Stick");
	// Damage 2-4
	int randomizer = rand() % 100 + 1;
	set_damage(2 + int (randomizer / 50));
	set_range(1);
	set_health(5);
}

Stick::~Stick() {
}

