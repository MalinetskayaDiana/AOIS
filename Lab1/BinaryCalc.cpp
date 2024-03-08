#include "BinaryNumbFloat.h"

int main()
{
    int num1, num2;
    float num3, num4;
    BinaryNumbInt binNum1, binNum2, binNum3;
    BinaryNumbFixedPoint binNum4;
    BinaryNumbFloat binNum5, binNum6, binNum7;
    cout << "Enter integer number: \n";
    cin >> num1;
    binNum1.transformToBinary(num1);
    cout << "Direct Code:     " << binNum1.getDirectCode() << endl << "Reverse Code:    " << binNum1.getReverseCode() << endl << "Additional Code: " << binNum1.getAdditionalCode() << endl << endl;
    cout << "---------------------------------------------------------\n"; 
    cout << "Enter integer number: \n";
    cin >> num2;
    binNum2.transformToBinary(num2);
    cout << "Direct Code:     " << binNum2.getDirectCode() << endl << "Reverse Code:    " << binNum2.getReverseCode() << endl << "Additional Code: " << binNum2.getAdditionalCode() << endl << endl;
    cout << "---------------------------------------------------------\n";
    cout << "Operation with integer numbers:\n";
    binNum3 = binNum1 + binNum2;
    cout << "A + B = " << binNum3.getAdditionalCode() << " : " << binNum3.addTransformToDecimal(binNum3.getAdditionalCode()) << endl;
    binNum3 = binNum1 - binNum2;
    cout << "A - B = " << binNum3.getAdditionalCode() << " : " << binNum3.addTransformToDecimal(binNum3.getAdditionalCode()) << endl;
    binNum3 = binNum1 * binNum2;
    cout << "A * B = " << binNum3.getDirectCode() << " : " << binNum3.directTransformToDecimal(binNum3.getDirectCode()) << endl;
    binNum4 = binNum1 / binNum2;
    cout << "A / B = " << binNum4.getFloatBinary() << " : " << binNum4.trasformToDecimal() << endl << endl;
    cout << "---------------------------------------------------------\n";
    cout << "Enter float number: \n";
    cin >> num3;
    binNum5.transformToBinary(num3);
    cout << binNum5.getBinaryFloat() << " : " << binNum5.transformFloatToDecimal() << endl << endl;
    cout << "---------------------------------------------------------\n";
    cout << "Enter float number: \n";
    cin >> num4;
    binNum6.transformToBinary(num4);
    cout << binNum6.getBinaryFloat() << " : " << binNum6.transformFloatToDecimal() << endl << endl;
    binNum7 = binNum5 + binNum6;
    cout << binNum7.getBinaryFloat() << " : " << binNum7.transformFloatToDecimal() << endl;
}
