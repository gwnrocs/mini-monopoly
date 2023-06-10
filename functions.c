/*  
	Description:		This file contains the functions used in "main.c"		
	Acknowledgements:	https://www.youtube.com/watch?v=oXEDMNXzuo4				
*/

#include <stdio.h>
#include <stdlib.h>

// for readability purposes only
#define BUY					1
#define SELL				2
#define NO_BUY				1
#define NO_RENOVATE			2
#define CANNOT_BUY			3	
#define CANNOT_RENOVATE		4
#define DONE				5           


// This function displays a divider containing 43 dashes.
void displayDivider ()
{
	printf ("-------------------------------------------\n");
}

// This function asks the user if they want to buy a property or not.
void displayBuyChoices ()
{
	printf ("\n\nDo you want to buy this property?\n");
	printf ("\t     [ 1 ] Yes\n\t     [ 2 ] No\n"); 
}

// This function asks the user if they want to renovate a property or not.
void displayRenovateChoices (float fRenovationCost)
{
	printf ("Do you want to renovate this property for $%.2f?\n", fRenovationCost);
	printf ("\t     [ 1 ] Yes\n\t     [ 2 ] No\n"); 
}

/*
This function displays the name and number of the property the player is on.
Precondition: 		 nPosition is a value from 0 to 9
@param  nPosition	 player's current position on the board
*/
void displayPositionName (int nPosition)
{
	if (nPosition == 0)
		printf ("GO (%d)", nPosition);
	else if (nPosition == 1)
		printf ("TREE HOUSE (%d)", nPosition);
	else if (nPosition == 2)
		printf ("ELECTRIC COMPANY (%d)", nPosition);
	else if (nPosition == 3)
		printf ("BEACH HOUSE (%d)", nPosition);
	else if (nPosition == 4)
		printf ("JAIL (%d)", nPosition);
	else if (nPosition == 5)
		printf ("CASTLE (%d)", nPosition);
	else if (nPosition == 6)
		printf ("FEELIN' LUCKY (%d)", nPosition);
	else if (nPosition == 7)
		printf ("RAILROAD (%d)", nPosition);
	else if (nPosition == 8)
		printf ("IGLOO (%d)", nPosition);
	else if (nPosition == 9)
		printf ("FARM HOUSE (%d)", nPosition);
}

/*
This function displays a brief message whenever a new turn starts. It shows the current
status of properties via a 9-digit integer, whose turn it currently is, what property they are 
currently on, and how much cash they have. 
Precondition:				nPropertyStatus is a positive 9-digit number with each digit ranging from 0 to 4,
			  				nPlayerNo is 1 or 2, nPosition is a value from 0 to 9, fCash is a positive value
@param  nPropertyStatus		status of all properties on the board
@param  nPlayerNo			player number where player1 = 1, player2 = 2
@param  nPosition	 		player's current position on the board
@param  fCash				amount of cash owned by the player
*/
void displayIntroMessage (int nPropertyStatus, int nPlayerNo, int nPosition, float fCash)
{
	printf ("Current Property Status: %09d\n", nPropertyStatus);
	printf ("PLAYER %d'S TURN\n", nPlayerNo);
	printf ("You are currently on ");
	displayPositionName (nPosition);
	printf ("\nCash on hand: $%.2f\n\n", fCash);
}

/*
This function displays the winner of the game.
Precondition: either fCash1 or fCash2 is a negative value
@param   fCash1 	player 1's cash 
@param   fCash2		player 2's cash 
*/
void displayWinner (float fCash1, float fCash2)
{
	if (fCash1 > fCash2)
		printf ("\n\t    CONGRATULATIONS!\n\n\tPLAYER 1 IS THE WINNER!!\n\n");
	
	else
		printf ("\n\t    CONGRATULATIONS!\n\n\tPLAYER 2 IS THE WINNER!!\n\n");
	
	displayDivider ();		
	printf ("\nDisplaying game menu again . . .\n\n");	
}

