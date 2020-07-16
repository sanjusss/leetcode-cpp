#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0785.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800 {
    TEST_CLASS(UnitTest785) {
    public:

        TEST_METHOD(TestMethod1) {
            doTest("[[1,3], [0,2], [1,3], [0,2]]",
                true);
        }

        TEST_METHOD(TestMethod2) {
            doTest("[[1,2,3], [0,2], [0,1,3], [0,2]]",
                false);
        }

        TEST_METHOD(TestMethod3) {
            doTest("[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]",
                false);
        }

        TEST_METHOD(TestMethod4) {
            doTest("[[]]",
                true);
        }

        TEST_METHOD(TestMethod5) {
            doTest("[[2,4],[2,3,4],[0,1],[1],[0,1],[7],[9],[5],[],[6],[12,14],[],[10],[],[10],[19],[18],[],[16],[15],[23],[23],[],[20,21],[],[],[27],[26],[],[],[34],[33,34],[],[31],[30,31],[38,39],[37,38,39],[36],[35,36],[35,36],[43],[],[],[40],[],[49],[47,48,49],[46,48,49],[46,47,49],[45,46,47,48]]",
                false);
        }

    private:
        void doTest(string graphSrc, bool expected) {
            auto graph = toInt2DArray(graphSrc);
            Solution sln;
            auto actual = sln.isBipartite(graph);
            Assert::IsTrue(fabs(expected - actual) < 1.0e-6);
        }
    };
}
