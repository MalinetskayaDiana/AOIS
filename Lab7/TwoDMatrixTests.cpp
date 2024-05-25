#include "pch.h"
#include "CppUnitTest.h"
#include "../TwoDimensionalMatrix/TwoDMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TwoDMatrixTests
{
	TEST_CLASS(TwoDMatrixTests)
	{
	public:
		
		TEST_METHOD(findWordWithIndexTest)
		{
			string result = "0000000000000000";
			TwoDMatrix matrix(16);
			matrix.changeWord(result, 5);
			Assert::AreEqual(matrix.findWordWithIndex(5), result);
		}

		TEST_METHOD(findAddressWordWithIndexTest)
		{
			string result = "0000000000000000";
			TwoDMatrix matrix(16);
			matrix.changeWord(result, 0);
			matrix.changeWord(result, 1);
			matrix.changeWord(result, 2);
			matrix.changeWord(result, 3);
			matrix.changeWord(result, 4);
			matrix.changeWord(result, 5);
			matrix.changeWord(result, 6);
			matrix.changeWord(result, 7);
			matrix.changeWord(result, 8);
			matrix.changeWord(result, 9);
			matrix.changeWord(result, 10);
			matrix.changeWord(result, 11);
			matrix.changeWord(result, 12);
			matrix.changeWord(result, 13);
			matrix.changeWord(result, 14);
			matrix.changeWord(result, 15);
			Assert::AreEqual(matrix.findAddressWordWithIndex(5), result);
		}

		TEST_METHOD(logicFunctionUnequalTest)
		{
			string result = "0011000000101100", str1 = "1001001001001001", str2 = "1010001001100101";
			TwoDMatrix matrix(16);
			matrix.changeWord(str1, 0);
			matrix.changeWord(str2, 1);
			matrix.logicFunctionUnequal(0, 1, 2);
			Assert::AreEqual(matrix.findWordWithIndex(2), result);
		}

		TEST_METHOD(logicFunctionEqualTest)
		{
			string result = "1100111111010011", str1 = "1001001001001001", str2 = "1010001001100101";
			TwoDMatrix matrix(16);
			matrix.changeWord(str1, 0);
			matrix.changeWord(str2, 1);
			matrix.logicFunctionEqual(0, 1, 2);
			Assert::AreEqual(matrix.findWordWithIndex(2), result);
		}

		TEST_METHOD(logicFormulaSecondArgumentProhibitionTest)
		{
			string result = "0010000000100100", str1 = "1001001001001001", str2 = "1010001001100101";
			TwoDMatrix matrix(16);
			matrix.changeWord(str1, 0);
			matrix.changeWord(str2, 1);
			matrix.logicFormulaSecondArgumentProhibition(0, 1, 2);
			Assert::AreEqual(matrix.findWordWithIndex(2), result);
		}

		TEST_METHOD(logicFunctionImplicationOfTheSecondArgumentToTheFirstTest)
		{
			string result = "1101111111011011", str1 = "1001001001001001", str2 = "1010001001100101";
			TwoDMatrix matrix(16);
			matrix.changeWord(str1, 0);
			matrix.changeWord(str2, 1);
			matrix.logicFunctionImplicationOfTheSecondArgumentToTheFirst(0, 1, 2);
			Assert::AreEqual(matrix.findWordWithIndex(2), result);
		}

		TEST_METHOD(SortTest)
		{
			string result = "1111111111111111";
			TwoDMatrix matrix(16);
			matrix.changeWord(result, 5);
			Assert::AreEqual(matrix.findWordWithIndex(5), result);
			matrix.changeWord("0111111111111111", 0);
			matrix.changeWord("0011111111111111", 1);
			matrix.changeWord("0001111111111111", 2);
			matrix.changeWord("1010000000000000", 3);
			matrix.changeWord("0010010110111010", 4);
			matrix.changeWord("1000000000000000", 6);
			matrix.changeWord("1110001101101011", 7);
			matrix.changeWord("0000000000001010", 8);
			matrix.changeWord("0000111111111111", 9);
			matrix.changeWord("1110010011110011", 10);
			matrix.changeWord("1100100101100110", 11);
			matrix.changeWord("1010110100101010", 12);
			matrix.changeWord("0000011111111111", 13);
			matrix.changeWord("0000000000001101", 14);
			matrix.changeWord("1111000101110110", 15);
			matrix.sort();
			Assert::AreEqual(matrix.findWordWithIndex(0), result);
		}

		TEST_METHOD(summaOfFieldsTest)
		{
			string result = "1110010000100011", str1 = "1010101010101010", str2 = "1110010000100000";
			TwoDMatrix matrix(16);
			matrix.changeWord(str1, 0);
			matrix.changeWord(str2, 1);
			Assert::AreEqual(matrix.findWordWithIndex(0), str1);
			Assert::AreEqual(matrix.findWordWithIndex(1), str2);
			matrix.summaOfFields();
			Assert::AreEqual(matrix.findWordWithIndex(0), str1);
			Assert::AreEqual(matrix.findWordWithIndex(1), result);
		}
	};
}
