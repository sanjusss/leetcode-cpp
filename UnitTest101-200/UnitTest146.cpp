#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0146.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest146)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            LRUCache lru(2);
            lru.put(1, 1);
            lru.put(2, 2);
            Assert::AreEqual(1, lru.get(1));
            lru.put(3, 3);
            Assert::AreEqual(-1, lru.get(2));
            lru.put(4, 4);
            Assert::AreEqual(-1, lru.get(1));
            Assert::AreEqual(3, lru.get(3));
            Assert::AreEqual(4, lru.get(4));
        }
    };
}
