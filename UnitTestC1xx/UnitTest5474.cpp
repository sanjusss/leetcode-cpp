#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5474.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC199 {
    TEST_CLASS(UnitTest5474) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[1,2,3,null,4]",
                3,
                1);
        }

        TEST_METHOD(TestMethod2) {
            check("[1,2,3,4,5,6,7]",
                3,
                2);
        }

        TEST_METHOD(TestMethod3) {
            check("[7,1,4,6,null,5,3,null,null,null,null,null,2]",
                3,
                1);
        }

        TEST_METHOD(TestMethod4) {
            check("[100]",
                1,
                0);
        }

        TEST_METHOD(TestMethod5) {
            check("[1,1,1]",
                2,
                1);
        }

        void check(string rootSrc, int distance, int expected) {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.countPairs(root, distance);
            Assert::AreEqual(expected, actual);
        }
    };
}