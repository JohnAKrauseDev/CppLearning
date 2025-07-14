//#include <iostream>
//
//// Gets tower height from user and returns it
//double getTowerHeight()
//{
//	std::cout << "Enter the height of the tower in meters: ";
//	double towerHeight{};
//	std::cin >> towerHeight;
//	return towerHeight;
//}
//
//// Returns the current ball height after "seconds" seconds
//double calculateBallHeight(double towerHeight, int seconds)
//{
//	const double gravity{ 9.8 };
//
//	// Using formula: s = (u * t) + (a * t^2) / 2
//	// here u (initial velocity) = 0, so (u * t) = 0
//	const double fallDistance{ gravity * (seconds * seconds) / 2.0 };
//	const double ballHeight{ towerHeight - fallDistance };
//
//	// If the ball would be under the ground, place it on the ground
//	if (ballHeight < 0.0)
//		return 0.0;
//
//	return ballHeight;
//}
//
//// Prints ball height above ground
//void printBallHeight(double ballHeight, int seconds)
//{
//	if (ballHeight > 0.0)
//		std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
//	else
//		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
//}
//
//// Calculates the current ball height and then prints it
//// This is a helper function to make it easier to do this
//
//int loopTillGround (const double towerHeight)
//{
//	double ballHeight{ towerHeight };
//	int seconds{ -1 };
//
//	while (ballHeight > 0)
//	{
//		ballHeight = calculateBallHeight(towerHeight, ++seconds);
//		printBallHeight(ballHeight, seconds);
//	}
//
//	return seconds;
//}
//
//
//int main()
//{
//	const double towerHeight{ getTowerHeight() };
//
//	loopTillGround(towerHeight);
//
//	return 0;
//}

//
////Question 2
//
//// Make sure that assert triggers even if we compile in release mode
//#undef NDEBUG
//
//#include <cassert> // for assert
//#include <iostream>
//
//bool isPrime(int x)
//{
//    if (x <= 1)
//        return false;
//    if (x != 2 && !(x % 2))
//        return false;
//
//    for (int i{ 3}; i*i <= x; i= i+2) // this auto ends when x = 2
//    {
//        if (x % i ==0)
//            return false;
//    }
//    return true;
//    // write this function using a for loop
//}
//
//int main()
//{
//    assert(!isPrime(0)); // terminate program if isPrime(0) is true
//    assert(!isPrime(1));
//    assert(isPrime(2));  // terminate program if isPrime(2) is false
//    assert(isPrime(3));
//    assert(!isPrime(4));
//    assert(isPrime(5));
//    assert(isPrime(7));
//    assert(!isPrime(9));
//    assert(isPrime(11));
//    assert(isPrime(13));
//    assert(!isPrime(15));
//    assert(!isPrime(16));
//    assert(isPrime(17));
//    assert(isPrime(19));
//    assert(isPrime(97));
//    assert(!isPrime(99));
//    assert(isPrime(13417));
//
//    std::cout << "Success!\n";
//
//    return 0;
//}


////Question 3
//
//#include <iostream>
//#include "random.h"
//
//bool playAgain()
//{
//
//	char response{};
//	while (true)
//	{
//		std::cout << "Play again? y/n?: ";
//		std::cin >> response;
//
//		if (response == 'n')
//		{
//			std::cout << "Ok, Have a nice day!";
//			return false;
//		}
//		if (response == 'y')
//			return true;
//
//	}
//}
//
//
//
//int main()
//{
//	int maxGuess{ 7 };
//	int numMin{ 1 };
//	int numMax{ 100 };
//
//	do 
//	{
//		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
//		int guess {};
//		const int num {Random::get(numMin, numMax)};
//		for (int i{1}; i <= maxGuess; ++i)
//		{
//			std::cout << "Guess #" << i << ": ";
//			std::cin >> guess;
//			std::cout << '\n';
//
//			if (guess == num)
//			{
//				std::cout << "You Win!" << '\n';
//				break;
//
//			}
//			else if (guess < num)
//				std::cout << "Your guess is too low" << '\n';
//			else
//				std::cout << "Your guess is too high" << '\n';
//		}
//
//	} while (playAgain());
//
//
//	return 0;
//}
//
//// i have discovered through thid that if i have a nested while, the inner while can change things so teh outer while is false 
////but it will not end the outer while unless i break the inner while ie loops dont end if im within nested blocks
