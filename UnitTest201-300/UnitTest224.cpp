#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0224.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest224)
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
            check("(1+(4+5+2)-3)+(6+8)",
                23);
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
