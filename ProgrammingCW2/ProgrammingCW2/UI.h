#pragma once
#include "Decoder.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class UI
{
public:
	UI();
	~UI();
	int menu();
	void decoded(bool b);
	void view(string names[], string outputs[]);
	void anaylse(string original, string decodedText[], string decodedErrors[]);
};

