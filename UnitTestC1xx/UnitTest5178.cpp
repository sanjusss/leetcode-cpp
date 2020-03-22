#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5178.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC181
{
    TEST_CLASS(UnitTest5178)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[21,4,7]",
                32);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,4,5,6,7,8,9,10]",
                45);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[7286,18704,70773,8224,91675]",
                10932);
        }

        void check(string numsSrc, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.sumFourDivisors(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}