#pragma once
#include <iostream>

using namespace std;

struct node {
	int inputBit;
	int state;
	struct node* left;
	struct node* right;
};


class BST
{
public:
	BST();
	~BST();
	void insert(int inputBit, int state);
	string recover(int currentState, int stateMoves[][2]);
	//void print_tree();
	//bool search(int inputBit);
private:
	void terminate_tree(node* tree);
	void insert(node** tree, int inputBit, int state);
	string recover(node** tree, int currentState, int stateMoves[][2]);
	//void print_tree(node* tree);
	//bool search(node*, int inputBit);
	node* root;
};

