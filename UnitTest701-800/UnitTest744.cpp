#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0744.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest744)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'a',
                'c');
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'c',
                'f');
        }

        TEST_METHOD(TestMethod3)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'd',
                'f');
        }

        TEST_METHOD(TestMethod4)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'g',
                'j');
        }

        TEST_METHOD(TestMethod5)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'j',
                'c');
        }

        TEST_METHOD(TestMethod6)
        {
            doTest("[\"c\", \"f\", \"j\"]",
                'k',
                'c');
        }

    private:
        void doTest(string lettersSrc, char target, char expected)
        {
            vector<char> letters = toCharArray(lettersSrc);
            Solution sln;
            auto actual = sln.nextGreatestLetter(letters, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
