#include "pch.h"
#include "CppUnitTest.h"
#include "../1201-1300/1224.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12011300
{
	TEST_CLASS(UnitTest1244)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			check("[2,2,1,1,5,3,3,5]",
				7);
		}

		TEST_METHOD(TestMethod2)
		{
			check("[1,1,1,2,2,2,3,3,3,4,4,4,5]",
				13);
		}

		TEST_METHOD(TestMethod3)
		{
			check("[1,1,1,2,2,2]",
				5);
		}

		TEST_METHOD(TestMethod4)
		{
			check("[10,2,8,9,3,8,1,5,2,3,7,6]",
				8);
		}

		TEST_METHOD(TestMethod5)
		{
			check("[1, 1]",
				2);
		}

		TEST_METHOD(TestMethod6)
		{
			check("[1,1,1,2,2,2]",
				5);
		}

	private:
		void check(string numsSrc, int expected)
		{
			auto nums = toIntArray(numsSrc);
			Solution sln;
			auto actual = sln.maxEqualFreq(nums);
			Assert::AreEqual(expected, actual);
		}
	};
}
