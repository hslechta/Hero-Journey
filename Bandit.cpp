/*
 * Bandit.cpp
 *
 *  Created on: Oct 5, 2022
 *      Author: HMS
 */

#include "Bandit.h"
#include "Dagger.h"

Bandit::Bandit() {
	Dagger dagger;
	// Initializes a bandit enemy
	set_name("Bandit");
	// Health 10-20
	int randomizer = rand() % 100 + 1;
	int health = 10 + int (randomizer / 10);
	set_health(health);
	set_max_health(health);
	// Healing Factor 1-3
	randomizer = rand() % 100 + 1;
	set_healing_factor(1 + int (randomizer / 50));
	// Accuracy 60-70
	randomizer = rand() % 100 + 1;
	set_accuracy(60 + int (randomizer / 10));
	// Dodge 10-20
	randomizer = rand() % 100 + 1;
	set_dodge(10 + int (randomizer / 10));
	// Stamina 10-15
	randomizer = rand() % 100 + 1;
	int stamina = 10 + int (randomizer / 20);
	set_stamina(stamina);
	set_max_stamina(stamina);
	// Weapon Dagger
	set_weapon(dagger);
	// No Shield
	set_hasShield(false);
}

Bandit::~Bandit() {
}

