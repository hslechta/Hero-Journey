/*
 * Shield.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include "Shield.h"
#include <iostream>
using namespace std;

Shield::Shield() {
	// Initializes a placeholder shield, just in case
	set_name("Shield");
	set_health(1);
	set_block(1);
}

Shield::~Shield() {
}

void Shield::Display() {
	// Displays the stats of a shield
	cout << "Name: " << get_name() << endl;
	cout << "Health: " << get_health() << endl;
	cout << "Block: " << get_block() << endl << endl;
}

