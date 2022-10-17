/*
 * Enemy.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <string>
#include "Enemy.h"
using namespace std;

Enemy::Enemy() {
	// Initializes a placeholder Enemy for Version 0
	set_name("Enemy");
	set_health(10);
	set_max_health(10);
	set_healing_factor(2);
	set_accuracy(20);
	set_dodge(10);
	set_stamina(5);
	set_max_stamina(5);
	set_hasShield(false);
}

Enemy::~Enemy() {
}

