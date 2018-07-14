#pragma once
#include <iostream>
#include <string>
#include<map>
#include<vector>
using namespace std;

void encode(string a)
{
	int count = 0;
	vector<char>vec1;
	map<char, string> code = {
		{ 'a', "._" },{ 'b',"_..." },{ 'c', "_.-." },{ 'd',"_.." },{ 'e',"." },{ 'f',".._." },{ 'g',"__." },{ 'h',"...." },{ 'i',".." },
	{ 'j',".___" },{ 'k',"_._" },{ 'l',"._.." },{ 'm',"__" },{ 'n',"-." },{ 'o',"___" },{ 'p',".__." },{ 'q',"__._" },{ 'r',"._." },
	{ 's',"..." },{ 't',"_" },{ 'u',".._" },{ 'v',"..._" },{ 'w',".__" },{ 'x',"_.._" },{ 'y',"_.__" },{ 'z',"__.." },
	{ 'A', "._" },{ 'B',"_..." },{ 'C', "_.-." },{ 'D',"_.." },{ 'E',"." },{ 'F',".._." },{ 'G',"__." },{ 'H',"...." },{ 'I',".." },
	{ 'J',".___" },{ 'K',"_._" },{ 'L',"._.." },{ 'M',"__" },{ 'N',"-." },{ 'O',"___" },{ 'P',".__." },{ 'Q',"__._" },{ 'R',"._." },
	{ 'S',"..." },{ 'T',"_" },{ 'U',".._" },{ 'V',"..._" },{ 'W',".__" },{ 'x',"_.._" },{ 'Y',"_.__" },{ 'Z',"__.." }
	};

	for (int i = 0; i < a.size(); i++)
	{
		if (isalpha(a[i])) {
			vec1.push_back(a[i]);

		}
		else {
			cout << " input just allowed letters" << endl;
			cout << "Okay!Go ahead and enter a plaintext string below : ";
			cin >> a;
			encode(a);
			break;
		}

	}
	while (!vec1.empty())
	{
		for (map<char, string>::iterator iter = code.begin(); iter != code.end(); iter++) {
			if (iter->first == a[count]) {
				cout << iter->second << " ";
				vec1.erase(vec1.begin());
				count++;
			}
		}
	}
	

}