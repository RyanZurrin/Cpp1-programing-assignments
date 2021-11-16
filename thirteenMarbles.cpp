/*****************************************************************************
author:			Ryan Zurrin
program:		thirteenMarbles.cpp	
date: 			11/3/19
assignment:		
purpose:    
*****************************************************************************/
#include<iostream>
using namespace std;
void Directions();
int computerPick(int);
int humanPick(); 
bool validPick(int);
void turnDisplay(int, char);
int main()
{
	int marbles;
	int human_pick, comp_pick;
	char replay;
	
	Directions();
	do {
		marbles = 13;
		human_pick = comp_pick = 0;
		while(marbles > 0) { 
			
			marbles -= computerPick(human_pick);
			if (marbles > 0) {
				turnDisplay(marbles, 'p');
				marbles -=human_pick = humanPick();
				turnDisplay(marbles, 'p');
				cout << endl;
			}			
		}
	cout << "The computer wins!\n\n";
	cout << "Would you like to play again? [Y/y]\n>>";
	cin >> replay;
	} while(replay == 'Y' || replay == 'y');

	cout << "thank you for playing, GoodBye!\n";
	return 0;
}
//////////////////////////////////////////////////////////
int computerPick(int last_taken_human)
{
	//let computer pick its goldfish
	if(last_taken_human == 1) {
		turnDisplay(3, 'c');
		return 3;
		
	} else if(last_taken_human == 2) {
		turnDisplay(2, 'c');
		return 2;
	} else {
		turnDisplay(1, 'c');
		return 1;
	}
	//make sure computer picks enough goldfish
	//upt to 4 between this pick and human pick
	
}
int humanPick() // if a function has anything but a void it must return a value of that type
{
	int human_picked;
	do{
		cout << "\nHow many Marbles would you like to take (1-3): ";
		cin >> human_picked;
	} while(!validPick(human_picked)); // you need to validatd the human pick each time they go
	return human_picked; // returning value of type int as specified with int HumanPick
}
bool validPick(int marbles_picked)
{
	while (!cin || (marbles_picked > 3 || marbles_picked < 1))
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Please pick between 1 and 3 marbles to remove from bag\n";
		return false;
	}
	return true;
}
void Directions()
{
	cout << "You have choosen to play 13 marbles with me the MIGHTY COMPUTER.\n"	
		 << "The object of the game is to take 1, 2, or 3 marbles" 
		 <<" from the bag on your turn.\n"
		 << "The player that removes the last marble or marbles" 
		 << " from the bag wins the game.\n"
		 << "One last thing, being the MIGHTY COMPUTER, I always go first.\n"
		 << "Good Luck... you will need it. I never Lose!\n\n";
}
void turnDisplay(int marbles, char mode) {
	if (mode == 'c') {
		cout << "I THE MIGHTY COMPUTER have taken " << marbles << " Marbles from the bag\n";
	} else {
		cout << "There are " << marbles << " Marbles left in the bag\n";
	}
}
