#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5303.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5303)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("10#11#12", "jkab");
        }

        TEST_METHOD(TestMethod2)
        {
            check("1326#", "acz");
        }

        TEST_METHOD(TestMethod3)
        {
            check("25#", "y");
        }


        TEST_METHOD(TestMethod4)
        {
            check("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#", "abcdefghijklmnopqrstuvwxyz");
        }

        void check(string s, string expected)
        {
            Solution sln;
            auto actual = sln.freqAlphabets(s);
            Assert::AreEqual(expected, actual);
        }
    };
}