// file bintree.cpp
// Member function definitions for class BinTree

#include "BinTree.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class BinTree
BinTree::BinTree()
{
	root = NULL;
}

//// ---------------------------------------------------------------------------
//// Copy 
//// Copy constructor for class BinTree
//// copyTree function recursively adds nodes to the binary tree
//BinTree::BinTree(const BinTree &secBin)
//{
//	root = copyTree(secBin.root);
//}
//
//BinTree::Node* BinTree::copyTree(const Node *treePtr) const
//{
//	Node* newTree = NULL;
//	if (treePtr != NULL)
//	{
//		newTree = new Node();
//		newTree->data = new Item(*treePtr->data);
//
//		newTree->right = copyTree(treePtr->right);
//		newTree->left = copyTree(treePtr->left);
//	}
//
//	return newTree;
//}

// ---------------------------------------------------------------------------
// Deconstructor 
// Empties the Binary Tree proparly after execution
BinTree::~BinTree()
{
	makeEmpty();
}

// ---------------------------------------------------------------------------
// Insert 
// Takes in a Item and sends the root, Item and boolean to 
// insertInorder that places the Item. 
bool BinTree::insert(Item *info)
{
	bool insertSuc = true;
	root = insertInOrder(root, info, insertSuc);

	return insertSuc;
}

BinTree::Node* BinTree::insertInOrder(Node *subTree, Item *node,
	bool &insertSuc)
{
	if (subTree == NULL)						  // if subTree is NULL
	{											  // insert Item here
		Node *newData = new Node();
		newData->data = node;
		newData->left = newData->right = NULL;

		return newData;
	}
	else if (*node < *subTree->data)
	{
		Node *temp;
		temp = insertInOrder(subTree->left, node, insertSuc);
		subTree->left = temp;
		temp = NULL;
	}
	else if (*subTree->data < *node)
	{
		Node *temp;
		temp = insertInOrder(subTree->right, node, insertSuc);
		subTree->right = temp;
		temp = NULL;
	}
	else                                          // if Item already exists
	{
		insertSuc = false;                        // make bool false
		return subTree;
	}
}

// ---------------------------------------------------------------------------
// Retrieve 
// Retrieves the desired Item and passes the pointer through the holder
// pointer. Sends root and Item to retrieveInOrder which retrieves
// the correct node. 
bool BinTree::retrieve(const Item *&info, Item *&holder)
{
	Node *findNode = retrieveInOrder(root, info);

	if (findNode == NULL)
	{
		holder = NULL;
		findNode = NULL;
		return false;
	}
	else
	{
		holder = findNode->data;
		findNode = NULL;
		return true;
	}
}

BinTree::Node* BinTree::retrieveInOrder(Node *subTree, const Item *info) const
{
	if (subTree == NULL)
	{
		return NULL;
	}
	else if (*subTree->data == *info)
	{		 
		return subTree;
	}
	else if (*info < *subTree->data)
	{
		return retrieveInOrder(subTree->left, info);
	}
	else
	{
		return retrieveInOrder(subTree->right, info);
	}
}

//---------------------------------------------------------------------------
// isEmpty
// Checks if the binary tree is empty
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}

	return false;
}

//---------------------------------------------------------------------------
// makeEmpty 
// Makes the binary tree empty by passing the root to emptyInorder funtion
void BinTree::makeEmpty()
{
	emptyInOrder(root);
	root = NULL;
}

void BinTree::emptyInOrder(Node *subTree)
{
	if (subTree != NULL)
	{
		emptyInOrder(subTree->left);
		emptyInOrder(subTree->right);

		delete subTree->data;
		subTree->data = NULL;
		delete subTree;
		subTree = NULL;
	}
}

//---------------------------------------------------------------------------
// operator<< 
// Output streams the Items in a Binary Tree in inorder formate
ostream & operator<<(ostream &outStream, const BinTree &tree)
{
	if (tree.root != NULL)
	{
		tree.root->data->displayHeader(); 
		outStream << endl; 
	}
	tree.inorderHelper(outStream, tree.root);
	outStream << endl;
	return outStream;
}

void BinTree::inorderHelper(ostream &outStream, Node *rootPtr) const
{
	if (rootPtr != NULL)
	{
		inorderHelper(outStream, rootPtr->left);
		Item *data = rootPtr->data;
		data->displayInfo(); 
		outStream << endl;
		inorderHelper(outStream, rootPtr->right);
	}

}