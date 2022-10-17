/*
 * Shortsword.cpp
 *
 *  Created on: Oct 12, 2022
 *      Author: HMS
 */

#include "Shortsword.h"

Shortsword::Shortsword() {
	// Initializes the shortsword
	set_name("Shortsword");
	// Damage 4-6
	int randomizer = rand() % 100 + 1;
	set_damage(4 + int (randomizer / 50));
	set_range(1);
	set_health(5);
}

Shortsword::~Shortsword() {
}

