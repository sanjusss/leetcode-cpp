#include "pch.h"
#include "CppUnitTest.h"
#include "../C2XX/5490.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC202 {
    TEST_CLASS(UnitTest5490) {
public:

    TEST_METHOD(TestMethod1) {
        check(10, 4);
    }

    TEST_METHOD(TestMethod2) {
        check(6, 3);
    }

    TEST_METHOD(TestMethod3) {
        check(1, 1);
    }

    TEST_METHOD(TestMethod4) {
        check(56, 6);
    }

    void check(int n, int expected) {
        Solution sln;
        auto actual = sln.minDays(n);
        Assert::AreEqual(expected, actual);
    }
    };
}