#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0097.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100 {
    TEST_CLASS(UnitTest97) {
public:
    TEST_METHOD(TestMethod1) {
        check("aabcc",
            "dbbca",
            "aadbbcbcac",
            true);
    }

    TEST_METHOD(TestMethod2) {
        check("aabcc",
            "dbbca",
            "aadbbbaccc",
            false);
    }

    TEST_METHOD(TestMethod3) {
        check("aabcc",
            "dbbca",
            "aadbbcbcac",
            true);
    }

    TEST_METHOD(TestMethod4) {
        check("aabcc",
            "dbbca",
            "aadbbcbacc",
            true);
    }

    TEST_METHOD(TestMethod5) {
        check("db",
            "b",
            "cbb",
            false);
    }

private:
    void check(string s1, string s2, string s3, bool expected) {
        Solution sln;
        auto actual = sln.isInterleave(s1, s2, s3);
        Assert::AreEqual(expected, actual);
    }
    };
}
