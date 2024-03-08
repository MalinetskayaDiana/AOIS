#pragma once
#include "BinaryNumbInt.h"

class BinaryNumbFloat
{
private:
	string signOfFloat_;
	string mantissa_;
	string exponent_;
	void setSignOfFloat(string sign);
	void setMantissa(string mantissa);
	void setExponent(string exponent);
	string getSignOfFloat();
	string getMantissa();
	string getExponent();
	void transformToStandart(string* mantissa, string* exponent);
	void summaSameSign(string firstMantissa, string secondMantissa, string* mantissa, string* exponent, string firstInt, string secondInt);
	void summaDifferentSign(string firstMantissa, string secondMantissa, string* mantissa, string* exponent, string firstInt, string secondInt);
public:
	string getBinaryFloat();
	void transformToBinary(float num);
	float transformFloatToDecimal();
	BinaryNumbFloat operator+(BinaryNumbFloat& secondSummand);
};

