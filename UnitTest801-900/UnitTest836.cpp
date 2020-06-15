#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0836.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest836)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[0,0,2,2]",
                "[1,1,3,3]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[0,0,1,1]",
                "[1,0,2,1]",
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[-836959955,-724514313,368220652,-449465289]",
                "[-703416829,-64916327,713807924,838108468]",
                false);
        }

    private:
        void check(string rec1Src, string rec2Src, bool expected)
        {
            auto rec1 = toIntArray(rec1Src);
            auto rec2 = toIntArray(rec2Src);
            Solution sln;
            auto actual = sln.isRectangleOverlap(rec1, rec2);
            Assert::AreEqual(expected, actual);
        }
    };
}
