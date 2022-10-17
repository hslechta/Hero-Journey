/*
 * Exile.cpp
 *
 *  Created on: Oct 4, 2022
 *      Author: HMS
 */

#include "Exile.h"
#include "Stick.h"
#include <string>
using namespace std;

Exile::Exile() {
	// Initializes an exile character (the standard player-character in Version 1)
	Stick stick;
	// Name randomization
	int randomizer = rand() % 100 + 1;
	if (randomizer < 20) {
		set_name("George");
	}
	else if (randomizer < 40) {
		set_name("Lucas");
	}
	else if (randomizer < 60) {
		set_name("John");
	}
	else if (randomizer < 70) {
		set_name("David");
	}
	else if (randomizer < 80) {
		set_name("Tom");
	}
	else if (randomizer < 90) {
		set_name("William");
	}
	else if (randomizer < 95) {
		set_name("Richard");
	}
	else {
		set_name("Fredrick");
	}
	// Health 10-20
	randomizer = rand() % 100 + 1;
	int health = 10 + int (randomizer / 10);
	set_health(health);
	set_max_health(health);
	// Healing Factor 2-4
	randomizer = rand() % 100 + 1;
	set_healing_factor(2 + int (randomizer / 50));
	// Accuracy 70-80
	randomizer = rand() % 100 + 1;
	set_accuracy(70 + int (randomizer / 10));
	// Dodge 25-35
	randomizer = rand() % 100 + 1;
	set_dodge(25 + int (randomizer / 10));
	// Stamina 10-20
	randomizer = rand() % 100 + 1;
	int stamina = 10 + int (randomizer / 10);
	set_stamina(stamina);
	set_max_stamina(stamina);
	// Weapon Large Stick
	set_weapon(stick);
	// No Shield
	set_hasShield(false);
}

Exile::~Exile() {
}

