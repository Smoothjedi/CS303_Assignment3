/*****************************************************************//**
 * \file   CS303_Assignment3.cpp
 * \brief  The main program and its 
 * 
 * \author Mike
 * \date   April 2023
 *********************************************************************/

#include <iostream>
#include "InfixToPostfix.h"
#include "Queue.h"

int main()
{
	bool terminateFlag = false;

    InfixToPostfix* infixToPostfix = new InfixToPostfix();
	Queue* queue = new Queue();
	do
	{
		// Menu interface
		int userSelection = 0;
		std::cout << "Please select an option:" << std::endl;
		std::cout << "***************** Assignment 3: Part 1 *******************" << std::endl;
		std::cout << " 1: Convert an Infix expression to Postfix" << std::endl << std::endl;

		std::cout << "***************** Assignment 3: Part 2 *******************" << std::endl;
		std::cout << " 2: Add an integer value to the back of the queue" << std::endl;
		std::cout << " 3: Check if the queue is empty" << std::endl;
		std::cout << " 4: Check how many integers are in the queue" << std::endl;
		std::cout << " 5: View the first integer value in the queue" << std::endl;
		std::cout << " 6: Pop the first integer value in the queue" << std::endl;

		std::cout << std::endl << "Any other value will exit" << std::endl;
		std::cin >> userSelection;

		switch (userSelection)
		{
		case 1:	//Convert an Infix expression to Postfix
		{
			try
			{
				system("cls");
				std::string expression;
				std::cout << "Please enter the Infix expression: " << std::endl;
				std::cin.ignore();
				std::getline(std::cin, expression);
				std::cout << "Your converted expression to Postfix notation is as follows:" << std::endl << std::endl
					<< infixToPostfix->ConvertInfixToPostfix(expression) << std::endl << std::endl;
			}
			catch (std::exception& error)
			{
				std::cout << error.what() << std::endl << std::endl;
			}
			break;
		}
		case 2:
		{
			system("cls");
			int valueToAdd = 0;
			std::cout << "Please enter an integer value to add: " << std::endl;
			std::cin >> valueToAdd;
			// Call to append the value to the end of the queue
			queue->push_back(valueToAdd);

			break;
		}
		case 3:
		{
			system("cls");
			if (queue->empty()) std::cout << "The queue is empty!" << std::endl << std::endl;
			else std::cout << "There are integers in the queue!" << std::endl << std::endl;
			break;
		}
		case 4:
		{
			system("cls");
			size_t size = queue->size();
			std::cout << "There ";
			if (size == 0) std::cout << "are no integers ";
			else if (size == 1) std::cout << "is " << size << " integer ";
			else std::cout << "There are " << size << " integers ";
			std::cout << "in the queue!" << std::endl << std::endl;
			break;
		}
		case 5:
		{
			system("cls");
			if (queue->empty()) std::cout << "The queue is empty!" << std::endl;
			else std::cout << "The first value is: " << queue->front() << std::endl << std::endl;
			break;
		}
		case 6:
		{
			system("cls");
			if (queue->empty()) std::cout << "The queue is empty!" << std::endl;
			else std::cout << "The first value was: " << queue->pop_front() << std::endl << std::endl;
			break;
		}

		default:
		{
			//End program
			terminateFlag = true;
		}
		}
	} while (!terminateFlag);

	delete queue;
	delete infixToPostfix;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
