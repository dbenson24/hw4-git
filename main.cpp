/*
 * main.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: chrisgregg
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void print_tree_details(BinarySearchTree &bst) {
	bst.print_tree();
	cout << "\n";
	cout << "min: " << bst.find_min() << "\n";
	cout << "max: " << bst.find_max() << "\n";
	cout << "nodes: " << bst.node_count() << "\n";
	cout << "count total: " << bst.count_total() << "\n";
	cout << "tree height: " << bst.tree_height() << "\n";
	cout << "\n";
}
int main8() {
	BinarySearchTree bst;
	cout << "minimum: " << bst.find_min() << "\n";
	cout << "maximum: " << bst.find_max() << "\n";

	return 0;
}

int main10() {
	BinarySearchTree bst;
	cout << "Tree height: " << bst.tree_height() << "\n";

	return 0;
}

int main13(){
	int rand_ints[100]={84, 49, -62, 95, 75, 18, -56, -27, -73, 42,
			80, 5, 35, 15, 64, -99, 3, 100, -36, -64,
			23, -24, -70, -2, -52, -62, 64, -97, 49,
			-33, 27, 31, -11, 55, 71, -66, 67, -69,
			-87, -43, -94, -66, 74, -91, 47, 3, -98,
			54, 90, -34, -7, -11, 58, 17, 80, 27, 93,
			73, -65, 55, 90, 76, 55, 41, -45, -28, -34,
			55, 0, 40, -63, -59, -48, -73, 17, -18, -39,
			98, 23, -16, 89, 98, 87, -59, -77, -95, -18,
			-11, 76, 17, 48, -59, 35, 58, 31, 13, -98,
			-70, 21, -87};

	BinarySearchTree bst;
	for (int i=0;i<100;i++) {
		cout << "Inserting " << rand_ints[i] << "\\n";
		bst.insert(rand_ints[i]);
	}
	cout << "Node count: " << bst.node_count() << "\\n";

	return 0;

}
int main19() {
	int rand_ints[12]={5,3,6,11,-5,-2,15,4,4,9,14,8};

	BinarySearchTree bst;
	for (int i=0;i<12;i++) {
		cout << "Inserting " << rand_ints[i] << "\n";
		bst.insert(rand_ints[i]);
	}
	bst.print_tree();
	cout << "Removing 5.\n";
	bst.remove(5);
	bst.print_tree();

	return 0;
}

int main20() {
	int rand_ints[12]={5,3,6,11,-5,-2,15,4,4,9,14,8};

	BinarySearchTree bst;
	for (int i=0;i<12;i++) {
		cout << "Inserting " << rand_ints[i] << "\n";
		bst.insert(rand_ints[i]);
	}
	bst.print_tree();
	cout << "Removing 11.\n";
	bst.remove(11);
	bst.print_tree();

	return 0;
}

int main21() {
	int rand_ints[100]={84, 49, -62, 95, 75, 18, -56, -27, -73, 42,
			80, 5, 35, 15, 64, -99, 3, 100, -36, -64,
			23, -24, -70, -2, -52, -62, 64, -97, 49,
			-33, 27, 31, -11, 55, 71, -66, 67, -69,
			-87, -43, -94, -66, 74, -91, 47, 3, -98,
			54, 90, -34, -7, -11, 58, 17, 80, 27, 93,
			73, -65, 55, 90, 76, 55, 41, -45, -28, -34,
			55, 0, 40, -63, -59, -48, -73, 17, -18, -39,
			98, 23, -16, 89, 98, 87, -59, -77, -95, -18,
			-11, 76, 17, 48, -59, 35, 58, 31, 13, -98,
			-70, 21, -87};

	BinarySearchTree bst;
	for (int i=0;i<100;i++) {
		cout << "Inserting " << rand_ints[i] << "\n";
		bst.insert(rand_ints[i]);
	}
	bst.print_tree();
	cout << "Node count: " << bst.node_count() << "\n";
	for (int i=0;i<95;i++) {
		cout << "Removing " << rand_ints[i] << "\n";
		if (rand_ints[i]==87) {
			cout << "About to remove root!\n";
			bst.print_tree();
		}
		bst.remove(rand_ints[i]);
	}
	bst.print_tree();

	cout << "Finished!\n";
	return 0;
}

int main22() {
	BinarySearchTree bst;

	bst.insert(12);
	bst.print_tree();
	cout << "Removing 12.\n";
	bst.remove(12);
	bst.print_tree();

	return 0;
}

int main23() {
	BinarySearchTree bst;

	bst.insert(12);
	bst.insert(20);
	bst.insert(15);
	bst.insert(23);
	bst.print_tree();
	cout << "Removing 12.\n";
	bst.remove(12);
	bst.print_tree();

	return 0;
}

int main24() {
	BinarySearchTree bst;

	bst.insert(12);
	bst.insert(20);
	bst.insert(15);
	bst.insert(23);
	bst.insert(5);
	bst.insert(6);
	bst.insert(3);
	bst.print_tree();
	cout << "Removing 12.\n";
	bst.remove(12);
	bst.print_tree();

	return 0;
}

int main30() {
	int rand_ints[4]={5,3,6,11};

	BinarySearchTree bst;
	for (int i=0;i<4;i++) {
		cout << "Inserting " << rand_ints[i] << "\n";
		bst.insert(rand_ints[i]);
	}
	BinarySearchTree bst2 = bst;

	bst.print_tree();
	bst2.print_tree();
	cout << "Removing 5 from bst, but not bst2.\n";
	bst.remove(5); // necessary to ensure that the trees
	// aren't pointing at each other's data
	bst.print_tree();
	bst2.print_tree(); // should be original

	return 0;
}

int main31() {
	int rand_ints[4]={5,3,6,11};

	BinarySearchTree bst,bst2;
	for (int i=0;i<4;i++) {
		cout << "Inserting " << rand_ints[i] << "\n";
		bst.insert(rand_ints[i]);
	}
	bst2 = bst;

	bst.print_tree();
	bst2.print_tree();
	cout << "Removing 5 from bst, but not bst2.\n";
	bst.remove(5); // necessary to ensure that the trees
	// aren't pointing at each other's data
	bst.print_tree();
	bst2.print_tree(); // should be original

	return 0;
}









int main() {
	int values[14] = {4,2,11,15,9,1,-6,5,3,15,2,5,13,14};
	BinarySearchTree bst;
	for (int i=0;i<14;i++) {
		cout << "Inserting " << values[i] << " into the tree.\n";
		bst.insert(values[i]);
	}
	cout << "Original tree " <<
			"(asterisks denote a count of more than 1):\n";
	print_tree_details(bst);

	cout << "Copy Constructor tree:\n";
	// make a copy with copy constructor
	BinarySearchTree bst_copy_constructor = bst;
	print_tree_details(bst_copy_constructor);

	cout << "Assignment Overload tree:\n";
	// make a copy with assignment overload
	BinarySearchTree bst_copy_1;
	bst_copy_1 = bst;
	print_tree_details(bst_copy_1);


	cout << "Removing 9 from original tree:\n";
	bst.remove(9); // remove a node with no children
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 1 from original tree:\n";
	bst.remove(1); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 11 from original tree:\n";
	bst.remove(11); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 5 from original tree " <<
			"(should still have one 5):\n";
	bst.remove(5); // remove a node with one child
	print_tree_details(bst);

	bst=bst_copy_1;

	cout << "Removing a root node\n";

	bst.remove(4); // remove a node with two children
	print_tree_details(bst);

	cout << "removing a node that doesn't exist\n";

	cout << bst.remove(29); //remove a non existent node
	print_tree_details(bst);

	// check if the tree contains values
	bst = bst_copy_1;
	for (int i=-10;i<20;i++) {
		cout << "Tree " << (bst.contains(i) ?
				"contains " :
				"does not contain ")
								<< "the value " << i << "\n";
	}

	cout << "\nFinished!\n";

	cout << "main 8\n";
	main8();

	cout << "main 10\n";
	main10();
	cout << "main 13\n";
	main13();

	cout << "main 20\n";
	main20();

	cout << "main 21\n";
	main21();

	cout << "main 22\n";
	main22();

	cout << "main 23\n";
	main23();

	cout << "main 24\n";
	main24();

	cout << "main 30\n";
	main30();

	cout << "main 31\n";
	main31();

	cout << "\n Extra Tests Done";
	return 0;
}
