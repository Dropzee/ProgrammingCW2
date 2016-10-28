#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

int UI::menu() throw (invalid_argument) {
	cout << "---------------- MENU ----------------" << endl;
	cout << "1. Decode encoded text files with and without errors" << endl;
	cout << "2. View decoded text files" << endl;
	cout << "3. View decoded text files which had errors" << endl;
	cout << "4. Analyse results" << endl;
	cout << "5. Exit" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Please choose an option: ";
	int x;
	if (!(cin >> x)) {
		throw invalid_argument("Invalid input.");
	}
	return x;
}

void UI::decoded(bool b) {
	cout << "--------------------------------------" << endl;
	if (b) {
		cout << "Both encoded files and encoded files with error bursts have been decoded." << endl;
	}
	else {
		cout << "All files have already been decoded." << endl;
	}
}

void UI::view(string names[], string outputs[]) throw (invalid_argument, out_of_range) {
	cout << "--------------------------------------" << endl;
	if (outputs[0] == "") {
		cout << "Files have not been decoded yet, please decode first." << endl;
	}
	else {
		for(int i = 0; i < 49; i++) {
			cout << i << ". " << names[i] << endl;
		}
		cout << "--------------------------------------" << endl;
		cout << "Input an index from the list above to view encoded output: ";
		int x;
		if (!(cin >> x)) {
			throw invalid_argument("Invalid input.");
		}
		cout << "--------------------------------------" << endl;
		if (x < 0 || x > 48) {
			throw out_of_range("Invalid input.");
		}
		cout << outputs[x] << endl;
	}
	return;
}

void UI::anaylse(string original, string names[], string decodedText[], string decodedErrors[]) {
	if (decodedText[0] == "") {
		cout << "Files have not been decoded yet, please decode first." << endl;
	}
	else {
		cout << "--------- SUCCESSFUL DECODES ---------" << endl;
		int textCount = 0;
		int errorCount = 0;
		for (int i = 0; i < 49; i++) {
			if (original.compare(decodedText[i]) == 0) {
				cout << i << ". " << names[i] << " - (Without Errors)" << endl;
				textCount++;
			}
			if (original.compare(decodedErrors[i]) == 0) {
				cout << i << ". " << names[i] << " - (With Errors)" << endl;
				errorCount++;
			}
		}

		cout << "--------------------------------------" << endl;
		cout << "Files with no error decoded correctly: " << textCount << "/49" << endl;
		cout << "Files with added error decoded correctly: " << errorCount << "/49" << endl;
	}
}