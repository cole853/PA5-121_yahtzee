/*
	Programmer: Cole Clark
	Date: 10-27-2020

	Description: PA5 game of Yahtzee
*/

#include "yahtzee.h"


/*************************************************************
* Function: game_menu()						                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: prints the game menu for Yahtzee				*
*															*
* Input parameters: void                                    *
* Returns: int			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int game_menu(void)
{
	int selected_option = 0;
	printf("Press 1 for game rules...\nPress 2 to start a game of yahtzee!\nPress 3 to Exit.\n");
	scanf("%d", &selected_option);

	return selected_option;
}


/*************************************************************
* Function: check_menu_option()				                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: does the selected task based on menu input	*
*															*
* Input parameters: int option from menu                    *
* Returns: int			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int check_menu_option(int selected_option)
{
	if (selected_option <= 0 || selected_option > 3)
	{
		//printf("\nplease choose one of the menu options.\n\n");
		//system("pause");
		system("cls");
		return 1;
	}
	else if (selected_option == 1)
	{
		print_rules();
	}
	else if (selected_option == 3)
	{
		system("cls");
		printf("\nGoodbye\n\n");

		return 3;
	}
	else
	{
		return 2;
	}
}


/*************************************************************
* Function: print_rules()					                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: prints the rules for Yahtzee					*
*															*
* Input parameters: void                                    *
* Returns: void			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void print_rules(void)
{
	//rules
	system("cls");
	printf("The Rules Of Yahtzee:\n\nThe scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n If a player rolls four 3's, then the score placed in the 3's box\n is the sum of the dice which is 12. Once a player has chosen to score a box,\n it may not be changed and the combination is no longer in play for future rounds.\n If the sum of the scores in the upper section is greater than or equal to 63,\n then 35 more points are added to the players overall score as a bonus.\n The lower section contains a number of poker like combinations.\n See the table provided below:\n\n");
	
	//score table
	printf("\tName\t\t\tCombination\t\t\t\tScore\n");
	printf("Three-of-a-kind\t\t Three dice with the same face\t Sum of all face values on the 5 dice\n");
	printf("Four-of-a-kind\t\t Four dice with the same face\t Sum of all face values on the 5 dice\n\n");
	printf("Full House\t\t One pair and a three-of-a-kind\t\t\t 25\n");
	printf("Small straight\t\t A sequence of four dice\t\t\t 30\n");
	printf("Large straight\t\t A sequence of five dice\t\t\t 40\n");
	printf("Yahtzee!!!\t\t Five dice with the same face\t\t\t 50\n\n");
	printf("Chance\t\t\t May be used for any sequence\t Sum of all face values on the 5 dice\n");
	printf("\t\t\t of dice;\n");
	printf("\t\t\t this is a catch all combination\n\n");

	system("pause");
	system("cls");
}


/*************************************************************
* Function: roll_five_dice()				                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: rolls the first 5 dice for a player			*
*															*
* Input parameters: roll array, player number, round number *
* Returns: changes the roll array			                *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int *roll_five_dice(int *roll, int player_number, int round_number)
{
	int number = 0;

		printf("player %d hit any key to roll the dice.\n", player_number);
		system("pause");

	roll[0] = rand() % 6 + 1;
	roll[1] = rand() % 6 + 1;
	roll[2] = rand() % 6 + 1;
	roll[3] = rand() % 6 + 1;
	roll[4] = rand() % 6 + 1;

	system("cls");
}


/*************************************************************
* Function: reroll_or_score()				                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: asks the player if they want to reroll or	*
*				score their current roll.					*
*															*
* Input parameters: void                                    *
* Returns: int 			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int reroll_or_score(void)
{
	int result = 0;

	while (result != 1 && result != 2)
	{

		//system("cls");
		printf("Would you like to use this roll for a game combination? 2 = yes  1 = no\n");
		scanf("%d", &result);
	}


	return result;
}


/*************************************************************
* Function: reroll_how_many()				                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: asks the player how many dice to reroll		*
*				returns the answer.							*
*															*
* Input parameters: void                                    *
* Returns: int			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int reroll_how_many(void)
{
	int response = 0;

	while (response <= 0 || response > 5)
	{
		printf("how many would you like to reroll?\n");
		scanf("%d", &response);
	}

	return response;
}


/*************************************************************
* Function: get_reroll()					                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: asks the player which dice to reroll and		*
*				saves the selections in reroll[].			*
*															*
* Input parameters: reroll[], number_of_rerolls             *
* Returns: changes reroll[]			                        *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int* get_reroll(int* reroll, int number_of_rerolls)
{
	int result = -1;
	int index = 0;

	printf("Enter the dice numbers you would like to reroll:\n");
	
	while (index != number_of_rerolls)
	{
		scanf("%d", &result);
		reroll[index] = result;

		index++;
	}
}


/*************************************************************
* Function: reroll()						                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: rerolls the selected dice					*
*															*
* Input parameters: roll[], reroll[], number_of_rr          *
* Returns: changes roll[]			                        *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int *reroll( int *roll, int *reroll, int number_of_rerolls)
{
	
	for (int i = 0; i != number_of_rerolls && reroll[i] != 0; ++i)
	{
		roll[reroll[i] - 1] = rand() % 6 + 1;
	}
}


/*************************************************************
* Function: enter_menu()									*
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: displays the score card.						*
*															*
* Input parameters: score_card[], used[]                    *
* Returns: void			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void* enter_menu(int* score_card, int* used)
{

	//sum of 1
	if (used[0] == 1)
	{
		printf("\n\n1. Sum of 1's:\t %d\t\t", score_card[0]);
	}
	else
	{
		printf("\n\n1. Sum of 1's:\t --\t\t");
	}

	//three of a kind
	if (used[6] == 1)
	{
		printf("7. Three-of-a-kind:\t %d\n", score_card[6]);
	}
	else
	{
		printf("7. Three-of-a-kind:\t --\n");
	}

	//sum of 2
	if (used[1] == 1)
	{
		printf("2. Sum of 2's:\t %d\t\t", score_card[1]);
	}
	else
	{
		printf("2. Sum of 2's:\t --\t\t");
	}

	//four of a kind
	if (used[7] == 1)
	{
		printf("8. Four-of-a-kind:\t %d\n", score_card[7]);
	}
	else
	{
		printf("8. Four-of-a-kind:\t --\n");
	}

	//sum of 3
	if (used[2] == 1)
	{
		printf("3. Sum of 3's:\t %d\t\t", score_card[2]);
	}
	else
	{
		printf("3. Sum of 3's:\t --\t\t");
	}

	//full house
	if (used[8] == 1)
	{
		printf("9. Full house:\t\t %d\n", score_card[8]);
	}
	else
	{
		printf("9. Full house:\t\t --\n");
	}

	//sum of 4
	if (used[3] == 1)
	{
		printf("4. Sum of 4's:\t %d\t\t", score_card[3]);
	}
	else
	{
		printf("4. Sum of 4's:\t --\t\t");
	}

	//small straight
	if (used[9] == 1)
	{
		printf("10. Small straight:\t %d\n", score_card[9]);
	}
	else
	{
		printf("10. Small straight:\t --\n");
	}

	//sum of 5s
	if (used[4] == 1)
	{
		printf("5. Sum of 5's:\t %d\t\t", score_card[4]);
	}
	else
	{
		printf("5. Sum of 5's:\t --\t\t");
	}

	//large straight
	if (used[10] == 1)
	{
		printf("11. Large straight:\t %d\n", score_card[10]);
	}
	else
	{
		printf("11. Large straight:\t --\n");
	}

	//sum of 6
	if (used[5] == 1)
	{
		printf("6. Sum of 6's:\t %d\t\t", score_card[5]);
	}
	else
	{
		printf("6. Sum of 6's:\t --\t\t");
	}

	//yahtzee
	if (used[11] == 1)
	{
		printf("12. Yahtzee:\t\t %d\n", score_card[11]);
	}
	else
	{
		printf("12. Yahtzee:\t\t --\n");
	}

	//chance
	if (used[12] == 1)
	{
		printf("\t\t\t\t13. Chance:\t\t %d\n\n", score_card[12]);
	}
	else
	{
		printf("\t\t\t\t13. Chance:\t\t --\n\n");
	}

	printf("Total upper score (must be 63 or higher for bonus): %d\n\n", score_card[14]);

	/*printf("\n\n1. Sum of 1's:\t %d\t\t", score_card[0]);
	printf("7. Three-of-a-kind:\t %d\n", score_card[6]);
	printf("2. Sum of 2's:\t %d\t\t", score_card[1]);
	printf("8. Four-of-a-kind:\t %d\n", score_card[7]);
	printf("3. Sum of 3's:\t %d\t\t", score_card[2]);
	printf("9. Full house:\t\t %d\n", score_card[8]);
	printf("4. Sum of 4's:\t %d\t\t", score_card[3]);
	printf("10. Small straight:\t %d\n", score_card[9]);
	printf("5. Sum of 5's:\t %d\t\t", score_card[4]);
	printf("11. Large straight:\t %d\n", score_card[10]);
	printf("6. Sum of 6's:\t %d\t\t", score_card[5]);
	printf("12. Yahtzee:\t\t %d\n", score_card[11]);
	printf("\t\t\t\t13. Chance:\t\t %d\n\n", score_card[12]);

	*/
}


