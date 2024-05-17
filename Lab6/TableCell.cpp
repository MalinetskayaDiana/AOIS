#include "TableCell.h"

TableCell::TableCell()
{
	_keyWord = "";
	_value = "";
	_freeCell = true;
}

string TableCell::getKeyWord()
{
	return _keyWord;
}

void TableCell::setKeyWord(string idWord)
{
	_keyWord = idWord;
}

string TableCell::getValue()
{
	return _value;
}

void TableCell::setValue(string definition)
{
	_value = definition;
}

bool TableCell::getFreeCellFlag()
{
	return _freeCell;
}

void TableCell::setFreeCellFlag(bool flag)
{
	_freeCell = flag;
}
