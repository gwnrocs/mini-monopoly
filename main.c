/*  
	Description:		This program is a text-based, menu-driven game entitled "Property Property". It revolves around the actions of 2 players switching
				turns, and rolling a 6-sided virtual dice in order to move around a board with 10 blocks. Depending on the block they landed on,
				the player can choose to buy, renovate, sell, pay or do nothing. The game ends when a player's cash plunges into the
				negative due to not affording rent with no properties left to sell. After this, the menu is displayed, and the player may choose
				to exit the program or start another game. The program closes only when the option [ EXIT GAME ] is chosen.						
	Acknowledgements:	https://www.youtube.com/watch?v=oXEDMNXzuo4			
*/

#include <stdio.h>
#include <time.h>
#include "functions.c"

#define   GO				 0
#define   ELECTRIC_COMPANY 	 	 2
#define   JAIL_TIME 			 4
#define   FEELIN_LUCKY 		 	 6
#define   RAILROAD 			 7	

int main()
{
	int nStartOrEndGame;				// 1 for start, 2 for end
	int nDice;					// number rolled by the dice
	int nPlayer1 = 1;
	int nPlayer2 = 2;
	int nPropertyStatus;				// tracks status of properties via a 9-digit integer
	int nPosition1;					// player 1's position on the board
	int nPosition2;					// player 2's position on the board
	int nTurnCounter;				// signals the program to switch turns
	int nJailCounter1 = 0;				// jail loop counter of player 1
	int nJailCounter2 = 0;				// jail loop counter of player 2
	int nGameCounter = 0;				// game counter: odd = game is ongoing, even = game is done
	float fCash1;					// player 1's total cash
	float fCash2;					// player 2's total cast
	float fGoBonus;	
	float fRenovationCost;
		
	srand (time (NULL));				// allows the program to generate random numbers every run
		
		
	// GAME MENU	
	nStartOrEndGame = displayMenu ();
	
	// If the user inputs 1, the game will begin.
	while (nStartOrEndGame == 1)
	{  
	  	// BONUS FEATURE: User may configure GO Bonus
		fGoBonus = getGoBonus ();
		   
		// BONUS FEATURE: User may configure starting cash 
		fCash1 = getStartingCash ();
		fCash2 = fCash1;

		// BONUS FEATURE: User may configure renovation cost 
		fRenovationCost	= getRenovationCost ();	
		   
		// (re)setting game stats to default
		nTurnCounter = 1;
		nPropertyStatus = 0;
		nPosition1 = 0;
		nPosition2 = 0;
		
		/***************************************************/
		
		printf ("\t    Let's start!\n");
		displayDivider ();
		nGameCounter++;								// makes game counter odd
		
		while (nGameCounter % 2 == 1)
		{
			// PLAYER 1'S TURN	
			while (nGameCounter % 2 == 1 && nTurnCounter == 1)
			{
				displayIntroMessage (nPropertyStatus, nPlayer1, nPosition1, fCash1);
				
				// if PLAYER 1 is still in jail
				if (nJailCounter1 % 3 != 0)
					nJailCounter1++;
							
				// if PLAYER 1 is NOT in jail
				else
				{
					nDice = rollDice ();
					printf ("[ %d ]\n\n", nDice);
					nPosition1 = getPosition (nPosition1, nDice, fGoBonus, &fCash1);
				}
									
				switch (nPosition1)
				{
					case GO: 
						fCash1 += fGoBonus;
						printf ("You have collected $%.2f from the bank.\nYou now have: $%.2f\n", fGoBonus, fCash1);
						break;
						
			   	  	case JAIL_TIME:
						if (nJailCounter1 % 3 == 0 || nJailCounter1 % 3 == 2)
							printf ("You are in jail.\n");
						nJailCounter1++;
						break;
						
					case FEELIN_LUCKY:	
						fCash1 = getLucky (&nPropertyStatus, &nPosition1, &nJailCounter1, nPlayer1, fCash1);
						break;
							
					case ELECTRIC_COMPANY: case RAILROAD:
						fCash1 = getUtility (&nPropertyStatus, nPosition1, nDice, nPlayer1, fCash1, &fCash2);
						break;
					
				  	default:
						fCash1 = getHouseProperty (&nPropertyStatus, nPosition1, nPlayer1, fRenovationCost, fCash1, &fCash2);
						break;	
				}
				
				if (fCash1 < 0)					// if player 1's cash dips into the negative, this
					nGameCounter++;				// makes the game counter even, signalling its end.
					
				displayDivider();
				nTurnCounter++;					// switches the turn to player 2
			}
			
			// PLAYER 2'S TURN	
			while (nGameCounter % 2 == 1 && nTurnCounter == 2)
			{
				displayIntroMessage (nPropertyStatus, nPlayer2, nPosition2, fCash2);
				
				// if PLAYER 2 is still in jail
				if (nJailCounter2 % 3 != 0)
					nJailCounter2++;
				
				// if PLAYER 2 is NOT in jail
				else 
				{
					nDice = rollDice();
					printf ("[ %d ]\n\n", nDice);
					nPosition2 = getPosition (nPosition2, nDice, fGoBonus, &fCash2);	
				}
				
				switch (nPosition2)
				{
					case GO:
					    fCash2 += fGoBonus;
						printf ("You have collected $%.2f from the bank.\nYou now have: $%.2f\n", fGoBonus, fCash2);
					   	break;
	
					case JAIL_TIME:
						if (nJailCounter2 % 3 == 0 || nJailCounter2 % 3 == 2)
							printf ("You are in jail.\n");
						nJailCounter2++;
						break;
						
					case FEELIN_LUCKY:	
						fCash2 = getLucky (&nPropertyStatus, &nPosition2, &nJailCounter2, nPlayer2, fCash2);
						break;
										
					case ELECTRIC_COMPANY: case RAILROAD:
						fCash2 = getUtility (&nPropertyStatus, nPosition2, nDice, nPlayer2, fCash2, &fCash1);
						break;
						
					default:
						fCash2 = getHouseProperty (&nPropertyStatus, nPosition2, nPlayer2, fRenovationCost, fCash2, &fCash1);
						break;
				}
				  
				if (fCash2 < 0)					// if player 2's cash dips into the negative, this
					nGameCounter++;				// makes the game counter even, signalling its end.
					
				displayDivider();
				nTurnCounter--;					// switches the turn to player 1
			}
		} 
		  
		displayWinner (fCash1, fCash2);								// displaying the winner
		nStartOrEndGame = displayMenu ();							// displaying menu again
  	}
			
	// If the user inputs 2, a goodbye message will be shown and the game will exit.
	if (nStartOrEndGame == 2)
	{
		printf ("Awwww, sad to see you go :(\nBye bye!");
		return 0;
	}		
}
