#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

class FileIO
{
public:
	FileIO();
	~FileIO();
	string read(string path);
	void read(string* arr, string path);
	void write(string output, string path);
};

