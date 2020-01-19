#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5317.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5317)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,null,2,null,2]", 2, "[1]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,1,1]", 1, "[]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,2,3]", 2, "[1,null,3]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1,2,3,2,null,2,4]", 2, "[1,null,3,null,4]");
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,3,3,3,2]", 3, "[1,3,null,null,2]");
        }

        void check(string rootSrc, int target, string expectedSrc)
        {
            auto root = toTreeNode(rootSrc);
            auto expected = toTreeNode(expectedSrc);
            Solution sln;
            auto actual = sln.removeLeafNodes(root, target);
            Assert::AreEqual(*expected, *actual);
        }
    };
}