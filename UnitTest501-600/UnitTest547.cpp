#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0547.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest547)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,1,0],[1,1,0],[0,0,1]]",
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,1,0],[1,1,1],[0,1,1]]",
                1);
        }

        void check(string MSrc, int expected)
        {
            auto M = toInt2DArray(MSrc);
            Solution sln;
            auto actual = sln.findCircleNum(M);
            Assert::AreEqual(expected, actual);
        }
    };
}
