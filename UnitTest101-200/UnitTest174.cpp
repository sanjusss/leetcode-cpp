#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0174.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200 {
    TEST_CLASS(UnitTest174) {
public:

    TEST_METHOD(TestMethod1) {
        doTest("[[-2,-3,3],[-5,-10,1],[10,30,-5]]",
            7);
    }

private:
    void doTest(string dungeonSrc, int expected) {
        auto dungeon = toInt2DArray(dungeonSrc);
        Solution sln;
        auto actual = sln.calculateMinimumHP(dungeon);
        Assert::AreEqual(expected, actual);
    }
    };
}