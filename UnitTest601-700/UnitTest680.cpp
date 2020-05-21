#include "pch.h"
#include "CppUnitTest.h"
#include "../601-700/0680.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest601700
{
	TEST_CLASS(UnitTest680)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			check("aba",
				true);
		}

		TEST_METHOD(TestMethod2)
		{
			check("abca",
				true);
		}

		void check(string s, bool expected)
		{
			Solution sln;
			auto actual = sln.validPalindrome(s);
			Assert::AreEqual(expected, actual);
		}
	};
}
