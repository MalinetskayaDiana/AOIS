#include "TwoDMatrix.h"

void TwoDMatrix::fullMatrix()
{
	srand(time(NULL));
    for (int i = 0; i < matrixSize_; i++) 
    {
        for (int j = 0; j < matrixSize_; j++) 
        {
            matrix_[i][j] = rand() % 2 == 0;
        }
    }
}

vector<bool> TwoDMatrix::matchCoincidence(string key, vector<string>& listToCheck, vector<bool> checkMatch)
{
    for (int i = 0; i < checkMatch.size(); i++)
    {
        bool flagToChange = true;
        for (int j = 0; j < key.size(); j++) 
        {
            if (key[j] != listToCheck[i][j]) 
            {
                flagToChange = false;
                break;
            }
        }
        if(flagToChange == false && checkMatch[i] != false)
            checkMatch[i] = flagToChange;
    }
    return checkMatch;
}

vector<string> TwoDMatrix::transformToListOfStr(int startIndex, int finishIndex)
{
    vector<string> wordList(finishIndex - startIndex, "");
    for (int i = startIndex; i < finishIndex; i++)
    {
        wordList[i - startIndex] = findWordWithIndex(i);
    }
    return wordList;
}

void TwoDMatrix::changeWord(string newWord, int resultIndex)
{
    for (int i = resultIndex; i < matrixSize_; i++)
    {
        matrix_[i][resultIndex] = newWord[i - resultIndex] == '0'? false : true;
    }
    for (int i = 0; i < resultIndex; i++)
    {
        matrix_[i][resultIndex] = newWord[newWord.size() - resultIndex + i] == '0' ? false : true;
    }
}

TwoDMatrix::TwoDMatrix():matrixSize_(0), matrix_() {}

TwoDMatrix::TwoDMatrix(int size): matrixSize_(size), matrix_(matrixSize_, std::vector<bool>(matrixSize_, false))
{
    fullMatrix();
}

void TwoDMatrix::printMatrix()
{
    for (int i = 0; i < matrixSize_; i++)
    {
        for (int j = 0; j < matrixSize_; j++)
        {
            cout << matrix_[i][j] << " ";
        }
        cout << endl;
    }
}

string TwoDMatrix::findWordWithIndex(int index)
{
    string result;
    for (int i = index; i < matrixSize_; i++) 
    {
        result.insert(result.size(), to_string(matrix_[i][index]));
    }
    for (int i = 0; i < index; i++)
    {
        result.insert(result.size(), to_string(matrix_[i][index]));
    }
    return result;
}

string TwoDMatrix::findAddressWordWithIndex(int index)
{
    string result;
    for (int j = 0; j < matrixSize_; j++) 
    {
        result.insert(result.size(), to_string(matrix_[index][j]));
        if (index == matrixSize_ - 1)
            index = 0;
        else
            index++;
    }
    return result;
}

string TwoDMatrix::logicFunctionUnequal(int firstIndex, int secondIndex, int resultIndex)
{
    string result, firstWord = findWordWithIndex(firstIndex), secondWord = findWordWithIndex(secondIndex);
    for (int i = 0; i < matrixSize_; i++) 
    {
        char symbol = firstWord[i] == secondWord[i] ? '0' : '1';
        result.insert(result.size(), 1, symbol);
    }
    changeWord(result, resultIndex);
    return result;
}

string TwoDMatrix::logicFunctionEqual(int firstIndex, int secondIndex, int resultIndex)
{
    string result, firstWord = findWordWithIndex(firstIndex), secondWord = findWordWithIndex(secondIndex);
    for (int i = 0; i < matrixSize_; i++)
    {
        char symbol = firstWord[i] == secondWord[i] ? '1' : '0';
        result.insert(result.size(), 1, symbol);
    }
    changeWord(result, resultIndex);
    return result;
}

string TwoDMatrix::logicFormulaSecondArgumentProhibition(int firstIndex, int secondIndex, int resultIndex)
{
    string result, firstWord = findWordWithIndex(firstIndex), secondWord = findWordWithIndex(secondIndex);
    char symbol;
    for (int i = 0; i < matrixSize_; i++)
    {
        if (firstWord[i] == '0' && secondWord[i] == '1')
            symbol = '1';
        else
            symbol = '0';
        result.insert(result.size(), 1, symbol);
    }
    changeWord(result, resultIndex);
    return result;
}

string TwoDMatrix::logicFunctionImplicationOfTheSecondArgumentToTheFirst(int firstIndex, int secondIndex, int resultIndex)
{
    string result, firstWord = findWordWithIndex(firstIndex), secondWord = findWordWithIndex(secondIndex);
    char symbol;
    for (int i = 0; i < matrixSize_; i++)
    {
        if (firstWord[i] == '0' && secondWord[i] == '1')
            symbol = '0';
        else
            symbol = '1';
        result.insert(result.size(), 1, symbol);
    }
    changeWord(result, resultIndex);
    return result;
}

int TwoDMatrix::findMaxWord(vector<string>& listToCheck, int degree)
{
    string key = "1";
    int indexMax;
    vector<bool> checkMatch(listToCheck.size(), true);
    vector<bool> maxWordList = matchCoincidence(key, listToCheck, checkMatch);
    while (count(maxWordList.begin(), maxWordList.end(), true) != 1) 
    {
        if (count(maxWordList.begin(), maxWordList.end(), true) > 1) 
        {
            checkMatch = maxWordList;
            key += '1';
        }
        else 
        {
            key[key.size() - 1] = '0';
            key += '1';
        }
        maxWordList = matchCoincidence(key, listToCheck, checkMatch);
    }
    for (int i = 0; i < maxWordList.size(); i++) 
    {
        if(maxWordList[i] == true)
            return i + degree;
    }
}

void TwoDMatrix::sort()
{
    cout << "Words in descending order: " << endl;
    for (int i = 0; i < matrixSize_; i++) 
    {
        vector<string> wordList = transformToListOfStr(i, matrixSize_);
        int indexMax = findMaxWord(wordList, i);
        string wordToChange = findWordWithIndex(i);
        cout << findWordWithIndex(indexMax) << endl;
        changeWord(findWordWithIndex(indexMax), i);
        changeWord(wordToChange, indexMax);
        wordList.clear();
    }
}

string TwoDMatrix::toBinary(int number)
{
    bitset<5> binary(number);
    return binary.to_string();
}

int TwoDMatrix::binaryToDecimal(string binary)
{
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--) 
    {
        if (binary[i] == '1') 
        {
            decimal += base;
        }
        base = base * 2;
    }
    return decimal;
}

void TwoDMatrix::summaOfFields()
{
    vector<string> wordList = transformToListOfStr(0, matrixSize_);
    vector<bool> checkMatch(wordList.size(), true);
    checkMatch = matchCoincidence("111", wordList, checkMatch);
    for (int i = 0; i < matrixSize_; i++) 
    {
        if (checkMatch[i]) 
        {
            cout << "(" << i << ") " << findWordWithIndex(i) << " -> ";
            string currentWord = findWordWithIndex(i);
            int numA = binaryToDecimal(currentWord.substr(3, 4));
            int numB = binaryToDecimal(currentWord.substr(7, 4));
            int summa = numA + numB;
            currentWord.erase(11, 5);
            string addToCurrentWord = toBinary(summa);
            if (addToCurrentWord.size() < 5) 
            {
                addToCurrentWord.insert(0, 5 - addToCurrentWord.size(), '0');
            }
            currentWord += addToCurrentWord;
            cout << currentWord << endl;
            changeWord(currentWord, i);
        }
    }
}