/*
This function gets the buy price of an ownable property.
Precondition:		nPosition is an ownable property's value (1, 2, 3, 5, 7, 8, or 9)
@param  nPosition 	assigned number of a property on the board
@return the buy price of a certain house property
*/
float getPropertyPrice (int nPosition)
{
	if (nPosition == 2)
		return 150;
		
	else if (nPosition == 7)
		return 100;
		
	else
		return nPosition % 7 * 20;
}

/*
This function gets the sell price of a certain property.
Precondition:		nPosition is a sellable property's value (1, 2, 3, 5, 6, 7, 8, or 9)
@param  nPosition 	assigned number of a property on the board
@return the sell price of a certain property
*/
float getSellPrice (int nPosition)
{
  	if (nPosition == 2)
  		return 150 / 2;
  		
  	else if (nPosition == 7)
  		return 100 / 2;
  		
	else
		return getPropertyPrice (nPosition) / 2;
}

/*
This function displays the game menu and receives the user's input. 
If input:	1 or 2		returns value
	  		  else 		program continuously asks for a valid input while displaying the game menu 
@return user's input upon seeing the menu
*/
int displayMenu ()
{
  	int nStartOrEndGame;
  	
  	while ((nStartOrEndGame != 1) && (nStartOrEndGame != 2))
	{
		displayDivider ();
		printf ("|      Welcome to Property Property!      |\n");
		printf ("|        a game coded by gwen roco        |\n");
		displayDivider ();
		printf ("|         Select an option below:         |\n");
		printf ("|            [ 1 ]  Start                 |\n");
		printf ("|            [ 2 ]  Exit                  |\n");
		displayDivider ();
		
		scanf (" %d", &nStartOrEndGame);
		
		if ((nStartOrEndGame != 1) && (nStartOrEndGame != 2))
			printf ("Invalid input.\nKindly enter [ 1 ] to start or [ 2 ] to exit.\n\nDisplaying game menu again . . .\n\n");
	}	
					
	displayDivider ();
	return nStartOrEndGame;
}

/*
This function rolls the dice. It gets a random number from 1 to 6.
@return a random number from 1 to 6.
*/
int rollDice ()
{
	int nChoice;
	
	while (nChoice != 1)
	{
		printf ("Press [ 1 ] to roll the dice.   ");
		scanf (" %d", &nChoice);
  	}
	
	printf ("\nRolling the dice . . . ");
	return rand() % 6 + 1;					
}

/*
This function determines whether a number is prime or not.
Precondition: 	nVal is a positive integer
@param  nVal	number to be checked		
@return 1 if prime and 0 if not
*/
int isPrime (int nVal)
{
	int nCounter;	
	int isPrime = 0;		// 0 for not prime, 1 for prime
	
	for (nCounter = 2; nCounter <= nVal / 2 && isPrime == 0; nCounter++)
	{
		if (nVal % nCounter == 0)
			isPrime++;
	}
	
	if (isPrime == 1 || nVal <= 1)
		return 0;
		
	else
		return 1;
}

/*
This function gets the player's position on the board based on the rolled dice. 
If the player passes GO (0), it updates the player's cash accordingly.
Precondition:		 nPosition is a value from 0 to 9, nDice is a value from 1 to 6,
			  		*fCash is a positive value  
@param 	nPosition 	player's current position on the board
@param	nDice 		number displayed by the rolled dice
@param	fGoBonus 	amount of cash to be received when passing GO
@param  *fCash		amount of cash owned by the player
@return the player's resulting position after rolling the dice
*/
int getPosition (int nPosition, int nDice, float fGoBonus, float *fCash)
{
	if (nPosition + nDice > 10)
	{
	  	*fCash += fGoBonus;
		printf ("You have passed GO. You receive $%.2f from the bank.\nYou now have: $%.2f\n\n", fGoBonus, *fCash);
	}
	
	nPosition = (nPosition + nDice) % 10;
	printf ("You landed on ");
	displayPositionName (nPosition);
	printf ("\n\n");
	return nPosition;
}

