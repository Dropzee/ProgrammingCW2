#pragma once
#include <string>
#include <iostream>
#include "FileIO.h"
#include "Decoder.h"

using namespace std;

int main() {

	string input;

	FileIO* io = new FileIO();
	Decoder* d = new Decoder();

	string test = "1001111010";

	cout << test << endl;
	cout << d->insertError(test) << endl;
	

	system("pause");

	try {
		input = io->read("binaryFile.txt");
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << endl;
		exit(1);
	}
}