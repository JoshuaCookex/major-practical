#include "Terrain.h"
#include "Hunter.h"
#include "Savanna.h"
#include "Mountain.h"
#include "Jungle.h"
#include "Story.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

// This section is adding items to the Inventory
	Hunter *ItemFound;
	ItemFound = new Hunter();
	string * Inventory;
// End of Inventory section

	string choice, yes;

	cout << "Choose a desired location you wish to explore" << endl;
	cout << "Possible locations include: 'Mountain', 'Savanna' or 'Jungle'" << endl;
	cout << "Mountain includes a moderate story, Savanna includes a basic story and Jungle includes a detailed story" << endl;
	cout << "Choice: ";
	cin >> choice;

	Terrain* terra = new Terrain(choice);

	int rare1 = terra -> get_rarity();
	if (rare1 <= 3) {
		yes = "Common";
	} else if (rare1 == 6) {
		yes = "Exotic";
	} else {
		yes = "Rare";
	}

	cout << endl;
	cout << "The location you chose was: " << terra -> get_place() << endl;
	cout << "The rarity you are hunting is: " << yes << endl;
	cout << "You have "<< terra -> get_events() << " events to go through!" << endl;
	
	if (choice == "Mountain") 
	{
		Mountain* one = new Mountain(choice);
		cout << "You are looking for a: " << one -> get_animal(rare1) << endl;
		ItemFound -> AddItem("Slingshot");
		ItemFound -> AddItem("Rock");
		ItemFound -> AddItem("Fish");
		Inventory = ItemFound -> getItems();
		cout << endl;
		cout << "Items you can get include: ";
		for (int i = 0; i < (ItemFound -> getItemCount()); i++) {
			cout << Inventory[i] << " ";
		}
		cout << endl;

		Event one1;
		one1.Events();
		int score = one1.getScore();
		string AnimFound = one1.getAnim();
		if (score > 0) {
			if (AnimFound == one -> get_animal(rare1)) {
				cout << "You got your targeted animal!" << endl;
				score = score + 10;
			} else {
				cout << "You did not manage to get your targeted animal!" << endl;
			}
			cout << "Your score is: " << score << endl;
		} else {
			cout << "You have died, should've picked better choices" << endl;
			exit(0);
		}


		delete one;

	} else if (choice == "Jungle") 
	{
		Jungle* two = new Jungle(choice);
		cout << "You are looking for a: " << two -> get_animal(rare1) << endl;
		ItemFound -> AddItem("Machete");
		ItemFound -> AddItem("Bait");
		ItemFound -> AddItem("Rock");
		ItemFound -> AddItem("Rifle");
		ItemFound -> AddItem("Bullets");
		Inventory = ItemFound -> getItems();
		cout << endl;
		cout << "Items you can get include: ";
		for (int i = 0; i < (ItemFound -> getItemCount()); i++) {
			cout << Inventory[i] << " ";
		}
		cout << endl;

		Event2 two2;
		two2.Events();
		int score = two2.getScore();
		string AnimFound = two2.getAnim();
		if (score > 0) {
			if (AnimFound == two -> get_animal(rare1)) {
				cout << "You got your targeted animal!" << endl;
				score = score + 10;
			} else {
				cout << "You did not manage to get your targeted animal!" << endl;
			}
			cout << "Your final score is: " << score << endl;
		} else {
			cout << "You have died, should've picked better choices" << endl;
			exit(0);
		}


		delete two;

	} else if (choice == "Savanna") 
	{
		Savanna* three = new Savanna(choice);
		cout << "You are looking for a: " << three -> get_animal(rare1) << endl;
		ItemFound -> AddItem("Rifle");
		ItemFound -> AddItem("Spear");
		Inventory = ItemFound -> getItems();
		cout << endl;
		cout << "Items you can get include: ";
		for (int i = 0; i < (ItemFound -> getItemCount()); i++) {
			cout << Inventory[i] << " ";
		}
		cout << endl;

		Event3 three3;
		three3.Events();
		int score = three3.getScore();
		string AnimFound = three3.getAnim();
		if (score > 0) {
			if (AnimFound == three -> get_animal(rare1)) {
				cout << "You got your targeted animal!" << endl;
				score = score + 10;
			} else {
				cout << "You did not manage to get your targeted animal!" << endl;
			}
			cout << "Your score is: " << score << endl;
		} else {
			cout << "You have died, should've picked better choices" << endl;
			exit(0);
		}


		delete three;

	}

	delete terra;
	return 0;

}