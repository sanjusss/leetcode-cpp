#include "pch.h"
#include "CppUnitTest.h"
#include "../901-1000/990.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9011000
{
    TEST_CLASS(UnitTest990)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"a==b\",\"b!=a\"]",
                false);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[\"b==a\",\"a==b\"]",
                true);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[\"a==b\",\"b==c\",\"a==c\"]",
                true);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[\"a==b\",\"b!=c\",\"c==a\"]",
                false);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[\"c==c\",\"b==d\",\"x!=z\"]",
                true);
        }

        TEST_METHOD(TestMethod6)
        {
            check("[\"h==j\",\"c!=g\",\"e==j\",\"f!=e\",\"g!=e\",\"j==h\",\"h!=e\",\"j!=a\"]",
                false);
        }

        TEST_METHOD(TestMethod7)
        {
            check("[\"a!=a\"]",
                false);
        }

        void check(string equationsSrc, bool expected)
        {
            auto equations = toStringArray(equationsSrc);
            Solution sln;
            auto actual = sln.equationsPossible(equations);
            Assert::AreEqual(expected, actual);
        }
    };
}
