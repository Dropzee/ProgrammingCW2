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
	string decode(string input);
};

