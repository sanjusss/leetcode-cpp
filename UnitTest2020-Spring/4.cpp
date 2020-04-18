#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/4.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest4)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[2, 5, 1, 1, 1, 1]",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[6, 1]",
                1);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[4, 1, 1, 1, 1]",
                2);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1, 3, 5, 1, 1, 1]",
                4);
        }

        void check(string jumpSrc, int expected)
        {
            auto jump = toIntArray(jumpSrc);
            Solution sln;
            auto actual = sln.minJump(jump);
            Assert::AreEqual(expected, actual);
        }
    };
}