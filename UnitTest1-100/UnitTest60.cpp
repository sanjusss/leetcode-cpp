#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0060.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0060)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(3, 3, "213");
        }

        TEST_METHOD(TestMethod2)
        {
            check(4, 9, "2314");
        }

        void check(int n, int k, string expected)
        {
            Solution sln;
            auto actual = sln.getPermutation(n, k);
            Assert::AreEqual(expected, actual);
        }
    };
}