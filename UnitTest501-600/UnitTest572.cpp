#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0572.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest572)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[3,4,5,1,2]",
                "[4,1,2]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[3,4,5,1,null,2]",
                "[3,1,2]",
                false);
        }

        void doTest(string sSrc, string tSrc, bool expected)
        {
            auto s = toTreeNode(sSrc);
            auto t = toTreeNode(tSrc);
            Solution sln;
            auto actual = sln.isSubtree(s, t);
            Assert::AreEqual(expected, actual);
        }
    };
}