/*
This function extracts a digit from the overall property status depending on the corresponding position.
Precondition: 				nPosition is a value from 1 to 9
@param  nPropertyStatus 	overall status of properties projected as a 9-digit integer
@param  nPosition		 	position of a property on the board
@return the specific property's status
*/
int getDigit (int nPropertyStatus, int nPosition)
{
	int nCounter;						
	int nDigit;
		
	for (nCounter = 1; nCounter <= nPosition; nCounter++)
	{
		nDigit = nPropertyStatus % 10;
		nPropertyStatus /= 10;	
	}
	  
	return nDigit;
}

/*
This function displays a player's owned properties, whether or not they are renovated, and their sell price.
Precondition: 				nPropertyStatus is a positive 9-digit integer with each digit ranging from 0 to 4
@param   nPropertyStatus  	overall status of properties on the board
@param   nPlayerNo		 	player number where player1 = 1, player2 = 2
@return 1 if the player owns one or more properties and 0 if none
*/
int getOwnedProperties (int nPropertyStatus, int nPlayerNo)
{
	int j;					// counter variable used for loops
	int nCounter = 0;		// counts the number of properties owned by the player
	int nRemainder;
	
	printf ("You don't have enough money to pay.\n\nYou own the following properties:\n");				
	
	if (nPlayerNo == 1)
	{
		for (j = 1; j <= 9; j++)
		{
			nRemainder = nPropertyStatus % 10;
			
			if (nRemainder == 1)
			{
				displayPositionName (j);
				printf (" - UNRENOVATED - sell for $%.2f\n", getSellPrice (j));
				nCounter++;
			}
			
			else if (nRemainder == 3)
			{
				displayPositionName (j);
				printf (" - RENOVATED - sell for $%.2f\n", getSellPrice (j));
				nCounter++;
			}
			
			nPropertyStatus /= 10;
		}
	}
	
	else if (nPlayerNo == 2)
	{
		for (j = 1; j <= 9; j++)
		{
			nRemainder = nPropertyStatus % 10;

			if (nRemainder == 2)
			{
				displayPositionName (j);
				printf (" - UNRENOVATED - sell for $%.2f\n", getSellPrice (j));
				nCounter++;
			}
			
			else if (nRemainder == 4)
			{
				displayPositionName (j);
				printf (" - RENOVATED - sell for $%.2f\n", getSellPrice (j));
				nCounter++;
			}
			
			nPropertyStatus /= 10;
		}
	}	
	  
	if (nCounter > 0)
		return 1;
	
	else if (nPropertyStatus == 0 && nCounter == 0)
		printf ("NONE\n");
	return 0;
}

/*
This function checks if a player legitimately owns a certain property.
Precondition: 			    nPosition is an ownable propery (house properties, Railroad, Electric Company)
@param   nPropertyStatus 	overall status of properties on the board
@param   nPosition		 	assigned number of a property on the board
@param   nPlayerNo		 	player number where player1 = 1, player2 = 2
@return 1 if the player owns the property and 0 if they don't
*/
int isValidOwner (int nPropertyStatus, int nPosition, int nPlayerNo)
{
	int j = getDigit (nPropertyStatus, nPosition);
		
	if (nPosition <= 0)
		return 0;
		
	if (nPlayerNo == 1)
		if (j == 1 || j == 3)
			return 1;
		else
			return 0;
		
	else if (nPlayerNo == 2)
	  	if (j == 2 || j == 4)
			return 1;
		else
			return 0;
}
  
