#include "BinaryNumbInt.h"

void BinaryNumbInt::setDirectCode(string directForm)
{
	directCode_ = directForm;
}

void BinaryNumbInt::setReverseCode(string reverseForm)
{
	reverseCode_ = reverseForm;
}

void BinaryNumbInt::setAdditionalCode(string additionalForm)
{
	additionalCode_ = additionalForm;
}

string BinaryNumbInt::transformDirect(int num)
{
	string result = "0";
	int divisible = num < 0 ? ( - 1 * num) : num, remainder;
	while (divisible != 1 && divisible != 0)
	{
		remainder = divisible % 2;
		result += remainder + '0';
		divisible /= 2;
	}
	result += divisible + '0';
	result.erase(0, 1);
	remainder = num < 0 ? 1 : 0;
	result += remainder + '0';
	reverse(result.begin(), result.end());
	return result;
}

string BinaryNumbInt::transformReverse(int num)
{
	string result;
	if (num < 0)
	{
		char element;
		result.insert(0, 1, directCode_[0]);
		for (int i = 1; i <= directCode_.size() - 1; i++)
		{
			element = directCode_[i] == '0' ? '1' : '0';
			result += element;
		}
	}
	else
		result = directCode_;
	return result;
}

string BinaryNumbInt::transformAdditional(int num)
{
	string result;
	if (num < 0)
	{
		result = reverseCode_;
		bool isAdd = true;
		for (int i = result.size() - 1; i >= 0; i--)
		{
			if(isAdd)
				if (result[i] == '0') 
				{
					result[i] = '1';
					isAdd = false;
				}
				else
					result[i] = '0';
		}
	}
	else
		result = directCode_;
	return result;
}

bool BinaryNumbInt::compareBinaryIntNorm(string first, string second)
{
	return abs(directTransformToDecimal(first)) > abs(directTransformToDecimal(second));
}

bool BinaryNumbInt::equalityBinaryIntNum(string first, string second)
{
	first.erase(0, 1);
	second.erase(0, 1);
	return first == second;
}

string BinaryNumbInt::summa(BinaryNumbInt& secondSummand, string summand1, string summand2, string result)
{
	bool trans = false;
	char element;
	for (int i = summand1.size() - 1; i >= 0; i--)
	{
		element = summand1[i];
		element = element == summand2[i] ? '0' : '1';
		if (trans)
		{
			element = element == '0' ? '1' : '0';
		}
		if ((summand1[i] == '1' && summand2[i] == '1') || (element == '0' && trans))
			trans = true;
		else
			trans = false;
		result.insert(0, 1, element);
	}
	if (trans && additionalCode_[0] == secondSummand.additionalCode_[0])
		result.insert(0, 1, '1');
	return result;
}

string BinaryNumbInt::divide(string* toDiv, string* dividerNum, string result, char symbol)
{
	*toDiv += symbol;
	char element = compareBinaryIntNorm((*toDiv).insert(0, 1, '0'), (*dividerNum).insert(0, 1, '0')) ? '1' :
		abs(directTransformToDecimal((*toDiv).insert(0, 1, '0'))) == abs(directTransformToDecimal((*dividerNum).insert(0, 1, '0'))) ? '1' : '0';
	result += element;
	if (element == '1')
	{
		*toDiv = transformDirect(directTransformToDecimal((*toDiv).insert(0, 1, '0')) - directTransformToDecimal((*dividerNum).insert(0, 1, '0')));
		(*toDiv).erase(0, 1);
	}
	return result;
}

void BinaryNumbInt::transformToBinary(int num)
{
	setDirectCode(transformDirect(num));
	setReverseCode(transformReverse(num));
	setAdditionalCode(transformAdditional(num));
}

int BinaryNumbInt::directTransformToDecimal(string directCode)
{
	char sign = directCode[0];
	directCode.erase(0, 1);
	int result = 0;
	reverse(directCode.begin(), directCode.end());
	for (int i = 0; i <= directCode.size() - 1; i++)
		result += (directCode[i] - '0') * pow(2, i);
	result = sign == '0' ? result : (-1 * result);
	return result;
}

int BinaryNumbInt::addTransformToDecimal(string additionalCode)
{
	string num = additionalCode;
	int result = 0;
	if (num[0] == '0')
	{
		result = directTransformToDecimal(num);
	}
	else 
	{
		num.erase(0, 1);
		for (int i = 0; i <= num.size() - 1; i++)
			num[i] = num[i] == '0' ? '1' : '0';
		bool isAdd = true;
		for (int i = num.size() - 1; i >= 0; i--)
		{
			if (isAdd)
				if (num[i] == '0')
				{
					num[i] = '1';
					isAdd = false;
				}
				else
					num[i] = '0';
		}
		num.insert(0, 1, '0');
		result = directTransformToDecimal(num);
		result *= -1;
	}
	return result;
}

