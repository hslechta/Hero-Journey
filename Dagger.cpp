/*
 * Dagger.cpp
 *
 *  Created on: Oct 12, 2022
 *      Author: HMS
 */

#include "Dagger.h"

Dagger::Dagger() {
	// Initializes the dagger
	set_name("Dagger");
	// Damage 3-5
	int randomizer = rand() % 100 + 1;
	set_damage(3 + int (randomizer / 50));
	set_range(1);
	set_health(5);
}

Dagger::~Dagger() {
}

