//---------------------------------------------------------------------------
// LINKEDLIST.H
// A container that represents a Linked List
//---------------------------------------------------------------------------
// Linked list Class: 
//   -- inserts items into linked list
//   -- removes items from linked list
//   -- clear items from linked list
//---------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Item.h"
using namespace std;

class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	bool insert(Item *obj);   //change this to take all sorts of objects
	bool remove(Item *target); //change this to take all sorts of objects
	void clear(); 

private:
	struct Node

	{
		Item *data;
		Node *next;
	};
	Node *headPtr;

};
