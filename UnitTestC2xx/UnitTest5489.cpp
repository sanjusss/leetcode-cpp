#include "pch.h"
#include "CppUnitTest.h"
#include "../C2XX/5489.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC202 {
    TEST_CLASS(UnitTest5489) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[1,2,3,4,7]",
                3,
                3);
        }

        TEST_METHOD(TestMethod2) {
            check("[5,4,3,2,1,1000000000]",
                2,
                999999999);
        }

        TEST_METHOD(TestMethod3) {
            check("[1,2,3,4,5,6,7,8,9,10]",
                4,
                3);
        }

        void check(string positionSrc, int m, int expected) {
            auto position = toIntArray(positionSrc);
            Solution sln;
            auto actual = sln.maxDistance(position, m);
            Assert::AreEqual(expected, actual);
        }
    };
}