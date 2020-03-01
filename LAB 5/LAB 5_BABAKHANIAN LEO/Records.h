#ifndef RECORDS_H
#define RECORDS_H
using namespace std;

class Records
{
private:
	//variables
	string first, last, email, IDnum;
	int compareS = 0, compareI = 0, compareQ = 0, moveS = 0, moveI = 0, moveQ = 0;
	double GPA;

public:
	//set functions
	void setFirst(string);
	void setLast(string);
	void setEmail(string);
	void setID(string);
	void setGPA(double);
	//get functions
	string getFirst();
	string getLast();
	string getEmail();
	string getID();
	double getGPA();
	//input file & print functions
	void inputFile(Records[], int&);
	void print(Records[], int&);
	void print_(string, int, int);
	//sort functions
	void selectionSort(Records[], int&);
	void insertionSort(Records[], int&);
	void quickSort(Records[], int&);
	void bubbleSort(Records[], int&);
	int partition(Records[], int, int);
	void quickSort_(Records[], int, int);
};

#endif