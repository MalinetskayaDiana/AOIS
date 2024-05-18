#include <iostream>
#include "LogicTableDigitalAutomat.h"
#include "..\..\AbbreviationOfLogicFormulas\AbbreviationOfLogicFormulas\MinimisationOfPDNF.h"
#include "..\..\AbbreviationOfLogicFormulas\AbbreviationOfLogicFormulas\MinimisationOfPCNF.h"

using namespace std;

int main()
{
	LogicTableDigitalAutomat table;
	//cout << "q1'   q2'   q3'   v   q1   q2   q3   h1   h2   h3" << endl;
	table.printLogicTable();
	
	cout << "\nFor h1\n";
	cout << endl << "SDNF of h1: " << table.PDNF(7) << endl;
	cout << endl << "SCNF of h1: " << table.PCNF(7) << endl;

	cout << "\nFor h2\n";
	cout << endl << "SDNF of h2: " << table.PDNF(8) << endl;
	cout << endl << "SCNF of h2: " << table.PCNF(8) << endl;

	cout << "\nFor h3\n";
	cout << endl << "SDNF of h3: " << table.PDNF(9) << endl;
	cout << endl << "SCNF of h3: " << table.PCNF(9) << endl;

	MinimisationOfPDNF minPNDFfirst("", table.PDNF(7));
	MinimisationOfPСNF minPCDFfirst("", table.PCNF(7));
	cout << endl << "Minimisation of SDNF of h1: ";
	minPNDFfirst.calculationMethod();
	cout << endl << "Minimisation of SCNF of h1: ";
	minPCDFfirst.calculationMethod();

	MinimisationOfPDNF minPNDFsecond("", table.PDNF(8));
	MinimisationOfPСNF minPCDFsecond("", table.PCNF(8));
	cout << endl << "Minimisation of SDNF of h2: ";
	minPNDFsecond.calculationMethod();
	cout << endl << "Minimisation of SCNF of h2: ";
	minPCDFsecond.calculationMethod();

	MinimisationOfPDNF minPNDFthird("", table.PDNF(9));
	MinimisationOfPСNF minPCDFthird("", table.PCNF(9));
	cout << endl << "Minimisation of SDNF of h3: ";
	minPNDFthird.calculationMethod();
	cout << endl << "Minimisation of SCNF of h3: ";
	minPCDFthird.calculationMethod();

}
