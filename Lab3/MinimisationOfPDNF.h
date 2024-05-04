#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "..\..\LogicTable\LogicTable\LogicTable.h"

using namespace std;

class MinimisationOfPDNF
{
private:
	string formula_;
	vector<string> pdnf_;
	vector<string> minimalDNF_;
	vector<char> allVaribles_;
	void setListOfVaribles();
	void splitByBrackets(string pdnf);
	void transformToBinary();
	//vector<string> spliteToElements(string formula);
	bool checkExist(vector<string>& resultANDF, string& element);
	bool checkOfGluingVaribles(int countOfGluingVaribles, string& varible);
	string gluingVaribles(string firstBracket, string secondBracket, int countOfGluingVaribles);
	void gluingStage(int countOfGluingVaribles, bool* gluingIsPossible);
	bool noteConstituents(string pdnf, string minimalDNF);
	bool checkDoubleVaribles(char element);
	void prepareBlocks(string stringResult, vector<string>& blocks);
	void prepareTable(vector<string>& blocks, vector<string>& table, int blocksOfColumns);
	void reorderTable(vector<string>& table);
	void printTableForCalcMethod(const vector<vector<bool>>& table, const vector<string>& pdnf, const vector<string>& minimalDNF);
	void printTable(vector<string>& table);
public:
	MinimisationOfPDNF();
	MinimisationOfPDNF(string formula, string pdnf);
	string calculationMethod();
	void calculateTabularMethod();
	void tabularMethod();

	string getMinimasationPDNF();
	vector<string> getPDNF();
};

