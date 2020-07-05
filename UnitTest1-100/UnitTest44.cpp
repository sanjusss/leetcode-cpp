#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0044.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100 {
    TEST_CLASS(UnitTest0044) {
    public:

        TEST_METHOD(TestMethod1) {
            check("aa", 
                "a", 
                false);
        }

        TEST_METHOD(TestMethod2) {
            check("aa",
                "*",
                true);
        }

        TEST_METHOD(TestMethod3) {
            check("cb",
                "?a", 
                false);
        }

        TEST_METHOD(TestMethod4) {
            check("adceb",
                "*a*b",
                "true");
        }

        TEST_METHOD(TestMethod5) {
            check("acdcb",
                "a*c?b",
                false);
        }

        TEST_METHOD(TestMethod6) {
            check("",
                "?",
                false);
        }

        void check(string s, string p, bool expected) {
            _44::Solution sln;
            auto actual = sln.isMatch(s, p);
            Assert::AreEqual(expected, actual);
        }
    };
}