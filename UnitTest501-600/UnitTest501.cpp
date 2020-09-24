#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0501.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600 {
    TEST_CLASS(UnitTest501) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[1,null,2,2]", "[2]");
        }

        void check(string rootSrc, string expectedSrc) {
            auto root = toTreeNode(rootSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.findMode(root);
            sort(expected.begin(), expected.end());
            sort(actual.begin(), actual.end());
            Assert::AreEqual(expected, actual);
        }
    };
}
