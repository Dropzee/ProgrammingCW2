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
	cout << "4. Exit" << endl;
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

//
//void UI::generateAll(bool b) {
//	cout << "--------------------------------------" << endl;
//	if (b) {
//		cout << "All unique outputs using combinations from 0000 to 3333 in base 4 have been created." << endl;
//	}
//	else {
//		cout << "All unique combinations have already been created." << endl;
//	}

//}
//
//void UI::inputCustom(string s, Encoder* e) {
//	cout << "--------------------------------------" << endl;
//	cout << "XOR inputs key:" << endl;
//	cout << "0 - Input Bit" << endl;
//	cout << "1 - Register 1" << endl;
//	cout << "2 - Register 2" << endl;
//	cout << "3 - Register 3" << endl;
//	cout << "--------------------------------------" << endl;
//	int ins[4];
//	string names[4] = { "XOR1 input A: ", "XOR1 input B: ", "XOR2 input A: ", "XOR2 input B: " };
//	for (int i = 0; i < 4; i++) {
//		cout << names[i];
//		if (!(cin >> ins[i])) {
//			throw invalid_argument("Invalid input.");
//		}
//		if (ins[i] < 0 || ins[i] > 3) {
//			throw out_of_range("Invalid input.");
//		}
//	}
//	cout << "--------------------------------------" << endl;
//	cout << e->encode(s, ins[0], ins[1], ins[2], ins[3]) << endl;
//	return;
//}
//
//void UI::viewAll(vector<string> names, vector<string> outputs) throw (invalid_argument, out_of_range) {
//	cout << "--------------------------------------" << endl;
//	if (outputs.empty()) {
//		cout << "No outputs generated, please generate first." << endl;
//	}
//	else {
//		int count = 0;
//		for each(string s in names) {
//			cout << count << ". " << s.c_str() << endl;
//			count++;
//		}
//		cout << "--------------------------------------" << endl;
//		cout << "Input an index from the list above to view encoded output: ";
//		int x;
//		if (!(cin >> x)) {
//			throw invalid_argument("Invalid input.");
//		}
//		cout << "--------------------------------------" << endl;
//		if (x < 0 || x >(outputs.size() - 1)) {
//			throw out_of_range("Invalid input.");
//		}
//		cout << outputs.at(x).c_str() << endl;
//	}
//	return;
//}
