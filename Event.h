#ifndef EVENT_H
#define EVENT_H
#include "Story.h"
using namespace std;
#include <iostream>

string choice1, choice2, choice3, MinorChoice1, MinorChoice2;
string Discovery;
class Event : public Story {

public:
// This is the Events for the Mountain
	void Events(){ 
		cout << "You see some trees and a small lake. Which way do you want to go?" << endl;
		cout << "Trees/Lake"<<endl;
		cin >> choice1;
		if (choice1 == "Trees") {
			score = score + 2;
			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << "Do you want to climb a tree to get a better view?" << endl;
			cout << "Yes/No" << endl;
			cin >> MinorChoice1;

			if (MinorChoice1 == "Yes") {
				score = 0;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				cout << "You grabbed a broken branch and fell!" << endl;
				Discovery = "Nothing";
			}
			else if (MinorChoice1 == "No") {
				score++;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				cout << "You have found a SLINGSHOT!" << endl;
				cout << "You hear a small growl to your left and a small river to you right. Where do you go?" << endl;
				cout << "Left/Right" << endl;
				cin >> choice2;

				if (choice2 == "Left") {
					score++;
					cout << "You head to the noise and come across a fox" << endl;
					cout << "You got a Fox using your SLINGSHOT" << endl;
					Discovery = "Fox";
				}
				else if (choice2 == "Right") {
					score++;
					cout << "You follow the river down until you hit a waterfall and a large river. Do you wait or try to cross?" << endl;
					cout << "Wait/Cross" << endl;
					cin >> choice3;

					if (choice3 == "Wait") {
						score = score + 3;
						cout << "---------------------------------------------------------------------------------------" << endl;
						cout << "You wait and see a bear, you use your SLINGSHOT" << endl;
						cout << "You got a Bear using your SLINGSHOT" << endl;
						Discovery = "Bear";
					}
					else if (choice3 == "Cross") {
						score--;
						cout << "---------------------------------------------------------------------------------------" << endl;
						cout << "You attempt to cross and fall in, you get taken out of the mountains" << endl;
						cout << "You didn't get anything" << endl;
						Discovery = "Nothing";
					}
				}
			}	
		}
		else if (choice1 == "Lake") {
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "You have found a large ROCK and a FISH!" << endl;
			score++;
			cout << "Do want to use the FISH as bait?" << endl;
			cout << "Yes/No" << endl;
			cin >> choice2;

			if (choice2 == "Yes") {
				score++;
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << "You heard a noise. Its an Eagle! Do you want to use your ROCK?" << endl;
				cout << "Yes/No" << endl;
				cin >> choice3;

				if (choice3 == "Yes") {
					score = score + 2;
					cout << "You manage to take down this eagle with your ROCK" << endl;
					cout << "You got a Eagle" << endl;
					Discovery = "Eagle";
				}
				else if (choice3 == "No") {
					score--;
					cout << "You missed your chance!" << endl;
					Discovery = "Nothing";
				}
			}
			else if (choice2 == "No") {
				score = 0;
				cout << "The smell attracted a crocodile, it attacked you!" << endl;
				Discovery = "Nothing";
			}
		}
	}
	int getScore() {
		return score;
	}
	string getAnim() {
		return Discovery;
	}
};



