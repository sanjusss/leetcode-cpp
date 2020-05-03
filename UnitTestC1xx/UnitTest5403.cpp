#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5403.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC187
{
    TEST_CLASS(UnitTest5403)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,3,11],[2,4,6]]",
                5,
                7);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,10,10],[1,4,5],[2,3,6]]",
                7,
                9);
        }

        void check(string matSrc, int k, int expected)
        {
            auto mat = toInt2DArray(matSrc);
            Solution sln;
            auto actual = sln.kthSmallest(mat, k);
            Assert::AreEqual(expected, actual);
        }
    };
}