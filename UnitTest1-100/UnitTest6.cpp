#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0006.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0006)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("LEETCODEISHIRING", 3, "LCIRETOESIIGEDHN");
        }

        TEST_METHOD(TestMethod2)
        {
            check("LEETCODEISHIRING", 4, "LDREOEIIECIHNTSG");
        }

        TEST_METHOD(TestMethod3)
        {
            check("A", 1, "A");
        }

        TEST_METHOD(TestMethod4)
        {
            check("ABCD", 2, "ACBD");
        }


        void check(string s, int numRows, string expected)
        {
            Solution sln;
            auto actual = sln.convert(s, numRows);
            Assert::AreEqual(expected, actual);
        }
    };
}