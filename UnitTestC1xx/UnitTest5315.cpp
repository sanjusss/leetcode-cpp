#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5315.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5315)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(9669, 9969);
        }

        TEST_METHOD(TestMethod2)
        {
            check(9996, 9999);
        }

        TEST_METHOD(TestMethod3)
        {
            check(9999, 9999);
        }

        void check(int num, int expected)
        {
            Solution sln;
            auto actual = sln.maximum69Number(num);
            Assert::AreEqual(expected, actual);
        }
    };
}