#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../½£Ö¸Offer/20.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest½£Ö¸Offer {
    TEST_CLASS(UnitTest½£Ö¸Offer20) {
    public:
        TEST_METHOD(TestMethod1) {
            check("E16",
                false);
        }

        TEST_METHOD(TestMethod2) {
            check("3.1416",
                true);
        }

        TEST_METHOD(TestMethod3) {
            check("-1E-16",
                true);
        }

        TEST_METHOD(TestMethod4) {
            check("-E-16",
                false);
        }

        TEST_METHOD(TestMethod5) {
            check("1 ",
                true);
        }

        TEST_METHOD(TestMethod6) {
            check(".1",
                true);
        }

        void check(string s, bool expected) {
            Solution sln;
            auto actual = sln.isNumber(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
