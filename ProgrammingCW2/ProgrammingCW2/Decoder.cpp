#pragma once
#include "Decoder.h"



Decoder::Decoder()
{
}


Decoder::~Decoder()
{
}

string Decoder::insertError(string input) {

	srand(time(NULL));

	bool burstMode = false;
	int count = 0;

	for (int i = 0; i < input.length(); i++) {
		if (burstMode) {
			input[i] = (char)((rand() % 2 + 48)); //ascii 0 - 48, 1 - 49
			count++;
			if (count > 4) {
				burstMode = false;
				count = 0;
			}
		}
		else {
			int x = rand() % 21; //0-20
			if (x > 18) { 
				burstMode = true;
			}
		}
	}
	return input;
}


//string states[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
//int stateMoves[8][2] = { { 0 , 4 },{ 0 , 4 },{ 1 , 5 },{ 1 , 5 },{ 2 , 6 },{ 2 , 6 },{ 3 , 7 },{ 3 , 7 } };
string Decoder::decode(string arr[][2], string input) {
	int currentState = 0;
	for (int place = 0; place < input.length() - 1; place += 2) {
		string bits = "";
		if () {

		}
	}
	return "";
}

//XOR Method
string Decoder::XOR(char a, char b) {
	return to_string((((int)a + (int)b) % 2));
}

//Generates outputs for each state given 0 or 1
void Decoder::generateTrellis(string arr[][2], string name) {

	for (int state = 0; state < 8; state++) {
		for (int bit = 0; bit < 2; bit++) {

			string current = to_string(bit) + states[state];

			arr[state][bit] += XOR(current.at(name.at(15) - 48), current.at(name.at(17) - 48));
			arr[state][bit] += XOR(current.at(name.at(5) - 48),  current.at(name.at(7) - 48));

		}
	}
}