#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../10xx/1028.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10xx
{
    TEST_CLASS(UnitTest1028)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("1-2--3--4-5--6--7",
                "[1,2,5,3,4,6,7]");
        }

        void check(string S, string expectedSrc)
        {
            auto expected = toTreeNode(expectedSrc);
            Solution sln;
            auto actual = sln.recoverFromPreorder(S);
            Assert::AreEqual(*expected, *actual);
        }
    };
}
