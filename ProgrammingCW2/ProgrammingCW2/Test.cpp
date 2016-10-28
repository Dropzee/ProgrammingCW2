#pragma once
#include <string>
#include <iostream>
#include "FileIO.h"
#include "Decoder.h"
#include "UI.h"

using namespace std;

int main() {
	
	string originalText;
	string fileNames[49], encodedText[49], burstErrorText[49], decodedText[49], decodedError[49];
	string trellis[49][8][2];

	FileIO* io = new FileIO();
	Decoder* d = new Decoder();
	UI* ui = new UI();

	try {
		//Interface loop
		while (true) {

			//Get list of encoded files from CW1
			io->read(&fileNames[0],"fileNames.txt");

			//Switch on menu option input
			switch (ui->menu()) {
			//1 - Decode
			case 1:
				if (decodedText[0] == "") {
					ui->decoded(true);
					//For each encoded file from CW1...
					for (int i = 0; i < 49; i++) {

						//Read in data, make a copy and add errors to it
						encodedText[i] = io->read("Encoded\\" + fileNames[i] + ".txt");
						burstErrorText[i] = d->insertError(encodedText[i]);

						//Generate trellis using register set up stored in the file name
						d->generateTrellis(trellis[i], fileNames[i]);

						//Decode both encoded texts
						decodedText[i] = d->decode(trellis[i], encodedText[i]);
						decodedError[i] = d->decode(trellis[i], burstErrorText[i]);

						//Output results of decoding to file
						io->write(decodedText[i], "Decoded\\Without Error\\" + fileNames[i]);
						io->write(decodedError[i], "Decoded\\With Error\\" + fileNames[i]);
					}
				}
				else {
					ui->decoded(false);
				}
				break;
			//2 - View decoded with no error
			case 2:
				ui->view(fileNames, decodedText);
				break;
			//3 - View decoded with error
			case 3:
				ui->view(fileNames, decodedError);
				break;
			//4 - Compare to original binary file
			case 4:
				originalText = io->read("binaryFile.txt");
				ui->anaylse(originalText, decodedText, decodedError);
				break;
			//5 - Exit
			case 5:
				goto Exit;
			default:
				cout << "Please enter a menu option between 1-5!" << endl;
			}
		}
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << endl;
		exit(1);
	}
	catch (const out_of_range& oore) {
		cout << oore.what() << endl;
		exit(1);
	}

Exit:
	delete io;
	delete d;
	delete ui;

	return 0;
}