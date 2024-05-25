#include "TwoDMatrix.h"

int main()
{
	int indexWord1, indexWord2, indexWordResult, indexAddress;
	TwoDMatrix matrix(16);
	matrix.printMatrix();
	cout << "Enter index of word: ";
	cin >> indexWord1;
	cout << "Word: " << matrix.findWordWithIndex(indexWord1) << endl << endl;
	cout << "Enter index of address word: ";
	cin >> indexAddress;
	cout << "Address word: " << matrix.findAddressWordWithIndex(indexAddress) << endl << endl;

	cout << "Enter index of the first word: ";
	cin >> indexWord1;
	cout << "Enter index of the second word: ";
	cin >> indexWord2;
	cout << "Enter index of the column to write result: ";
	cin >> indexWordResult;
	cout << "Unequal: " << endl;
	cout << matrix.findWordWithIndex(indexWord1) << endl;
	cout << matrix.findWordWithIndex(indexWord2) << endl;
	cout << matrix.logicFunctionUnequal(indexWord1, indexWord2, indexWordResult) << endl;
	matrix.printMatrix();
	cout << endl;

	cout << "Enter index of the first word: ";
	cin >> indexWord1;
	cout << "Enter index of the second word: ";
	cin >> indexWord2;
	cout << "Enter index of the column to write result: ";
	cin >> indexWordResult;
	cout << "Equal: " << endl;
	cout << matrix.findWordWithIndex(indexWord1) << endl;
	cout << matrix.findWordWithIndex(indexWord2) << endl;
	cout << matrix.logicFunctionEqual(indexWord1, indexWord2, indexWordResult) << endl;
	matrix.printMatrix();
	cout << endl;

	cout << "Enter index of the first word: ";
	cin >> indexWord1;
	cout << "Enter index of the second word: ";
	cin >> indexWord2;
	cout << "Enter index of the column to write result: ";
	cin >> indexWordResult;
	cout << "Second argument prohibition: " << endl;
	cout << matrix.findWordWithIndex(indexWord1) << endl;
	cout << matrix.findWordWithIndex(indexWord2) << endl;
	cout << matrix.logicFormulaSecondArgumentProhibition(indexWord1, indexWord2, indexWordResult) << endl;
	matrix.printMatrix();
	cout << endl;

	cout << "Enter index of the first word: ";
	cin >> indexWord1;
	cout << "Enter index of the second word: ";
	cin >> indexWord2;
	cout << "Enter index of the column to write result: ";
	cin >> indexWordResult;
	cout << "Second argument prohibition: " << endl;
	cout << matrix.findWordWithIndex(indexWord1) << endl;
	cout << matrix.findWordWithIndex(indexWord2) << endl;
	cout << matrix.logicFunctionImplicationOfTheSecondArgumentToTheFirst(indexWord1, indexWord2, indexWordResult) << endl;
	matrix.printMatrix();
	cout << endl;

	cout << "Sort: " << endl;
	matrix.sort();
	matrix.printMatrix();
	cout << endl;

	cout << "Addition of fields with a given match: " << endl;
	matrix.summaOfFields();
	matrix.printMatrix();
}