#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5305.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5305)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[\"A\",\"B\"],[\"C\"],[\"B\",\"C\"],[\"D\"]]",
                "[[1,2],[0,3],[0,3],[1,2]]",
                0,
                1,
                "[\"B\",\"C\"]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[\"A\",\"B\"],[\"C\"],[\"B\",\"C\"],[\"D\"]]",
                "[[1,2],[0,3],[0,3],[1,2]]",
                0,
                2,
                "[\"D\"]");
        }

        void check(string watchedVideosSrc, string friendsSrc, int id, int level, string expectedSrc)
        {
            auto watchedVideos = toString2DArray(watchedVideosSrc);
            auto friends = toInt2DArray(friendsSrc);
            auto expected = toStringArray(expectedSrc);

            Solution sln;
            auto actual = sln.watchedVideosByFriends(watchedVideos, friends, id, level);
            Assert::AreEqual(expected, actual);
        }
    };
}