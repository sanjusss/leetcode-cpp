#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../10xx/1095.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10xx
{
	TEST_CLASS(UnitTest1095)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			check(3, "[1,2,3,4,5,3,1]", 2);
		}

		TEST_METHOD(TestMethod2)
		{
			check(3, "[0,1,2,4,2,1]", -1);
		}

		TEST_METHOD(TestMethod3)
		{
			check(1, "[2,4,1]", 2);
		}

		TEST_METHOD(TestMethod4)
		{
			check(101, "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82]",
				100);
		}

		TEST_METHOD(TestMethod5)
		{
			check(5, "[3,5,3,2,0]", 1);
		}

		void check(int target, string mountainArrSrc, int expected)
		{
			MountainArray mountainArr(toIntArray(mountainArrSrc));
			Solution sln;
			auto actual = sln.findInMountainArray(target, mountainArr);
			Assert::AreEqual(expected, actual);
		}
	};
}
