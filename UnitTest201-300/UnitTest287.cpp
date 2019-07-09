#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0287.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest287)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[8,1,1,1,2,7,4,3,1,1]",
                1);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[1,4,4,2,4]",
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            doTest("[3,1,3,4,2]",
                3);
        }

    private:
        void doTest(string src, int expected)
        {
            auto nums = toIntArray(src);
            Solution sln;
            auto actual = sln.findDuplicate(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
