#include "pch.h"
#include "CppUnitTest.h"
#include"C:\Users\Андрей\Desktop\software eng\Lab #5\UNIT_test\UNIT_test\UNIT_test.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_get3and4_6returned)
		{
			int n = 3;
			int x = 4;
			int expected = 6;

			int actual = calculate(n, x);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculate_get3and_1__3returned)
		{
			int n = 3;
			int x = -1;
			int expected = -3;

			int actual = calculate(n, x);

			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get5_exceptionNotThrown)
		{
			int n = 5;

			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkValidParams_get1_exceptionNotThrown)
		{
			int n = 1;

			try
			{
				checkValidParams(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
