#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/5.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest5)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(" [47, 74, 31]",
                121);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[15, 21, null, 24, null, 27, 26]",
                87);
        }

        TEST_METHOD(TestMethod3)
        {
            check(" [1,3,2,null,null,4,4]",
                7.5);
        }

        void check(string rootSrc, double expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.minimalExecTime(root);
            Assert::AreEqual(expected, actual);
        }
    };
}