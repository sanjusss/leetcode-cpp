#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0752.hpp"
#include "stringconvert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest752)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            auto deadends = toStringArray("[\"0201\",\"0101\",\"0102\",\"1212\",\"2002\"]");
            string target = "0202";
            int expected = 6;

            Solution s;
            int actual = s.openLock(deadends, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
