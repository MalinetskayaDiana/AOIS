#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "..\..\LogicTable\LogicTable\LogicTable.h"

using namespace std;

class MinimisationOfPÑNF
{
private:
	string formula_;
	vector<string> pcnf_;
	vector<string> minimalCNF_;
	vector<char> allVaribles_;
	void setListOfVaribles();
	void splitByBrackets(string pcnf);
	void transformToBinary();
	//vector<string> spliteToElements(string formula);
	bool checkExist(vector<string>& resultACNF, string& element);
	bool checkOfGluingVaribles(int countOfGluingVaribles, string& varible);
	string gluingVaribles(string firstBracket, string secondBracket, int countOfGluingVaribles);
	void gluingStage(int countOfGluingVaribles, bool* gluingIsPossible);
	bool noteConstituents(string pcnf, string minimalCNF);
	bool checkDoubleVaribles(char element);
	void prepareBlocks(string stringResult, vector<string>& blocks);
	void prepareTable(vector<string>& blocks, vector<string>& table, int blocksOfColumns);
	void reorderTable(vector<string>& table);
	void printTableForCalcMethod(const vector<vector<bool>>& table, const vector<string>& pcnf, const vector<string>& minimalCNF);
	void printTable(vector<string>& table);
public:
	MinimisationOfPÑNF();
	MinimisationOfPÑNF(string formula, string pcnf);
	string calculationMethod();
	void calculateTabularMethod();
	void tabularMethod();

	string getMinimasationPCNF();
	vector<string> getPCNF();
};

