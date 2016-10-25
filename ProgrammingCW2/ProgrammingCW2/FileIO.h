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
	void read(vector<string> &files, string folder);
};