/*************************************************************
* Function: show_dice()						                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: clears the screen then prints player number,	*
*				round number, and dice						*
*															*
* Input parameters: roll[], round_number, player_number     *
* Returns: void			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void *show_dice(int *roll, int round_number, int player_number)
{
	system("cls");

	printf("Player %d\n", player_number);
	printf("Round number: %d\n\n", round_number);

	printf("dice 1: %d\n", roll[0]);
	printf("dice 2: %d\n", roll[1]);
	printf("dice 3: %d\n", roll[2]);
	printf("dice 4: %d\n", roll[3]);
	printf("dice 5: %d\n", roll[4]);

}


/*************************************************************
* Function: which_score()					                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: asks the player which combination to use.	*
*															*
* Input parameters: void                                    *
* Returns: int			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int which_score(void)
{
	int position = 0;
	printf("where would you like to add this score?");
	scanf("%d", &position);

	system("cls");

	return position;

}


/*************************************************************
* Function: enter_score()					                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: enters the roll in the selected combination	*
*				space										*
*															*
* Input parameters: position, scorecard[], used[], roll[]   *
* Returns: int			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int* enter_score(int position, int* scorecard, int* used, int* roll)
{
	int array_position = position - 1;
	int list[7] = { 0 };

	if (used[array_position] == 0) // checks to make sure the position isnt used yet
	{
		if (position > 0 && position <= 6) // checks to see if this will be in the top part of the scorecard
		{
			for (int i = 0; i != 5; i++) // loops 5 times
			{
				if (roll[i] == position) // checks to see if the roll is equal to the position
				{
					scorecard[array_position] += position; // adds every dice that matches position
				}


			}

		}
		else if (position == 7) // checks to see if position is 7 for three of a kind
		{
			for (int i = 0; i != 5; i++) // loops 5 times
			{
				++list[roll[i]]; // creates a list of how many times each number is rolled

			}
			if (list[1] >= 3 || list[2] >= 3 || list[3] >= 3 || list[4] >= 3 || list[5] >= 3 || list[6] >= 3) //checks to see if any of the numbers were rolled 3 times
			{
				scorecard[array_position] = roll[0] + roll[1] + roll[2] + roll[3] + roll[4]; // adds all dice if there was a three of a kind
			}
			else
			{
				scorecard[array_position] = 0; // scorecard is 0 in the 3 of a kind position if there isnt a 3 of a kind
			}

		}
		else if (position == 8)
		{
			for (int i = 0; i != 5; i++)
			{
				++list[roll[i]];

			}
			if (list[1] >= 4 || list[2] >= 4 || list[3] >= 4 || list[4] >= 4 || list[5] >= 4 || list[6] >= 4)
			{
				scorecard[array_position] = roll[0] + roll[1] + roll[2] + roll[3] + roll[4];
			}
			else
			{
				scorecard[array_position] = 0;
			}

		}
		else if (position == 9)
		{
			for (int i = 0; i != 5; i++)
			{
				++list[roll[i]];

			}
			if ((list[1] == 3 || list[2] == 3 || list[3] == 3 || list[4] == 3 || list[5] == 3 || list[6] == 3) && (list[1] == 2 || list[2] == 2 || list[3] == 2 || list[4] == 2 || list[5] == 2 || list[6] == 2))
			{
				scorecard[array_position] = 25;
			}
			else
			{
				scorecard[array_position] = 0;
			}
		}
		else if (position == 10)
		{
			for (int i = 0; i != 5; i++)
			{
				++list[roll[i]];

			}
			if ((list[1] >= 1 && list[2] >= 1 && list[3] >= 1 && list[4] >= 1) || (list[2] >= 1 && list[3] >= 1 && list[4] >= 1 && list[5] >= 1) || (list[3] >= 1 && list[4] >= 1 && list[5] >= 1 && list[6] >= 1))
			{
				scorecard[array_position] = 30;
			}
			else
			{
				scorecard[array_position] = 0;
			}
		}
		else if (position == 11)
		{
			for (int i = 0; i != 5; i++)
			{
				++list[roll[i]];

			}
			if ((list[1] == 1 && list[2] == 1 && list[3] == 1 && list[4] == 1 && list[5] == 1) || (list[2] == 1 && list[3] == 1 && list[4] == 1 && list[5] == 1 && list[6] == 1))
			{
				scorecard[array_position] = 40;
			}
			else
			{
				scorecard[array_position] = 0;
			}
		}
		else if (position == 12)
		{
			for (int i = 0; i != 5; i++)
			{
				++list[roll[i]];

			}
			if (list[1] == 5 || list[2] == 5 || list[3] == 5 || list[4] == 5 || list[5] == 5 || list[6] == 5)
			{
				scorecard[array_position] = 50;
			}
			else
			{
				scorecard[array_position] = 0;
			}

		}
		else if (position == 13)
		{
		scorecard[array_position] = roll[0] + roll[1] + roll[2] + roll[3] + roll[4];
		}


		scorecard[14] = scorecard[0] + scorecard[1] + scorecard[2] + scorecard[3] + scorecard[4] + scorecard[5];
		used[array_position] = 1;

	}
}


/*************************************************************
* Function: end_of_game()					                *
* Date Created: 10/30/2020	                                *
* Date Last Modified: 10/30/2020                            *
*															*
* Description: prints the players scores and the winner		*
*															*
* Input parameters: scorecard1[], scorecard2[]              *
* Returns: void			                                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void end_of_game(int* scorecard1, int* scorecard2)
{
	int player1_score = scorecard1[14] + scorecard1[6] + scorecard1[7] + scorecard1[8] + scorecard1[9] + scorecard1[10] + scorecard1[11] + scorecard1[12];
	int player2_score = scorecard2[14] + scorecard2[6] + scorecard2[7] + scorecard2[8] + scorecard2[9] + scorecard2[10] + scorecard2[11] + scorecard2[12];

	if (scorecard1[14] >= 63)
	{
		player1_score += 35;
	}
	if (scorecard2[14] >= 63)
	{
		player2_score += 35;
	}

	printf("Player 1 score: %d\t Player 2 score: %d\n", player1_score, player2_score);

	if (player1_score > player2_score)
	{
		printf("Player 1 is the winner!!!\n\n");
	}
	else if (player2_score > player1_score)
	{
		printf("Player 2 is the winner!!!\n");
	}
	else
	{
		printf("Draw");
	}
}