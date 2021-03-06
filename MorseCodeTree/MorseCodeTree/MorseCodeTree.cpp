// MorseCodeTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Binary_Tree.h"
#include "Morse_Tree.h"

using namespace std;


int main()
{

	cout << "Welcome to the Morse Code Converter!"
		<< endl << endl
		<< "Let's start by loading up our code cipher, from input.txt... ";

	Morse_Tree *m;

	try
	{
		m = new Morse_Tree(ifstream("morse.txt"));
	}
	catch (char e)
	{
		cout << endl << "ERROR: Illegal input detected while attempting to add '" << e << "' to the tree." << endl;
		cout << "Aborting execution..." << endl << endl;
		return 1;
	}

	Morse_Tree morse_tree = *m;

	cout << "Done!" << endl << endl;
	cout << "Time to start reading in the morse code... ";


	system("PAUSE");

	int menuChoice = 0;
	string inputString;

	while (menuChoice != 5)
	{
		system("CLS");
		cout << "Main Menu"
			<< endl << endl
			<< "1. Encode a plaintext string into Morse" << endl
			<< "2. Decode a Morse string back into plaintext" << endl
			<< "3. Display the mapping of all Morse code characters" << endl
			<< "4. Output the morse code tree" << endl
			<< "5. Exit"
			<< endl << endl
			<< "Enter your choice: ";

		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
		{
			cout<< endl << endl
				<< "Okay!  Go ahead and enter a plaintext string below:"
				<< endl << endl;
			cin.ignore();
			getline(cin, inputString);

			cout
				<< endl << endl
				<< "Okay!  That string translates to the following morse code:"
				<< endl << endl;

			cout << morse_tree.encode(inputString) << endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			cout<< endl << endl
				<< "Okay!  Go ahead and enter a morsecode string below:" << endl;
			cin.ignore();
			getline(cin, inputString);

			cout << endl << endl
				<< "Okay!  That string translates to the following plaintext:" << endl;

			cout << morse_tree.decode(inputString) << endl;
			system("PAUSE");
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "The morsecode map we've built for you is as follows:"
				<< endl << endl;
			morse_tree.print_morse_map();

			cout << endl;
			system("PAUSE");
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "The morsecode tree we've built for you is as follows:"
				<< endl << endl;

			morse_tree.print_morse_tree();

			system("PAUSE");
		}
		case 5:
		{
			cout << "Understood.  Goodbye for now!" << endl;
			break;
		}
		default:
		{
			cout << "I'm so sorry, I don't recognize that input." << endl;
			system("PAUSE");
			break;
		}
		}
	}
	return 0;
}