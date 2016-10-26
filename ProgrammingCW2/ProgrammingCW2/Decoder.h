#pragma once
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h> 
#include <string>

using namespace std;

class Decoder
{
public:
	Decoder();
	~Decoder();
	string insertError(string s);
	string decode(string arr[][2], string input);
	void generateTrellis(string arr[][2], string names);
private:
	string XOR(char a, char b);
	string states[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	int stateMoves[8][2] = { { 0 , 4 },{ 0 , 4 },{ 1 , 5 },{ 1 , 5 },{ 2 , 6 },{ 2 , 6 },{ 3 , 7 },{ 3 , 7 } };
};

