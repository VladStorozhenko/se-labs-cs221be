#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Admin\source\repos\Lab5_SE\Lab5_SE\Lab5_SE.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(xSmallerThanZero_get3andmin1)
		{
			int n = 3;
			int x = -1;
			double expected = -0.5;

			double actual = xSmallerThanZero(n, x);

			Assert::AreEqual(expected, actual);
		}

	public:

		TEST_METHOD(xGreaterThanZero_get6and1)
		{
			int n = 6;
			int x = 1;
			double expected = 32.8;

			double actual = xGreaterThanZero(n, x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkNValue_get2_returnedfail)
		{
			int n = 2;
			
			try
			{
				checkNValue(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	};

}
