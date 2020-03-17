#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0207.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest207)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2, "[[1,0]]", true);
        }

        TEST_METHOD(TestMethod2)
        {
            check(2, "[[1,0],[0,1]]", false);
        }

        TEST_METHOD(TestMethod3)
        {
            check(4, "[[0,1],[3,1],[1,3],[3,2]]", false);
        }

        TEST_METHOD(TestMethod4)
        {
            check(2, "[[0,1]]", true);
        }

        void check(int numCourses, string prerequisitesSrc, bool expected)
        {
            auto prerequisites = toInt2DArray(prerequisitesSrc);
            Solution sln;
            auto actual = sln.canFinish(numCourses, prerequisites);
            Assert::AreEqual(expected, actual);
        }
    };
}