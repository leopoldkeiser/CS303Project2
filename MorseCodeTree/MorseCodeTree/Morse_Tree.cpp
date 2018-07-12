#include "stdafx.h"
#include "Morse_Tree.h"
#include "Binary_Tree.h"
#include <iostream>

Morse_Tree::Morse_Tree()
{
}

Morse_Tree::Morse_Tree(ifstream codeFile)
{
	morse_tree = Binary_Tree<char> ('0');
	char nextLetter;
	string nextCode;
	while (codeFile.good())
	{
		codeFile >> nextLetter;
		codeFile >> nextCode;
		try
		{
			add_code_to_tree(morse_tree.getRoot(), nextLetter, nextCode);
		}
		catch(char e)
		{
			throw e;
		}
	}

}

template<typename Item_Type>
void Morse_Tree::add_code_to_tree(BTNode<Item_Type>* t, char letter, string codeStr)
{
	if (codeStr.length() == 0)
	{
		t->data = letter;
		return;
	}

	if (codeStr[0] == MORSE_DOT)
	{
		if (t->left == NULL)
			t->left = new BTNode<Item_Type>(' ');
		add_code_to_tree(t->left, letter, codeStr.substr(1, codeStr.length()));
		return;
	}
	else if (codeStr[0] == MORSE_DASH)
	{
		if (t->right == NULL)
			t->right = new BTNode<Item_Type>(' ');
		add_code_to_tree(t->right, letter, codeStr.substr(1, codeStr.length()));
		return;
	}
	else
	{
		throw letter;
	}
}

string Morse_Tree::decode(string& inputCode)
{
	int index = 0;
	string result= "";
	BTNode<char>* current_node;

	while (index < inputCode.size()) {
		current_node = morse_tree.getRoot();
		while (inputCode[index] != ' ' && index < inputCode.size())
		{
			if (inputCode[index] == '.')
			{
				current_node = current_node->left;
				++index;
			} else if (inputCode[index] == '_')
			{
				current_node = current_node->right;
				++index;
			}
		}
		result += current_node->data;
		++index;
	}
	return result;
}

string Morse_Tree::encode(string& inputText)
{
	string result;
	return result;
}

void Morse_Tree::to_string()
{
	cout << morse_tree.to_string();
}

Morse_Tree::~Morse_Tree()
{
}

Morse_Tree& Morse_Tree::operator=(const Morse_Tree & m)
{
	const char MORSE_DOT = m.MORSE_DOT;
	const char MORSE_DASH = m.MORSE_DASH;
	morse_tree = m.morse_tree;
	return *this;
}
