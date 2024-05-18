#pragma once
#include "..\..\LogicTable\LogicTable\LogicTable.h"
#include "..\..\BinaryCalc\BinaryCalc\BinaryNumbInt.h"

class LogicTableDigitalAutomat : public LogicTable
{
private:
	void addToTableRows();
	void valueComparison();
public:
	LogicTableDigitalAutomat();
	string PDNF(int index);
	string PCNF(int index);
};

