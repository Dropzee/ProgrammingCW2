#pragma once
#include <iostream>

using namespace std;

class Decoder
{
public:
	Decoder();
	~Decoder();
	void insertError(string* s);
	string decode(string input);
};

