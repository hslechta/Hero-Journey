/*
 * Weapon.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include "Weapon.h"

Weapon::Weapon() {
	// Initializes a placeholder weapon for Version 0
	set_damage(1);
	set_range(1);
	set_health(5);
}

Weapon::~Weapon() {
}

