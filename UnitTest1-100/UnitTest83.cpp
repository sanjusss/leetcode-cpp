#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0083.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest83)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1,1,2]",
                "[1,2]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,1,2,3,3]",
                "[1,2,3]");
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
