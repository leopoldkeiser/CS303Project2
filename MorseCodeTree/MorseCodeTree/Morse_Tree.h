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
	// Construct an empty Morse_Tree.
	Morse_Tree();
	// Construct a Morse_Tree with a input file.
	Morse_Tree(ifstream codeFile);
	// Add code to tree
	template<typename Item_Type>
	void add_code_to_tree(BTNode<Item_Type>* t, char letter, string codeStr);
	// Overloading operator =
	Morse_Tree& operator=(const Morse_Tree &m);
	// Encode a plaintext string into Morse code
	string encode(string& inputText);
	// Decode a Morse string back into plaintext
	string decode(string& inputCode);
    // Print Morse Tree
	void print_morse_tree();
	// Print Morse Map
	void print_morse_map();
	// Destructor
	~Morse_Tree();

private:
	Binary_Tree<char> morse_tree;
	map<char, string> morse_map;
	const char MORSE_DASH = '_';
	const char MORSE_DOT = '.';
	const char DELIMITER = ' ';
};
#endif
