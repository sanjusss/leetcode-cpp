#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0079.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest79)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[[\"A\",\"B\",\"C\",\"E\"],[\"S\",\"F\",\"C\",\"S\"],[\"A\",\"D\",\"E\",\"E\"]]",
                "ABCCED",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[\"A\",\"B\",\"C\",\"E\"],[\"S\",\"F\",\"C\",\"S\"],[\"A\",\"D\",\"E\",\"E\"]]",
                "SEE",
                true);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[\"A\",\"B\",\"C\",\"E\"],[\"S\",\"F\",\"C\",\"S\"],[\"A\",\"D\",\"E\",\"E\"]]",
                "ABCB",
                false);
        }

    private:
        void check(string boardSrc, string word, bool expected)
        {
            auto board = toChar2DArray(boardSrc);
            Solution sln;
            auto actual = sln.exist(board, word);
            Assert::AreEqual(expected, actual);
        }
    };
}
