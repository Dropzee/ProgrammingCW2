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

string BST::recover(int currentState, int stateMoves[][2], int trellis[][2]) {
	return recover(&root, currentState, stateMoves, trellis);
}


string BST::recover(node** tree, int currentState, int stateMoves[][2], int trellis[][2]) {
	if (tree != NULL) {
		int depthCounter = 0;
		while (true) {

			//Safety to prevent infinite while loop and limit the size of the tree
			if (depthCounter >= 9) {
				return "";
			}

			addLayer(tree, stateMoves);
			
			//test
		}
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

//void BST::print_tree() {
//	cout << "BST: ";
//	print_tree(root);
//}

//void BST::print_tree(node* tree) {
//	if (tree != NULL) {
//		print_tree(tree->left);
//		cout << tree->value << " ";
//		print_tree(tree->right);
//	}
//}

//bool BST::search(int value) {
//	return search(root, value);
//}

//bool BST::search(node* tree, int value) {
//	if (tree == NULL) {
//		return false;
//	}
//	else {
//		if (tree->value == value) {
//			return true;
//		}
//		if (value < tree->value) {
//			search(tree->left, value);
//
//		}
//		else if (value >= tree->value) {
//			search(tree->right, value);
//		}
//	}
//}