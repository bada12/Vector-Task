#include <iostream>
#include "vector.h"
using namespace std;

void ValidationEnterNumber(int & n);

int main()
{
	vector vect;
	char op;			// var to choose operation
	int item, index;
	cout << "Please enter symbol:\n"
		<< "P - push element,\nI - insert by index,\n"
		<< "D - delete by index,\nC - clear,\n"
		<< "F - find index of element by value,\n"
		<< "S - show, or Q - to exit\n";

	while (cin >> op && tolower(op) != 'q')
	{
		while (cin.get() != '\n')	
			continue;		// skip the rest of the characters in the input
		if (!isalpha(op))	// skip all characters that not be a symbol`s
			continue;
		switch (op)
		{
		case 'P':
		case 'p':
			cout << "Enter number to push: ";
			ValidationEnterNumber(item);
			vect.push(item);
			break;

		case 'I':
		case 'i':
			cout << "Enter index: ";
			ValidationEnterNumber(index);
			cout << "Enter number to insert: ";
			ValidationEnterNumber(item);
			vect.pushByIndex(index, item);
			break;

		case 'D':
		case 'd':
			cout << "Enter index: ";
			ValidationEnterNumber(index);
			vect.popByIndex(index);
			break;

		case 'C':
		case 'c':
			vect.clear();
			break;

		case 'F':
		case 'f':
			cout << "Enter number to find: ";
			ValidationEnterNumber(item);
			index = vect.findIndex(item);
			if (index == -1)
				cout << "You entered: " << item <<
				" but vector does not contain it" << endl;
			else
				cout << "Item: " << item << ", Index: " << index << endl;
			break;

		case 'S':
		case 's':
			cout << vect << endl;
			break;
		default:
			cout << "Please enter correct symbol!\n";
		}
		cout << "Please enter symbol:\n"
			<< "P - push element,\nI - insert by index,\n"
			<< "D - delete by index,\nC - clear,\n"
			<< "F - find index of element by value,\n"
			<< "S - show, or Q - to exit\n";
	}

	vector vectCopy(vect);		// use copy constructor
	cout << "Made a copy: " << vectCopy << endl;

	
	int mas[] = { 5,9,10,34,50 };
	vector vectArray(mas, sizeof(mas) / sizeof(int));
	cout << "Made on the basis of array: " << vectArray << endl; // make vector on the basis of array
	

	vectArray = vectCopy;
	cout << "After = operation: " << vectArray << endl;


	cout << "See you later!\n";
	system("pause");
	return 0;
}


void ValidationEnterNumber(int & n)
{
	while (!(cin >> n))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a number: ";
	}
}