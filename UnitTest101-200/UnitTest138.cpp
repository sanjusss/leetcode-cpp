#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0138.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest138)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Node* node1 = new Node();
            Node* node2 = new Node();
            node1->val = 1;
            node1->next = node2;
            node1->random = node2;
            node2->val = 2;
            node2->random = node2;
            node2->next = nullptr;
            
            Solution sln;
            sln.copyRandomList(node1);
        }

        TEST_METHOD(TestMethod2)
        {
            Solution sln;
            sln.copyRandomList(nullptr);
        }
    };
}