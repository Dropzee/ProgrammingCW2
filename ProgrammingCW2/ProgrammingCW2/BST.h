#pragma once
#include <iostream>

using namespace std;

class BST
{

	struct node {
		int inputBit;
		int state;
		struct node* left;
		struct node* right;
	};

public:
	BST(int value);
	~BST();
	void insert(int inputBit, int state);
	//void print_tree();
	//bool search(int inputBit);
private:
	void terminate_tree(node* tree);
	void insert(node** tree, int inputBit, int state);
	//void print_tree(node* tree);
	//bool search(node*, int inputBit);
	node* root;
};

