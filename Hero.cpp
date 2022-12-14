/*
 * Hero.cpp
 *
 *  Created on: Sep 22, 2022
 *      Author: HMS
 */

#include <string>
#include "Hero.h"
using namespace std;

Hero::Hero() {
	// Initializes a place-holder hero for Version 0
	set_name("Hero");
	set_health(10);
	set_max_health(10);
	set_healing_factor(2);
	set_accuracy(50);
	set_dodge(20);
	set_stamina(10);
	set_max_stamina(10);
	set_hasShield(false);
}

Hero::~Hero() {
}

