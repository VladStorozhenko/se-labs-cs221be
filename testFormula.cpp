#include "pch.h"
#include "CppUnitTest.h"
#include "D:\university\software engineering\lab5\lab5\lab5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testFormula
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		
		TEST_METHOD(calculate_get3and2_minus1returned)
		{
			int n = 3;
			double x = 2;

			double expected = -100;

			double actual = calculate(n, x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculate_get3andminus2_13returned)
		{
			int n = 3;
			double x = -2;

			double expected = 13;

			double actual = calculate(n, x);

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(checkValidParams_Test)
	{
	public:

		TEST_METHOD(checkValidParams_get2and5and1and4_expectionNotThrown)
		{
			double a = 2;
			double b = 5;
			int step = 1;
			int n = 4;

			try {
				check_valid_params(a, b, step, n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
			
		}

		TEST_METHOD(checkValidParams_get2and5and1and1_expectionThrown)
		{
			double a = 2;
			double b = 5;
			int step = 1;
			int n = 1;

			try {
				check_valid_params(a, b, step, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(checkValidParams_get6and5and1and4_expectionThrown)
		{
			double a = 6;
			double b = 5;
			int step = 1;
			int n = 4;

			try {
				check_valid_params(a, b, step, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(checkValidParams_get2and5and7and5_expectionThrown)
		{
			double a = 2;
			double b = 5;
			int step = 7;
			int n = 5;

			try {
				check_valid_params(a, b, step, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};
} 
