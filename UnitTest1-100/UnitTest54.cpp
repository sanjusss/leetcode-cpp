#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0054.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest54)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> matrix = toInt2DArray("[[1,2,3],[5,6,7],[9,10,11],[4,8,12]]");
            auto expected = toIntArray("[1,2,3,7,11,12,8,4,9,5,6,10]");
            
            Solution s;
            auto actual = s.spiralOrder(matrix);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<vector<int>> matrix = toInt2DArray("[[1,2,3,4],[5,6,7,8],[9,10,11,12]]");
            auto expected = toIntArray("[1,2,3,4,8,12,11,10,9,5,6,7]");

            Solution s;
            auto actual = s.spiralOrder(matrix);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod3)
        {
            vector<vector<int>> matrix = toInt2DArray("[[7],[9],[6]]");
            auto expected = toIntArray("[7,9,6]");

            Solution s;
            auto actual = s.spiralOrder(matrix);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod4)
        {
            vector<vector<int>> matrix = toInt2DArray("[[2,5,8],[4,0,-1]]");
            auto expected = toIntArray("[2,5,8,-1,0,4]");

            Solution s;
            auto actual = s.spiralOrder(matrix);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod5)
        {
            vector<vector<int>> matrix = toInt2DArray("[[1,11],[2,12],[3,13],[4,14],[5,15],[6,16],[7,17],[8,18],[9,19],[10,20]]");
            auto expected = toIntArray("[1,11,12,13,14,15,16,17,18,19,20,10,9,8,7,6,5,4,3,2]");

            Solution s;
            auto actual = s.spiralOrder(matrix);
            Assert::AreEqual(expected, actual);
        }
    };
}
