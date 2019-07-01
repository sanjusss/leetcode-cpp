#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0328.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest328)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[1,2,3,4,5]", "[1,3,5,2,4]");
        }

        void doTest(string srcHead, string srcExpected)
        {
            auto head = toListNode(srcHead);
            auto headRemovers = createListNodeAutoRemovers(head);
            auto expected = toListNode(srcExpected);
            auto expectedRemovers = createListNodeAutoRemovers(expected);

            Solution sln;
            auto actual = sln.oddEvenList(head);
            Assert::AreEqual(*expected, *actual);
        }
    };
}