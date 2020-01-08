#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0474.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500
{
    TEST_CLASS(UnitTest474)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"10\", \"0001\", \"111001\", \"1\", \"0\"]",
                5,
                3,
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[\"10\", \"0\", \"1\"]",
                1,
                1,
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[\"10\",\"0001\",\"111001\",\"1\",\"0\"]",
                3,
                4,
                3);
        }

        void check(string strsSrc, int m, int n, int expected)
        {
            auto strs = toStringArray(strsSrc);
            Solution sln;
            auto actual = sln.findMaxForm(strs, m, n);
            Assert::AreEqual(expected, actual);
        }
    };
}
