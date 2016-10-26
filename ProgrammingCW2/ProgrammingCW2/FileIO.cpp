#pragma once
#include "FileIO.h"

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

//Read file as one string
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

//Read file line by line into an array
void FileIO::read(string* arr, string path) throw (invalid_argument) {
	
	string line;
	int count = 0;

	ifstream file(path);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			arr[count] = line;
			count++;
		}
		file.close();
	}
	else {
		throw invalid_argument("no file exists " + path);
	}
}