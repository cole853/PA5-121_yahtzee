/*
	Programmer: Cole Clark
	Date: 10-27-2020

	Description: PA5 game of Yahtzee
*/

#include "yahtzee.h"

int main(void)
{
	int checked_option = 0;
	int quit_game = 0;

	while (quit_game != 1)
	{
	srand((unsigned int)time(NULL));

	int selected_option = 0;
	int* roll[5] = { 0 };
	int* rr[5] = { 0 };
	int* new_roll[5] = { 0 };
	int* scorecard1[15] = { 0 };
	int* scorecard2[15] = { 0 };
	int* used1[13] = { 0 };
	int* used2[13] = { 0 };
	int number_of_players = 0;
	int rr_or_s = 0;
	int number_of_rr = 0;
	int number_of_rolls = 0;
	int position = 0;
	int already_used = 1;
	int already_used2 = 0;


	

		while (quit_game != 1 && checked_option != 2)
		{

			selected_option = game_menu(); // prints game menu and stores the user input as selected_option
			checked_option = check_menu_option(selected_option); // checks the selected option to make sure it is within the proper range and returns selected_option if it is

			if (checked_option == 3)
			{
				quit_game = 1;
			}
		}

		checked_option = 0;

		if (quit_game != 1)
		{

			system("cls"); // clears the screen after the menu

			for (int i = 1; i != 14; ++i)
			{
				roll_five_dice(roll, 1, i); // asks the player to enter 1 to roll then rolls 5 dice and stores them in the array named roll
				//system("pause");

				show_dice(roll, i, 1); // clears the screen then prints the player number, round number and dice
				rr_or_s = reroll_or_score(); // asks the user if they want to reroll any or score

				for (number_of_rolls = 1; number_of_rolls != 3 && rr_or_s != 2; ++number_of_rolls) // j is the amount of rolls this round
				{
					//system("cls");
					show_dice(roll, i, 1); // clears the screen then prints the player number, round number and dice

					if (rr_or_s == 1) //if the player wants to reroll
					{
						number_of_rr = reroll_how_many(); // asks the player how many to reroll and stores the number in number_of_rr
						get_reroll(rr, number_of_rr); //asks the player which dice to reroll and stores the numbers in reroll
						reroll(roll, rr, number_of_rr); //rerolls dice the player wanted to reroll
						show_dice(roll, i, 1); //clears the screen then prints the round number and dice
					}
					if (number_of_rolls != 2) // if there havent been 3 rolls
					{
						rr_or_s = reroll_or_score(); // asks the user if they want to reroll any or score
					}
				}

				show_dice(roll, i, 1); //clears the screen then prints the player number, round numberand dice
				enter_menu(scorecard1, used1);
				position = which_score();
				already_used = used1[position - 1];
				enter_score(position, scorecard1, used1, roll);
				//already_used = used1[position - 1];

				while (already_used == 1)
				{
					show_dice(roll, i, 1); //clears the screen then prints the player number, round numberand dice
					enter_menu(scorecard1, used1);
					position = which_score();
					already_used = used1[position - 1];
					enter_score(position, scorecard1, used1, roll);
					//already_used = used1[position - 1];
				}
				//enter_score(position, scorecard1, used1, roll);

				enter_menu(scorecard1, used1);
				system("pause");
				system("cls");


				//setup for next player

				number_of_rolls = 0;

				//NEXT PLAYER

				roll_five_dice(roll, 2, i); // asks the player to enter 1 to roll then rolls 5 dice and stores them in the array named roll
				//system("pause");

				show_dice(roll, i, 2); //clears the screen then prints the player number, round numberand dice
				rr_or_s = reroll_or_score(); // asks the user if they want to reroll any or score

				for (number_of_rolls = 1; number_of_rolls != 3 && rr_or_s != 2; ++number_of_rolls) // j is the amount of rolls this round
				{
					//system("cls");
					show_dice(roll, i, 2); //clears the screen then prints the player number, round numberand dice

					if (rr_or_s == 1) //if the player wants to reroll
					{
						number_of_rr = reroll_how_many(); // asks the player how many to reroll and stores the number in number_of_rr
						get_reroll(rr, number_of_rr); //asks the player which dice to reroll and stores the numbers in reroll
						reroll(roll, rr, number_of_rr); //rerolls dice the player wanted to reroll
						show_dice(roll, i, 2); //clears the screen then prints the player number, round numberand dice
					}
					if (number_of_rolls != 2) // if there havent been 3 rolls
					{
						rr_or_s = reroll_or_score(); // asks the user if they want to reroll any or score
					}
				}

				show_dice(roll, i, 2); //clears the screen then prints the player number, round numberand dice
				enter_menu(scorecard2, used2);
				position = which_score();
				already_used = used2[position - 1];
				enter_score(position, scorecard2, used2, roll);
				

				while (already_used == 1)
				{
					show_dice(roll, i, 2); //clears the screen then prints the player number, round numberand dice
					enter_menu(scorecard2, used2);
					position = which_score();
					already_used = used2[position - 1];
					enter_score(position, scorecard2, used2, roll);
					
				}
				//enter_score(position, scorecard1, used1, roll);

				enter_menu(scorecard2, used2);
				system("pause");
				system("cls");

				//setup for next player

				number_of_rolls = 0;

			}

			end_of_game(scorecard1, scorecard2);

			system("pause");
			system("cls");
		}
	}
}