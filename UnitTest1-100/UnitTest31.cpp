#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0031.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0031)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3]", "[1,3,2]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,2,1]", "[1,2,3]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,1,5]", "[1,5,1]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1,3,2]", "[2,1,3]");
        }

        TEST_METHOD(TestMethod5)
        {
            check("[2,3,1]", "[3,1,2]");
        }

        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            sln.nextPermutation(nums);
            Assert::AreEqual(expected, nums);
        }
    };
}