class Event2 : public Story{
public:
// This is the Events for the Jungle
	void Events(){
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << "You reach the edge of a vast jungle and see to your left, a flowing river heading deeper into the jungle, and to your right, a trail leading along the edge. Where do you go?" << endl;
		cout << "Left/Right: " << endl;
		cin >> choice1;

		if (choice1 == "Left") {
			score++;
			cout << endl;
			cout << "Do you walk through the water? Or along the edge of the river?" << endl;
			cout << "Through/Along: " << endl;
			cin >> MinorChoice1;

			if (MinorChoice1 == "Through") {
				score++;
				cout << endl;
				cout << "Good choice! As a hunter, masking your own footsteps and smell will make it easier to hunt your target!" << endl;
				cout << "------------------------------------------------------------------------------------------" << endl;
				cout << "You reach a impass along the river and on your right, you see a very dense section of the jungle, and straight ahead of you, you see a marsh full of willows and vines. Where do you go?" << endl;
				cout << "Right/Straight: " << endl;
				cin >> choice2;

				if (choice2 == "Right") {
					score++;
					cout << endl;
					cout << "Do you search around the area or dive straight through the growth?" << endl;
					cout << "Search/Dive: " << endl;
					cin >> MinorChoice2;

					if (MinorChoice2 == "Search") {
						score++;
						cout << endl;
						cout << "You find a MACHETE, you can now cut through the dense growth" << endl;
						// Add MACHETE To Inventory Possibly?
						cout << "------------------------------------------------------------------------------------------------" << endl;
						cout << "Do you study the growth or just start making your way through?" << endl;
						cout << "Study/Move" << endl;
						cin >> choice3;

						if (choice3 == "Study") {
							score++;
							cout << endl;
							cout << "As you look closer at this growth, you find a snake sitting above, you manage to defeat it using the machete you were going to use on the growth" << endl;
							cout << "You got a snake!" << endl;
							Discovery = "Snake";
						} 

						else if (choice3 == "Move") {
							score--;
							cout << endl;
							cout << "You hack at the growth, causing a snake to slither further into the jungle and out of your sights" << endl;
							cout << "You got nothing! You leave without a catch" << endl;
							Discovery = "Nothing";
						}
					} 

					else if (MinorChoice2 == "Dive") {
						cout << endl;
						cout << "As you dive into the dense growth, you get stuck within it, as a snake appears out of sight and bites you" << endl;
						cout << "This snakes venom is very lethal to humans" << endl;
						Discovery = "Nothing";
						score = 0;
					}
				} 

				else if (choice2 == "Straight") {
					score++;
					cout << endl;
					cout << "You start to travel through the marsh until you come across much deeper water as well as a snake, sitting well above you on top of a willow tree. What do you do?" << endl;
					cout << "Snake/Water" << endl;
					cin >> choice3;

					if (choice3 == "Snake") {
						score++;
						cout << "---------------------------------------------------------------------------------------------------------------" << endl;
						cout << "You try to figure out a way to get to the snake, but instead find some BAIT" << endl;
						//Add BAIT To Inventory Possibly?
						cout << "Do you wish to continue trying to get to the snake, or go to the water and use the BAIT?" << endl;
						cout << "Snake/Water" << endl;
						cin >> MinorChoice2;

						if (MinorChoice2 == "Snake") {
							score = score - 2;
							cout << "You grab at a branch and the snake attacks you" << endl;
							cout << "-----------------------------------------------------------------------------------------------" << endl;
							cout << "You leave the Jungle to tend to your wound and rush to a hospital" << endl;
							Discovery = "Nothing";
						}

						else if (MinorChoice2 == "Water") {
							score = score + 2;
							cout << "You place the bait and wait for a catch" << endl;
							cout << "------------------------------------------------------------------------------------------------" << endl;
							cout << "Piranhas proceed to attack your bait and you manage to catch one" << endl;
							cout << "You got a piranha!" << endl;
							Discovery = "Piranha";
						}
					}

					else if (choice3 == "Water") {
						score = 0;
						cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "You proceed to the waters edge and slip on some moss covered rocks and fall into the water" << endl;
						cout << "You fumble around in the water for some time causing piranhas to attack you" << endl;
						Discovery = "Nothing";
					}
				}
			} 

			else if (MinorChoice1 == "Along") {
				score--;
				cout << "This is a bad choice! As a hunter, masking your own footsteps and smell will make it easier to hunt your target!" << endl;
				cout << "------------------------------------------------------------------------------------------" << endl;
				cout << "As you proceed along the side of the river, your smell is picked up by the wind" << endl;
				cout << "A couger attacks you as you pass its territory" << endl;
				cout << "You manage to fend it off and run from the Jungle" << endl;
				Discovery = "Nothing";
			}
		}

		if (choice1 == "Right") {
			score++;
			cout << "----------------------------------------------------------------------------------------" << endl;
			cout << "You proceed down the path and travel a fair distance around the Jungle where you come across a clearing on your left and a cave straight ahead" << endl;
			cout << "Do you go into the clearing or proceed further ahead towards the cave?" << endl;
			cout << "Left/Straight" << endl;
			cin >> MinorChoice1;

			if (MinorChoice1 == "Left") {
				score++;
				cout << "You head into the clearing and notice movement further in the clearing, however you can't make out what it is as it is fairly small" << endl;
				cout << "Do you wish to search for it or do you want to keep going through the clearing, away from whatever it was?" << endl;
				cout << "Search/Continue" << endl;
				cin >> choice2;

				if (choice2 == "Search") {
					score++;
					cout << "----------------------------------------------------------------------------------------------" << endl;
					cout << "You explore the clearing and soon spot the animal which you saw, it was a snake" << endl;
					cout << "You can either try and catch it or search around for anything you can use against it" << endl;
					cout << "Catch/Search" << endl;
					cin >> MinorChoice2;

					if (MinorChoice2 == "Catch") {
						cout << "You attempt to catch the snake and get bitten by the snake as it defends itself" << endl;
						cout << "This snake was heavily venomous and is lethal to humans" << endl;
						score = 0;
						Discovery = "Nothing";
					}

					else if (MinorChoice2 == "Search") {
						score++;
						cout << "You search the area around you and come across a fairly hefty ROCK" << endl;
						//Add ROCK To Inventory Possibly?
						cout << "You use the newly aquired ROCK to attack the snake, allowing you to succeed in keeping your hands safe" << endl;
						cout << "You got a snake!" << endl;
						Discovery = "Snake";
					}
				}

				else if (choice2 == "Continue") {
					score--;
					cout << "------------------------------------------------------------------------------------------------------" << endl;
					cout << "You attempt to continue through the clearing, steering clear of the figure you saw and end up becoming too preoccupied" << endl;
					cout << "You end up tripping over another snake and land next to it, as it slithers towards you, you pick up a ROCK next to you" << endl;
					//Add ROCK To Inventory Possibly?
					cout << "Do you run away, or fight?" << endl;
					cout << "Run/Fight" << endl;
					cin >> MinorChoice2;

					if (MinorChoice2 == "Run") {
						cout << endl;
						score++;
						cout << "You attempt to get up and run, and succeed to do so as the snake continues towards you, you escape" << endl;
						cout << "You have however sprained your ankle as you tripped over the snake so suddenly and cannot continue" << endl;
						Discovery = "Nothing";
					}

					else if (MinorChoice2 == "Fight") {
						cout << endl;
						score = 0;
						cout << "You try to fight off the snake as it gets closer, however as you are on the ground, the snake manages to get close enough to bite you" << endl;
						cout << "This snake was heavily venomous and lethal to humans" << endl;
						Discovery = "Nothing";
					}
				}
			}

			else if (MinorChoice1 == "Straight") {
				score++;
				cout << "You head towards the cave and notice a small hand-made shack next to the entrace of the cave, it seems beatan and scratched" << endl;
				cout << "Do you want to search the shack or proceed into the cave" << endl;
				cout << "Shack/Cave" << endl;
				cin >> choice2;

				if (choice2 == "Shack") {
					score = score + 2;
					cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "You study the shack closely as well as search the insides and come across a RIFLE and some BULLETS, as well as notice heavy scratch marks, possibly from a form of cat" << endl;
					//Add RIFLE and BULLETS To Inventory Possibly;
					cout << "You grab the gear and head inside the cave, being more subtle and quite as you have a faint idea of what animal lies within" << endl;
					cout << "The cave is fairly lit up suprisingly and you think you may be able to continue without the need of a light source, What do you do?" << endl;
					cout << "Continue/Wait" << endl;
					cin >> MinorChoice2;

					if (MinorChoice2 == "Continue") {
						score--;
						cout << "You continue further into the cave and the light starts to dim, you also hear a subtle growl coming from behind you as you see a couger waiting for you" << endl;
						cout << "The light coming from behind the couger and the entrance to the cave, managing to somewhat obscure your vision" << endl;
						cout << "Do you want to try and kill the cougar or escape" << endl;
						cout << "Fight/Esccape" << endl;
						cin >> choice3;

						if (choice3 == "Fight") {
							score++;
							cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "You fire an inaccurate shot at the cougar which manages to scrape past its face, as you fire this bullet, you use this time to get around it" << endl;
							cout << "You managed to still escape despite the bad spot and the light almost blinding you, but you didn't run and still attempted to fight" << endl;
							cout << "You didn't get the animal, however you did escape with your dignity" << endl;
							Discovery = "Nothing";
						}

						else if (choice3 == "Escape") {
							score = 0;
							cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "You attempt to flee from the animal and try to get around it, as it starts to play with you, keeping you from getting past it" << endl;
							cout << "It finally attacks you; pinning you down, biting and clawing to get its next feed" << endl;
							Discovery = "Nothing";
						}
					}

					else if (MinorChoice2 == "Wait") {
						score++;
						cout << "You wait at the entrance of the cave, sitting yourself within a pile of rocks and out of sight as you see a cougar walk ahead of you out of the shadows" << endl;
						cout << "As it starts to walk closer to the entrance, close to where you are currently, do you shoot the cougar or wait again?" << endl;
						cout << "Shoot/Wait" << endl;
						cin >> choice3;

						if (choice3 == "Shoot") {
							score = score + 3;
							cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "You aim at the creature as it stands still listening, lining up your shot as you pull the trigger, bullet whirls away from you and hits the cougar" << endl;
							cout << "You manage to hit the cougar well in its side, killing it" << endl;
							cout << "You got a Cougar" << endl;
							Discovery = "Cougar";
						}

						else if (choice3 == "Wait") {
							score--;
							cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "You decide to wait on shooting the animal, however as you didn't take the shot, the cougar hears something outside a sprints out of the cave" << endl;
							cout << "You sprint after it and end up losing it in the Jungle, you have lost your catch and cannot continue as its nearly already night" << endl;
							Discovery = "Nothing";
						}
					}
				}

				else if (choice2 == "Cave") {
					score = 0;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "You proceed into the cave without a weapon and without searching the shack for anything, witnessing a feline of sorts walking towards the shadows inside" << endl;
					cout << "It hears you as you waltz into its lair and charges you, however you have no way of defending yourself so the cougar overwhelms you" << endl;
					Discovery = "Nothing";
				}
			}
		}
	}
	int getScore() {
		return score;
	}
	string getAnim() {
		return Discovery;
	}

};

