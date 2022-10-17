/*
 * Person.h
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <string>
#include "Weapon.h"
#include "Shield.h"

#ifndef PERSON_H_
#define PERSON_H_

class Person {
public:
	Person();
	virtual ~Person();

	// Accessors
	std::string get_name() { return name_; };
	int get_health() { return health_; };
	int get_max_health() { return max_health_; };
	int get_healing_factor() { return healing_factor_; };
	int get_accuracy() { return accuracy_; };
	int get_dodge() { return dodge_; };
	int get_stamina() { return stamina_; };
	int get_max_stamina() { return max_stamina_; };
	Weapon get_weapon() { return weapon_; };
	bool check_shield() { return hasShield_; };
	Shield get_shield() { return shield_; };

	// Mutators
	void set_name(std::string new_name) { name_ = new_name; };
	void set_health(int new_health) { health_ = new_health; };
	void set_max_health(int new_max_health) { max_health_ = new_max_health; };
	void set_healing_factor(int new_healing_factor) { healing_factor_ = new_healing_factor; };
	void set_accuracy(int new_accuracy) { accuracy_ = new_accuracy; };
	void set_dodge(int new_dodge) { dodge_ = new_dodge; };
	void set_stamina(int new_stamina) { stamina_ = new_stamina; };
	void set_max_stamina(int new_max_stamina) { max_stamina_ = new_max_stamina; };
	void set_weapon(Weapon new_weapon) { weapon_ = new_weapon; };
	void set_hasShield(bool veracity) { hasShield_ = veracity; };
	void set_shield(Shield new_shield) { shield_ = new_shield; hasShield_ = true; };

	// Methods
	int BasicAttack(Person &target);
	void Meditate();
	void Rest();
	void Display();

	// Generic qualities of all people in the game
private:
	std::string name_;
	int health_;
	int max_health_;
	int healing_factor_;
	int accuracy_;
	int dodge_;
	int stamina_;
	int max_stamina_;
	Weapon weapon_;
	bool hasShield_;
	Shield shield_;
};

#endif /* PERSON_H_ */
