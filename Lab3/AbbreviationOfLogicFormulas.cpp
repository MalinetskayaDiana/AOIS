#include <iostream>
#include "MinimisationOfPDNF.h"
#include "MinimisationOfPCNF.h"


//   ((a|b)&(!c))
//   (a|(!(b&c)))
//   (a&(a->b))
//   ((a&b)|(!((!c)->d)))
//   (a&(b~((!c)->(d|e))))
//   ((a&b)|(c->d))
//   (!(((a->b)|c)~d))

//   (!a&b&c) | (a&!b&!c) | (a&!b&c) | (a&b&!c) | (a&b&c)

int main()
{
    string formula;
    cout << "Enter logic formula: ";
    cin >> formula;
    LogicTable table(formula);
    table.printLogicTable();
    cout << endl << table.PDNF() << endl;
    cout << endl << table.PCNF() << endl;
    MinimisationOfPDNF adnfCalc(formula, table.PDNF());
    MinimisationOfPСNF acnfCalc(formula, table.PCNF());
    MinimisationOfPDNF adnfCalcTab(formula, table.PDNF());
    MinimisationOfPСNF acnfCalcTab(formula, table.PCNF());
    MinimisationOfPDNF adnfTab(formula, table.PDNF());
    //MinimisationOfPDNF adnf("(!a&b&c) | (a&!b&!c) | (a&!b&c) | (a&b&!c) | (a&b&c)");
    //MinimisationOfPCNF acnf("(!a&b&c) | (a&!b&!c) | (a&!b&c) | (a&b&!c) | (a&b&c)");
    cout << "\n-------------------------------------\nCALCULATION METHOD\n-------------------------------------\n";
    adnfCalc.calculationMethod();
    acnfCalc.calculationMethod();
    cout << "\n-------------------------------------\nCALCULATION-Tabular METHOD\n-------------------------------------\n";
    adnfCalcTab.calculateTabularMethod();
    acnfCalcTab.calculateTabularMethod();
    cout << "\n-------------------------------------\nTABULAR METHOD\n-------------------------------------\n";
    adnfTab.tabularMethod();
}