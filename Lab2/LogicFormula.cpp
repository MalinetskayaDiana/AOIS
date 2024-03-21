#include "LogicFormula.h"

void LogicFormula::splitVaribles()
{
	regex str("[a-z]");
	for (int i = 0; i < logicFormula_.size(); i++)
	{
		string singleChar(1, logicFormula_[i]);
		if (regex_match(singleChar, str) && !checkDoubleVaribles(singleChar))
			allSubformulas_.push_back(singleChar);
	}
}

string LogicFormula::formationSubformula(string formula)
{
	string subformula = "(";
	int openBrackets = 1, closeBrackets = 0, index = 0;
	while (openBrackets != closeBrackets) 
	{
		subformula += formula[index];
		if (formula[index] == '(') openBrackets++;
		if (formula[index] == ')') closeBrackets++;
		index++;
	}
	subformula.erase(0, 1);
	subformula.erase(subformula.size()-1, 1);
	return subformula;
}

void LogicFormula::splitByBrackets()
{
	string subformula;
	for (int i = logicFormula_.size(); i >= 0; i--)
	{
		if (logicFormula_[i] == '(') {
			subformula = formationSubformula(logicFormula_.substr(i + 1));
			allSubformulas_.push_back(subformula);
		}
	}
}

void LogicFormula::splitIntoSubformulas()
{
	splitVaribles();
	splitByBrackets();
}

bool LogicFormula::checkDoubleVaribles(string varible)
{
	bool alreadyExist = false;
	for (int i = 0; i < allSubformulas_.size(); i++)
		if (allSubformulas_[i] == varible)
			alreadyExist = true;
	return alreadyExist;
}

LogicFormula::LogicFormula(){}

LogicFormula::LogicFormula(string formula): logicFormula_(formula)
{
	splitIntoSubformulas();
}

int LogicFormula::countOfVaribles()
{
	int count = 0;
	for (int i = 0; i < allSubformulas_.size(); i++) 
		if (allSubformulas_[i].size() == 1)
			count++;
	return count;
}

vector<string> LogicFormula::getAllSubformulas()
{
	return allSubformulas_;
}

void LogicFormula::printSubformulas()
{
	for (int i = 1; i <= allSubformulas_.size(); i++) 
	{
		cout << i << ".) " << allSubformulas_[i-1] << endl;
	}
}
