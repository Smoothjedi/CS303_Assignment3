/*****************************************************************//**
 * \file   Queue.h
 * \brief  Header file for a class utilizing a single linked list as a queue.
 * 
 * \author Mike McDonough
 * \date   April 2023
 *********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
	//Constructor
	Queue();
	//Destructor
	~Queue();
	//Adds an integer value to the end of the queue
	void push_back(const int& value);
	//Removes and returns an integer value from the queue
	int pop_front();
	//Returns the integer from the front of the queue without removing it
	int front();
	//Returns whether the queue is empty or not
	bool empty();
	//The current size of the queue.
	size_t size();
private:
	struct Node
	{
		//The data saved in the queue
		int data;
		//The next node in the queue
		Node* next;
	};
	//The start of the queue
	Node* Head;
	//The end of the queue
	Node* Tail;
	//Amount of values in the queue
	size_t numItems;
};

#endif