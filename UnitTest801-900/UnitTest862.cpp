#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0862.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest862)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1]",
                1,
                1);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2]",
                4,
                -1);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[2,-1,2]",
                3,
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[77,19,35,10,-14]",
                19,
                1);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[17,85,93,-45,-21]",
                150,
                2);
        }

        TEST_METHOD(TestMethod6)
        {
            check("[-28,81,-20,28,-29]",
                89,
                3);
        }

    private:
        void check(string ASrc, int K, int expected)
        {
            auto A = toIntArray(ASrc);
            Solution sln;
            auto actual = sln.shortestSubarray(A, K);
            Assert::AreEqual(expected, actual);
        }
    };
}