string BinaryNumbInt::getDirectCode()
{
	return directCode_;
}

string BinaryNumbInt::getReverseCode()
{
	return reverseCode_;
}

string BinaryNumbInt::getAdditionalCode()
{
	return additionalCode_;
}

BinaryNumbInt BinaryNumbInt::operator+(BinaryNumbInt& secondSummand)
{
	BinaryNumbInt result;
	string resultInBinary;
	string firstNum = additionalCode_, secondNum = secondSummand.additionalCode_;
	char sign;
	if (equalityBinaryIntNum(directCode_, secondSummand.directCode_))
		sign = '0';
	else
		sign = compareBinaryIntNorm(directCode_, secondSummand.directCode_) ? firstNum[0] : secondNum[0];
	if (firstNum.size() > secondNum.size())
		secondNum.insert(1, firstNum.size() - secondNum.size(), secondNum[0]);
	else
		firstNum.insert(1, secondNum.size() - firstNum.size(), firstNum[0]);
	resultInBinary = summa(secondSummand, firstNum, secondNum, resultInBinary);
	resultInBinary.insert(0, 1, sign);
	result.setAdditionalCode(resultInBinary);
	return result;
}

BinaryNumbInt BinaryNumbInt::operator-(BinaryNumbInt& subtractive)
{
	BinaryNumbInt opposSubtractive;
	int toMinus = -1 * subtractive.directTransformToDecimal(subtractive.directCode_);
	opposSubtractive.transformToBinary(toMinus);
	return *this + opposSubtractive;
}

BinaryNumbInt BinaryNumbInt::operator*(BinaryNumbInt& secondMultiplier)
{
	BinaryNumbInt result, firstSummand, secondSummand, summa;
	string multipleResult, firstMultiple = directCode_, secondMultiple = secondMultiplier.directCode_, summand1, summand2, trans = "0";
	char signResult = firstMultiple[0] == secondMultiple[0] ? '0' : '1';
	firstMultiple.erase(0, 1);
	secondMultiple.erase(0, 1);
	reverse(secondMultiple.begin(), secondMultiple.end());
	summand1 = secondMultiple[0] == '0' ? "00" : firstMultiple;
	firstSummand.setAdditionalCode(summand1.insert(0,1,'0'));
	for (int i = 1; i <= secondMultiple.size() - 1; i++) 
	{
		summand2 = secondMultiple[i] == '1' ? (firstMultiple + trans) : "00";
		trans += '0';
		secondSummand.setAdditionalCode(summand2.insert(0,1,'0'));
		summa = firstSummand + secondSummand;
		firstSummand = summa;
	}
	multipleResult = firstSummand.getAdditionalCode();
	multipleResult.insert(0, 1, signResult);
	result.setDirectCode(multipleResult);
	return result;
}

BinaryNumbFixedPoint BinaryNumbInt::operator/(BinaryNumbInt& divider)
{
	BinaryNumbFixedPoint result;
	string divisionResultInt, divisionResultFloat, divisibleNum = directCode_, dividerNum = divider.directCode_, toDiv;
	char signResult = divisibleNum[0] == dividerNum[0] ? '0' : '1', element;
	divisionResultInt.insert(0, 1, signResult);
	if (!compareBinaryIntNorm(divisibleNum, dividerNum)) 
	{
		divisionResultInt += "0";
		toDiv = divisibleNum;
		toDiv.erase(0, 1);
	}
	else 
	{
		divisibleNum.erase(0, 1);
		dividerNum.erase(0, 1);
		toDiv = divisibleNum.substr(0, dividerNum.size() - 1);
		for (int i = dividerNum.size() - 1; i < divisibleNum.size(); i++)
			divisionResultInt = divide(&toDiv, &dividerNum, divisionResultInt, divisibleNum[i]);
	}
	if (directTransformToDecimal(toDiv.insert(0, 1, '0')) != 0)
	{
		divisionResultFloat = "0";
		while (directTransformToDecimal(toDiv.insert(0, 1, '0')) != 0 && divisionResultFloat.size() <= 5)
			divisionResultFloat = divide(&toDiv, &dividerNum, divisionResultFloat, '0');
		divisionResultFloat.erase(0, 1);
	}
	else
		divisionResultFloat = "0";
	result.setIntBinaryPart(divisionResultInt);
	result.setFloatBinaryPart(divisionResultFloat);
	return result;
}
