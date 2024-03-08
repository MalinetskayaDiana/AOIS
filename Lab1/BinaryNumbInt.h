#pragma once
#include "BinaryNumbFixedPoint.h"

class BinaryNumbInt
{
private:
	string directCode_;
	string reverseCode_;
	string additionalCode_;
	void setDirectCode(string directForm);
	void setReverseCode(string reverseForm);
	void setAdditionalCode(string additionalForm);
	string transformDirect(int num);
	string transformReverse(int num);
	string transformAdditional(int num);
	bool compareBinaryIntNorm(string first, string second);
	bool equalityBinaryIntNum(string first, string second);
	string summa(BinaryNumbInt& secondSummand, string summand1, string summand2, string result);
	string divide(string* toDiv, string* dividerNum, string result, char symbol);
public:
	void transformToBinary(int num);
	int directTransformToDecimal(string directCode);
	int addTransformToDecimal(string additionalCode);
	string getDirectCode();
	string getReverseCode();
	string getAdditionalCode();
	BinaryNumbInt operator+(BinaryNumbInt& secondSummand);
	BinaryNumbInt operator-(BinaryNumbInt& subtractive);
	BinaryNumbInt operator*(BinaryNumbInt& secondMultiplier);
	BinaryNumbFixedPoint operator/(BinaryNumbInt& divider);
};

