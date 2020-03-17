#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0210.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest210)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2, "[[1,0]]", "[0,1]");
        }

        TEST_METHOD(TestMethod2)
        {
            check(4, "[[1,0],[2,0],[3,1],[3,2]]", "[0,2,1,3]");
        }

        void check(int numCourses, string prerequisitesSrc, string expectedSrc)
        {
            auto prerequisites = toInt2DArray(prerequisitesSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.findOrder(numCourses, prerequisites);
            Assert::AreEqual(expected, actual);
        }
    };
}