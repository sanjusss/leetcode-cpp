#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/3.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[2,8,4],[2,5,0],[10,9,8]]",
                "[[2,11,3],[15,10,7],[9,17,12],[8,1,14]]",
                "[2,-1,3,-1]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[0,4,5],[4,8,8],[8,6,1],[10,10,0]]",
                "[[12,11,16],[20,2,6],[9,2,6],[10,18,3],[8,14,9]]",
                "[-1,4,3,3,3]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,1,1]]",
                "[[0,0,0]]",
                "[0]");
        }

        void check(string increaseSrc, string requirementsSrc, string expectedSrc)
        {
            auto increase = toInt2DArray(increaseSrc);
            auto requirements = toInt2DArray(requirementsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.getTriggerTime(increase, requirements);
            Assert::AreEqual(expected, actual);
        }
    };
}