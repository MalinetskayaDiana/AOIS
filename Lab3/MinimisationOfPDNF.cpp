#include "MinimisationOfPDNF.h"

void MinimisationOfPDNF::setListOfVaribles()
{
	for (int i = 0; i < pdnf_.size(); i++) 
	{
		for (char ch : pdnf_[i]) 
		{
			if (ch != '!' && ch != '&' && !checkDoubleVaribles(ch))
				allVaribles_.push_back(ch);
		}
	}
}

void MinimisationOfPDNF::splitByBrackets(string pdnf)
{
	string oneBracket;
	int count = 0;
	for (int i = 0; i < pdnf.size(); i++)
	{
		if (pdnf[i] == '(') 
		{
			oneBracket = pdnf.substr(i + 1);
			count = 0;
		}
		if (pdnf[i] == '&') 
		{
			oneBracket.erase(count - 1, 1);
			count--;
		}
		if (pdnf[i] == ')')
		{
			oneBracket.erase(count - 1, pdnf.size() - i);
			pdnf_.push_back(oneBracket);
		}
		count++;
	}
}

void MinimisationOfPDNF::transformToBinary()
{
	string result;
	for (int i = 0; i < pdnf_.size(); i++) 
	{
		for (int j = 0; j < pdnf_[i].size(); j++) 
		{
			if (pdnf_[i][j] == '!') 
			{
				result.insert(result.size(), 1, '0');
				j++;
			}
			else 
				result.insert(result.size(), 1, '1');
		}
		minimalDNF_[i] = result;
		result.clear();
	}
}

//vector<string> MinimisationOfPDNF::spliteToElements(string formula)
//{
//	string element;
//	vector<string> result;
//	for (char ch : formula) 
//	{
//		if (ch != '&')
//			element.insert(element.size(), ch, 1);
//		else
//			result.push_back(element);
//	}
//	result.push_back(element);
//	return result;
//}

bool MinimisationOfPDNF::checkExist(vector<string>& resultANDF, string& element)
{
	bool result = false;
	for (string i : resultANDF) 
	{
		if (i == element) result = true;
	}
	return result;
}

bool MinimisationOfPDNF::checkOfGluingVaribles(int countOfGluingVaribles, string& varible)
{
	int countOfX = 0;
	for (int i = 0; i < varible.size(); i++) 
	{
		if (varible[i] == 'X') countOfX++;
	}
	if ((countOfGluingVaribles == allVaribles_.size() - countOfX) && (varible.size() == allVaribles_.size()))
		return true;
	else
		return false;
}

string MinimisationOfPDNF::gluingVaribles(string firstBracket, string secondBracket, int countOfGluingVaribles)
{
	int countOfMatches = 0;
	string result;
	for (int i = 0; i < firstBracket.size(); i++)
	{
		if (firstBracket[i] == secondBracket[i])
		{
			result.insert(result.size(), 1, firstBracket[i]);
		}
		else if ((firstBracket[i] == 'X' && secondBracket[i] != 'X') || (firstBracket[i] != 'X' && secondBracket[i] == 'X'))
			break;
		else
			result.insert(result.size(), 1, 'X');
	}
	if (!checkOfGluingVaribles(countOfGluingVaribles, result))
		result.clear();
	return result;
}

void MinimisationOfPDNF::gluingStage(int countOfGluingVaribles, bool* gluingIsPossible)
{
	*gluingIsPossible = false;
	vector<string> resultOfGluing;
	vector<bool> checkOfGluing(minimalDNF_.size(), false);
	for (int i = 0; i < minimalDNF_.size() - 1; i++)
	{
		for (int j = i + 1; j < minimalDNF_.size(); j++)
		{
			string el = gluingVaribles(minimalDNF_[i], minimalDNF_[j], countOfGluingVaribles);
			if (!el.empty()) 
			{
				if(!checkExist(resultOfGluing, el))
					resultOfGluing.push_back(el);
				*gluingIsPossible = true;
				checkOfGluing[i] = true;
				checkOfGluing[j] = true;
			}
		}
	}
	for (int i = 0; i < checkOfGluing.size(); i++) 
	{
		if (!checkOfGluing[i])
			resultOfGluing.push_back(minimalDNF_[i]);
	}
	minimalDNF_.clear();
	minimalDNF_ = resultOfGluing;
}

bool MinimisationOfPDNF::noteConstituents(string pdnf, string minimalDNF)
{
	string pdnfBinary;
	bool result = true;
	for (int i = 0; i < pdnf.size(); i++)
	{
		if (pdnf[i] == '!')
		{
			pdnfBinary.insert(pdnfBinary.size(), 1, '0');
			i++;
		}
		else
			pdnfBinary.insert(pdnfBinary.size(), 1, '1');
	}
	for (int i = 0; i < pdnfBinary.size(); i++) 
	{
		if (minimalDNF[i] != 'X' && pdnfBinary[i] != minimalDNF[i])
		{
			result = false;
			break;
		}
	}
	return result;
}

bool MinimisationOfPDNF::checkDoubleVaribles(char element)
{
	bool alreadyExist = false;
	for (int i = 0; i < allVaribles_.size(); i++)
		if (allVaribles_[i] == element)
			alreadyExist = true;
	return alreadyExist;
}

