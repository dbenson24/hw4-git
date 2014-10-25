# ReadMe for COMP 15 HW4
## Binary Search Tree Assignment 

Author - Derek Benson

The program implements a binary search tree with linked list style nodes. 
When compiled and run the program will output a brief test of it's ability
to manipulate binary search trees.

BinarySearchTree.cpp
    This file contains the definitions of all of the functions that the
    BinarySearchTree class needs.

BinarySearchTree.h
    This is the header file for the BinarySearchTree class. It declares
    all of the methods and variables defined in BinarySearchTree.cpp.

pretty_print.cpp
    Defines the pretty_print class. Used to output a beautified version
    a Binary Search Tree.

main.cpp
    Defines a short test method that demonstrates how the program
    can manipulate Binary Search Trees.

This program compiles with the provided Makefile.

The Binary Search Tree is stored as a single Node: root which contains
left and right pointers for navigation through the rest of the tree.
Data is stored in the data pointer on each node and the count is stored
in the count pointer on each node.

Binary Search Trees are implemented so that for any given node all of the
nodes to the left are smaller and all of the nodes to the right are larger.
Nodes are inserted into the first possible position, checking left positions
before possible right ones.