class Event3 : public Story{
public: 
// This is the Events for the Savanna
	void Events(){
		cout << "You see a pond and a group of trees, Where do you go?" << endl;
		cout << "Pond/Trees" << endl;
		cin >> choice1;

		if (choice1 == "Pond") {
			score++;
			cout << "You find a RIFLE by the waters edge" << endl;
			cout << "You see a Leopard grazing by the far end of the water" << endl;
			cout << "Do you shoot it or move on?" << endl;
			cout << "Shoot/Move" << endl;
			cin >> choice2;

			if (choice2 == "Shoot") {
				score = score + 3;
				cout << "You shoot the Leopard" << endl;
				cout << "You got a Leopard" << endl;
				Discovery = "Leopard";
			}
			else if (choice2 == "Move") {
				score = 0;
				cout << "You try to move away and is caught by a hippo" << endl;
				Discovery = "Nothing";
			}
		}
		if (choice1 == "Trees") {
			score++; 
			cout << "You move towards the trees and find a SPEAR" << endl;
			cout << "You see a lion and a hyena feeding. Which do you attack" << endl;
			cout << "Lion/Hyena" << endl;
			cin >> choice2;

			if (choice2 == "Lion") {
				score = score + 2;
				cout << "The lion spots you and charges you, you kill it with the SPEAR" << endl;
				cout << "You got a Lion" << endl;
				Discovery = "Lion";
			}
			else if (choice2 == "Hyena") {
				score++;
				cout << "The hyena runs as it spots the lion, do you chase?" << endl;
				cout << "Yes/No" << endl;
				cin >> choice3;

				if (choice3 == "Yes") {
					score++;
					cout << "You chase down the hyena and attack it with the SPEAR" << endl;
					cout << "You got a Hyena" << endl;
					Discovery = "Hyena";
				}
				else if (choice3 == "No") {
					score--;
					cout << "The lion starts chasing you, you run away with nothing" << endl;
					Discovery = "Nothing";
				}
			}
		}
	}
	int getScore() {
		return score;
	}
	string getAnim() {
		return Discovery;
	}
};

#endif //EVENT_H