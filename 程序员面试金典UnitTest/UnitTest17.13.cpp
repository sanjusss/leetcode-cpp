#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../����Ա���Խ��/17.13.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ����Ա���Խ��UnitTest17 {
    TEST_CLASS(����Ա���Խ��UnitTest17_13) {
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
