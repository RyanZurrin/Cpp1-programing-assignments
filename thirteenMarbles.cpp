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
			cout << "There are " << marbles << " Marbles left in the bag\n";
			marbles -= computerPick(human_pick);
			if (marbles > 0) {
				cout << "\nThere are " << marbles << " Marbles left in the bag\n";
				marbles -=human_pick = humanPick();
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
	
	if(last_taken_human == 1) {
		cout << "I THE MIGHTY COMPUTER have taken 3 Marbles from the bag\n";
		return 3;
		
	} else if(last_taken_human == 2) {
		cout << "I THE MIGHTY COMPUTER have taken 2 Marbles from the bag\n";
		return 2;
	} else {
		cout << "I THE MIGHTY COMPUTER have taken 1 Marbles from the bag\n";
		return 1;
	}	
}
int humanPick() 
{
	int human_picked;
	do{
		cout << "How many Marbles would you like to take (1-3): ";
		cin >> human_picked;
	} while(!validPick(human_picked));
	return human_picked; 
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