/*
This function updates the overall property status whenever a player buys or sells a property.
Precondition: 				nPosition corresponds to an ownable property
@param  nPropertyStatus 	indicates whether or not a property is owned / renovated by a player
@param  nPosition 			assigned number of a property on the board
@param  nPlayerNo			player number where player1 = 1, player2 = 2
@param  nBuyOrSell			BUY (1) = buying / renovating,  SELL (2) = selling
@return updated overall property status
*/
int updateProperty (int nPropertyStatus, int nPosition, int nPlayerNo, int nBuyOrSell)
{
	int nCounter; 								
	int i = 1;								// amount to be subtracted from property status to update it
	
	if (nPosition != 1)
		for (nCounter = 2; nCounter <= nPosition; nCounter++)
			i *= 10;	
	
	if (getDigit (nPropertyStatus, nPosition) == 0)
		return nPropertyStatus + i * nPlayerNo;
					
	else if (getDigit (nPropertyStatus, nPosition) == 1 || getDigit (nPropertyStatus, nPosition) == 2)
	{
		if (nBuyOrSell == BUY)
			return nPropertyStatus + i * 2;
		else if (nBuyOrSell == SELL)
			return nPropertyStatus - i * nPlayerNo;
	}	
	
	else if (getDigit (nPropertyStatus, nPosition) == 3)
		return nPropertyStatus - i * 3;
		
	else if (getDigit (nPropertyStatus, nPosition) == 4)
		return nPropertyStatus - i * 4;	
}

/*
This function allows the player to set the GO Bonus. If they input 1, they may change the GO bonus from $0.00 above. If they input 
2, the bonus will reset to default $200.00. If the user inputs an invalid value, the program will continuously ask for a valid input.
@return GO bonus cash amount
*/
float getGoBonus ()
{
	int nChoice;
  	float fGoBonus;
  	
  	printf ("Do you want to configure the GO bonus?\n\t     [ 1 ] Yes\n\t     [ 2 ] No\n");
	scanf ("%d", &nChoice);
		
	while (nChoice != 1 && nChoice != 2)
	{
		printf ("Invalid input. Enter 1 or 2: ");
		scanf ("%d", &nChoice);
	}
  	
  	if (nChoice == 1)
  	{
	  	printf ("\nNOTE: Default settings make it hard for the game to end\nso it is advisable ");
	  	printf ("to enter an amount lower than the default.\n\nDefault GO bonus: $200.00\nSet new GO bonus amount: ");
		scanf (" %f", &fGoBonus);
		
		while (fGoBonus < 0)
		{
			printf ("Invalid input. Enter a positive value: ");
			scanf (" %f", &fGoBonus);	
		}
		  
		if (fGoBonus == 200)
			printf ("You've decided to set the GO Bonus to default.\n");
		  
		else
			printf ("\nYou've set the GO Bonus to $%.2f.\n", fGoBonus);
			
		displayDivider ();
		return fGoBonus;
	}
	
	else if (nChoice == 2)
	{
		printf ("You've decided not to change the GO Bonus.\n");
		displayDivider ();
		return 200;
	}
}
  
/*
This function allows the player to set the starting cash. If they input 1, they may change the starting cash from $0.00 above. If they input 
2, the starting cash will reset to default $200.00. If the user inputs an invalid value, the program will continuously ask for a valid input.
@return starting cash amount
*/
float getStartingCash ()
{
	int nChoice;
	float fStartingCash;
  	
	printf ("Do you want to configure the starting cash?\n\t     [ 1 ] Yes\n\t     [ 2 ] No\n");
	scanf ("%d", &nChoice);
	
	while (nChoice != 1 && nChoice != 2)
	{
		printf ("Invalid input. Enter 1 or 2: ");
		scanf ("%d", &nChoice);
	}
  	
  	if (nChoice == 1)
  	{
	  	printf ("\nDefault starting cash: $200.00\nSet new starting cash: ");
		scanf (" %f", &fStartingCash);
		
		while (fStartingCash < 0)
		{
			printf ("Invalid input. Enter a positive value: ");
			scanf (" %f", &fStartingCash);	
		}
		  
		if (fStartingCash == 200)
			printf ("\nYou've decided to set the starting cash to default.\n");
		  
		else
			printf ("\nYou've set the starting cash to $%.2f.\n", fStartingCash);
			
		displayDivider ();
		return fStartingCash;
	}
	
	else if (nChoice == 2)
	{
		printf ("You've decided not to change the starting cash.\n");
		displayDivider ();
		return 200;
	}
}

