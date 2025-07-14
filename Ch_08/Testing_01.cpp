#include <iostream>
#include <random>


//// this was a test to figure out switch, 
//// it seems every case after chosen csae also runs unless its in a funct rto return or otherwise skipped
// to skipp out use break to say drop out of switch but not the function
//int main()
//{
//	int x{ 2 };
//
//	switch(x)
//	{
//	case 1:
//		std::cout << "one";
//	case 2:
//		std::cout << "no";
//	case 3:
//		std::cout << "yes";
//
//	}
//
//	return 0;
//}

////8.6 quiz
//
//int calculate(int a, int b, char math)
//{
//	switch (math)
//	{
//	case '+':
//		return a + b;
//	case '-':
//		return a - b;
//	case '/':
//		return a / b;
//	case '*':
//		return a * b;
//	case '%':
//		return a % b;
//	default :
//		std::cout << "invalid operator";
//		return 0;
//	}
//}
//
//int main()
//{
//	int a;
//	int b;
//	char c;
//	std::cout << "input int: ";
//	std::cin >> a;
//	std::cout << '\n'<< "input another int: ";
//	std::cin >> b;
//	std::cout << '\n' << "What operation (+, -, *, /, %): ";
//	std::cin >> c;
//
//	std::cout << '\n' << calculate(a, b, c);
//	return 0;
//}

//// im stupid, gotta remember how < works
//int main()
//{
//	std::cout << (10 < 10);
//}

//// 8.8 Quiz #2
//
//int main()
//{
//
//	char letter{ 'a' };
//	while (letter <= 'z')
//	{
//		std::cout << letter << static_cast<int>(letter) << '\n';
//		++letter;
//	}
//
//
//
//	return 0;
//}


////8.8 Quiz #3
//
//int main()
//{
//	int xiii{ 5 };
//	while (xiii >= 1)
//	{
//		int yiii{ xiii };
//		while (yiii >= 1)
//		{
//			std::cout << yiii-- << ' ';
//			
//
//		}
//
//		--xiii;
//		std::cout << '\n';
//
//	}
//
//	return 0;
//}

////8.8 Quiz #4
//
//int main()
//{
//	int outter{ 1 };
//	while (outter <= 5)
//	{
//		int inner{ 5 };
//		while (inner > 0)
//		{
//			if (inner > outter)
//				std::cout << ' ' << ' ';
//			else
//				std::cout << inner << ' ';
//			--inner;
//		}
//		std::cout << '\n';
//		outter++;
//	}
//
//	return 0;
//}



////quiz 8.10 #1
//
//int main()
//{
//	for (int iii{ 0 }; iii <= 20; ++iii)
//	{
//		std::cout << iii << '\n';
//	}
//
//	return 0;
//}

////8.10 quiz #2
//
//int sumTo(int x)
//{
//	int sum{};
//	for (int iii{ 0 }; iii <= x; ++iii)
//	{
//		sum += iii;
//	}
//	return sum;
//}
//
//int main()
//{
//	int x;
//	std::cout << "Enter an integer: ";
//	std::cin >> x;
//	std::cout << '\n' << sumTo(x);
//
//	return 0;
//}

////8.10 quiz #4
//
//void fizbuzz(int max)
//{
//
//	for (int iii{ 1 }; iii <= max; ++iii)
//	{
//		if (!(iii % 3))
//		{
//			std::cout << "fizz";
//			if (!(iii % 5))
//				std::cout << "buzz";
//		}
//		else if (!(iii % 5))
//			std::cout << "buzz";
//		else
//			std::cout << iii;
//		std::cout << '\n';
//	}
//
//
//
//}
//
//int main()
//{
//		int x;
//	std::cout << "Enter an integer: ";
//	std::cin >> x;
//	fizbuzz(x);
//
//	return 0;
//}

////8.10 quiz #5
//
//void fizbuzz(int max)
//{
//
//	for (int iii{ 1 }; iii <= max; ++iii)
//	{
//		if (!(iii % 3))
//			std::cout << "fizz";
//		if (!(iii % 5))
//			std::cout << "buzz";
//		if (!(iii % 7))
//			std::cout << "pop";
//		if (iii%3 && iii%5 && iii%7)
//			std::cout << iii;
//		std::cout << '\n';
//	}
//
//
//
//}
//
//int main()
//{
//		int x;
//	std::cout << "Enter an integer: ";
//	std::cin >> x;
//	fizbuzz(x);
//
//	return 0;
//}


//// testing mersenne twister
//
//int main()
//{
//	std::mt19937 ran{};
//
//	std::cout << ran();
//
//	return 0;
//}
////result, you can name the mersenne twister whatever u want, not limited to mt
////in other words i think ran in this case is what im nanming a mt object with default function
////of making a random number