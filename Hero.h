/*
 * Hero.h
 *
 *  Created on: Sep 22, 2022
 *      Author: HMS
 */

#include "Person.h"

#ifndef HERO_H_
#define HERO_H_

class Hero : public Person {
public:
	Hero();
	virtual ~Hero();

	// Heroes will have extra abilities that Enemies do not have in future versions of this game
};

#endif /* HERO_H_ */
