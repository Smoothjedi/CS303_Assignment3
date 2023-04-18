/*****************************************************************//**
 * \file   Queue.cpp
 * \brief  Implementation file for a queue
 * 
 * \author Mike McDonough
 * \date   April 2023
 *********************************************************************/
#include "Queue.h"
#include <iostream>
#include <stdlib.h>

Queue::Queue()
{
	//Create initial values
	Head = NULL;
	Tail = NULL;
	numItems = 0;
}

Queue::~Queue()
{
	//Cycles through the queue and removes all the nodes
	while (Head != NULL) 
	{
		pop_front();
	}
}

void Queue::push_back(const int& value)
{
	// make a new node
	Node* newNode = new Node();
	newNode->data = value;
	//if the list is empty, just set the head and tail to the new node
	if (numItems == 0)
	{
		Head = newNode;
		Tail = newNode;
	}
	//if not, then shift the tail to accomodate
	else
	{
		Tail->next = newNode;
		Tail = newNode;
	}
	numItems++;
}

int Queue::pop_front()
{
	//if empty, then just return 0
	if (numItems == 0)
	{
		return NULL;
	}
	//if only one item, then remove and don't bother trying to check for other pointers
	if (numItems == 1)
	{
		int value = Head->data;
		delete Head;
		Head = NULL;
		Tail = NULL;
		numItems--;
		return value;
	}
	//remove head and assign a new one
	Node* newHead = Head->next;
	int value = Head->data;
	delete Head;
	Head = newHead;
	numItems--;
	return value;

}

int Queue::front()
{
	//if empty, return zero
	if (numItems == 0)
	{
		return NULL;
	}
	//return data without modifying the list
	else
	{
		return Head->data;
	}
}

bool Queue::empty()
{
	//check if any items
	return (numItems == 0);
}

size_t Queue::size()
{
	//return the number of items
    return numItems;
}
