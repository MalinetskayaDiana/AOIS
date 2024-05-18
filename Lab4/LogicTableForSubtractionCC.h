#pragma once
#include "..\..\LogicTable\LogicTable\LogicTable.h"
#include "..\..\BinaryCalc\BinaryCalc\BinaryNumbInt.h"

class LogicTableForSubtractionCC : public LogicTable
{
private:
	void calculationTableCC(vector<string>& secondOperand);
	void addToTable(int number);
public:
	LogicTableForSubtractionCC();
	LogicTableForSubtractionCC(int input, int output, vector<string>& allSubformulas);
	string PDNF(int index);
};

