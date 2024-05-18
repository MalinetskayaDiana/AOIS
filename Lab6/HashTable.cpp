#include "HashTable.h"

int HashTable::charSymbolToInt(char ch)
{
	ch = tolower(ch);
	return ch - 'a';
}

int HashTable::hashFunction(string keyWord)
{
	int hash;
	hash = charSymbolToInt(keyWord[0]) * 26 + charSymbolToInt(keyWord[1]);
	return hash;
}

void HashTable::fullTableCell(int index, string termin, string definition)
{
	_hashTable[index].setKeyWord(termin);
	_hashTable[index].setValue(definition);
	_hashTable[index].setFreeCellFlag(false);
	_countOfFreeCell--;
}

void HashTable::cleanOutCell(int index)
{
	_hashTable[index].setKeyWord("");
	_hashTable[index].setValue("");
	_countOfFreeCell++;
}

HashTable::HashTable()
{
	_countOfFreeCell = 20;
}

int HashTable::getCountOfFreeCell()
{
	return _countOfFreeCell;
}

void HashTable::addTermin(string termin, string definition)
{
	if (_countOfFreeCell > 0)
	{
		int probation = hashFunction(termin);
		int index = probation % _countOfRows;
		if (_hashTable[index].getKeyWord() == "")
			fullTableCell(index, termin, definition);
		else 
		{
			int i = 1;
			while (_hashTable[index].getKeyWord() != "")
			{
				index = (probation + i * termin.length()) % _countOfRows;
				i++;
			}
			fullTableCell(index, termin, definition);
		}
	}
	else
		cout << "The table is completely full.\n";
}

void HashTable::removeTermin(string termin)
{
	int index = findTermin(termin);
	if (index < _countOfRows)
	{
		cleanOutCell(index);
	}
	else
		cout << "There is no such term" << endl;
}

int HashTable::findTermin(string termin)
{
	int result = 20;
	int probation = hashFunction(termin), i = 1;
	int index = probation % _countOfRows;
	while (!_hashTable[index].getFreeCellFlag()) 
	{
		if (_hashTable[index].getKeyWord() == termin) 
		{
			result = index;
			break;
		}
		else 
		{
			index = (probation + i * termin.length()) % _countOfRows;
			i++;
		}
	}
	return result;
}

void HashTable::printHashTable()
{
	cout << "\nHash Table:" << endl;
	for (int i = 0; i < _countOfRows; i++)
	{
		string tabulation = i < 10 ? " " : "";
		if (_hashTable[i].getKeyWord() == "")
			cout << tabulation << "[" << i << "]  " << "This line is empty " << endl;
		else
			cout << tabulation << "[" << i << "]  " << _hashTable[i].getKeyWord() << " - " << _hashTable[i].getValue() << endl;
	}
}
