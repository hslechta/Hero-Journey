/*
 * Enemy.h
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include "Person.h"

#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy : public Person {
public:
	Enemy();
	virtual ~Enemy();

	// In future versions of this game, Enemies will have additional abilities that Heroes do not have
};

#endif /* ENEMY_H_ */
