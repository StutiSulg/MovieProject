// file bintree.h
// Binary Search Tree (linked Nodes)
#pragma once
// file bintree.h
// Binary Search Tree (linked Nodes)
#pragma once
#include "Item.h"

//---------------------------------------------------------------------------
// BinTree class:  a binary tree that organizes data from Item. Contains 
//   all the normal features of a BTS but also : 
//   -- allows getting the hieght of a certian piece of data
//   -- allows for a converstion from an array of pointers to data to be  
//      stored in a binary tree. 
//   -- allows for a converstion from a binary tree to an array of data
//   -- allows the binary tree to be displayed sideways 
//   -- allows for the comparison of two binary trees.
//
// Implementation and assumptions:
//   -- valid input is given to Item
//   -- array of Item passed are all initialized
//   -- binary tree will be NULL after transfering data to array of Nodes
//   -- array of Item pointers will be NULL after passing all data to BTS
//---------------------------------------------------------------------------
class BinTree
{
	friend ostream & operator<<(ostream &, const BinTree &);
public:
	BinTree();											// default constructor
	BinTree(const BinTree &);							// copy constructor
	~BinTree();											// deconstructor

	bool isEmpty() const;								// checks if empty
	void makeEmpty();									// makes BST empty
	bool insert(Item* info);						// inserts data

	//retrieves data and stores it in the holder pointer
	bool retrieve(const Item *&info, Item *&holder);


private:
	struct Node {
		Item *data;									// pointer to data object
		Node *left;										// left subtree pointer
		Node *right;									// right subtree pointer
	};

	Node *root;


	// utility functions
	void inorderHelper(ostream &outStream, Node *rootPtr) const;


	// recursive helpers 
	// copies thetree rooted at treePtr and returns a pointer to the copy
	Node* copyTree(const Node *treePtr) const;
	// insert recursive helper
	Node* insertInOrder(Node *subTree, Item *node, bool &insertSuc);
	// retrieve recursive helper
	Node* retrieveInOrder(Node *subTree, const Item *info) const;
	// empty recursive helper
	void emptyInOrder(Node *subTree);

};