#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0543.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest543)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,4,5]",
                3);
        }

        void check(string rootSrc, int expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.diameterOfBinaryTree(root);
            Assert::AreEqual(expected, actual);
        }
    };
}
