#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5316.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5316)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("HOW ARE YOU", "[\"HAY\",\"ORO\",\"WEU\"]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("TO BE OR NOT TO BE", "[\"TBONTB\",\"OEROOE\",\"   T\"]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("CONTEST IS COMING", "[\"CIC\",\"OSO\",\"N M\",\"T I\",\"E N\",\"S G\",\"T\"]");
        }

        void check(string s, string expectedSrc)
        {
            auto expected = toStringArray(expectedSrc);
            Solution sln;
            auto actual = sln.printVertically(s);
            Assert::AreEqual(expected, actual);
        }
    };
}