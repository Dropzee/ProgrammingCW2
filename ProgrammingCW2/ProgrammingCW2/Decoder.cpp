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

string Decoder::decode(string input) {
	return "";
}