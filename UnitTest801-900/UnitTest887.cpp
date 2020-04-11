#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0887.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
	TEST_CLASS(UnitTest887)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			check(1, 2 , 2);
		}

		TEST_METHOD(TestMethod2)
		{
			check(2, 6, 3);
		}

		TEST_METHOD(TestMethod3)
		{
			check(3, 14, 4);
		}

		TEST_METHOD(TestMethod4)
		{
			check(1, 3, 3);
		}

		TEST_METHOD(TestMethod5)
		{
			check(4, 10000, 23);
		}

	private:
		void check(int K, int N, int expected)
		{
			Solution sln;
			auto actual = sln.superEggDrop(K, N);
			Assert::AreEqual(expected, actual);
		}
	};
}
