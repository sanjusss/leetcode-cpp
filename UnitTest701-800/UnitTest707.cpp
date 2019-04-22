#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0707.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest707)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            MyLinkedList list;
            list.addAtHead(1);
            list.addAtIndex(1, 2);
            Assert::AreEqual(2, list.get(1));
            Assert::AreEqual(1, list.get(0));
            Assert::AreEqual(-1, list.get(2));
        }

        TEST_METHOD(TestMethod2)
        {
            MyLinkedList list;
            list.addAtHead(1);
            list.addAtIndex(1, 2);
            list.deleteAtIndex(2);
        }

        TEST_METHOD(TestMethod3)
        {
            MyLinkedList list;
            list.addAtHead(1);
            list.addAtIndex(5, 2);
        }

        TEST_METHOD(TestMethod4)
        {
            MyLinkedList list;
            list.addAtHead(7);
            list.addAtTail(9);
            Assert::AreEqual(-1, list.get(2));
            Assert::AreEqual(9, list.get(1));
            list.addAtTail(6);
            list.addAtIndex(3, 4);
            list.addAtIndex(3, 1);
        }

        TEST_METHOD(TestMethod5)
        {
            MyLinkedList list;
            list.addAtIndex(-1, 2);
            Assert::AreEqual(2, list.get(0));
        }
    };
}
