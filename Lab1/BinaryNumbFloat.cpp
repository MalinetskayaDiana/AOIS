#include "BinaryNumbFloat.h"

void BinaryNumbFloat::setSignOfFloat(string sign)
{
	signOfFloat_ = sign;
}

void BinaryNumbFloat::setMantissa(string mantissa)
{
	mantissa_ = mantissa;
}

void BinaryNumbFloat::setExponent(string exponent)
{
	exponent_ = exponent;
}

string BinaryNumbFloat::getSignOfFloat()
{
	return signOfFloat_;
}

string BinaryNumbFloat::getMantissa()
{
	return mantissa_;
}

string BinaryNumbFloat::getExponent()
{
	return exponent_;
}

void BinaryNumbFloat::transformToStandart(string* mantissa, string* exponent)
{
	BinaryNumbInt exp;
	(*mantissa).insert((*mantissa).size(), 1, '0');
	(*mantissa).erase(0, 1);
	int expon = exp.directTransformToDecimal('0' + *exponent) - 1;
	exp.transformToBinary(expon);
	*exponent = exp.getDirectCode().erase(0, 1);
}

void BinaryNumbFloat::summaSameSign(string firstMantissa, string secondMantissa, string* mantissa, string* exponent, string firstInt, string secondInt)
{
	BinaryNumbInt exp;
	string resultInt;
	bool trans = false;
	char element;
	for (int i = 22; i >= 0; i--)
	{
		element = firstMantissa[i] == secondMantissa[i] ? '0' : '1';
		if (trans)
			element = element == '0' ? '1' : '0';
		if ((firstMantissa[i] == '1' && secondMantissa[i] == '1') || (element == '0' && trans))
			trans = true;
		else
			trans = false;
		(*mantissa).insert(0, 1, element);
	}
	resultInt = firstInt != secondInt ? "1" : firstInt == "0" ? "0" : "10";
	if (trans)
	{
		resultInt = resultInt == "0" ? "1" : resultInt == "1" ? "10" : "11";
	}
	if (resultInt.size() > 1)
	{
		resultInt.erase(0, 1);
		(*mantissa).erase((*mantissa).size() - 1, 1);
		(*mantissa).insert(0, resultInt);
		int expon = exp.directTransformToDecimal('0' + *exponent) + 1;
		exp.transformToBinary(expon);
		*exponent = exp.getDirectCode().erase(0, 1);
	}
}

void BinaryNumbFloat::summaDifferentSign(string firstMantissa, string secondMantissa, string* mantissa, string* exponent, string firstInt, string secondInt)
{
	BinaryNumbInt exp;
	string resultInt;
	bool trans = false;
	char element;
	for (int i = 22; i >= 0; i--)
	{
		if (trans && firstMantissa[i] == '0')
			firstMantissa[i] = '1';
		else if (trans && firstMantissa[i] == '1')
		{
			firstMantissa[i] = '0';
			trans = false;
		}
		element = firstMantissa[i] == secondMantissa[i] ? '0' : '1';
		if ((firstMantissa[i] == '0' && secondMantissa[i] == '1'))
			trans = true;
		(*mantissa).insert(0, 1, element);
	}
	if (trans)
		firstInt = "0";
	resultInt = firstInt == secondInt ? "0" : firstInt == "1" ? "1" : "0";
	if (resultInt == "0")
	{
		while ((*mantissa)[0] == '0')
			transformToStandart(mantissa, exponent);
		transformToStandart(mantissa, exponent);
	}
}

string BinaryNumbFloat::getBinaryFloat()
{
	return getSignOfFloat() + " | " + getExponent() + " | " + getMantissa();
}

