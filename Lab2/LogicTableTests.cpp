#include "pch.h"
#include "CppUnitTest.h"
#include "..\LogicTable\LogicTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicTableTests
{
	TEST_CLASS(LogicTableTests)
	{
	public:
		TEST_METHOD(SpliteToSubformulasTest)
		{
			LogicFormula formula("((a|b)&(!c))");
			int countOfSubformula = formula.getAllSubformulas().size();
			Assert::AreEqual(6, countOfSubformula);
		}
		TEST_METHOD(CountOfVariblesTest)
		{
			LogicFormula formula("((a|b)&(!b))");
			int countOfVaribles = formula.countOfVaribles();
			Assert::AreEqual(2, countOfVaribles);
		}
		TEST_METHOD(CreateLogicTableTest)
		{
			LogicTable table("(a&(b~((!c)->(!(d|e)))))");
			int countOfRows = table.getLogicTable().size();
			int countOfColumns = table.getLogicTable()[0].size();
			Assert::AreEqual(11, countOfRows);
			Assert::AreEqual(32, countOfColumns);
		}
		TEST_METHOD(IndexFormOfFormulaTest)
		{
			LogicTable table("((a|b)&(!b))");
			string indexForm = table.indexFormOfFunction(), result = "0010";
			Assert::AreEqual(result, indexForm);
		}
		TEST_METHOD(PDNFTest)
		{
			LogicTable table("((a|b)&(!b))");
			string pdnf = table.PDNF(), result = "(a & !b)";
			Assert::AreEqual(result, pdnf);
		}
		TEST_METHOD(PCNFTest)
		{
			LogicTable table("((a|b)&(!b))");
			string pcnf = table.PCNF(), result = "(a | b) & (a | !b) & (!a | !b)";
			Assert::AreEqual(result, pcnf);
		}
		TEST_METHOD(PDNFinNumberFormTest)
		{
			LogicTable table("((a|b)&(!b))");
			string pdnf = table.PDNFinNumbForm(), result = "(2 ) |";
			Assert::AreEqual(result, pdnf);
		}
		TEST_METHOD(PCNFinNumberFormTest)
		{
			LogicTable table("((a|b)&(!b))");
			string pcnf = table.PCNFinNumbForm(), result = "(0, 1, 3 ) &";
			Assert::AreEqual(result, pcnf);
		}
	};
}
