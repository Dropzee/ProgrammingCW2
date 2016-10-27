#pragma once
#include <string>
#include <iostream>
#include "FileIO.h"
#include "Decoder.h"
#include "UI.h"

using namespace std;

void analyse(string in, string out){}

int main() {
	
	string originalText;
	string fileNames[49], encodedText[49], burstErrorText[49], decodedText[49], decodedError[49];
	string trellis[49][8][2];

	FileIO* io = new FileIO();
	Decoder* d = new Decoder();
	UI* ui = new UI();

	try {

		originalText = io->read("binaryFile.txt");
		io->read(&fileNames[0],"fileNames.txt");

		while (true) {
			switch (ui->menu()) {
			case 1:
				if (decodedText[0] == "") {
					ui->decoded(true);
					for (int i = 0; i < 49; i++) {
						encodedText[i] = io->read("Encoded\\" + fileNames[i] + ".txt");
						burstErrorText[i] = d->insertError(encodedText[i]);
						d->generateTrellis(trellis[i], fileNames[i]);
						decodedText[i] = d->decode(trellis[i], encodedText[i]);
						decodedError[i] = d->decode(trellis[i], burstErrorText[i]);
						io->write(decodedText[i], "Decoded\\Without Error\\" + fileNames[i]);
						io->write(decodedError[i], "Decoded\\With Error\\" + fileNames[i]);
					}
				}
				else {
					ui->decoded(false);
				}
				break;
			case 2:
				ui->view(fileNames, decodedText);
				break;
			case 3:
				ui->view(fileNames, decodedError);
				break;
			case 4:
				ui->anaylse(originalText, decodedText, decodedError);
				break;
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