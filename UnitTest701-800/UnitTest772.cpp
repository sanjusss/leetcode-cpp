#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0772.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest772)
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

        TEST_METHOD(TestMethod6)
        {
            check(" 6-4 / 2 ",
                4);
        }

        TEST_METHOD(TestMethod7)
        {
            check("2*(5+5*2)/3+(6/2+8)",
                21);
        }

        TEST_METHOD(TestMethod8)
        {
            check("(2+6* 3+5- (3*14/7+2)*5)+3",
                -12);
        }

        TEST_METHOD(TestMethod9)
        {
            check("-1+4*3/3/3",
                0);
        }

        TEST_METHOD(TestMethod10)
        {
            check("1+-2",
                -1);
        }

        TEST_METHOD(TestMethod11)
        {
            check("1*-2",
                -2);
        }

        TEST_METHOD(TestMethod12)
        {
            check("1 - (-7)",
                8);
        }

    private:
        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.calculate(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
