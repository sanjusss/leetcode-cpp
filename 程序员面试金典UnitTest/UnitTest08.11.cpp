#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../����Ա���Խ��/08.11.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ����Ա���Խ��UnitTest08
{
    TEST_CLASS(����Ա���Խ��UnitTest08_11)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check(5,
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(10,
                4);
        }

        void check(int n, int expected)
        {
            Solution sln;
            auto actual = sln.waysToChange(n);
            Assert::AreEqual(expected, actual);
        }
    };
}
