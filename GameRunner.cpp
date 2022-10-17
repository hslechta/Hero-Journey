/*
 * GameRunner.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: HMS
 */

#include <iostream>
#include <string>
#include "Hero.h"
#include "Exile.h"
#include "Bandit.h"
#include "BanditCaptain.h"
#include "Weapon.h"
using namespace std;

// Introduction printed at the beginning of the game
void ShowIntro() {
	cout << "Welcome to Hero's Journey!" << endl;
	cout << "In version 1 of this fantasy role-playing game, you will be playing as an exiled hero, and you will fight five bandits and their bandit captain." << endl;
	cout << "You have been exiled from your home kingdom. You've moved into the woods, and you are attacking a bandit camp to try to regain your king's favor." << endl;
	cout << "Good luck!" << endl << endl;
}

// Displays if the player wins the game
void WinnerText(Person &player) {
	cout << "Congratulations! You have cleared the bandit's camp, and your king will reinstate you in his guard." << endl;
	cout << "Here is how you looked at the end: " << endl << endl;
	player.Display();
	cout << "See you next time!" << endl;
}

// Displays if the player loses the game
void LoserText(Person &player) {
	cout << "Too bad! You have failed to clear the bandit camp, and your king will forget you ever existed." << endl;
	cout << "Here is how you looked at the end: " << endl << endl;
	player.Display();
	cout << "Better luck next time!" << endl;
}

// Offers the player the choice of three characters
Hero ChooseHero() {
	Exile choice_one;
	Exile choice_two;
	Exile choice_three;
	int selection;
	cout << "You have three choices:" << endl << endl;
	cout << "Option 1: " << endl;
	choice_one.Display();
	cout << "Option 2: " << endl;
	choice_two.Display();
	cout << "Option 3: " << endl;
	choice_three.Display();
	cout << "Enter the number of the hero you'd like to choose: " << endl;
	cin >> selection;
	cout << endl;
	while (selection != 1 && selection != 2 && selection != 3) {
		cout << "That is not a valid response. Enter 1 for Option 1, 2 for Option 2, or 3 for Option 3." << endl;
		cin >> selection;
		cout << endl;
	}
	if (selection == 1) {
		return choice_one;
	}
	else if (selection == 2) {
		return choice_two;
	}
	else {
		return choice_three;
	}
}

// Shows the menu that the player uses for general purposes
int GeneralMenu() {
	int choice;
	cout << "Enter 1 to attack the nearest enemy." << endl;
	cout << "Enter 2 to prepare for a future attack." << endl;
	cin >> choice;
	cout << endl;
	return choice;
}

// Generates the next enemy to be fought (placeholder for Version 1)
Enemy ChooseEnemy() {
	Bandit bandit;
	cout << "Here is the enemy that you are about to fight: " << endl << endl;
	bandit.Display();
	return bandit;
}

// Shows the menu that the player uses on their turn
int TurnMenu(Person &player) {
	int choice;
	cout << "It is your turn." << endl;
	cout << "Here are your stats:" << endl << endl;
	player.Display();
	cout << "Enter 1 to attack. Stamina -1." << endl;
	cout << "Enter 2 to meditate. Stamina -2. (Restores health)" << endl;
	cout << "Enter 3 to rest. (Restores stamina)" << endl;
	cin >> choice;
	cout << endl;
	return choice;
}

