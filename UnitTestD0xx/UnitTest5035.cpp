#include "pch.h"
#include "CppUnitTest.h"
#include "../D0XX/5035.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD003
{
    TEST_CLASS(UnitTest5035)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[[5,4,5],[1,2,6],[7,4,6]]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[[2,2,1,2,2,2],[1,2,2,2,1,2]]",
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            doTest("[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]",
                3);
        }

        void doTest(string src, int expected)
        {
            auto A = toInt2DArray(src);
            Solution sln;
            auto actual = sln.maximumMinimumPath(A);
            Assert::AreEqual(expected, actual);
        }
    };
}