/*
This function allows the player to set the renovation cost. If they input 1, they may change the renovation cost from $0.00 above. If they input 
2, the renovation cost will reset to default $50.00. If the user inputs an invalid value, the program will continuously ask for a valid input.
@return starting cash amount
*/
float getRenovationCost ()
{
	int nChoice;
	float fRenovationCost;
  	
	printf ("Do you want to configure the renovation cost?\n\t     [ 1 ] Yes\n\t     [ 2 ] No\n");
	scanf ("%d", &nChoice);
	
	while (nChoice != 1 && nChoice != 2)
	{
		printf ("Invalid input. Enter 1 or 2: ");
		scanf ("%d", &nChoice);
	}
  	
  	if (nChoice == 1)
  	{
	  	printf ("\nDefault renovation cost: $50.00\nSet new renovation cost: ");
		scanf (" %f", &fRenovationCost);
		
		while (fRenovationCost < 0)
		{
			printf ("Invalid input. Enter a positive value: ");
			scanf (" %f", &fRenovationCost);	
		}
		  
		if (fRenovationCost == 50)
			printf ("You've decided to set the renovation cost to default.\n");
		  
		else
			printf ("\nYou've set the renovation cost to $%.2f.\n", fRenovationCost);
			
		displayDivider ();
		return fRenovationCost;
	}
	
	else if (nChoice == 2)
	{
		printf ("You've decided not to change the renovation cost.\n");
		displayDivider ();
		return 50;
	}
}

/*
This function allows the player to automatically pay their rent.
Precondition:	both are positive values with fCash >= fRent
@param  fCash 	amount of cash owned by a player
@param  fRent 	amount of rent needed to be paid
@return the player's cash after paying rent
*/
float payRent (float fCash, float fRent)
{	
  	fCash -= fRent;
	printf ("Paying rent . . .\nYou now have: $%.2f\n", fCash);		
	return fCash;
}

/*
This function displays the price and name of the property, and allows the player to sell it
Precondition: 			both are positive values
@param  fCash 			amount of cash owned by a player
@param  nPosition 		assigned number of a property on the board
@return player's cash after selling a property
*/
float sellProperty (int nPosition, float fCash)
{		
	printf ("\nSelling . . . ");
	displayPositionName (nPosition);
	printf (" for $%.2f\n", getSellPrice (nPosition));
	return fCash + getSellPrice (nPosition); 
}

/*
This function alerts a player who landed on their own renovated property / own property that does not offer renovation options.
@param  nChoice		 determines whether the player CHOOSES NOT TO buy / renovate, CANNOT buy / renovate, or has no other options left
@param  fCash		 amount of cash owned by a player
@return player's initial cash 
*/
float doNothing (int nChoice, float fCash)
{
  	if (nChoice == NO_BUY)
		printf ("You've decided not to buy this property.\n");
	else if (nChoice == NO_RENOVATE)
		printf ("You've decided not to renovate this property.\n");
	else if (nChoice == CANNOT_BUY)
		printf ("You don't have enough funds to buy this property.\n");
	else if (nChoice == CANNOT_RENOVATE)
		printf ("You don't have enough funds to renovate this property.\n");		
	else if (nChoice == DONE)
		printf ("You OWN this property.\n");
			
	printf ("You now have: $%.2f\n", fCash);
	return fCash;
}

