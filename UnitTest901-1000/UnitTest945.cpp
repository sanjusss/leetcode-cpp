#include "pch.h"
#include "CppUnitTest.h"
#include "../901-1000/0945.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9011000
{
	TEST_CLASS(UnitTest945)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
            check("[1,2,2]", 1);
		}

		TEST_METHOD(TestMethod2)
		{
			check("[3,2,1,2,1,7]", 6);
		}

        void check(string ASrc, int expected)
        {
            auto A = toIntArray(ASrc);
            Solution sln;
            auto actual = sln.minIncrementForUnique(A);
            Assert::AreEqual(expected, actual);
        }
	};
}
