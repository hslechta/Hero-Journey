/*
 * Weapon.h
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <string>

#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon {
public:
	Weapon();
	virtual ~Weapon();

	// Accessors
	std::string get_name() { return name_; };
	int get_damage() { return damage_; };
	int get_range() { return range_; };
	int get_health() { return health_; };

	// Mutators
	void set_name(std::string new_name) { name_ = new_name; };
	void set_damage(int new_damage) { damage_ = new_damage; };
	void set_range(int new_range) { range_ = new_range; };
	void set_health(int new_health) { health_ = new_health; };

	void Display();

private:
	// Qualities of all weapons in the game
	std::string name_;
	int damage_;
	int range_;
	int health_;
};

#endif /* WEAPON_H_ */