/*
This function displays the status of the house property the player landed on, and its price / rent.
It gives the player a choice of buying / renovating / paying rent / selling / doing nothing,
and accordingly updates the overall status of properties projected as a 9-digit integer.
Preconidition:				nPosition corresponds to a house property on the board
@param   *nPropertyStatus	overall status of properties on the board
@param   nPosition			assigned number of a property on the board
@param   nPlayerNo		 	player number where player1 = 1, player2 = 2
@param 	 fRenovationCost	cost of renovation for a certain property
@param   fCash	 			amount of cash owned by the player who landed on this property
@param   *fRentOwner 		amount of cash owned by the player who receives rent
@return player's cash after making choices on this property
*/
float getHouseProperty (int *nPropertyStatus, int nPosition, int nPlayerNo, float fRenovationCost, float fCash, float *fRentOwner)
{
	int nChoice;
	int nPropertySell;
	float fCost = getPropertyPrice (nPosition);		// cost of buying this property
	float fRent = fCost / 5;						// rent to be paid on this property
	
	// if property is UNOWNED
	if (getDigit (*nPropertyStatus, nPosition) == 0)
	{
		printf ("The property is UNOWNED.\nTo purchase, you must pay $%.2f.", fCost);
		displayBuyChoices ();
		scanf (" %d", &nChoice);
		
		// while the input is invalid, the program will continuously ask for a valid one
		while (nChoice != 1 && nChoice != 2)
		{
			printf ("Invalid input. Enter 1 or 2: ");
			scanf (" %d", &nChoice);
		}
			
		if (nChoice == 1)
		{	
			if (fCash < fCost)
			  	return doNothing (CANNOT_BUY, fCash);
		
			else
			{
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPosition, nPlayerNo, BUY);
				fCash -= fCost;
				printf ("You've bought this property!\nYou now have: $%.2f\n", fCash);
				return fCash;
			}
		}
			
		else if (nChoice == 2)
		  	 return doNothing (NO_BUY, fCash);
	}	

	// if property is OWNED by PLAYER 1
	else if (getDigit (*nPropertyStatus, nPosition) == 1)
	{
		if (nPlayerNo == 1)
		{
			printf ("You OWN this property.\n");
			displayRenovateChoices (fRenovationCost);
			scanf (" %d", &nChoice);

			while (nChoice != 1 && nChoice != 2)
			{
				printf ("Invalid input. Enter 1 or 2: \n");
				scanf (" %d", &nChoice);
			}
			
			if (nChoice == 1)
			{	
				if (fCash < fRenovationCost)
				 	return doNothing (CANNOT_RENOVATE, fCash);

				else
				{
					fCash -= fRenovationCost;
					*nPropertyStatus = updateProperty (*nPropertyStatus, nPosition, nPlayerNo, BUY);
					printf ("You've renovated this property!\nYou now have: $%.2f\n", fCash);
					return fCash;
				}
			}
				
			else if (nChoice == 2)
			 	return doNothing (NO_RENOVATE, fCash);
		}
		
		else if (nPlayerNo == 2)
		{
			printf ("Player 1 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{				
				printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);

				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}
				
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);					
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	  
			 	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
	}
	
	// if property is OWNED by PLAYER 2
	else if (getDigit (*nPropertyStatus, nPosition) == 2)
	{
		if (nPlayerNo == 1)
		{  
			printf ("Player 2 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{				
				printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);

				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}
				
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);					
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	  
			 	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
		
		else if (nPlayerNo == 2)
		{
			printf ("You OWN this property.\n");
			displayRenovateChoices (fRenovationCost);
			scanf (" %d", &nChoice);

			// while the input is invalid, the program will continuously ask for a valid one
			while (nChoice != 1 && nChoice != 2)
			{
				printf ("Invalid input. Enter 1 or 2: \n");
				scanf (" %d", &nChoice);
			}

			if (nChoice == 1)
			{	
				if (fCash < fRenovationCost)
				{
					printf ("You don't have enough funds to renovate this property.\nYou now have: $%.2f\n", fCash);
					return fCash;
				}
			
				else
				{
					fCash -= fRenovationCost;
					*nPropertyStatus = updateProperty (*nPropertyStatus, nPosition, nPlayerNo, BUY);
					printf ("You've renovated this property!\nYou now have: $%.2f\n", fCash);
					return fCash;
				}
			}
			
			else if (nChoice == 2)
			{
				printf ("You've decided not to renovate this property.\nYou now have: $%.2f\n", fCash);
				return fCash;
			}
		}	
	}
	  
	// if property is RENOVATED by PLAYER 1
	else if (getDigit (*nPropertyStatus, nPosition) == 3)
	{	
		fRent = 1 + 2 * fRent;

		if (nPlayerNo == 1)
		  return doNothing (DONE, fCash);
		
		else if (nPlayerNo == 2)
		{
			printf ("Player 1 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{				
				printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);

				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}
				
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);					
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	  
			 	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
	}
	  
	// if property is RENOVATED by PLAYER 2
	else if (getDigit (*nPropertyStatus, nPosition) == 4)
  	{  	
		fRent = 1 + 2 * fRent;

		if (nPlayerNo == 1)
		{
			printf ("Player 2 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{				
				printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);

				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}
				
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);					
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	  
			 	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
		
		else if (nPlayerNo == 2)
		    return doNothing (DONE, fCash);
	}
}

