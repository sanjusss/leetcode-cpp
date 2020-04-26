#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0023.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0023)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1, 4, 5], [1, 3, 4], [2, 6]] ",
                "[1,1,2,3,4,4,5,6]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[]] ",
                "[]");
        }

        void check(string listsSrc, string expectedSrc)
        {
            auto lists = toListNodeArray(listsSrc);
            auto expected = toListNode(expectedSrc);
            Solution sln;
            auto actual = sln.mergeKLists(lists);
            Assert::AreEqual(*expected, *actual);
        }
    };
}