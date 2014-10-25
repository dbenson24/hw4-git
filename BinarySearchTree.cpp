/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
	// post-order traversal to remove all nodes
	if (node == NULL){
		delete node;
		return;
	}
	if (node->left!=NULL)
		post_order_delete(node->left);
	if (node->right!=NULL)
		post_order_delete(node->right);
	delete node;
	return;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
	// check for self-assignment
	if (this == &source){
		return *this;
	}
	// delete current tree if it exists
	if (root!=NULL)
		post_order_delete(root);
	//pre-order traversal to copy the tree
	root = pre_order_copy(source.root);

	return *this;
}

// Returns a copy of a BST
Node * BinarySearchTree::pre_order_copy(Node *node) {
	// a pre-order traversal to copy details from the
	// node to a new_node

	// base case: node is null
	if (node == NULL) return NULL;

	// deep copy
	Node *new_node = new Node();
	new_node->count = node->count;
	new_node->data = node->data;

	// copy left then copy right
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);

	return new_node;
}

// Returns the lowest value in the tree
int BinarySearchTree::find_min() {
	if (root == NULL) return INT_MIN;
	Node* temp = find_min(root);
	if (temp != NULL)
		return temp->data;
	else
		return INT_MIN;
}

// Returns the lowest value after *node
Node *BinarySearchTree::find_min(Node *node) {
	// continues to recursively check left nodes
	if (node == NULL)
		return node;
	if (node->left == NULL)
		return node;
	else
		return find_min(node->left);
}

// Returns the highest value in tree
int BinarySearchTree::find_max() {
	if (root == NULL) return INT_MAX;
	Node* temp = find_max(root);
	if (temp != NULL)
		return temp->data;
	else
		return INT_MAX;
}

//Returns the highest value after *node
Node *BinarySearchTree::find_max(Node *node) {
	// continues to recursively check right nodes
	if (node == NULL)
		return node;
	if (node->right==NULL)
		return node;
	else
		return find_max(node->right);
}

// Returns whether the tree contains value
bool BinarySearchTree::contains(int value) {
	return contains(root, value);
}

// Returns whether the tree starting on *node
// contains value
bool BinarySearchTree::contains(Node *node, int value) {
	// Base Case: node is null, return false
	if (node == NULL){
		return false;
	}
	// if found node, return true
	else if (node->data == value){
		return true;
	}
	// if node is larger than value, go left
	else if (value < node->data){
		return contains(node->left, value);
	}
	// if node is smaller than value, go right
	else{
		return contains(node->right, value);
	}
}

// Inserts value at first location on tree
void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

// Inserts value at first location below *node
// *node is the starting node, *parent is *node's parent
// value is the integer to be inserted.
void BinarySearchTree::insert(Node *node, Node *parent, int value) {
	if (node == NULL){
		Node *temp = new Node();
		temp->data = value;
		temp->count = 1;
		if (parent != NULL){
			// correctly insert the node into it's child position
			if (parent->data > value){
				parent->left = temp;
			}
			else{
				parent->right = temp;
			}
		}
		if (parent == NULL){
			// if no parent, make node the root
			root = temp;
		}
	}
	else if (node->data == value){
		// if the node already exists, increment count
		node->count++;
	}
	else if (value < node->data){
		// if the node is larger than value, go left
		insert(node->left, node, value);
	}
	else if (value > node->data){
		// if the node is smaller than value, go right
		insert(node->right, node, value);
	}
}

// Returns whether value is successfully removed from the tree
bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

// Returns whether value was removed from the tree
// *node is the current node in the tree
// *parent is the parent of node
bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// Node not found
	if (node == NULL)
		return false;
	else if (node->data == value){
		// Node count is higher than 1
		if (node->count > 1){
			// decrement count
			node->count--;
			return true;
		}
		// No children
		if (node->left == NULL && node->right == NULL){
			// if deleting a childless root
			if (parent == NULL){
				delete root;
				root = NULL;
				return true;
			}

			// determines which child the current node is
			else if (parent->data > node->data)
				parent->left = NULL;
			else
				parent->right = NULL;

			delete node;

			return true;
		}
		// One right child
		else if (node->left == NULL && node->right != NULL){
			// Move the right child into the node's position
			// right child root
			if (parent == NULL)
				root = node->right;

			// determines which child the current node is
			else if (parent->data > node->data)
				parent->left = node->right;
			else
				parent->right = node->right;

			delete node;

			return true;
		}
		// One left child
		else if (node->right == NULL && node->left != NULL){
			// Move the left child into the node's position
			// left child root
			if (parent == NULL)
				root = node->left;

			// determines which child the current node is
			else if (parent->data > node->data)
				parent->left = node->left;
			else
				parent->right = node->left;

			delete node;

			return true;
		}
		// Both children
		else {

			// Remove the smallest node to the right
			Node *rmin = find_min(node->right);

			// Replace the current node with the smallest node

			node->data = rmin->data;
			node->count = rmin->count;

			// Delete the smallest node
			rmin->count = 1;
			remove(node->right, node, rmin->data);

			return true;
		}
	}

	// If the current node is larger than the value, move left
	else if (value < node->data){
		return remove(node->left, node, value);
	}

	// If the current node is smaller than the value, move right
	else{
		return remove(node->right, node, value);
	}
}

// Returns the height of the tree
int BinarySearchTree::tree_height() {
	return tree_height(root);
}

// Returns the height of the *node recursively
int BinarySearchTree::tree_height(Node *node) {
	if (node == NULL)
		// Base height of -1
		return -1;
	// calculates relative height of both sides
	int lheight = 1 + tree_height(node->left);
	int rheight = 1 + tree_height(node->right);

	//returns the larger height
	if (lheight > rheight){
		return lheight;
	}
	return rheight;
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
	if (node == NULL)
		return 0;
	return (node_count(node->right) + node_count(node->left) + 1);
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}

// Return the sum of all the nodes below and including *node
int BinarySearchTree::count_total(Node *node) {
	if (node == NULL)
		return 0;

	// Returns the value of the node plus the value of all
	// nodes to the left and to the right of it
	return (count_total(node->right) + count_total(node->left)
			+ node->data*node->count);
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

// Returns the parent of *child
Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left == child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