/*
This function displays the status of the property the player landed on, and its price / rent.
It gives the player a choice of buying / paying rent / selling / doing nothing,
and accordingly updates the overall status of properties projected as a 9-digit integer.
Precondition:				nPosition is 2 or 4
@param  *nPropertyStatus	overall status of properties on the board
@param  nPosition			player's current position on the board
@param  nDice				value rolled by the dice
@param  nPlayerNo			player number where player1 = 1, player2 = 2
@param  fCash				amount of cash owned by the player who landed on this property
@param  *fRentOwner			amount of cash owned by the player who receives rent
@return player's cash after making choices on this property
*/
float getUtility (int *nPropertyStatus, int nPosition, int nDice, int nPlayerNo, float fCash, float *fRentOwner)
{
	int nChoice;
	int nPropertySell;
	float fCost = getPropertyPrice (nPosition);
	float fRent;
	
	// assigning rent 
	if (nPosition == 2)					// ELECTRIC COMPANY
		fRent = nDice * 8;
	  
	else if (nPosition == 7)			// RAILROAD
		fRent = 35;
	
	// if property is UNOWNED	
	if (getDigit (*nPropertyStatus, nPosition) == 0)
	{
		printf ("The property is UNOWNED.\nTo purchase, you must pay %.2f", fCost);
		displayBuyChoices ();
		scanf (" %d", &nChoice);
		
		while ((nChoice != 1) && (nChoice != 2))
		{
			printf ("Invalid input. Enter 1 or 2: ");
			scanf (" %d", &nChoice);
		}
		  
		if (nChoice == 1)
	  	{	
			if (fCash < fCost)
				return doNothing (CANNOT_BUY, fCash);
			
			else
			{
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPosition, nPlayerNo, BUY);
				fCash -= fCost;
				printf ("You've bought this property!\nYou now have: $%.2f\n", fCash);
				return fCash;
		 	}
		}
			
		else if (nChoice == 2)
		  	return doNothing (NO_BUY, fCash);
    }
	
	// if property is OWNED by PLAYER 1
	else if (getDigit (*nPropertyStatus, nPosition) == 1)
	{
		if (nPlayerNo == 1)
			return doNothing (DONE, fCash);
		
		else if (nPlayerNo == 2)
		{
			printf ("Player 1 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{				
				printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);

				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}
				
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);					
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	  
			 	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
	}

	// if property is OWNED by PLAYER 2
	else if (getDigit (*nPropertyStatus, nPosition) == 2)
	{
		if (nPlayerNo == 1)
		{
			printf ("Player 2 OWNS this property.\nYou have to pay a rent of: $%.2f\n", fRent);
			
			while (fCash < fRent && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
			{		
			 	printf ("\nEnter the property number you want to sell: ");
				scanf (" %d", &nPropertySell);	
								
				while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
				{
					printf ("\nInvalid input. Enter a property YOU OWN: ");
					scanf (" %d", &nPropertySell);
				}	
			  
				fCash = sellProperty (nPropertySell, fCash);
				*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
				printf ("You now have: $%.2f\n", fCash);								
			}
			  
			if (fCash < fRent)
			{
				printf ("\nYou don't have enough properties to sell.\n");
				return -1;
		 	}	 
		 	   	  
			*fRentOwner += fRent;			  
			return payRent (fCash, fRent);
		}
		
		else if (nPlayerNo == 2)
			return doNothing (DONE, fCash);
	}	
}

