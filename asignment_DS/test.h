#ifndef __TEST_H__
#define __TEST_H__
#include<iostream>
#include<stack>
#include<cctype>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
bool checkUndefinedError(string s);
bool checkSyntaxError(string s);
bool checkErrorLogic(string s);
bool checkDividedbyZero(string s);
bool checkOperator(char s);
int precedence(char c);
string Infix2Postfix(string infix);
string Infix2Prefix(string infix);
string PostfixPrefixCalculator(string input);
bool isLogicOper(char c);
bool isChar(char c);
int getPrecedence(char c);
string LogicInfix2Postfix(string infix);
string LogicInfix2Prefix(string infix);
bool Implication(bool p, bool q);
bool Biconditional(bool p, bool q);
string LogicPostfixPrefixCalculator(string input,string varlue);
#endif
