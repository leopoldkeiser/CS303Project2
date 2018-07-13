#ifndef MORSE_H
#define MORSE_H

#include <fstream>
#include <string>
#include <map>
#include "Binary_Tree.h"
using namespace std;

class Morse_Tree
{
public:
	Morse_Tree();
	Morse_Tree(ifstream codeFile);
	template<typename Item_Type>
	void add_code_to_tree(BTNode<Item_Type>* t, char letter, string codeStr);
	string encode(string& inputText);
	string decode(string& inputCode);
	void print_morse_tree();
	~Morse_Tree();
	Morse_Tree& operator=(const Morse_Tree &m);

private:
	map<char, string> morsemap;
	Binary_Tree<char> morse_tree;
	const char MORSE_DASH = '_';
	const char MORSE_DOT = '.';
};



#endif
