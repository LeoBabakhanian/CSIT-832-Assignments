//BABAKHANIAN, LEO
//CO SCI 836
//LAB #5

/*OUTPUT AT BOTTOM OF PROGRAM
Input file located in project directory*/

#include <iostream>
#include <fstream>
#include "Records.h"
using namespace std;

int main()
{
	const int SIZE = 100;
	Records r[SIZE];
	Records unsorted[SIZE];
	int n = 0;
	char choice;
	//Call set function
	r->inputFile(r, n);

	//Create shallow copy of our records array so that it stays unaltered by the sort functions
	for (int i = 0; i < n; i++)
	{
		unsorted[i] = r[i];
	}

	//Menu
	do
	{
		cout << "SORTING MENU\n" <<
			"==========================\n" << 
			"1) Print records unsorted\n" <<
			"2) Selection sort\n" << 
			"3) Insertion sort\n" << 
			"4) Quick sort\n" << 
			"5) Bubble sort\n" << 
			"Q) Quit" << endl;
		cin >> choice;
		
		//Sorting is done by GPA
		switch (choice)
		{
		case '1':
			cout << endl;
			//Call print function
			//Pass unsorted Records array
			r->print(unsorted, n); 
			break;

		case '2':
			cout << endl;
			//Call selection sort function
			r->selectionSort(r, n);
			break;

		case '3':
			cout << endl;
			//Call insertion sort function
			r->insertionSort(r, n);
			break;

		case '4':
			cout << endl;
			//Call quick sort function
			r->quickSort(r, n);
			break;

		case '5':
			cout << endl;
			//Call bubble sort function
			r->bubbleSort(r, n);
			break;

		case 'q' : case 'Q' :
			//Quiting program
			cout << endl << "Qutting..." << endl; 
			break;

		default:
			//Default
			cout << endl << "Invalid choice. Please try again. " << endl;
		}

		cout << endl;

	} while (choice != 'q' && choice != 'Q');

	return 0;
}

/****OUTPUT SAMPLE*** of options 1 and 2
SORTING MENU
==========================
1) Print records unsorted
2) Selection sort
3) Insertion sort
4) Quick sort
5) Bubble sort
Q) Quit
1

Mary    Jones   3.9     887196478       may.jones@pierce.edu
John    Doe     3.5     922415674       johndoe@gmail.com
Mary    Sue     3.2     110456827       sue-mary@yahoo.com
Mike    Smith   3.7     101457621       msmith@gmail.com
Ben     Murray  2.6     556778898       benmurr@pierce.edu
Albert  Jones   3.1     122010560       albert.jones56@hotmail.com
Alysa   James   3.4     170556486       dptrson1990@gmail.com
Gerald  Taylor  2.8     144578913       geraldtaylor556@pierce.edu
Brenda  Miller  4.1     199283452       b.mill446@yahoo.com
Kevin   Jones   3.8     114140061       kjones1992@gmail.com
Tom     Hill    4.2     001424256       t.hill232@pierce.edu
Suzy    Allen   3.1     992302300       allensuzy@hotmail.com
Chuck   Norris  4.5     110554004       cnorris@gmail.com
Tommy   Turner  2.2     430402747       tturnertt@yahoo.com
James   Morris  2       193293903       jjmorris1121@gmail.com
Jill    Tucker  3.6     320392312       jtuck23@yahoo.com

SORTING MENU
==========================
1) Print records unsorted
2) Selection sort
3) Insertion sort
4) Quick sort
5) Bubble sort
Q) Quit
2

James   Morris  2       193293903       jjmorris1121@gmail.com
Tommy   Turner  2.2     430402747       tturnertt@yahoo.com
Ben     Murray  2.6     556778898       benmurr@pierce.edu
Gerald  Taylor  2.8     144578913       geraldtaylor556@pierce.edu
Albert  Jones   3.1     122010560       albert.jones56@hotmail.com
Suzy    Allen   3.1     992302300       allensuzy@hotmail.com
Mary    Sue     3.2     110456827       sue-mary@yahoo.com
Alysa   James   3.4     170556486       dptrson1990@gmail.com
John    Doe     3.5     922415674       johndoe@gmail.com
Jill    Tucker  3.6     320392312       jtuck23@yahoo.com
Mike    Smith   3.7     101457621       msmith@gmail.com
Kevin   Jones   3.8     114140061       kjones1992@gmail.com
Mary    Jones   3.9     887196478       may.jones@pierce.edu
Brenda  Miller  4.1     199283452       b.mill446@yahoo.com
Tom     Hill    4.2     001424256       t.hill232@pierce.edu
Chuck   Norris  4.5     110554004       cnorris@gmail.com

Sort             Field   Comparisons     Movements
=====================================================
Selection        GPA       23            14

SORTING MENU
==========================
1) Print records unsorted
2) Selection sort
3) Insertion sort
4) Quick sort
5) Bubble sort
Q) Quit
q

Qutting...
*/