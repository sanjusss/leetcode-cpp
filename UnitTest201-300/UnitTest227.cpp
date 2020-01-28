#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0227.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest227)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("1 + 1",
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(" 2-1 + 2 ",
                3);
        }

        TEST_METHOD(TestMethod3)
        {
            check("3+2*2",
                7);
        }

        TEST_METHOD(TestMethod4)
        {
            check(" 3/2 ",
                1);
        }

        TEST_METHOD(TestMethod5)
        {
            check(" 3+5 / 2 ",
                5);
        }

    private:
        void check(string s, int expected)
        {
            _0227::Solution sln;
            auto actual = sln.calculate(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
