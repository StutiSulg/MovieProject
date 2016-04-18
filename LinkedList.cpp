// file Transaction.cpp
// Member function definitions for class Transaction
#include "LinkedList.h"

// ---------------------------------------------------------------------------
// LinkedList 
// Default constructor for class LinkedList 
LinkedList::LinkedList() : headPtr(NULL)
{
}

// ---------------------------------------------------------------------------
// insert 
// Inserts item into linked list in order
bool LinkedList::insert(Item *obj)
{
	Node *insNode = new Node();
	insNode->data = obj;

	if (headPtr == NULL)
	{
		headPtr = insNode;
		insNode->next = NULL;
		return true;
	}

	if (*obj < *headPtr->data)
	{
		insNode->next = headPtr;
		headPtr = insNode;
		return true;
	}

	Node *curPtr = headPtr;

	while (curPtr->next != NULL && (*(curPtr->next)->data < *obj || *(curPtr->next)->data == *obj))
	{
		curPtr = curPtr->next;
	}

		insNode->next = curPtr->next;
		curPtr->next = insNode;
		return true;

}

// ---------------------------------------------------------------------------
// remove 
// Removes correct item from linked list by dereferncing the pointer
bool LinkedList::remove(Item *target)
{
	Node *curPtr, *tempPtr;

	if (headPtr == NULL)
	{
		return false;
	}
	if (*headPtr->data == *target)
	{
		tempPtr = headPtr;
		headPtr = headPtr->next;
		tempPtr->data = NULL; 
		delete tempPtr;
		tempPtr = NULL;
		return true;
	}

	curPtr = headPtr;
	while (curPtr->next != NULL && !(*(curPtr->next)->data == *target))
	{
		curPtr = curPtr->next;
	}

	tempPtr = curPtr->next;
	if (tempPtr->next == NULL)
	{
		curPtr->next = NULL;
		tempPtr->data = NULL;
		delete tempPtr;
		tempPtr = NULL;
		return true;
	}
	else
	{
		curPtr->next = tempPtr->next;
		tempPtr->data = NULL;
		delete tempPtr;
		tempPtr = NULL;
		return true;
	}
	return false;

}

// ---------------------------------------------------------------------------
// clear 
// Clears the Linked list
void LinkedList::clear()
{
	Node *del = headPtr; 
	while (headPtr != NULL)
	{
		headPtr = headPtr->next; 
		del->data = NULL; 
		delete del; 
		del = headPtr; 
	}

	del = NULL;
	headPtr = NULL; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor of Linked List
LinkedList::~LinkedList()
{
	clear(); 
}

