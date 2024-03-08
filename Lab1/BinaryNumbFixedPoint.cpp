#include "BinaryNumbFixedPoint.h"

void BinaryNumbFixedPoint::setIntBinaryPart(string intPart)
{
	intBinaryPart_ = intPart;
}

void BinaryNumbFixedPoint::setFloatBinaryPart(string floatPart)
{
	floatBinaryPart_ = floatPart;
}

void BinaryNumbFixedPoint::transformIntPart(float floatNumber)
{
	string result = "0";
	int num = floatNumber < 0 ? (-1 * int(floatNumber)) : int(floatNumber);
	int divisible = num, remainder;
	while (divisible != 1 && divisible != 0)
	{
		remainder = divisible % 2;
		result += remainder + '0';
		divisible /= 2;
	}
	result += divisible + '0';
	result.erase(0, 1);
	remainder = floatNumber < 0 ? 1 : 0;
	result += remainder + '0';
	reverse(result.begin(), result.end());
	setIntBinaryPart(result);
}

void BinaryNumbFixedPoint::transformFloatPart(float floatNumber)
{
	int n = 25 - intBinaryPart_.size();
	string result = "0";
	floatNumber = floatNumber < 0 ? floatNumber *= -1 : floatNumber;
	int num = int(floatNumber);
	float floatPart = floatNumber - num;
	for (int i = 0; i < n; i++) 
	{
		floatPart *= 2;
		num = int(floatPart);
		floatPart = num == 1 ? (floatPart - 1) : floatPart;
		result += num + '0';
	}
	result.erase(0, 1);
	setFloatBinaryPart(result);
}

float BinaryNumbFixedPoint::transformIntPartToDecimal()
{
	string intPart = intBinaryPart_;
	char sign = intPart[0];
	intPart.erase(0, 1);
	float result = 0;
	reverse(intPart.begin(), intPart.end());
	for (int i = 0; i <= intPart.size() - 1; i++)
		result += (intPart[i] - '0') * pow(2, i);
	result = sign == '0' ? result : (-1 * result);
	return result;
}

float BinaryNumbFixedPoint::transformFloatPartToDecimal()
{
	string floatPart = floatBinaryPart_;
	float result = 0;
	for (int i = 0; i <= floatPart.size() - 1; i++)
		result += (floatPart[i] - '0') * pow(2, -1 * (i + 1));
	result = intBinaryPart_[0] == '0' ? result : (-1 * result);
	return result;
}

void BinaryNumbFixedPoint::trasformToBinary(float num)
{
	transformIntPart(num);
	transformFloatPart(num);
}

float BinaryNumbFixedPoint::trasformToDecimal()
{
	return transformIntPartToDecimal() + transformFloatPartToDecimal();
}

string BinaryNumbFixedPoint::getIntBinatyPart()
{
	return intBinaryPart_;
}

string BinaryNumbFixedPoint::getFloatBinaryPart()
{
	return floatBinaryPart_;
}

string BinaryNumbFixedPoint::getFloatBinary()
{
	return intBinaryPart_ + '.' + floatBinaryPart_;
}
