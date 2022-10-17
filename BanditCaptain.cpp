/*
 * BanditCaptain.cpp
 *
 *  Created on: Oct 12, 2022
 *      Author: HMS
 */

#include "BanditCaptain.h"
#include "Shortsword.h"

BanditCaptain::BanditCaptain() {
	Shortsword shortsword;
	// Initializes a bandit captain enemy
	set_name("Bandit Captain");
	// Health 15-25
	int randomizer = rand() % 100 + 1;
	int health = 15 + int (randomizer / 10);
	set_health(health);
	set_max_health(health);
	// Healing Factor 2-4
	randomizer = rand() % 100 + 1;
	set_healing_factor(2 + int (randomizer / 50));
	// Accuracy 90-100
	randomizer = rand() % 100 + 1;
	set_accuracy(90 + int (randomizer / 10));
	// Dodge 10-20
	randomizer = rand() % 100 + 1;
	set_dodge(10 + int (randomizer / 10));
	// Stamina 15-20
	randomizer = rand() % 100 + 1;
	int stamina = 15 + int (randomizer / 20);
	set_stamina(stamina);
	set_max_stamina(stamina);
	// Weapon Shortsword
	set_weapon(shortsword);
	// No Shield
	set_hasShield(false);
}

BanditCaptain::~BanditCaptain() {
}

