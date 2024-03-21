#include "LogicTable.h"

void LogicTable::setParametersOfTable(int rows, int columns, int varibles)
{
	countOfColumns_ = columns;
	countOfRows_ = rows;
	countOfVaribles_ = varibles;
}

void LogicTable::setsubformulas(vector<string> subformulas)
{
	subformulas_ = subformulas;
}

int LogicTable::findSubformula(string subformula)
{
	for (int i = 0; i < countOfRows_; i++)
		if (subformulas_[i] == subformula)
			return i;
}

void LogicTable::fillInVaribles()
{
	string significance;
	int degree = countOfVaribles_;
	for (int i = 0; i < countOfVaribles_; i++)
	{
		significance = "0";
		degree--;
		int changeOn = pow(2, degree);
		for (int j = 1; j <= countOfColumns_; j++) 
		{
			logicTable_[i][j-1] = significance;
			if (j % changeOn == 0)
				significance = significance == "0" ? "1" : "0";
		}
	}
}

void LogicTable::createLogicTable()
{
	vector<string> possinleCombination;
	for (int j = 0; j < countOfRows_; j++)
	{
		for (int i = 0; i < countOfColumns_; i++)
		{
			possinleCombination.push_back("0");
		}
		logicTable_.push_back(possinleCombination);
		possinleCombination.clear();
	}
}

void LogicTable::resultOfLogicFormula(string formula, int indexOFOperation)
{
	string operand1, operand2, operation;
	if(formula[0] == '(')
	{
		int openBrackets = 1, closeBrackets = 0, index = 1;
		while (openBrackets != closeBrackets) 
		{
			operand1.insert(operand1.size(), 1, formula[index]);
			if (formula[index] == '(') openBrackets++;
			if (formula[index] == ')') closeBrackets++;
			index++;
		}
		operand1.erase(operand1.size() - 1, 1);
		splitLogicFormula(formula.substr(index), &operation, &operand2);
	}
	else if(formula[0] == '!')
	{
		operation = "!";
		operand2 = formula.substr(1);
		if (operand2[0] == '(')
		{
			operand2.erase(0, 1);
			operand2.erase(operand2.size() - 1, 1);
		}
	}
	else 
	{
		int index = 0;
		operand1.insert(operand1.size(), 1, formula[index]);
		index++;
		splitLogicFormula(formula.substr(index), &operation, &operand2);
	}
	defineOperation(operation, findSubformula(operand1), findSubformula(operand2), indexOFOperation);
}

void LogicTable::splitLogicFormula(string formula, string* operation, string* operand2)
{
	int index = 0;
	if (formula[index] == '-')
	{
		*operation = formula[index];
		++index;
		*operation += formula[index];
	}
	else
		*operation = formula[index];
	++index;
	*operand2 = formula.substr(index);
	if ((*operand2)[0] == '(')
	{
		(*operand2).erase(0, 1);
		(*operand2).erase((*operand2).size() - 1, 1);
	}
}

void LogicTable::defineOperation(string operation, int indexOfOperand1, int indexOfOperand2, int indexOFOperation)
{
	if (operation == "!") 
	{
		inversion(indexOfOperand2, indexOFOperation);
	}
	else if (operation == "~") 
	{
		equivalence(indexOfOperand1, indexOfOperand2, indexOFOperation);
	}
	else if (operation == "->") 
	{
		implication(indexOfOperand1, indexOfOperand2, indexOFOperation);
	}
	else if (operation == "&") 
	{
		conjunction(indexOfOperand1, indexOfOperand2, indexOFOperation);
	}
	else if (operation == "|") 
	{
		disjunction(indexOfOperand1, indexOfOperand2, indexOFOperation);
	}
}

void LogicTable::inversion(int indexOfOperand2, int indexOFOperation)
{
	for (int i = 0; i < logicTable_[indexOFOperation].size(); i++)
	{
		logicTable_[indexOFOperation][i] = logicTable_[indexOfOperand2][i] == "0" ? "1" : "0";
	}
}

void LogicTable::conjunction(int indexOfOperand1, int indexOfOperand2, int indexOFOperation)
{
	for (int i = 0; i < logicTable_[indexOFOperation].size(); i++)
	{
		if (logicTable_[indexOfOperand1][i] == "1" && logicTable_[indexOfOperand2][i] == "1")
		{
			logicTable_[indexOFOperation][i] = "1";
		}
	}
}

void LogicTable::disjunction(int indexOfOperand1, int indexOfOperand2, int indexOFOperation)
{
	for (int i = 0; i < logicTable_[indexOFOperation].size(); i++)
	{
		if (logicTable_[indexOfOperand1][i] == "1" || logicTable_[indexOfOperand2][i] == "1")
		{
			logicTable_[indexOFOperation][i] = "1";
		}
	}
}

