/*
 * GameRunner.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <iostream>
#include <string>
#include "Hero.h"
#include "Weapon.h"
#include "Enemy.h"
using namespace std;

// Introduction printed at the beginning of the game
void ShowIntro() {
	cout << "Welcome to Hero's Journey!" << endl;
	cout << "In version 0 of this fantasy role-playing game, you will be playing as a generic hero, and you will fight a single generic enemy." << endl;
	cout << "Good luck!" << endl << endl;
}

// Placeholder function that handles combat in Version 0
void RunCombat(Person &player, Person &npc) {
	int counter = 0;
	// Run until player or enemy dies
	while (player.get_health() > 0 && npc.get_health() > 0) {
		counter++;
		// Player attacks the enemy
		player.BasicAttack(npc);
		// If the enemy is dead, display winner text
		if (npc.get_health() <= 0) {
			cout << "Enemy has died. Congratulations!" << endl;
			cout << "It took " << counter << " turns to win." << endl;
			break;
		}
		// If the player is dead, display loser text
		npc.BasicAttack(player);
		if (player.get_health() <= 0) {
			cout << "You have died. Better luck next time." << endl;
			cout << "It took " << counter << " turns to lose." << endl;
			break;
		}
	}
}

// Main initializes a hero, an enemy, sets the seed for the random number generators, and then calls the necessary functions
int main() {
	Hero protag;
	Enemy enem;
	srand(time(NULL));

	ShowIntro();
	RunCombat(protag, enem);
}


