#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5266.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5266)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            string gridSrc = "[[\"#\",\"#\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\"T\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\".\",\".\",\"B\",\".\",\"#\"],[\"#\",\".\",\"#\",\"#\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\"S\",\"#\"],[\"#\",\"#\",\"#\",\"#\",\"#\",\"#\"]]";
            int expected = 3;
            check(gridSrc, expected);
        }

        TEST_METHOD(TestMethod2)
        {
            string gridSrc = "[[\"#\",\".\",\".\",\"#\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\".\",\".\",\"T\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\"#\",\"B\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\"#\",\".\",\"S\",\"#\"],[\"#\",\".\",\".\",\"#\",\"#\",\"#\",\"#\",\"#\"]]";
            int expected = 7;
            check(gridSrc, expected);
        }

        TEST_METHOD(TestMethod3)
        {
            string gridSrc = "[[\"#\",\".\",\".\",\"#\",\"T\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\".\",\".\",\"#\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\"#\",\".\",\"#\",\"B\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\"#\",\".\",\"S\",\"#\"],[\"#\",\".\",\".\",\"#\",\".\",\"#\",\"#\",\"#\",\"#\"]]";
            int expected = 8;
            check(gridSrc, expected);
        }

        TEST_METHOD(TestMethod4)
        {
            string gridSrc = "[[\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\"],[\"#\",\".\",\".\",\".\",\"#\",\"#\",\".\",\"#\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\"T\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\"#\",\".\",\".\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\".\",\"#\"],[\"#\",\".\",\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\".\",\"#\"],[\"#\",\".\",\"#\",\".\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\"#\",\".\",\"#\",\"#\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\"B\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"S\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\"#\",\".\",\".\",\"#\"],[\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\",\"#\"]]";
            int expected = 29;
            check(gridSrc, expected);
        }

        void check(string gridSrc, int expected)
        {
            auto grid = toChar2DArray(gridSrc);

            Solution sln;
            auto actual = sln.minPushBox(grid);
            Assert::AreEqual(expected, actual);
        }
    };
}