// Combat function
void RunCombat(Person &player, bool &alive) {
	Enemy enem = ChooseEnemy();
	while (player.get_health() > 0 && enem.get_health() > 0) {
		// Player's turn in combat
		int turn_choice = TurnMenu(player);
		if (turn_choice == 1 && player.get_stamina() >= 1) {
			player.BasicAttack(enem);
			if (enem.get_health() <= 0) {
				cout << "You have killed this enemy." << endl << endl;
				break;
			}
		}
		else if (turn_choice == 2 && player.get_stamina() >= 2) {
			player.Meditate();
		}
		else if (turn_choice == 3) {
			player.Rest();
		}
		else {
			cout << "Your stamina is too low to perform that action. You will automatically rest this turn." << endl << endl;
			player.Rest();
		}
		// Enemy's turn in combat
		// Enemy meditates if they have been reduced to 1/10 of their max health
		if (enem.get_health() <= int(enem.get_max_health() / 10) && enem.get_stamina() >= 2) {
			enem.Meditate();
		}
		// If enemy's health is at least 1/10 of their max health and they have at least 1 stamina, they attack
		else if (enem.get_stamina() >= 1) {
			enem.BasicAttack(player);
		}
		// If enemy's stamina is at 0, they rest
		else {
			enem.Rest();
		}
		if (player.get_health() <= 0) {
			cout << "You have been killed." << endl << endl;
			LoserText(player);
			alive = false;
			break;
		}
	}
}

// Shows the menu that the player uses before the final boss
int FinalMenu() {
	int choice;
	cout << "Congratulations! You've made it to the captain of the bandits." << endl << endl;
	cout << "Enter 1 to attack." << endl;
	cout << "Enter 2 to prepare." << endl;
	cin >> choice;
	cout << endl;
	return choice;
}

// Initializes the final boss
Enemy SetBoss() {
	BanditCaptain enem;
	cout << "Here is the bandit captain that you are about to fight: " << endl << endl;
	enem.Display();
	return enem;
}

// Final boss combat function
void RunFinalCombat(Person &player, bool &alive) {
	Enemy enem = SetBoss();
	while (player.get_health() > 0 && enem.get_health() > 0) {
		// Player's turn in combat
		int turn_choice = TurnMenu(player);
		if (turn_choice == 1 && player.get_stamina() >= 1) {
			player.BasicAttack(enem);
			if (enem.get_health() <= 0) {
				cout << "You have killed the bandit captain!" << endl << endl;
				WinnerText(player);
				break;
			}
		}
		else if (turn_choice == 2 && player.get_stamina() >= 2) {
			player.Meditate();
		}
		else if (turn_choice == 3) {
			player.Rest();
		}
		else {
			cout << "Your stamina is too low to perform that action. You will automatically rest this turn." << endl << endl;
			player.Rest();
		}
		// Enemy's turn in combat
		// Enemy meditates if they have been reduced to 1/10 of their max health
		if (enem.get_health() <= int(enem.get_max_health() / 10) && enem.get_stamina() >= 2) {
			enem.Meditate();
		}
		// If enemy's health is at least 1/10 of their max health and they have at least 1 stamina, they attack
		else if (enem.get_stamina() >= 1) {
			enem.BasicAttack(player);
		}
		// If enemy's stamina is at 0, they rest
		else {
			enem.Rest();
		}
		if (player.get_health() <= 0) {
			cout << "You have been killed." << endl;
			LoserText(player);
			alive = false;
			break;
		}
	}
}

// Main sets the seed for the random number generators, and then calls the necessary functions to run the game
int main() {
	srand(time(NULL));
	bool alive = true;

	ShowIntro();
	Hero player = ChooseHero();
	int counter = 0;
	while (alive) {
		// Player chooses where to move, whom to engage, etc.
		int choice = GeneralMenu();
		if (choice == 1) {
			// Starts the combat mechanic
			RunCombat(player, alive);
			if (alive) {
				counter += 1;
			}
		}
		else {
			// In Version 1, this option merely serves to delay combat
			int placeholder = 0;
			while (placeholder != 1) {
				cout << "Enter 1 when ready to return to the menu." << endl;
				cin >> placeholder;
				cout << endl;
			}
		}
		if (counter == 5) {
			while (counter == 5) {
				int final_choice = FinalMenu();
				if (final_choice == 1) {
					// Starts the final boss combat mechanic
					RunFinalCombat(player, alive);
					break;
				}
				else {
					// In Version 1, this option merely serves to delay combat
					int placeholder = 0;
					while (placeholder != 1) {
						cout << "Enter 1 when ready to return to the menu." << endl;
						cin >> placeholder;
						cout << endl;
					}
				}
			}
			break;
		}
	}
}


