#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0056.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest56)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,3],[2,6],[8,10],[15,18]]",
                "[[1,6],[8,10],[15,18]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,4],[4,5]]",
                "[[1,5]]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,4],[1,5]]",
                "[[1,5]]");
        }

    private:
        void check(string intervalsSrc, string expectedSrc)
        {
            auto intervals = toInt2DArray(intervalsSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution s;
            auto actual = s.merge(intervals);
            Assert::AreEqual(expected, actual);
        }
    };
}
