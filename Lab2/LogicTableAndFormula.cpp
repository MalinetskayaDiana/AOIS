#include <iostream>
#include "LogicTable.h"
#include "..\..\BinaryCalc\BinaryCalc\BinaryNumbInt.h"

//   ((a|b)&(!c))
//   (a&(a->b))
//   ((a&b)|(!((!c)->d)))
//   (a&(b~((!c)->(d|e))))
//   ((a&b)|(c->d))
//   (!(((a->b)|c)~d))

int main()
{
    string formula, indexForm;
    cout << "Enter logic formula: ";
    cin >> formula;
    BinaryNumbInt indexFormNumb;
    LogicFormula logicFormula(formula);
    LogicTable table(formula);
    logicFormula.printSubformulas();
    table.printLogicTable();

    cout << "\nSDNF : " << table.PDNF() << endl;
    cout << "SKNF : " << table.PCNF() << endl;

    cout << "\nSDNF in number form : " << table.PDNFinNumbForm() << endl;
    cout << "SKNF in number form : " << table.PCNFinNumbForm() << endl;

    indexForm = table.indexFormOfFunction();
    cout << "\nIndex form: " << indexForm << " : " << indexFormNumb.directTransformToDecimal('0' + indexForm) << endl;
}