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

//Read all files in a folder
void FileIO::read(vector<string> &files, string folder) {

}