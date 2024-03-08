#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class BinaryNumbFixedPoint
{
private:
	string intBinaryPart_;
	string floatBinaryPart_;
	void transformIntPart(float floatNumber);
	void transformFloatPart(float floatNumber);
	float transformIntPartToDecimal();
	float transformFloatPartToDecimal();
public:
	void setIntBinaryPart(string intPart);
	void setFloatBinaryPart(string floatPart);
	void trasformToBinary(float number);
	float trasformToDecimal();
	string getIntBinatyPart();
	string getFloatBinaryPart();
	string getFloatBinary();
};

