#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0542.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
	TEST_CLASS(UnitTest542)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            vector<vector<int>> matrix = toInt2DArray("[[0,0,1,0,1,1,1,0,1,1],[1,1,1,1,0,1,1,1,1,1],[1,1,1,1,1,0,0,0,1,1],[1,0,1,0,1,1,1,0,1,1],[0,0,1,1,1,0,1,1,1,1],[1,0,1,1,1,1,1,1,1,1],[1,1,1,1,0,1,0,1,0,1],[0,1,0,0,0,1,0,0,1,1],[1,1,1,0,1,1,0,1,0,1],[1,0,1,1,1,0,1,1,1,0]]");
            vector<vector<int>> expected = toInt2DArray("[[0,0,1,0,1,2,1,0,1,2],[1,1,2,1,0,1,1,1,2,3],[2,1,2,1,1,0,0,0,1,2],[1,0,1,0,1,1,1,0,1,2],[0,0,1,1,1,0,1,1,2,3],[1,0,1,2,1,1,1,2,1,2],[1,1,1,1,0,1,0,1,0,1],[0,1,0,0,0,1,0,0,1,2],[1,1,1,0,1,1,0,1,0,1],[1,0,1,1,1,0,1,2,1,0]]");
            Solution s;
            auto actual = s.updateMatrix(matrix);
            Assert::AreEqual(expected, actual);
		}


        TEST_METHOD(TestMethod2)
        {
            vector<vector<int>> matrix = toInt2DArray("[[0,1,0],[0,1,0],[0,1,0],[0,1,0],[0,1,0]]");
            vector<vector<int>> expected = toInt2DArray("[[0,1,0],[0,1,0],[0,1,0],[0,1,0],[0,1,0]]");
            Solution s;
            auto actual = s.updateMatrix(matrix);
            Assert::AreEqual(expected, actual);
        }
	};
}
