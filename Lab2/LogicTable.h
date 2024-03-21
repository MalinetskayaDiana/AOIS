#pragma once
#include "LogicFormula.h"

class LogicTable
{
private:
	int countOfColumns_;
	int countOfRows_;
	int countOfVaribles_;
	vector<string> subformulas_;
	vector<vector<string>> logicTable_;
	void setParametersOfTable(int columns, int rows, int varibles);
	void setsubformulas(vector<string> subformulas);
	int findSubformula(string subformula);
	void fillInVaribles();
	void createLogicTable();
	void resultOfLogicFormula(string formula, int indexOFOperation);
	void splitLogicFormula(string formula, string* operation, string* operand2);
	void defineOperation(string operation, int indexOfOperand1, int indexOfOperand2, int indexOFOperation);
	void inversion(int indexOfOperand2, int indexOFOperation);
	void conjunction(int indexOfOperand1, int indexOfOperand2, int indexOFOperation);
	void disjunction(int indexOfOperand1, int indexOfOperand2, int indexOFOperation);
	void implication(int indexOfOperand1, int indexOfOperand2, int indexOFOperation);
	void equivalence(int indexOfOperand1, int indexOfOperand2, int indexOFOperation);
public:
	LogicTable();
	LogicTable(string formula);
	string indexFormOfFunction();
	string PDNF();
	string PDNFinNumbForm();
	string PCNF();
	string PCNFinNumbForm();
	vector<vector<string>>& getLogicTable();
	void printLogicTable();
};

