#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryCalc/BinaryNumbFloat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryCalcUnitTests
{
	TEST_CLASS(BinaryCalcUnitTests)
	{
	public:
		TEST_METHOD(BinaryNumberIntPositiveTest)
		{
			BinaryNumbInt number;
			int num = 5;
			number.transformToBinary(num);
			string directCode = "0101", reverseCode = "0101", additionalCode = "0101";
			Assert::AreEqual(number.getDirectCode(), directCode);
			Assert::AreEqual(number.getReverseCode(), reverseCode);
			Assert::AreEqual(number.getAdditionalCode(), additionalCode);
		}
		TEST_METHOD(BinaryNumberIntNegativeTest)
		{
			BinaryNumbInt number;
			int num = -5;
			number.transformToBinary(num);
			string directCode = "1101", reverseCode = "1010", additionalCode = "1011";
			Assert::AreEqual(number.getDirectCode(), directCode);
			Assert::AreEqual(number.getReverseCode(), reverseCode);
			Assert::AreEqual(number.getAdditionalCode(), additionalCode);
		}
		TEST_METHOD(BinaryNumberFixedPointPositiveTest)
		{
			BinaryNumbFixedPoint fixedPoint;
			float num = 5.25;
			fixedPoint.trasformToBinary(num);
			string result = "0101.010000000000000000000";
			Assert::AreEqual(fixedPoint.getFloatBinary(), result);
		}
		TEST_METHOD(BinaryNumberFixedPointNegativeTest)
		{
			BinaryNumbFixedPoint fixedPoint;
			float num = -5.25;
			fixedPoint.trasformToBinary(num);
			string result = "1101.010000000000000000000";
			Assert::AreEqual(fixedPoint.getFloatBinary(), result);
		}
		TEST_METHOD(BinaryNumberFloatPositiveTest)
		{
			BinaryNumbFloat floatNumb;
			float num = 5.25;
			floatNumb.transformToBinary(num);
			string result = "0 | 10000001 | 01010000000000000000000";
			Assert::AreEqual(floatNumb.getBinaryFloat(), result);
		}
		TEST_METHOD(BinaryNumberFloatNegativeTest)
		{
			BinaryNumbFloat floatNumb;
			float num = -5.25;
			floatNumb.transformToBinary(num);
			string result = "1 | 10000001 | 01010000000000000000000";
			Assert::AreEqual(floatNumb.getBinaryFloat(), result);
		}
		TEST_METHOD(BinaryNumberIntSummaPosAndPosTest)
		{
			BinaryNumbInt operand1, operand2, summa;
			int num1 = 2, num2 = 3, result = num1 + num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.addTransformToDecimal(summa.getAdditionalCode()), result);
		}
		TEST_METHOD(BinaryNumberIntSummaPosAndNegTest)
		{
			BinaryNumbInt operand1, operand2, summa;
			int num1 = 2, num2 = -3, result = num1 + num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.addTransformToDecimal(summa.getAdditionalCode()), result);
		}
		TEST_METHOD(BinaryNumberIntSummaNegAndNegTest)
		{
			BinaryNumbInt operand1, operand2, summa;
			int num1 = -2, num2 = -3, result = num1 + num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.addTransformToDecimal(summa.getAdditionalCode()), result);
		}
		TEST_METHOD(BinaryNumberIntDifferencePosAndPosTest)
		{
			BinaryNumbInt operand1, operand2, difference;
			int num1 = 2, num2 = 3, result = num1 - num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			difference = operand1 - operand2;
			Assert::AreEqual(difference.addTransformToDecimal(difference.getAdditionalCode()), result);
		}
		TEST_METHOD(BinaryNumberIntMultiplePosAndPosTest)
		{
			BinaryNumbInt operand1, operand2, multiple;
			int num1 = 2, num2 = 3, result = num1 * num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			multiple = operand1 * operand2;
			Assert::AreEqual(multiple.directTransformToDecimal(multiple.getDirectCode()), result);
		}
		TEST_METHOD(BinaryNumberIntMultiplePosAndNegTest)
		{
			BinaryNumbInt operand1, operand2, multiple;
			int num1 = 2, num2 = -3, result = num1 * num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			multiple = operand1 * operand2;
			Assert::AreEqual(multiple.directTransformToDecimal(multiple.getDirectCode()), result);
		}
		TEST_METHOD(BinaryNumberIntDividePosAdnPosTest)
		{
			BinaryNumbInt operand1, operand2;
			BinaryNumbFixedPoint divide;
			int num1 = 5, num2 = 10;
			float result = 0.5;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			divide = operand1 / operand2;
			Assert::AreEqual(divide.trasformToDecimal(), result);
		}
		TEST_METHOD(BinaryNumberIntDividePosAndNegTest)
		{
			BinaryNumbInt operand1, operand2;
			BinaryNumbFixedPoint divide;
			int num1 = 11, num2 = -2;
			float result = -5.5;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			divide = operand1 / operand2;
			Assert::AreEqual(divide.trasformToDecimal(), result);
		}
		TEST_METHOD(BinaryNumberFloatSummaPosAndPosTest)
		{
			BinaryNumbFloat operand1, operand2, summa;
			float num1 = 2.5, num2 = 3.1, result = num1 + num2;
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.transformFloatToDecimal(), result);
		}
		TEST_METHOD(BinaryNumberFloatSummaPosAndNegTest)
		{
			BinaryNumbFloat operand1, operand2, summa;
			float num1 = -12.5, num2 = 3.1;
			string result = "1 | 10000010 | 00101100110011001100111";
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.getBinaryFloat(), result);
		}
		TEST_METHOD(BinaryNumberFloatSummaNegAndNegTest)
		{
			BinaryNumbFloat operand1, operand2, summa;
			float num1 = -12.5, num2 = -3.1;
			string result = "1 | 10000010 | 11110011001100110011001";
			operand1.transformToBinary(num1);
			operand2.transformToBinary(num2);
			summa = operand1 + operand2;
			Assert::AreEqual(summa.getBinaryFloat(), result);
		}
	};
}
