#include "pch.h"
#include "CppUnitTest.h"
#include "../901-1000/0994.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9011000
{
	TEST_CLASS(UnitTest994)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			check("[[2,1,1],[1,1,0],[0,1,1]]", 4);
		}

		TEST_METHOD(TestMethod2)
		{
			check("[[2,1,1],[0,1,1],[1,0,1]]", -1);
		}

		TEST_METHOD(TestMethod3)
		{
			check("[[0,2]]", 0);
		}

		void check(string gridSrc, int expected)
		{
			auto grid = toInt2DArray(gridSrc);
			Solution sln;
			auto actual = sln.orangesRotting(grid);
			Assert::AreEqual(expected, actual);
		}
	};
}
