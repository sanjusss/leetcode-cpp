#pragma once

#include <stdexcept>
#include <memory>

#include "listnode.h"

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            inline void freeListNode(const ListNode* head)
            {
                while (head != nullptr)
                {
                    auto temp = head;
                    head = head->next;
                    delete temp;
                }
            }

            inline std::vector<std::shared_ptr<ListNode>> createListNodeAutoRemovers(ListNode* head)
            {
                std::vector<std::shared_ptr<ListNode>> removers;
                while (head != nullptr)
                {
                    removers.push_back(std::shared_ptr<ListNode>(head));
                    head = head->next;
                }

                return removers;
            }

            inline std::wstring ToString(const ListNode* t)
            {
                return L"\nuse \"ListNode\" or \"shared_ptr<ListNode>\" instead of \"ListNode*\" in Assert::areEqual or Assert::notEqual !\n";
            }

            inline std::wstring ToString(ListNode* t)
            {
                return L"\nuse \"ListNode\" or \"shared_ptr<ListNode>\" instead of \"ListNode*\" in Assert::areEqual or Assert::notEqual !\n";
            }

            inline std::wstring ToString(const ListNode& node)
            {
                std::wstring res;
                res += L"[";

                const ListNode* head = &node;
                while (head != nullptr)
                {
                    res += ToString(head->val);
                    if (head->next != nullptr)
                    {
                        res += L",";
                    }

                    head = head->next;
                }

                res += L"]";
                return res;
            }

            inline bool operator == (const ListNode& a, const ListNode& b)
            {
                return ToString(a) == ToString(b);
            }

            inline bool operator != (const ListNode& a, const ListNode& b)
            {
                return ToString(a) != ToString(b);
            }

            inline std::wstring ToString(const std::shared_ptr<ListNode>& node)
            {
                return ToString(*node);
            }

            inline bool operator == (const std::shared_ptr<ListNode>& a, const std::shared_ptr<ListNode>& b)
            {
                return ToString(a) == ToString(b);
            }

            inline bool operator != (const std::shared_ptr<ListNode>& a, const std::shared_ptr<ListNode>& b)
            {
                return ToString(a) != ToString(b);
            }
        }
    }
}