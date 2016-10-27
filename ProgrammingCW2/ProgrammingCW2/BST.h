#pragma once
#include <iostream>
#include <stack>
#include <string>

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
	string recover(string text, int currentState, int stateMoves[][2], string trellis[][2]);
	void addLayer(node** tree, int stateMoves[][2]);
	node* testPaths(string text, string trellis[][2]);
	void getText(node* solution, stack<int>* output);
private:
	void terminate_tree(node* tree);
	void insert(node** tree, int inputBit, int state);
	string recover(node** tree, string targetBits, int currentState, int stateMoves[][2], string trellis[][2]);
	node* testPaths(node*, string targetBits, string trellis[][2]);
	void getText(node* tree, node* solution, stack<int>* output);
	node* root;
};

