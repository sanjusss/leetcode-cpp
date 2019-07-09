#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0154.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest154)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[10,1,10,10,10]", 1);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[3,3,3,1]", 1);
        }

        TEST_METHOD(TestMethod3)
        {
            doTest("[2,2,2,0,1]", 0);
        }

        TEST_METHOD(TestMethod4)
        {
            doTest("[1, 3 , 5]", 1);
        }

        TEST_METHOD(TestMethod5)
        {
            doTest("[10,10,10,1,10]", 1);
        }

        void doTest(string src, int expected)
        {
            auto arr = toIntArray(src);
            Solution sln;
            auto actual = sln.findMin(arr);
            Assert::AreEqual(expected, actual);
        }
    };
}