#include <cstdlib>
#include <iostream>
#include <time.h>

int main(void)
{
	std::cout << "Welcome to My Game!"
	<< " If you wish to end the game, enter -1" << std::endl;
	int min = 1, max = 100;
	bool correct = false;
	bool endgame = false;
	srand(time(NULL));
	int val = rand() % max + min;
	std::cout << "Guess a number between "
 		<< min << " and " << max << std::endl;
	for (int tries = 1; !correct && !endgame; tries++)
	{
		std::cout << "Enter Number: ";
		int guess;
		std::cin >> guess;
		if (guess == -1) endgame = true;
		else if (guess == val) {
			correct = true;
			std::cout << "Correct! You won after " 
				<< tries << " tries." << std::endl;
		}
		else if (guess > val)
			std::cout << "Too high, try again." << std::endl;
		else std::cout << "Too low, try again." << std::endl;
	}
	std::cout << "Game Over" << std::endl;
	if (endgame) std::cout << "Number was " << val << std::endl;
	return 0;
}
