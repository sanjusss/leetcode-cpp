#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0049.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest49)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]",
                "[[\"bat\"],[\"nat\",\"tan\"],[\"ate\",\"eat\",\"tea\"]]");
        }

        void doTest(string strsSrc, string expectedSrc)
        {
            auto strs = toStringArray(strsSrc);
            auto expected = toString2DArray(expectedSrc);

            Solution sln;
            auto actual = sln.groupAnagrams(strs);

        }
    };
}
