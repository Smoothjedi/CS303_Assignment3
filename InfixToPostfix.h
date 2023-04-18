/*****************************************************************//**
 * \file   InfixToPostfix.h
 * \brief  Header file
 * 
 * \author Mike McDonough
 * \date   April 2023
 *********************************************************************/
#pragma once
#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <stack>;
#include <string>;
#include <sstream>;

class InfixToPostfix
{
public:
	InfixToPostfix();
	~InfixToPostfix();
	std::string ConvertInfixToPostfix(std::string infixChar);

private:
	int GetOperatorPrecedence(char oper);
	char GetOpeningParenthesis(char closingParenthesis);

};

#endif