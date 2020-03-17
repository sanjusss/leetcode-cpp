#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0166.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest166)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest(1, 2, "0.5");
        }

        TEST_METHOD(TestMethod2)
        {
            doTest(2, 1, "2");
        }

        TEST_METHOD(TestMethod3)
        {
            doTest(2, 3, "0.(6)");
        }

        TEST_METHOD(TestMethod4)
        {
            doTest(1, 6, "0.1(6)");
        }

    private:
        void doTest(int numerator, int denominator, string expected)
        {
            Solution sln;
            auto actual = sln.fractionToDecimal(numerator, denominator);
            Assert::AreEqual(expected, actual);
        }
    };
}