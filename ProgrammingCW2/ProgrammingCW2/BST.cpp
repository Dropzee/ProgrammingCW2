#include "BST.h"

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	terminate_tree(root);
}

void BST::terminate_tree(node* tree) {
	if (tree != NULL) {
		terminate_tree(tree->left);
		terminate_tree(tree->right);
		delete tree;
	}
}

void BST::insert(int inputBit, int state) {
	insert(&root, inputBit, state);
}

void BST::insert(node** tree, int inputBit, int state) {
	if ((*tree) == NULL) {
		(*tree) = new node;
		(*tree)->inputBit = inputBit;
		(*tree)->state = state;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else {
		if (inputBit <= (*tree)->inputBit) {
			insert(&(*tree)->left, inputBit, state);

		}
		else if (inputBit >= (*tree)->inputBit) {
			insert(&(*tree)->right, inputBit, state);
		}
	}
}

string BST::recover(string text, int currentState, int stateMoves[][2], string trellis[][2]) {
	return recover(&root, text, currentState, stateMoves, trellis);
}


string BST::recover(node** tree, string text, int currentState, int stateMoves[][2], string trellis[][2]) {

	insert(0, currentState);

	int depthCounter = 0;

	while (true) {

		//Safety to prevent infinite while loop and limit the size of the tree
		if (depthCounter >= 9) {
			return "";
		}

		addLayer(tree, stateMoves);

		node* solution = testPaths(text.substr(depthCounter * 2, 2), trellis);
		if (solution != NULL) {
			//akfhasjldasl;jdfh
		}

		depthCounter++;
	}

}

void BST::addLayer(node** tree, int stateMoves[][2]) {
	if ((*tree)->left == NULL && (*tree)->right == NULL) {
		insert(&(*tree)->left, 0, stateMoves[(*tree)->state][0]);
		insert(&(*tree)->right, 1, stateMoves[(*tree)->state][1]);
	}
	else {
		addLayer(&(*tree)->left, stateMoves);
		addLayer(&(*tree)->right, stateMoves);
	}
}

node* BST::testPaths(string targetBits, string trellis[][2]) {
	return testPaths(root, targetBits, trellis);
}

node* BST::testPaths(node* tree, string targetBits, string trellis[][2]) {
	if (tree->left == NULL || tree->right == NULL) {
		return NULL;
	}
	else {
		if (trellis[tree->left->state][0] == targetBits) {
			return tree->left;

		}
		else if (trellis[tree->left->state][1] == targetBits) {
			return tree->right;
		}
		else {
			testPaths(tree->left, targetBits, trellis);
			testPaths(tree->right, targetBits, trellis);
		}
	}
	return NULL;
}

string BST::getText(node* solution) {
	return "";
}