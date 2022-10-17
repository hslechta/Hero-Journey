/*
 * Exile.h
 *
 *  Created on: Oct 4, 2022
 *      Author: HMS
 */

#include "Hero.h"

#ifndef EXILE_H_
#define EXILE_H_

class Exile : public Hero {
public:
	Exile();
	virtual ~Exile();

	// Exiles will have additional abilities in future versions of this game
};

#endif /* EXILE_H_ */
