/*
 * Person.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <iostream>
#include "Person.h"
using namespace std;

Person::Person() {
	// Initialize a generic person, just in case
	set_name("Person");
	set_health(1);
	set_max_health(1);
	set_healing_factor(1);
	set_accuracy(10);
	set_dodge(10);
	set_stamina(1);
	set_max_stamina(1);
	set_hasShield(false);
}

Person::~Person() {
}

// The standard attack method: a person attacks a targeted person with a weapon
int Person::BasicAttack(Person &target) {
	set_stamina(get_stamina() - 1);
	int accuracy_check = rand() % 100 + 1;

	// Check if the attacker is on-target with their attack
	if (accuracy_check <= get_accuracy()) {
		int dodge_check = rand() % 100 + 1;

		// Check if the target dodges the on-target attack
		if (dodge_check > target.get_dodge()) {
			int damage_dealt = rand() % get_weapon().get_damage() + 1;

			// Check if the target has a shield
			if (target.check_shield()) {
				Shield shield = target.get_shield();

				// Check if the shield blocks the damage of the attack
				if (shield.get_block() >= damage_dealt) {
					cout << target.get_name() << " has blocked " << get_name() << "'s attack with their shield." << endl << endl;
					return 0;
				}
				// The shield is damaged by the attack, blocking an amount up to its total health value
				else {
					shield.set_health(shield.get_health() - damage_dealt);

					// Check if the shield has been destroyed
					if (shield.get_health() <= 0) {
						damage_dealt = 0 - shield.get_health();  // Resets the damage value to the amount not blocked by the shield
						target.get_shield().~Shield();
						target.set_hasShield(false);
						cout << target.get_name() << "'s shield was destroyed." << endl;
						if (target.get_health() < damage_dealt) {
							damage_dealt = target.get_health();  // Resets the damage value to the amount of health the target had remaining
							target.set_health(0);
						}
						else {
							target.set_health(target.get_health() - damage_dealt);
						}
						cout << get_name() << " has dealt " << damage_dealt << " damage to " << target.get_name() << endl;
						cout << target.get_name() << " has " << target.get_health() << " health remaining." << endl << endl;
						return damage_dealt;
					}
					// Shield absorbs the full damage and survives the attack
					else {
						cout << target.get_name() << " blocked the attack with their shield." << endl;
						cout << target.get_name() << "'s shield has been damaged absorbing " << damage_dealt << " damage." << endl << endl;
						return 0;
					}
				}
			}
			// Target has no shield, so the attack hits the target
			else {
				if (target.get_health() < damage_dealt) {
					damage_dealt = target.get_health();  // Resets the damage value to the amount of health the target had remaining
					target.set_health(0);
				}
				else {
					target.set_health(target.get_health() - damage_dealt);
				}
				cout << get_name() << " has dealt " << damage_dealt << " damage to " << target.get_name() << endl;
				cout << target.get_name() << " has " << target.get_health() << " health remaining." << endl << endl;
				return damage_dealt;
			}
		}
		// Target managed to dodge the attack
		else {
			cout << target.get_name() << " has dodged " << get_name() << "'s attack." << endl << endl;
			return 0;
		}
	}
	// Attacker was unable to strike on-target
	cout << get_name() << " has missed with their attack." << endl << endl;
	return 0;
}

void Person::Meditate() {
	// Performs the meditate action, restoring health
	set_stamina(get_stamina() - 2);
	int restored_health = get_health() + get_healing_factor();
	if (restored_health <= get_max_health()) {
		cout << get_name() << " has healed " << get_healing_factor() << " health." << endl;
		set_health(restored_health);
		cout << get_name() << " has " << get_health() << " health remaining." << endl << endl;
	}
	else {
		cout << get_name() << " has healed " << (get_max_health() - get_health()) << " health." << endl;
		set_health(get_max_health());
		cout << get_name() << " has " << get_health() << " health remaining." << endl << endl;
	}
}

void Person::Rest() {
	// Performs the rest action, restoring stamina
	set_stamina(get_max_stamina());
	cout << get_name() << " has rested and regained their stamina of " << get_max_stamina() << endl << endl;
}

void Person::Display() {
	// Displays the stats of a character
	cout << "Name: " << get_name() << endl;
	cout << "Accuracy: " << get_accuracy() << endl;
	cout << "Dodge: " << get_dodge() << endl;
	cout << "Health: " << get_health() << endl;
	cout << "Healing Factor: " << get_healing_factor() << endl;
	cout << "Stamina: " << get_stamina() << endl;
	cout << endl << "Weapon: " << endl;
	get_weapon().Display();
	if (check_shield()) {
		cout << endl << "Shield: " << endl;
		get_shield().Display();
	}
}
