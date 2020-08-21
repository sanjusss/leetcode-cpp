#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0529.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600 {
    TEST_CLASS(UnitTest529) {
public:

    TEST_METHOD(TestMethod1) {
        check("[[\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"M\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\"]]",
            "[3,0]",
            "[[\"B\",\"1\",\"E\",\"1\",\"B\"],[\"B\",\"1\",\"M\",\"1\",\"B\"],[\"B\",\"1\",\"1\",\"1\",\"B\"],[\"B\",\"B\",\"B\",\"B\",\"B\"]]");
    }

    TEST_METHOD(TestMethod2) {
        check("[[\"B\",\"1\",\"E\",\"1\",\"B\"],[\"B\",\"1\",\"M\",\"1\",\"B\"],[\"B\",\"1\",\"1\",\"1\",\"B\"],[\"B\",\"B\",\"B\",\"B\",\"B\"]]",
            "[1,2]",
            "[[\"B\",\"1\",\"E\",\"1\",\"B\"],[\"B\",\"1\",\"X\",\"1\",\"B\"],[\"B\",\"1\",\"1\",\"1\",\"B\"],[\"B\",\"B\",\"B\",\"B\",\"B\"]]");
    }

    TEST_METHOD(TestMethod3) {
        check("[[\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"M\"],[\"E\",\"E\",\"M\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"M\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\",\"E\"],[\"E\",\"E\",\"M\",\"M\",\"E\",\"E\",\"E\",\"E\"]]",
            "[0,0]",
            "[[\"B\",\"B\",\"B\",\"B\",\"B\",\"B\",\"1\",\"E\"],[\"B\",\"1\",\"1\",\"1\",\"B\",\"B\",\"1\",\"M\"],[\"1\",\"2\",\"M\",\"1\",\"B\",\"B\",\"1\",\"1\"],[\"M\",\"2\",\"1\",\"1\",\"B\",\"B\",\"B\",\"B\"],[\"1\",\"1\",\"B\",\"B\",\"B\",\"B\",\"B\",\"B\"],[\"B\",\"B\",\"B\",\"B\",\"B\",\"B\",\"B\",\"B\"],[\"B\",\"1\",\"2\",\"2\",\"1\",\"B\",\"B\",\"B\"],[\"B\",\"1\",\"M\",\"M\",\"1\",\"B\",\"B\",\"B\"]]");
    }

    void check(string boardSrc, string clickSrc, string expectedSrc) {
        auto board = toChar2DArray(boardSrc);
        auto click = toIntArray(clickSrc);
        auto expected = toChar2DArray(expectedSrc);
        Solution sln;
        auto actual = sln.updateBoard(board, click);
        Assert::AreEqual(expected, actual);
    }
    };
}
