#include "pch.h"
#include "CppUnitTest.h"
#include "..\HashTable\HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(HashTableTests)
	{
	public:
		
		TEST_METHOD(TableCellConstructorTest)
		{
			string key = "", def = "";
			TableCell tc;
			Assert::AreEqual(tc.getKeyWord(), key);
			Assert::AreEqual(tc.getValue(), def);
			Assert::AreEqual(tc.getFreeCellFlag(), true);
		}

		TEST_METHOD(TableCellSetterTest)
		{
			string key = "Abscissa", def = "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.";
			TableCell tc;
			tc.setKeyWord(key);
			tc.setValue(def);
			tc.setFreeCellFlag(false);
			Assert::AreEqual(tc.getKeyWord(), key);
			Assert::AreEqual(tc.getValue(), def);
			Assert::AreEqual(tc.getFreeCellFlag(), false);
		}

		TEST_METHOD(HashTableConstructorTest)
		{
			HashTable ht;
			Assert::AreEqual(ht.getCountOfFreeCell(), 20);
		}

		TEST_METHOD(HashTableAddTerminTest)
		{
			HashTable ht;
			string key = "Abscissa", def = "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.";
			ht.addTermin(key, def);
			Assert::AreEqual(ht.getCountOfFreeCell(), 19);
		}

		TEST_METHOD(HashTableAddTerminCollisionTest)
		{
			HashTable ht;
			string key = "Abscissa", def = "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.";
			ht.addTermin(key, def);
			ht.addTermin(key, def);
			Assert::AreEqual(ht.getCountOfFreeCell(), 18);
		}

		TEST_METHOD(HashTableRemoveTerminTest)
		{
			HashTable ht;
			string key = "Abscissa", def = "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.";
			ht.addTermin(key, def);
			Assert::AreEqual(ht.getCountOfFreeCell(), 19);
			ht.removeTermin(key);
			Assert::AreEqual(ht.getCountOfFreeCell(), 20);
		}

		TEST_METHOD(HashTableFindTerminTest)
		{
			HashTable ht;
			string key = "Abscissa", def = "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.";
			ht.addTermin(key, def);
			Assert::AreEqual(ht.getCountOfFreeCell(), 19);
			Assert::AreEqual(ht.findTermin(key), 1);
		}

	};
}
