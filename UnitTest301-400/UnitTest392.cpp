#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0392.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400 {
    TEST_CLASS(UnitTest392) {
public:

    TEST_METHOD(TestMethod1) {
        check("abc",
            "ahbgdc",
            true);
    }

    TEST_METHOD(TestMethod2) {
        check("axc",
            "ahbgdc", 
            false);
    }

    void check(string s, string t, bool expected) {
        Solution sln;
        auto actual = sln.isSubsequence(s, t);
        Assert::AreEqual(expected, actual);
    }
    };
}