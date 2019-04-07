#include "pch.h"
#include "CppUnitTest.h"
#include "../C131/5019.hpp"
#include "stringconvert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC131
{
	TEST_CLASS(UnitTest5019)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            vector<vector<int>> clips = StringConvertor::toInt2DArray("[[0,0],[9,9],[2,10],[0,3],[0,5],[3,4],[6,10],[1,2],[4,7],[5,6]]");
            int T = 5;
            int expected = 1;

            Solution s;
            int actual = s.videoStitching(clips, T);
            Assert::AreEqual(expected, actual);
		}

        TEST_METHOD(TestMethod2)
        {
            vector<vector<int>> clips = StringConvertor::toInt2DArray("[[0,5],[1,6],[2,7],[3,8],[4,9],[5,10],[6,11],[7,12],[8,13],[9,14],[10,15],[11,16],[12,17],[13,18],[14,19],[15,20],[16,21],[17,22],[18,23],[19,24],[20,25],[21,26],[22,27],[23,28],[24,29],[25,30],[26,31],[27,32],[28,33],[29,34],[30,35],[31,36],[32,37],[33,38],[34,39],[35,40],[36,41],[37,42],[38,43],[39,44],[40,45],[41,46],[42,47],[43,48],[44,49],[45,50],[46,51],[47,52],[48,53],[49,54]]");
            int T = 50;
            int expected = 10;

            Solution s;
            int actual = s.videoStitching(clips, T);
            Assert::AreEqual(expected, actual);
        }
	};
}
