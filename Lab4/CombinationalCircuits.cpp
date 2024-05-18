#include "..\..\AbbreviationOfLogicFormulas\AbbreviationOfLogicFormulas\MinimisationOfPDNF.h"
#include "LogicTableForSubtractionCC.h"

int main()
{
    LogicTableForSubtractionCC tableCC;
    tableCC.printLogicTable();
    cout << "\nCDNF of D : " << tableCC.PDNF(3) << endl;
    cout << "\nCDNF of t : " << tableCC.PDNF(4) << endl;
    cout << "\nMINIMISATION\n";
    MinimisationOfPDNF minPNDFd("", tableCC.PDNF(3));
    MinimisationOfPDNF minPDNFt("", tableCC.PDNF(4));
    minPNDFd.calculationMethod();
    minPDNFt.calculationMethod();

    vector<string> varibles{ "a", "b", "c", "d" };
    LogicTableForSubtractionCC table(4, 4, varibles);
    table.printLogicTable();
    cout << "\nCDNF of a : " << table.PDNF(4) << endl;
    cout << "\nCDNF of b : " << table.PDNF(5) << endl;
    cout << "\nCDNF of c : " << table.PDNF(6) << endl;
    cout << "\nCDNF of d : " << table.PDNF(7) << endl;
    cout << "\nMINIMISATION\n";
    MinimisationOfPDNF minPNDFa("", table.PDNF(4));
    MinimisationOfPDNF minPDNFb("", table.PDNF(5));
    MinimisationOfPDNF minPNDFc("", table.PDNF(6));
    MinimisationOfPDNF minPDNFd("", table.PDNF(7));
    minPNDFa.calculationMethod();
    minPDNFb.calculationMethod();
    minPNDFc.calculationMethod();
    minPDNFd.calculationMethod();
}