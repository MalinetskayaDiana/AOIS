#include "MinimisationOfPCNF.h"

void MinimisationOfPÑNF::setListOfVaribles()
{
	for (int i = 0; i < pcnf_.size(); i++)
	{
		for (char ch : pcnf_[i])
		{
			if (ch != '!' && ch != '|' && !checkDoubleVaribles(ch))
				allVaribles_.push_back(ch);
		}
	}
}

void MinimisationOfPÑNF::splitByBrackets(string pcnf)
{
	string oneBracket;
	int count = 0;
	for (int i = 0; i < pcnf.size(); i++)
	{
		if (pcnf[i] == '(')
		{
			oneBracket = pcnf.substr(i + 1);
			count = 0;
		}
		if (pcnf[i] == '|')
		{
			oneBracket.erase(count - 1, 1);
			count--;
		}
		if (pcnf[i] == ')')
		{
			oneBracket.erase(count - 1, pcnf.size() - i);
			pcnf_.push_back(oneBracket);
		}
		count++;
	}
}

void MinimisationOfPÑNF::transformToBinary()
{
	string result;
	for (int i = 0; i < pcnf_.size(); i++)
	{
		for (int j = 0; j < pcnf_[i].size(); j++)
		{
			if (pcnf_[i][j] == '!')
			{
				result.insert(result.size(), 1, '0');
				j++;
			}
			else
				result.insert(result.size(), 1, '1');
		}
		minimalCNF_[i] = result;
		result.clear();
	}
}

//vector<string> MinimisationOfPÑNF::spliteToElements(string formula)
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

bool MinimisationOfPÑNF::checkExist(vector<string>& resultACNF, string& element)
{
	bool result = false;
	for (string i : resultACNF)
	{
		if (i == element) result = true;
	}
	return result;
}

bool MinimisationOfPÑNF::checkOfGluingVaribles(int countOfGluingVaribles, string& varible)
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

string MinimisationOfPÑNF::gluingVaribles(string firstBracket, string secondBracket, int countOfGluingVaribles)
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

void MinimisationOfPÑNF::gluingStage(int countOfGluingVaribles, bool* gluingIsPossible)
{
	*gluingIsPossible = false;
	vector<string> resultOfGluing;
	vector<bool> checkOfGluing(minimalCNF_.size(), false);
	for (int i = 0; i < minimalCNF_.size() - 1; i++)
	{
		for (int j = i + 1; j < minimalCNF_.size(); j++)
		{
			string el = gluingVaribles(minimalCNF_[i], minimalCNF_[j], countOfGluingVaribles);
			if (!el.empty())
			{
				if (!checkExist(resultOfGluing, el))
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
			resultOfGluing.push_back(minimalCNF_[i]);
	}
	minimalCNF_.clear();
	minimalCNF_ = resultOfGluing;
}

bool MinimisationOfPÑNF::noteConstituents(string pcnf, string minimalCNF)
{
	string pcnfBinary;
	bool result = true;
	for (int i = 0; i < pcnf.size(); i++)
	{
		if (pcnf[i] == '!')
		{
			pcnfBinary.insert(pcnfBinary.size(), 1, '0');
			i++;
		}
		else
			pcnfBinary.insert(pcnfBinary.size(), 1, '1');
	}
	for (int i = 0; i < pcnfBinary.size(); i++)
	{
		if (minimalCNF[i] != 'X' && pcnfBinary[i] != minimalCNF[i])
		{
			result = false;
			break;
		}
	}
	return result;
}

bool MinimisationOfPÑNF::checkDoubleVaribles(char element)
{
	bool alreadyExist = false;
	for (int i = 0; i < allVaribles_.size(); i++)
		if (allVaribles_[i] == element)
			alreadyExist = true;
	return alreadyExist;
}

void MinimisationOfPÑNF::prepareBlocks(string stringResult, vector<string>& blocks)
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

void MinimisationOfPÑNF::prepareTable(vector<string>& blocks, vector<string>& table, int blocksOfColumns)
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

void MinimisationOfPÑNF::reorderTable(vector<string>& table)
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

void MinimisationOfPÑNF::printTable(vector<string>& table)
{
	for (const auto& str : table)
	{
		cout << str << endl;
	}
}

MinimisationOfPÑNF::MinimisationOfPÑNF() {}

MinimisationOfPÑNF::MinimisationOfPÑNF(string formula, string pcnf)
{
	formula_ = formula;
	splitByBrackets(pcnf);
	minimalCNF_ = pcnf_;
	setListOfVaribles();
	transformToBinary();
}

string MinimisationOfPÑNF::calculationMethod()
{
	bool gluingIsPossible = true;
	int countOfGluingVaribles = allVaribles_.size() - 1;
	cout << "\nAll stages of gluing: \n";
	while (gluingIsPossible && countOfGluingVaribles > 0)
	{
		gluingStage(countOfGluingVaribles, &gluingIsPossible);
		countOfGluingVaribles--;
		cout << getMinimasationPCNF() << endl;
	}
	return getMinimasationPCNF();
}

void MinimisationOfPÑNF::calculateTabularMethod()
{
	bool gluingIsPossible = true;
	int countOfGluingVaribles = allVaribles_.size() - 1;
	cout << "\nAll stages of gluing: \n";
	while (gluingIsPossible && countOfGluingVaribles > 0)
	{
		gluingStage(countOfGluingVaribles, &gluingIsPossible);
		countOfGluingVaribles--;
		cout << getMinimasationPCNF() << endl;
	}
	vector<vector<bool>> table(minimalCNF_.size(), vector<bool>(pcnf_.size(), false));
	for (int i = 0; i < minimalCNF_.size(); i++)
	{
		for (int j = 0; j < pcnf_.size(); j++)
			if (noteConstituents(pcnf_[j], minimalCNF_[i]))
				table[i][j] = true;
	}
	printTableForCalcMethod(table, pcnf_, minimalCNF_);
}

void MinimisationOfPÑNF::printTableForCalcMethod(const vector<vector<bool>>& table, const vector<string>& pcnf, const vector<string>& minimalCNF)
{
	cout << "   ";
	for (int i = 0; i < pcnf.size(); i++)
		cout << pcnf[i] << "   ";
	for (int i = 0; i < minimalCNF.size(); i++)
	{
		cout << endl << i << "    ";
		for (int j = 0; j < pcnf.size(); j++)
			cout << table[i][j] << "       ";
	}
	cout << endl;
}


void MinimisationOfPÑNF::tabularMethod()
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


string MinimisationOfPÑNF::getMinimasationPCNF()
{
	string minimalPDNF = "(", bracket;
	for (int i = 0; i < minimalCNF_.size(); i++)
	{
		for (int j = 0; j < minimalCNF_[i].size(); j++)
		{
			if (minimalCNF_[i][j] == '1')
			{
				bracket.insert(bracket.size(), 1, allVaribles_[j]);
				bracket += '|';
			}
			if (minimalCNF_[i][j] == '0')
			{
				bracket.insert(bracket.size(), 1, '!');
				bracket += allVaribles_[j];
				bracket += '|';
			}
		}
		bracket.erase(bracket.size() - 1, 1);
		minimalPDNF += bracket;
		bracket.clear();
		minimalPDNF += ") & (";
	}
	minimalPDNF.erase(minimalPDNF.size() - 4, 4);
	return minimalPDNF;
}

vector<string> MinimisationOfPÑNF::getPCNF()
{
	return pcnf_;
}