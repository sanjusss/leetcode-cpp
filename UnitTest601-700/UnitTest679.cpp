#include "pch.h"
#include "CppUnitTest.h"
#include "../601-700/0679.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest601700
{
	TEST_CLASS(UnitTest679)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			check("[4, 1, 8, 7]",
				true);
		}

		TEST_METHOD(TestMethod2)
		{
			check("[1, 2, 1, 2]",
				false);
		}

		TEST_METHOD(TestMethod3)
		{
			check("[1,3,4,6]",
				true);
		}

		void check(string numsSrc, bool expected)
		{
			auto nums = toIntArray(numsSrc);
			Solution sln;
			auto actual = sln.judgePoint24(nums);
			Assert::AreEqual(expected, actual);
		}
	};
}
