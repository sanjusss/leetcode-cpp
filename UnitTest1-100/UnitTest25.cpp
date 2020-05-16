#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0025.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0025)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,4,5]",
                1,
                "[1,2,3,4,5]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,4,5]",
                2,
                "[2,1,4,3,5]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,2,3,4,5]",
                3,
                "[3,2,1,4,5]");
        }

        void check(string headSrc, int k, string expectedSrc)
        {
            auto head = toListNode(headSrc);
            auto expected = toListNode(expectedSrc);
            Solution sln;
            auto actual = sln.reverseKGroup(head, k);
            Assert::AreEqual(*expected, *actual);
        }
    };
}