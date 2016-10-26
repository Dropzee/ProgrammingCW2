#pragma once
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h> 
#include <string>

using namespace std;

struct stateTransition {
	string bits[2]; //output bits given input 0 or 1
	stateTransition* nextState[2]; //next state given 0 or 1
};

class Decoder
{
public:
	Decoder();
	~Decoder();
	string insertError(string s);
	string decode(string input);
	void generateTrellis(stateTransition* arr, string names);
private:
	string XOR(char a, char b);
};

