#include "LogicTableForSubtractionCC.h"

void LogicTableForSubtractionCC::calculationTableCC(vector<string>& secondOperand)
{
	for (int i = 0; i < logicTable_[3].size(); i++)
	{
		if (logicTable_[3][i] == secondOperand[i])
		{
			logicTable_[3][i] = "0";
		}
		else
		{
			logicTable_[3][i] = "1";
			if(secondOperand[i] == "1")
				logicTable_[4][i] = "1";
		}
	}
}

void LogicTableForSubtractionCC::addToTable(int number)
{
	for (int j = 0; j < countOfColumns_; j++) 
	{
		string binaryNumb = "0";
		for (int i = 0; i < countOfVaribles_; i++)
		{
			binaryNumb.insert(binaryNumb.size(), logicTable_[i][j]);
		}
		BinaryNumbInt binInt;
		int decimalNum = binInt.directTransformToDecimal(binaryNumb);
		binInt.transformToBinary(decimalNum + number);
		binaryNumb = binInt.getDirectCode();
		reverse(binaryNumb.begin(), binaryNumb.end());
		for (int i = countOfVaribles_; i > 0; i--)
		{
			logicTable_[countOfRows_ - i][j] = binaryNumb[i-1];
		}
	}
}

LogicTableForSubtractionCC::LogicTableForSubtractionCC()
{
	int sizeOfTableRows = 5;
	int sizeOfTableColums = 3;
	vector<string> allSubformulas{ "a", "b", "c", "d", "t" };
	setParametersOfTable(sizeOfTableRows, pow(2, sizeOfTableColums), sizeOfTableColums);
	setsubformulas(allSubformulas);
	createLogicTable();
	fillInVaribles();
	logicTable_[3] = logicTable_[0];
	calculationTableCC(logicTable_[1]);
	calculationTableCC(logicTable_[2]);
}

LogicTableForSubtractionCC::LogicTableForSubtractionCC(int input, int output, vector<string>& allSubformulas)
{
	setParametersOfTable(input + output, pow(2, input), input);
	setsubformulas(allSubformulas);
	createLogicTable();
	fillInVaribles();
	addToTable(6);
}

string LogicTableForSubtractionCC::PDNF(int index)
{
	string pdnf;
	for (int i = 0; i < countOfColumns_; i++)
	{
		if (logicTable_[index][i] == "1")
		{
			pdnf.insert(pdnf.size(), "(");
			for (int j = 0; j < countOfVaribles_; j++)
			{
				if (logicTable_[j][i] == "0")
					pdnf.insert(pdnf.size(), "!");
				pdnf.insert(pdnf.size(), subformulas_[j] + "&");
			}
			pdnf.erase(pdnf.size() - 1, 1);
			pdnf.insert(pdnf.size(), ") | ");
		}
	}
	return pdnf.erase(pdnf.size() - 3, 3);
}
