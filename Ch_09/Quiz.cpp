// modify ch 8 question 3 for this quiz t include handling out of bound numbers
// or extranious characters


#include <iostream>
#include "random.h"
#include <limits>

void clearLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearCin()
{
	std::cin.clear();
	clearLine();
}


int getUserGuess(int count, int min, int max)
{
	
	int input;
	std::cout << "Guess #" << count << ": ";
	std::cin >> input;
	std::cout << '\n';

	if (!std::cin) // invalid input such as letters
	{
		clearCin();
		
		std::cout << "Error: Invalid Input, please try again." << '\n';
		input = getUserGuess(count, min, max);
		return input;
	}

	if (std::cin.peek() != '\n') // check to ensure the buffer is clear if not, clear it
	{
		clearLine();
	}


	if (input < min || input > max) // check if input is within range
	{
		std::cout << "That number is not between " << min << " and " << max << ". Please try again" << '\n';
		input = getUserGuess(count, min, max);
		return input;
	}

	return input;
}

bool playAgain()
{

	char response{};
	while (true)
	{
		std::cout << "Play again? y/n?: ";
		std::cin >> response;

		if (std::cin.peek() != '\n') // for sake of quiz throw error if input more than one char
		{
			std::cout << "thats too many characters, please input either Y or N" << '\n';
			clearLine();
		}
		else
		{
			if (response == 'n')
			{
				std::cout << "Ok, Have a nice day!";
				return false;
			}
			if (response == 'y')
			{
				return true;
			}
		}
	}
}



int main()
{
	int maxGuess{ 7 };
	int numMin{ 1 };
	int numMax{ 100 };

	do 
	{
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
		int guess {};
		const int num {Random::get(numMin, numMax)};
		for (int i{1}; i <= maxGuess; ++i)
		{
			guess = getUserGuess(i, numMin, numMax);

			if (guess == num)
			{
				std::cout << "You Win!" << '\n';
				break;

			}
			else if (guess < num)
				std::cout << "Your guess is too low" << '\n';
			else
				std::cout << "Your guess is too high" << '\n';
		}

	} while (playAgain());


	return 0;
}