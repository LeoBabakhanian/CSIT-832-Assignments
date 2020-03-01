#include <iostream>
#include <fstream>
#include <string>
#include "Records.h"
using namespace std;

//Set functions
void Records::setFirst(string fName)
{
	this->first = fName;
}

void Records::setLast(string lName)
{
	this->last = lName;
}

void Records::setGPA(double GPAnum)
{
	this->GPA = GPAnum;
}

void Records::setID(string ID)
{
	this->IDnum = ID;
}

void Records::setEmail(string eMailAddress)
{
	this->email = eMailAddress;
}

//Get functions
string Records::getFirst()
{
	return first;
}

string Records::getLast()
{
	return last;
}

double Records::getGPA()
{
	return GPA;
}

string Records::getID()
{
	return IDnum;
}

string Records::getEmail()
{
	return email;
}

void Records::inputFile(Records r[], int& n)
{
	//Input file
	ifstream file("input.txt");
	//Call file and read all values
	string fName, lName, IDnum, email, line;
	int lines = 0;
	double GPA;
	
	//Test if file is not opening
	if (!file)
	{
		//If empty, exit program
		cout << "Problem opening file." << endl;
		exit(0);
	}

	//Test for empty input file
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		//If empty, display message and exit the program immediately
		cout << "Empty file" << endl;
		exit(0);
	}

	//While not end of file, run loop
	while (!file.eof())
	{
		//Check to see if there are 100 or more records
		if (n >= 100)
		{
			//If 100 or more, exit program
			cout << "You have more than 100 or more records. Please lower the amount." << endl;
			exit(0);
		}

		file >> fName >> lName >> GPA >> IDnum >> email;
		//Get each value from input file and set them using our set functions
		r[n].setFirst(fName);
		r[n].setLast(lName);
		r[n].setGPA(GPA);
		r[n].setID(IDnum);
		r[n].setEmail(email);

		//Add to counter
		n++;
	}
	file.close();
	//Close the file
}

void Records::print(Records r[], int& n)
{
	//Print records with for loop
	for (int i = 0; i < n; i++)
	{
		cout << r[i].getFirst() << "\t" << r[i].getLast() << "\t" << r[i].getGPA() 
			<< "\t" << r[i].getID() << "\t" << r[i].getEmail() << endl;
	}
}

//Print fields after sort
void Records::print_(string t, int c, int m)
{
	cout << "\nSort\tField\tComparisons\tMovements\n" <<
		"========================================================\n" <<
		t << "\tGPA\t" << c << "\t" << m << endl;
}

//Swap function used for sort functions
void swap(Records* xp, Records* yp)
{
	Records temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Selection sort function
void Records::selectionSort(Records r[], int& n)
{
	string sortType = "Selection";
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;

		for (j = i + 1; j < n; j++)
			if (r[j].GPA < r[min].GPA)
			{
				//Add to comparison counter
				compareS++;
				min = j;
			}

		//Add to movement counter
		moveS++;
		swap(&r[min], &r[i]);
	}

	//Print after sort is complete
	print(r, n);
	print_(sortType, compareS, moveS);
}

//Insertion sort function
void Records::insertionSort(Records r[], int& n)
{
	string sortType = "Insertion";
	int i, j;
	double k;

	for (i = 1; i < n; i++)
	{
		string sortType = "Insertion";
		k = r[i].GPA;
		j = i - 1;
		//Add to movement counter
		moveI++;

		while (j >= 0 && r[j].GPA > k)
		{
			r[j + 1] = r[j];
			j = j - 1;
			//Add to comparison counter
			compareI++;
		}

		//Add to movement counter
		moveI++;
		r[j + 1].GPA = k;
	}

	//Print after sort is complete
	print(r,n);
	print_(sortType, compareI, moveI);
}

//Partition used for quicksort
int Records::partition(Records r[], int l, int h)
{
	double pivot = r[h].getGPA();
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (r[j].getGPA() <= pivot)
		{
			i++;
			swap(&r[i], &r[j]);
			//Add to comparison and movement counter for quicksort
			compareQ++;
			moveQ++;
		}
	}

	swap(&r[i + 1], &r[h]);
	//Add to movement counter for quicksort
	moveQ++;

	return (i + 1);
}

//Quicksort_ function used for actual quicksort function
void Records::quickSort_(Records r[], int l, int h)
{
	if (l < h)
	{
		int pi = partition(r, l, h);

		//Recursive call
		quickSort_(r, l, pi - 1);
		quickSort_(r, pi + 1, h);
	}
}

//Quick sort function
void Records::quickSort(Records r[], int& n)
{
	string sortType = "Quick";
	int x = 0;
	int y = n - 1;

	quickSort_(r, x, y);

	//Print after sort is complete
	print(r, n);
	print_(sortType, compareQ, moveQ);
}

//Bubble sort function
void Records::bubbleSort(Records r[], int& n)
{
	string sortType = "Bubble";
	int i, j, compareB = 0, moveB = 0;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (r[j].GPA > r[j + 1].GPA)
			{
				swap(&r[j], &r[j + 1]);
				//Add to comparison and movement counter
				compareB++;
				moveB++;
			}

	//Print after sort is complete
	print(r, n);
	print_(sortType, compareB, moveB);
}