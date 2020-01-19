#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0045.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0045)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[2,3,1,1,4]", 2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]", 2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[0]", 0);
        }

        void check(string numSrc, int expected)
        {
            auto nums = toIntArray(numSrc);
            Solution sln;
            auto actual = sln.jump(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}