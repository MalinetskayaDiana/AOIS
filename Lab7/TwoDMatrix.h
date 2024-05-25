#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <ctime>

using namespace std;

class TwoDMatrix
{
private:
	int matrixSize_;
	vector<vector<bool>> matrix_;
	void fullMatrix();
	vector<bool> matchCoincidence(string key, vector<string>& listToCheck, vector<bool> checkMatch);
	vector<string> transformToListOfStr(int startIndex, int finishIndex);
	string toBinary(int number);
	int binaryToDecimal(string binary);
public:
	TwoDMatrix();
	TwoDMatrix(int size);
	void printMatrix();
	string findWordWithIndex(int index);
	string findAddressWordWithIndex(int index);
	void changeWord(string newWord, int resultIndex);
	string logicFunctionUnequal(int firstIndex, int secondIndex, int resultIndex);
	string logicFunctionEqual(int firstIndex, int secondIndex, int resultIndex);
	string logicFormulaSecondArgumentProhibition(int firstIndex, int secondIndex, int resultIndex);
	string logicFunctionImplicationOfTheSecondArgumentToTheFirst(int firstIndex, int secondIndex, int resultIndex);
	int findMaxWord(vector<string>& listToCheck, int degree);
	void sort();
	void summaOfFields();
};

