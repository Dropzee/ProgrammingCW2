#pragma once
#include <string>
#include <iostream>
#include "FileIO.h"
#include "Decoder.h"

using namespace std;

int main() {
	
	string originalText;
	stateTransition statePermutations[49][8];
	string fileNames[49], encodedText[49], burstErrorText[49], decodedText[49], decodedError[49];

	FileIO* io = new FileIO();
	Decoder* d = new Decoder();

	try {
		originalText = io->read("binaryFile.txt");
		io->read(&fileNames[0],"fileNames.txt");

		stateTransition test[8];

		d->generateTrellis(&test[0], fileNames[43]);

		for (int i = 0; i < 49; i++) {

			encodedText[i] = io->read("Encoded\\" + fileNames[i] + ".txt");
			burstErrorText[i] = d->insertError(encodedText[i]);

			decodedText[i] = d->decode(encodedText[i]);
			decodedError[i] = d->decode(burstErrorText[i]);
		}
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << endl;
		exit(1);
	}

	delete io;
	delete d;

	system("pause");

	return 0;
}