void LogicTable::implication(int indexOfOperand1, int indexOfOperand2, int indexOFOperation)
{
	for (int i = 0; i < logicTable_[indexOFOperation].size(); i++)
	{
		if (!(logicTable_[indexOfOperand1][i] == "1" && logicTable_[indexOfOperand2][i] == "0"))
		{
			logicTable_[indexOFOperation][i] = "1";
		}
	}
}

void LogicTable::equivalence(int indexOfOperand1, int indexOfOperand2, int indexOFOperation)
{
	for (int i = 0; i < logicTable_[indexOFOperation].size(); i++)
	{
		if (logicTable_[indexOfOperand1][i] == logicTable_[indexOfOperand2][i])
		{
			logicTable_[indexOFOperation][i] = "1";
		}
	}
}

LogicTable::LogicTable(){}

LogicTable::LogicTable(string formula)
{
	LogicFormula logicFormula(formula);
	int sizeOfTableRows = logicFormula.getAllSubformulas().size();
	int sizeOfTableColums = logicFormula.countOfVaribles();
	setParametersOfTable(sizeOfTableRows, pow(2, sizeOfTableColums), sizeOfTableColums);
	setsubformulas(logicFormula.getAllSubformulas());
	createLogicTable();
	fillInVaribles();
	for (int i = sizeOfTableColums; i < countOfRows_; i++)
	{
		resultOfLogicFormula(logicFormula.getAllSubformulas()[i], i);
	}
}

string LogicTable::indexFormOfFunction()
{
	string indexForm;
	for (int i = 0; i < countOfColumns_; i++)
	{
		indexForm.insert(indexForm.size(), logicTable_[logicTable_.size() - 1][i]);
	}
	return indexForm;
}

string LogicTable::PDNF()
{
	string pdnf;
	for (int i = 0; i < countOfColumns_; i++) 
	{
		if (logicTable_[logicTable_.size() - 1][i] == "1") 
		{
			pdnf.insert(pdnf.size(), "(");
			for (int j = 0; j < countOfVaribles_; j++) 
			{
				if(logicTable_[j][i] == "0")
					pdnf.insert(pdnf.size(), "!");
				pdnf.insert(pdnf.size(), subformulas_[j] + " & ");
			}
			pdnf.erase(pdnf.size() - 3, 3);
			pdnf.insert(pdnf.size(), ") | ");
		}
	}
	return pdnf.erase(pdnf.size() - 3, 3);
}

string LogicTable::PDNFinNumbForm()
{
	string pdnfNumb = "(";
	for (int i = 0; i < countOfColumns_; i++) 
	{
		if (logicTable_[logicTable_.size() - 1][i] == "1")
			pdnfNumb.insert(pdnfNumb.size(), to_string(i) + ", ");
	}
	pdnfNumb.erase(pdnfNumb.size() - 2, 2);
	return pdnfNumb + " ) |";
}

string LogicTable::PCNF()
{
	string pcnf;
	for (int i = 0; i < countOfColumns_; i++)
	{
		if (logicTable_[logicTable_.size() - 1][i] == "0")
		{
			pcnf.insert(pcnf.size(), "(");
			for (int j = 0; j < countOfVaribles_; j++)
			{
				if (logicTable_[j][i] == "1")
					pcnf.insert(pcnf.size(), "!");
				pcnf.insert(pcnf.size(), subformulas_[j] + " | ");
			}
			pcnf.erase(pcnf.size() - 3, 3);
			pcnf.insert(pcnf.size(), ") & ");
		}
	}
	pcnf.erase(pcnf.size() - 3, 3);
	return pcnf;
}

string LogicTable::PCNFinNumbForm()
{
	string pcnfNumb = "(";
	for (int i = 0; i < countOfColumns_; i++)
	{
		if (logicTable_[logicTable_.size() - 1][i] == "0")
			pcnfNumb.insert(pcnfNumb.size(), to_string(i) + ", ");
	}
	pcnfNumb.erase(pcnfNumb.size() - 2, 2);
	return pcnfNumb + " ) &";
}

vector<vector<string>>& LogicTable::getLogicTable()
{
	return logicTable_;
}

void LogicTable::printLogicTable()
{
	cout << endl;
	for (int i = 1; i <= countOfRows_; i++)
		cout << i << "  ";
	cout << endl << "-------------------------------\n";
	for (int i = 0; i < countOfColumns_; i++)
	{
		for (int j = 0; j < countOfRows_; j++)
		{
			cout << logicTable_[j][i] << "  ";
		}
		cout << endl;
	}
}
