#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0200.hpp"
#include "stringconvert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest200)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            auto grid = StringConvertor::toChar2DArray("[[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"0\",\"0\",\"1\",\"0\",\"0\"],[\"0\",\"0\",\"0\",\"1\",\"1\"]]");
            int expected = 3;

            Solution s;
            int actual = s.numIslands(grid);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            auto grid = StringConvertor::toChar2DArray("[[\"1\"],[\"1\"]]");
            int expected = 1;

            Solution s;
            int actual = s.numIslands(grid);

            Assert::AreEqual(expected, actual);
        }
    };
}
