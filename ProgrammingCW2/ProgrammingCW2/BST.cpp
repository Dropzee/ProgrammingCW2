#include "BST.h"

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	terminate_tree(root);
}

//Recursive termination of nodes, starting at root
void BST::terminate_tree(node* tree) {
	if (tree != NULL) {
		terminate_tree(tree->left);
		terminate_tree(tree->right);
		delete tree;
	}
}

//Public insertion method abstracts away root
void BST::insert(int inputBit, int state) {
	insert(&root, inputBit, state);
}

//Private insertion method
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

//Public recovery method abstracts away root
string BST::recover(string text, int currentState, int stateMoves[][2], string trellis[][2]) {
	return recover(&root, text, currentState, stateMoves, trellis);
}

//Private recovery method
string BST::recover(node** tree, string text, int currentState, int stateMoves[][2], string trellis[][2]) {

	//Set root as the state the error was decovered in
	insert(-1, currentState);

	int depthCounter = 0;

	while (true) {

		//Safety to prevent infinite while loop and limit the size of the tree
		if (depthCounter >= (text.length() / 2) || depthCounter >= 6) {
			return "00";
		}

		//Add another layer to the tree (a pair of leafs represents 0 or 1 being input the parent state)
		addLayer(tree, stateMoves);

		//Test whether there is a path back from a successful state
		node* solution = testPaths(text.substr(depthCounter * 2, 2), trellis);
		if (solution != NULL) {

			//If there is then record the path and return it 
			stack<int> output;
			getText(solution, &output);
			string bits;

			while (output.size() > 0) {
				bits += to_string(output.top());
				output.pop();
			}

			return string(bits.rbegin(), bits.rend());
		}

		depthCounter++;
	}

}

//Private method to add another depth layer to the tree
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

//Public search method abstracts away root
node* BST::testPaths(string targetBits, string trellis[][2]) {
	return testPaths(root, targetBits, trellis);
}

//Private search method, returns pointer to node if found
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

//Public get result method abstracts away root
void BST::getText(node* solution, stack<int>* output) {
	getText(root, solution, output);
}

//Private get result method, creates trace back from found solution to root
void BST::getText(node* tree, node* solution, stack<int>* output) {
	
	if (tree == NULL) {
		return;
	}

	else {

		if (tree == solution) {
			output->push(tree->inputBit);
			return;
		}
		
		if (tree->left != NULL) {
			output->push(tree->left->inputBit);
			getText(tree->left, solution, output);
			output->pop();
		}

		if (tree->right != NULL) {
			output->push(tree->right->inputBit);
			getText(tree->right, solution, output);
			output->pop();
		}
	}
}