/*
 * Shield.h
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <string>

#ifndef SHIELD_H_
#define SHIELD_H_

class Shield {
public:
	Shield();
	virtual ~Shield();

	// Shields will be used in future versions

	// Accessors
	std::string get_name() { return name_; };
	int get_health() { return health_; };
	int get_block() { return block_; };

	// Mutators
	void set_name(std::string new_name) { name_ = new_name; };
	void set_health(int new_health) { health_ = new_health; };
	void set_block(int new_block) { block_ = new_block; };

	void Display();

private:
	// Qualities of all shields in the game
	std::string name_;
	int health_;
	int block_;
};

#endif /* SHIELD_H_ */
