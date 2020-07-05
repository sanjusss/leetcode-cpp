#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5454.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC196 {
    TEST_CLASS(UnitTest5454) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[[1,0,1],[1,1,0],[1,1,0]]",
                13);
        }

        TEST_METHOD(TestMethod2) {
            check("[[0,1,1,0],[0,1,1,1],[1,1,1,0]]",
                24);
        }

        TEST_METHOD(TestMethod3) {
            check("[[1,1,1,1,1,1]]",
                21);
        }

        TEST_METHOD(TestMethod4) {
            check("[[1,0,1],[0,1,0],[1,0,1]]",
                5);
        }

        void check(string matSrc, int expected) {
            auto mat = toInt2DArray(matSrc);

            Solution sln;
            auto actual = sln.numSubmat(mat);
            Assert::AreEqual(expected, actual);
        }
    };
}