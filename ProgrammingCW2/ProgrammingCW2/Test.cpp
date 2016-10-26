#pragma once
#include <string>
#include <iostream>
#include "FileIO.h"
#include "Decoder.h"

using namespace std;

int main() {

	string input;
	string fileNames[49];

	FileIO* io = new FileIO();
	Decoder* d = new Decoder();

	try {
		input = io->read("binaryFile.txt");
		io->read(&fileNames[0],"FileNames.txt");
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << endl;
		exit(1);
	}

	fileNames;

	delete io;
	delete d;

	system("pause");

	return 0;
}