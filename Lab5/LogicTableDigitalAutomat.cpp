#include "LogicTableDigitalAutomat.h"

void LogicTableDigitalAutomat::addToTableRows()
{
	for (int j = 0; j < countOfColumns_; j++)
	{
		string binaryNumb = "0";
		for (int i = 0; i < countOfVaribles_ - 1; i++)
		{
			binaryNumb.insert(binaryNumb.size(), logicTable_[i][j]);
		}
		BinaryNumbInt binInt;
		int decimalNum = binInt.directTransformToDecimal(binaryNumb);
		int subtracted = logicTable_[3][j] == "1" ? 1 : 0;
		if (decimalNum == 0 and subtracted == 1)
			decimalNum = 8;
		binInt.transformToBinary(decimalNum - subtracted);
		binaryNumb = binInt.getDirectCode();
		binaryNumb.erase(0, 1);
		while (binaryNumb.size() < 3)
			binaryNumb.insert(0, 1, '0');
		for (int i = 4; i < 7; i++)
		{
			logicTable_[i][j] = binaryNumb[i - 4];
		}
	}
}

void LogicTableDigitalAutomat::valueComparison()
{
	for (int j = 0; j < countOfColumns_; j++) 
	{
		for (int i = 0; i < 3; i++) 
		{
			logicTable_[i + 7][j] = logicTable_[i][j] == logicTable_[i + 4][j] ? "0" : "1";
		}
	}
}

LogicTableDigitalAutomat::LogicTableDigitalAutomat()
{
	int sizeOfTableRows = 10;
	int sizeOfTableColums = 4;
	vector<string> allSubformulas{ "a", "b", "c", "d"};
	setParametersOfTable(sizeOfTableRows, pow(2, sizeOfTableColums), sizeOfTableColums);
	setsubformulas(allSubformulas);
	createLogicTable();
	fillInVaribles();
	addToTableRows();
	valueComparison();
}

string LogicTableDigitalAutomat::PDNF(int index)
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

string LogicTableDigitalAutomat::PCNF(int index)
{
	string pcnf;
	for (int i = 0; i < countOfColumns_; i++)
	{
		if (logicTable_[index][i] == "0")
		{
			pcnf.insert(pcnf.size(), "(");
			for (int j = 0; j < countOfVaribles_; j++)
			{
				if (logicTable_[j][i] == "1")
					pcnf.insert(pcnf.size(), "!");
				pcnf.insert(pcnf.size(), subformulas_[j] + "|");
			}
			pcnf.erase(pcnf.size() - 1, 1);
			pcnf.insert(pcnf.size(), ") & ");
		}
	}
	pcnf.erase(pcnf.size() - 3, 3);
	return pcnf;
}
