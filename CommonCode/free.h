#pragma once

#include "listnode.h"

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            inline void freeListNode(ListNode* head)
            {
                while (head != nullptr)
                {
                    auto temp = head;
                    head = head->next;
                    delete temp;
                }
            }
        }
    }
}