void MinimisationOfPDNF::prepareBlocks(string stringResult, vector<string>& blocks)
{
	for (int i = 0; i < stringResult.size(); i += 4)
	{
		string block = stringResult.substr(i, 4);
		blocks.push_back(block);
	}
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].push_back(blocks[i][2]);
		blocks[i].erase(2, 1);
	}
}

void MinimisationOfPDNF::prepareTable(vector<string>& blocks, vector<string>& table, int blocksOfColumns)
{
	for (int i = 0; i < blocks.size(); i += blocksOfColumns)
	{
		string resultRow = blocks[i];
		for (int j = i + 1; j < blocksOfColumns; j++)
		{
			string addToRow = blocks[j];
			if (j % 2 == 1)
				reverse(addToRow.begin(), addToRow.end());
			resultRow.insert(resultRow.size(), addToRow);
		}
		table.push_back(resultRow);
	}
}

void MinimisationOfPDNF::reorderTable(vector<string>& table)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (i % 4 == 2)
		{
			string tmp = table[i];
			table[i] = table[i + 1];
			table[i + 1] = tmp;
		}
	}
	for (int i = 4; i < table.size(); i += 8)
	{
		string tmp = table[i];
		table[i] = table[i + 3];
		table[i + 3] = tmp;
		tmp = table[i + 1];
		table[i + 1] = table[i + 2];
		table[i + 2] = tmp;
	}
}

void MinimisationOfPDNF::printTable(vector<string>& table)
{
	for (const auto& str : table)
	{
		cout << str << endl;
	}
}

MinimisationOfPDNF::MinimisationOfPDNF(){}

MinimisationOfPDNF::MinimisationOfPDNF(string formula, string pdnf)
{
	formula_ = formula;
	splitByBrackets(pdnf);
	minimalDNF_ = pdnf_;
	setListOfVaribles();
	transformToBinary();
}

string MinimisationOfPDNF::calculationMethod()
{
	bool gluingIsPossible = true;
	int countOfGluingVaribles = allVaribles_.size() - 1;
	cout << "\nAll stages of gluing: \n";
	while (gluingIsPossible && countOfGluingVaribles > 0)
	{
		gluingStage(countOfGluingVaribles, &gluingIsPossible);
		countOfGluingVaribles--;
		cout << getMinimasationPDNF() << endl;
	}
	return getMinimasationPDNF();
}

void MinimisationOfPDNF::calculateTabularMethod()
{
	bool gluingIsPossible = true;
	int countOfGluingVaribles = allVaribles_.size() - 1;
	cout << "\nAll stages of gluing: \n";
	while (gluingIsPossible && countOfGluingVaribles > 0)
	{
		gluingStage(countOfGluingVaribles, &gluingIsPossible);
		countOfGluingVaribles--;
		cout << getMinimasationPDNF() << endl;
	}
	vector<vector<bool>> table(minimalDNF_.size(), vector<bool>(pdnf_.size(), false));
	for (int i = 0; i < minimalDNF_.size(); i++)
	{
		for (int j = 0; j < pdnf_.size(); j++)
			if (noteConstituents(pdnf_[j], minimalDNF_[i]))
				table[i][j] = true;
	}
	printTableForCalcMethod(table, pdnf_, minimalDNF_);
}

void MinimisationOfPDNF::printTableForCalcMethod(const vector<vector<bool>>& table, const vector<string>& pdnf, const vector<string>& minimalDNF)
{
	cout << "   ";
	for (int i = 0; i < pdnf.size(); i++)
		cout << pdnf[i] << "   ";
	for (int i = 0; i < minimalDNF.size(); i++)
	{
		cout << endl << i << "    ";
		for (int j = 0; j < pdnf.size(); j++)
			cout << table[i][j] << "       ";
	}
	cout << endl;
}


void MinimisationOfPDNF::tabularMethod()
{
	LogicTable logicTable(formula_);
	string stringResult = logicTable.indexFormOfFunction();
	int rowsVaribles = allVaribles_.size() / 2, columnsVaribles = allVaribles_.size() - rowsVaribles;
	int columns = pow(2, columnsVaribles), rows = pow(2, rowsVaribles);
	vector<string> blocks;
	prepareBlocks(stringResult, blocks);
	vector<string> table;
	int blocksOfColumns = columns / 4;
	prepareTable(blocks, table, blocksOfColumns);
	reorderTable(table);
	printTable(table);
}

string MinimisationOfPDNF::getMinimasationPDNF()
{
	string minimalPDNF = "(", bracket;
	for (int i = 0; i < minimalDNF_.size(); i++)
	{
		for (int j = 0; j < minimalDNF_[i].size(); j++)
		{
			if (minimalDNF_[i][j] == '1')
			{
				bracket.insert(bracket.size(), 1, allVaribles_[j]);
				bracket += '&';
			}
			if (minimalDNF_[i][j] == '0')
			{
				bracket.insert(bracket.size(), 1, '!');
				bracket += allVaribles_[j];
				bracket += '&';
			}
		}
		bracket.erase(bracket.size() - 1, 1);
		minimalPDNF += bracket;
		bracket.clear();
		minimalPDNF += ") | (";
	}
	minimalPDNF.erase(minimalPDNF.size() - 4, 4);
	return minimalPDNF;
}

vector<string> MinimisationOfPDNF::getPDNF()
{
	return pdnf_;
}
