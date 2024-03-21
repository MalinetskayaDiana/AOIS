#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>

using namespace std;

class LogicFormula
{
private:
	string logicFormula_;
	vector<string> allSubformulas_;
	void splitVaribles();
	string formationSubformula(string formula);
	void splitByBrackets();
	void splitIntoSubformulas();
	bool checkDoubleVaribles(string varible);
public:
	LogicFormula();
	LogicFormula(string formula);
	int countOfVaribles();
	vector<string> getAllSubformulas();
	void printSubformulas();
};

