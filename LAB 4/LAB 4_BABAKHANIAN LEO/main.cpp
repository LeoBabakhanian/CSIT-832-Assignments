//BABAKHANIAN, LEO
//CO SCI 836
//LAB #4

#include <iostream>
#include <string>
#include "GraphType.cpp"
using namespace std;

//****OUTPUT IS AT BOTTOM OF MAIN****

int main()
{
	int maxV = 5;

	//creating graph 
	GraphType<char> graph(maxV);
	string vname;

	//vertices from 'A' to 'E'
	for (int i = 0; i < maxV; i++) 
	{
		char ch = i+'A';
		graph.AddVertex(ch);
	}

	//add edges
	graph.AddEdge('A','B', 2);
	graph.AddEdge('A','D', 2);
	graph.AddEdge('B','E', 1);
	graph.AddEdge('B','C', 4);
	graph.AddEdge('C','E', 3);
	graph.AddEdge('D', 'E', 3);

    //checking for edge from 'A' to 'C'
	cout << "Checking edge A-C : ";

	if (graph.EdgeExists('A', 'C')) 
	{
		cout << "Edge from 'A' to 'C' exists" << endl;
	}
	else
	{
		cout << "Edge from 'A' to 'C' does not exist" << endl;
	}

    //checking for edge from 'A' to 'D'

	cout << "Checking edge A-D : ";

	if (graph.EdgeExists('A', 'D'))
	{
		cout << "Edge from 'A' to 'D' exists" << endl;
	}
	else 
	{
		cout << "Edge from 'A' to 'D' does not exist" << endl;
	}

	cout << "Deleting edge A-D" << endl;
	graph.DeleteEdge('A', 'D');

	cout << "Checking edge A-D : ";

	if (graph.EdgeExists('A', 'D')) 
	{
		cout << "Edge from 'A' to 'D' exists" << endl;
	}
	else 
	{
		cout << "Edge from 'A' to 'D' does not exist" << endl;
	}

	system("PAUSE");
	return 0;
}

/* Output:
====================
Checking edge A-C : Edge from 'A' to 'C' does not exist
Checking edge A-D : Edge from 'A' to 'D' exists
Deleting edge A-D
Checking edge A-D : Edge from 'A' to 'D' does not exist
Press any key to continue . . .
*/