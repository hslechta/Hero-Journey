/*
 * Shield.h
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#ifndef SHIELD_H_
#define SHIELD_H_

class Shield {
public:
	Shield();
	virtual ~Shield();

	// Shields will be used in future versions

	// Accessors
	int get_health() { return health_; };
	int get_block() { return block_; };

	// Mutators
	void set_health(int new_health) { health_ = new_health; };
	void set_block(int new_block) { block_ = new_block; };

private:
	// Qualities of all shields in the game
	int health_;
	int block_;
};

#endif /* SHIELD_H_ */
