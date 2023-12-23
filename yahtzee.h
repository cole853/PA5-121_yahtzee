/* 
	Programmer: Cole Clark
	Date: 10-27-2020

	Description: PA5 game of Yahtzee
*/

#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
int game_menu(void);


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
int check_menu_option(int selected_option);


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
void print_rules(void);


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
int *roll_five_dice(int *roll, int player_number, int round_number);


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
int reroll_or_score(void);


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
int reroll_how_many(void);


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
int* get_reroll(int* reroll, int number_of_rerolls);


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
int* reroll(int* roll, int* reroll, int number_of_rr);


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
void* enter_menu(int* score_card, int *used);


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
void* show_dice(int* roll, int round_number, int player_number);


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
int which_score(void);


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
int* enter_score(int position, int* scorecard, int* used, int* roll);


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
void end_of_game(int* scorecard1, int* scorecard2);

#endif