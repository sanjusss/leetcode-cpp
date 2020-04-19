#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0466.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500
{
    TEST_CLASS(UnitTest466)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("acb",
                4,
                "ab",
                2,
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("aaa",
                3,
                "aa",
                1,
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("aahumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikeffmznimkkasvwsrenazkycxf",
                1000000,
                "aac",
                1000000,
                2);
        }

        TEST_METHOD(TestMethod4)
        {
            check("bacaba",
                3,
                "abacab",
                1,
                2);
        }

        TEST_METHOD(TestMethod5)
        {
            check("phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikef",
                1000000,
                "fmznimkkasvwsrenzkycxfxtlsgypsfad",
                333,
                333);
        }

        TEST_METHOD(TestMethod6)
        {
            check("nlhqgllunmelayl",
                2,
                "lnl",
                1,
                3);
        }

        TEST_METHOD(TestMethod7)
        {
            check("baba",
                11,
                "baab",
                1,
                7);
        }

        TEST_METHOD(TestMethod8)
        {
            check("aaa",
                20,
                "aaaaa",
                1,
                12);
        }

        void check(string s1, int n1, string s2, int n2, int expected)
        {
            Solution sln;
            auto actual = sln.getMaxRepetitions(s1, n1, s2, n2);
            Assert::AreEqual(expected, actual);
        }
    };
}