void BinaryNumbFloat::transformToBinary(float num)
{
	string sign, exponent, standartForm;
	if (num == 0) 
	{
		sign = "0";
		exponent = "00000000";
		standartForm = "00000000000000000000000";
	}
	else 
	{
		BinaryNumbFixedPoint fixedPoint;
		BinaryNumbInt intNum;
		fixedPoint.trasformToBinary(num);
		sign = fixedPoint.getIntBinatyPart().substr(0, 1);
		string partInt = fixedPoint.getIntBinatyPart();
		standartForm = fixedPoint.getIntBinatyPart() + fixedPoint.getFloatBinaryPart();
		partInt.erase(0, 1);
		standartForm.erase(0, 1);
		int digit = 0, powerOfNumb, exp = 127;
		while (standartForm[digit] == '0') digit++;
		powerOfNumb = partInt.size() - digit - 1;
		standartForm.erase(0, digit + 1);
		exp += powerOfNumb;
		intNum.transformToBinary(exp);
		if (standartForm.size() < 23)
			standartForm.insert(standartForm.size(), 23 - standartForm.size(), '0');
		exponent = intNum.getDirectCode();
		if (intNum.getDirectCode().size() > 8)
			exponent.erase(0, 1);
	}
	setSignOfFloat(sign);
	setExponent(exponent);
	setMantissa(standartForm);
}

float BinaryNumbFloat::transformFloatToDecimal()
{
	BinaryNumbInt intNum;
	BinaryNumbFixedPoint fixedPoint;
	string exponent = exponent_, intPart = signOfFloat_, floatPart = mantissa_;
	int exp = intNum.directTransformToDecimal(exponent.insert(0, 1, '0')), powerOfNumber;
	if (exp == 0) return 0;
	else 
	{
		powerOfNumber = exp - 127;
		if (powerOfNumber >= 0)
		{
			intPart += '1' + floatPart.substr(0, powerOfNumber);
			floatPart.erase(0, powerOfNumber);
		}
		else
		{
			intPart += '0';
			floatPart.insert(0, 1, '1');
			floatPart.insert(0, (-1 * powerOfNumber) - 1, '0');
		}
		fixedPoint.setIntBinaryPart(intPart);
		fixedPoint.setFloatBinaryPart(floatPart);
		return fixedPoint.trasformToDecimal();
	}
}

BinaryNumbFloat BinaryNumbFloat::operator+(BinaryNumbFloat& secondSummand)
{
	BinaryNumbFloat result;
	BinaryNumbInt exp;
	string sign, exponent, firstMantissa, secondMantissa, resultMantissa, firstInt = "1", secondInt, resultInt;
	int firstExp, secondExp, powerOfNum;
	firstExp = exp.directTransformToDecimal('0' + this->exponent_);
	secondExp = exp.directTransformToDecimal('0' + secondSummand.exponent_);
	powerOfNum = abs(firstExp - secondExp);
	if (firstExp >= secondExp)
	{
		sign = this->signOfFloat_;
		exponent = this->exponent_;
		firstMantissa = this->mantissa_;
		secondMantissa = secondSummand.mantissa_;
		secondInt = "1";
	}
	else
	{
		sign = secondSummand.signOfFloat_;
		exponent = secondSummand.exponent_;
		secondMantissa = this->mantissa_;
		firstMantissa = secondSummand.mantissa_;
	}
	if (powerOfNum > 0)
	{
		secondMantissa.insert(0, 1, '1');
		secondMantissa.insert(0, powerOfNum - 1, '0');
		secondMantissa.erase(23, powerOfNum);
		secondInt = "0";
	}
	if (this->signOfFloat_ == secondSummand.signOfFloat_)
		summaSameSign(firstMantissa, secondMantissa, &resultMantissa, &exponent, firstInt, secondInt);
	else 
	{
		if (this->mantissa_ == secondSummand.mantissa_) 
		{
			resultMantissa = "00000000000000000000000";
			if (powerOfNum == 0)
				exponent = "00000000";
		}
		else 
			summaDifferentSign(firstMantissa, secondMantissa, &resultMantissa, &exponent, firstInt, secondInt);

	}
	result.setSignOfFloat(sign);
	result.setExponent(exponent);
	result.setMantissa(resultMantissa);
	return result;
}