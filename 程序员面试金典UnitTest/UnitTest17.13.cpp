#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../程序员面试金典/17.13.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 程序员面试金典UnitTest17 {
    TEST_CLASS(程序员面试金典UnitTest17_13) {
public:
    TEST_METHOD(TestMethod1) {
        check("[\"looked\",\"just\",\"like\",\"her\",\"brother\"]",
            "jesslookedjustliketimherbrother",
            7);
    }

    void check(string dictionarySrc, string sentence, int expected) {
        auto dictionary = toStringArray(dictionarySrc);
        Solution sln;
        auto actual = sln.respace(dictionary, sentence);
        Assert::AreEqual(expected, actual);
    }
    };
}
