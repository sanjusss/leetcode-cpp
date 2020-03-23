#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0082.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest82)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1,1,2]",
                "[2]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,1,2,3,3]",
                "[2]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,2,3,3,4,4,5]",
                "[1,2,5]");
        }

    private:
        void check(string headSrc, string expectedSrc)
        {
            auto head = toListNode(headSrc);
            auto expected = toListNode(expectedSrc);
            Solution sln;
            auto actual = sln.deleteDuplicates(head);
            Assert::AreEqual(*expected, *actual);
        }
    };
}
