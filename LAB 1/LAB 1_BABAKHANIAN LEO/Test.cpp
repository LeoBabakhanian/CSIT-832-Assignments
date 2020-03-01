//LAB 1 - BABAKHANIAN LEO
//CSIT 832

#include <iostream>
using namespace std;

double PowerFunction(double, double);
double AdditionReverse(double, bool);
double Addition(double, bool, double);
double Validation(double);
double ValidationPower(double);
double Setup();

//Modified addition functions to print from within
//Modified case 2 and case 3 to have a function that prints prompts
//Modified cin.fail() check with a function to check it
//Modified cases to have default case for incorrect input over 4

int main()
{
	int choice;

	do
	{
		//menu
		cout << "1) Raise x to the power of n" << endl;
		cout << "2) Add the first n terms of the series" << endl;
		cout << "3) Add the first n terms of the series (reverse order)" << endl;
		cout << "4) Quit" << endl;
		cin >> choice;
		
		//data type validation
		if (cin.fail() || choice <= 0)
			cout << "Invalid entry. Please try again." << endl;

		choice = Validation(choice);

		switch (choice)
		{
			//Power function option
		case 1:
		{
			double n, x, answer;

			cout << "Enter base" << endl;
			cin >> x;

			//I decided to change the way I made my validation and used the cin.fail() function itself to do this throughout my program
			//Validate user inputs
			if (cin.fail())
				cout << "Incorrect entry. Please try again.\nEnter base." << endl;
			//data type validation
			x = ValidationPower(x);

			cout << "Enter power (can be positive or negative)" << endl;
			cin >> n;

			//Validate user inputs
			if (cin.fail())
				cout << "Incorrect entry. Please try again.\nEnter power." << endl;
			//data type validation
			n = ValidationPower(n);

			//We transfer our user inputs into the function for it to calculate and print it out below
			answer = PowerFunction(x, n);
			cout << '\n' << x << "^" << n << " = " << answer << '\n' << endl;
			//output sample: 2^3 = 8
			//test cases match
			break;
		}
		//Addition function option
		case 2:
		{
			Addition(Setup(), true, 1);
			//output sample 1/1 + 1/2 + 1/3 = 1.83333
			break;
		}
		//Addition Reverse function option
		case 3:
		{
			AdditionReverse(Setup(), true);
			//output sample 1/3 + 1/2 + 1/1 = 1.83333
			break;
		}
		//Quit
		case 4:
			cout << "Quitting program..." << endl;
			break;
		//Default
		default:
			cout << "Invalid entry. Please try again." << endl;
			break;
		}
	} while (choice != 4);

	system("PAUSE");
	return 0;
}

//Power Function
double PowerFunction(double base, double exponent)
{
	if (exponent > 0)
		return (base*PowerFunction(base, exponent - 1));
	//Recursive formula if number is positive
	else if (exponent < 0)
		return (1 / base)*(PowerFunction(base, exponent + 1));
	//Recursive formula if number is negative
	else if (exponent == 0)
		return 1;
	//If number is 0 return 1
	else if (exponent == 1)
		return base;
	//If number is 1 return the base number
}

//Addition Function
double Addition(double n, bool test, double i)
{
	double result;

	//If user enters 1 return 1
	if (n == i)
	{
		cout << "1/" << i;

		return 1 / n;
	}
	else
	{
		cout << "1/" << i << " + ";
		//Recursive formula
		result = 1 / i + Addition(n, false, i + 1);

		if (test)
			cout << " = " << result << "\n";

		return result;
	}
}

//Addition Function
double AdditionReverse(double n, bool test)
{
	double result;

	//If user enters 1 return 1
	if (n == 1)
	{
		cout << "1/" << n << " = ";
		return 1;
	}
	else
	{
		cout << "1/" << n << " + ";
		//Recursive formula
		result = 1 / n + AdditionReverse(n - 1, false);

		if (test)
			cout << result << "\n";

		return result;
	}
}

double Validation(double input)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin >> input;
	}

	while (input <= 0)
	{
		cin.clear();
		cin.ignore();
		cin >> input;
	}

	return input;
}

double ValidationPower(double input)
{
	//Special function that allows user to enter negative base and power
	//If I used the regular validation function the user would not be able to enter negative inputs for case 1
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin >> input;
	}

	return input;
}

double Setup()
{
	double n;

	cout << "Enter n (positive integer only)" << endl;
	cin >> n;

	//Validate user inputs
	if (cin.fail() || n <= 0)
		cout << "Incorrect entry. Please try again.\nEnter n." << endl;

	//data type validation
	n = Validation(n);
	
	return n;
}