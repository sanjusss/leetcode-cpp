#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0119.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest119)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest(3, "[1,3,3,1]");
        }

        void doTest(int rowIndex, string srcExpected)
        {
            auto expected = toIntArray(srcExpected);
            Solution sln;
            auto actual = sln.getRow(rowIndex);
            Assert::AreEqual(expected, actual);
        }
    };
}
