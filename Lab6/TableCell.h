#pragma once
#include <string>
#include <iostream>

using namespace std;

class TableCell
{
private:
	string _keyWord;
	string _value;
	bool _freeCell;
public:
	TableCell();
	void setKeyWord(string idWord);
	void setValue(string definition);
	void setFreeCellFlag(bool flag);
	string getKeyWord();
	string getValue();
	bool getFreeCellFlag();
};

