/*
 * TestModule.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: HMS
 */

#include <iostream>
#include "Hero.h"
#include "Enemy.h"
#include "Person.h"
using namespace std;


// Test 1

/* Test which checks the shield mechanics of combat.
 *
 * RunCombat and main of GameRunner must be commented out when running this test.
 * To run this test, delete the slash and asterisk at the beginning of RunCombat and the end of main.
 */

/*int RunCombat(Person &player, Person &npc) {
	int counter = 0;
	while (player.get_health() > 0 && npc.get_health() > 0) {
		counter++;
		player.BasicAttack(npc);
		if (npc.get_health() <= 0) {
			cout << "Enemy has died. Congratulations!" << endl;
			cout << "It took " << counter << " turns to win." << endl;
			return counter;
		}
		npc.BasicAttack(player);
		if (player.get_health() <= 0) {
			cout << "You have died. Better luck next time." << endl;
			cout << "It took " << counter << " turns to lose." << endl;
			return counter;
		}
	}
	return counter;
}

int main() {
	Hero protag;
	Enemy enem;
	Shield shield;
	srand(time(NULL));

	protag.set_shield(shield);
	enem.set_shield(shield);
	RunCombat(protag, enem);
}*/


// Test 2

/* Test which checks that random number generation is creating correct percentages.
 *
 * RunCombat and main of GameRunner must be commented out when running this test.
 * To run this test, delete the slash and asterisk at the beginning of RunCombat and the end of main.
 */

/*int RunCombat(Person &player, Person &npc) {
	int counter = 0;
	while (player.get_health() > 0 && npc.get_health() > 0) {
		counter++;
		player.BasicAttack(npc);
		if (npc.get_health() <= 0) {
			cout << "Enemy has died. Congratulations!" << endl;
			cout << "It took " << counter << " turns to win." << endl;
			return counter;
		}
		npc.BasicAttack(player);
		if (player.get_health() <= 0) {
			cout << "You have died. Better luck next time." << endl;
			cout << "It took " << counter << " turns to lose." << endl;
			return counter;
		}
	}
	return counter;
}

int main() {
	int hero_wins = 0;
	int enemy_wins = 0;
	int hero_hits = 0;
	int enemy_hits = 0;
	int total_rounds = 0;
	double hero_hit_percent;
	double enemy_hit_percent;
	srand(time(NULL));

	for (int counter = 0; counter < 10000; counter++) {
		Hero protag;
		Enemy enem;
		total_rounds += RunCombat(protag, enem);

		if (protag.get_health() <= 0) {
			enemy_wins += 1;
			enemy_hits += protag.get_max_health();
			hero_hits += (enem.get_max_health() - enem.get_health());
		}
		if (enem.get_health() <= 0) {
			hero_wins += 1;
			hero_hits += enem.get_max_health();
			enemy_hits += (protag.get_max_health() - protag.get_health());
		}
	}

	hero_hit_percent = 100 * hero_hits / total_rounds;
	enemy_hit_percent = 100 * enemy_hits / total_rounds;


	cout << endl << "Total rounds: " << total_rounds << endl;
	cout << "Hero won " << hero_wins << " rounds." << endl;
	cout << "Enemy won " << enemy_wins << " rounds." << endl;
	cout << "Hero's hit percentage: " << hero_hit_percent << "%." << endl;
	cout << "Enemy's hit percentage: " << enemy_hit_percent << "%." << endl;
}*/


