#pragma once
#include "TableCell.h"

class HashTable
{
private:
	TableCell _hashTable[20];
	int _countOfFreeCell;
	int charSymbolToInt(char ch);
	int hashFunction(string keyWord);
	void fullTableCell(int index, string termin, string definition);
	void cleanOutCell(int index);
public:
	HashTable();
	int getCountOfFreeCell();
	void addTermin(string termin, string definition);
	void removeTermin(string termin);
	int findTermin(string termin);
	void printHashTable();
};

