#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0371.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0371)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(1, 2, 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check(-2, 3, 1);
        }

        void check(int a, int b, int expected)
        {
            Solution sln;
            auto actual = sln.getSum(a, b);
            Assert::AreEqual(expected, actual);
        }
    };
}