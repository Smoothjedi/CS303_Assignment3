/*****************************************************************//**
 * \file   InfixToPostfix.cpp
 * \brief  Implementation of the Infix conversion to Postfix notation
 * 
 * \author Mike McDonough
 * \date   April 2023
 *********************************************************************/
#include "InfixToPostfix.h"

InfixToPostfix::InfixToPostfix()
{
}

InfixToPostfix::~InfixToPostfix()
{
}

std::string InfixToPostfix::ConvertInfixToPostfix(std::string expression)
{
	std::stringstream outfix;
	std::stack<char> stack;
	int roundBracketCount = 0;
	int squareBracketCount = 0;
	int curlyBracketCount = 0;

	for (int i = 0; i < expression.length(); i++)
	{
		int itest = expression.length();
		char infixChar = expression[i];
		//Ignore spaces
		if (infixChar == ' ') continue;
		//Check for parenthesis
		if (infixChar == '('
			|| infixChar == '['
			|| infixChar == '{')
		{
			//Pushes the character onto the stack
			stack.push(infixChar);
			//Keep a count of how many opening parenthesis we have in case they are unbalanced at the end
			if (infixChar == '(') { roundBracketCount++; }
			if (infixChar == '[') { squareBracketCount++; }
			if (infixChar == '{') { curlyBracketCount++; }
			//Go to next character
			continue;
		}

		if (infixChar == ')'
			|| infixChar == ']'
			|| infixChar == '}'
			)
		{
			//Add a space so we can have a prettier format
			outfix << " ";
			bool found = false;
			while (!found)
			{
				//If the stack is empty, the parenthesis are not balanced from the right
				if (stack.empty())
				{
					std::stringstream error;
					error << "An opening parenthesis corresponding to " << infixChar << " at position " << i << " was not found!";
					throw std::exception(error.str().c_str());
				}
				//Need to know what parenthesis matches the one we are analyzing
				//Search for the matching parenthesis
				if (stack.top() != GetOpeningParenthesis(infixChar))
				{
					outfix << stack.top();
					stack.pop();
				}
				else
				{
					if (infixChar == ')') { roundBracketCount--; }
					if (infixChar == ']') { squareBracketCount--; }
					if (infixChar == '}') { curlyBracketCount--; }

					found = true;
				}
			}
			stack.pop();
			//Go to next character
			continue;
		}

		if ((infixChar >= 'a' && infixChar <= 'z')
			|| (infixChar >= 'A' && infixChar <= 'Z')
			|| (infixChar >= '0' && infixChar <= '9'))
		{
			outfix << infixChar;
			//Go to next character
			continue;
		}
		//Check for an operator
		if (infixChar == '%' 
			|| infixChar == '/' 
			|| infixChar == '*'
			|| infixChar == '-'
			|| infixChar == '+')
		{
			outfix << " ";
			//Check the precedence of the operator to determine if we need to put it on the stack or not
			while (!stack.empty()  
				&& GetOperatorPrecedence(expression[i]) <= GetOperatorPrecedence(stack.top()))
			{
				outfix << stack.top() << " ";
				stack.pop();
			}
			stack.push(infixChar);
		}
	}

	while (!stack.empty())
	{
		//If we have characters still on the stack when we're done with the expression, pop them
		outfix << " " << stack.top();
		stack.pop();
	}
	
	if (roundBracketCount != 0 || squareBracketCount != 0 || curlyBracketCount != 0)
	{
		//If we did not decrement down to zero, we had unbalanced opening parenthesis. Throw an error
		std::stringstream error;
		error << "Parenthesis were not balanced in the expression!";
		throw std::exception(error.str().c_str());
	}

	return outfix.str();
}

int InfixToPostfix::GetOperatorPrecedence(char oper)
{
	//Higher value is a higher precedence
	switch (oper)
	{
	case('+'):
	case('-'):
		return 0;
		break;
	case('/'):
	case('*'):
	case('%'):
		return 1;
		break;
	default:
		return -1;
	}
}

char InfixToPostfix::GetOpeningParenthesis(char closingParenthesis)
{
	//Return the parenthesis matching opening parenthesis
	switch (closingParenthesis)
	{
	case(')'):
		return '(';
		break;
	case(']'):
		return '[';
		break;
	case('}'):
		return '{';
		break;
	default:
		return '0';
	}
}
