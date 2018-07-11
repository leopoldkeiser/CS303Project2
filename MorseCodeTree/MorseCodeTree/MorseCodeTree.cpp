// MorseCodeTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Binary_Tree.h"

using namespace std;

template<typename Item_Type>
void add_code_to_tree(BTNode<Item_Type>* t, char letter, string codeStr);

int main()
{
	Binary_Tree<char> b('0');


	cout << "Welcome to the Morse Code Converter!"
		<< endl << endl
		<< "Let's start by loading up our code cipher, from input.txt... ";

	ifstream codeInput("morse.txt");

	cout << "Done!" << endl << endl;

	map<char, string> morsemap;
	char nextLetter;
	string nextCode;

	cout << "Time to start reading in the morse code... ";

	while (codeInput.good())
	{
		codeInput >> nextLetter;
		codeInput >> nextCode;
		morsemap.insert(pair<char, string>(nextLetter, nextCode));	
		add_code_to_tree(b.getRoot(), nextLetter, nextCode);
	}
	
	cout << "Done!  " << morsemap.size() << " characters read." << endl << endl;

	system("PAUSE");

	int menuChoice = 0;
	string inputString;

	while (menuChoice != 5)
	{
		system("CLS");
		cout << "Main Menu"
			<< endl << endl
			<< "1. Encode a plaintext string into Morse" << endl
			<< "2. Encode a Morse string back into plaintext" << endl
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
			cout
				<< endl << endl
				<< "Okay!  Go ahead and enter a plaintext string below:"
				<< endl << endl;

			cin >> inputString;

			cout
				<< endl << endl
				<< "Okay!  That string translates to the following morse code:"
				<< endl << endl
				<< // function call to encode()
				endl;

			system("PAUSE");
			break;
		}
		case 2:
		{
			cout
				<< endl << endl
				<< "Okay!  Go ahead and enter a morsecode string below:"
				<< endl << endl;

			cin >> inputString;

			cout
				<< endl << endl
				<< "Okay!  That string translates to the following plaintext:"
				<< endl << endl
				<< // function call to decode()
				endl;

			system("PAUSE");
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "The morsecode map we've built for you is as follows:"
				<< endl << endl;

			for (map<char, string>::iterator i = morsemap.begin(); i != morsemap.end(); i++)
				cout << i->first << "  " << i->second << endl;

			cout << endl;
			system("PAUSE");
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "The morsecode tree we've built for you is as follows:"
				<< endl << endl;

			cout << b.to_string() << endl;

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

template<typename Item_Type>
void add_code_to_tree(BTNode<Item_Type>* t, char letter, string codeStr)
{
	if (codeStr.length() == 0)
	{
		t->data = letter;
		return;
	}

	if (codeStr[0] == '.')
	{
		if (t->left == NULL)
			t->left = new BTNode<Item_Type>(' ');
		add_code_to_tree(t->left, letter, codeStr.substr(1, codeStr.length()));
		return;
	}
	else
	{
		if (t->right == NULL)
			t->right = new BTNode<Item_Type>(' ');
		add_code_to_tree(t->right, letter, codeStr.substr(1, codeStr.length()));
		return;
	}

}