/*
This function alerts the player that they have landed on FEELIN' LUCKY (6). It allows the player to
roll the dice. If the resulting number is prime, the player is rewarded a random cash amount from
100 to 200 by the bank. If it is not prime, the player is forced to pay a random cash amount from 
50 to 150 to the bank. If it is 1, the player heads straight to jail and loses a turn. 
Precondition:				*nPosition = 6, *nJailCounter % 3 = 0
@param  *nPropertyStatus	overall status of properties on the board
@param  *nPosition			player's current position on the board
@param  *nJailCounter		determines whether the player is in jail or not
@param  nPlayerNo			player number where player1 = 1, player2 = 2
@param  fCash				amount of cash owned by the player
@return player's cash after making choices on this block
*/
float getLucky (int *nPropertyStatus, int *nPosition, int *nJailCounter, int nPlayerNo, float fCash)
{
	float fAmount;			// the money given by the bank or paid to the bank
	int nDice;				// the number generated by the dice to determine luck
	int nPropertySell;
	
	printf ("Roll the dice to determine your luck.\n");
	nDice = rollDice ();
	printf ("[ %d ]", nDice);

	// if dice rolls 1
	if (nDice == 1)
	{
		printf ("\nUNLUCKY! Off to JAIL you go.\n");
		*nPosition = 4;									// moves player's position to JAIL (4)
		*nJailCounter += 1;								// updates jail counter
		return fCash;
	}

	// if dice rolls a prime number,
	else if (isPrime (nDice == 1))
	{  
		printf ("\nLUCKY! It's a prime number!\n");
		
		// gets a random number from 100 to 200
		fAmount = (rand() % (200 - 100 + 1)) + 100;
		
		fCash += fAmount;
		printf ("The bank has rewarded you with: $%.2f\nYou now have: $%.2f\n", fAmount, fCash);
		return fCash;
	}
	
	// if dice does not roll a prime number,
	else
	{
		printf ("\nUNLUCKY! It's not a prime number!\n");
		
		// gets a random number from 50 to 150
		fAmount = (rand() % (150 - 50 + 1)) + 50;
		
		printf ("You must pay the bank: $%.2f\n\n", fAmount);				
			
		while (fCash < fAmount && getOwnedProperties (*nPropertyStatus, nPlayerNo) != 0)
		{				
			printf ("\nEnter the property number you want to sell: ");
			scanf (" %d", &nPropertySell);

			while (isValidOwner (*nPropertyStatus, nPropertySell, nPlayerNo) == 0)	
			{
				printf ("\nInvalid input. Enter a property YOU OWN: ");
				scanf (" %d", &nPropertySell);
			}
			
			fCash = sellProperty (nPropertySell, fCash);
			*nPropertyStatus = updateProperty (*nPropertyStatus, nPropertySell, nPlayerNo, SELL);
			printf ("You now have: $%.2f\n", fCash);					
		}
		  
		if (fCash < fAmount)
		{
			printf ("\nYou don't have enough properties to sell.\n");
			return -1;
	 	}	  
		
		fCash -= fAmount;
		printf ("Paying the bank . . .\nYou now have: $%.2f\n", fCash);		
		return fCash;		
	}
}
