#pragma once
#include "FileIO.h"

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

//Read individual file
string FileIO::read(string path) throw (invalid_argument) {

	string input;

	ifstream file;
	string temp;

	file.open(path.c_str());

	if (file.fail()) {
		throw invalid_argument("no file exists " + path);
	}

	while (file >> temp) {
		input += temp;
	}

	file.close();
	
	return input;
}

void FileIO::read(string* arr, string path) {
	string line;
	int count = 0;
	ifstream myfile(path);
	while (getline(myfile, line))
	{
		arr[count] = line;
		count++;
	}
	myfile.close();
}