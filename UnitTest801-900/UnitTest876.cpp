#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0876.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest876)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,4,5]",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,4,5,6]",
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,2]",
                2);
        }

    private:
        void check(string headSrc, int expected)
        {
            auto head = toListNode(headSrc);
            Solution sln;
            auto actual = sln.middleNode(head);
            Assert::AreEqual(expected, actual->val);
        }
    };
}
