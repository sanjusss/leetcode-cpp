#pragma once

#include <vector>

#include "listnode.h"

namespace Microsoft 
{
    namespace VisualStudio 
    {
        namespace CppUnitTestFramework
        {
            template<typename T> 
            inline std::wstring ToString(const std::vector<T>& t) 
            { 
                std::wstring res;
                res += L"[";

                int max = t.size() - 1;
                for (int i = 0; i <= max; ++i)
                {
                    res += ToString(t[i]);
                    if (i != max)
                    {
                        res += L",";
                    }
                }

                res += L"]";
                return res;
            }

            inline std::wstring ToString(ListNode* t)
            {
                std::wstring res;
                res += L"[";

                ListNode* head = t;
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
        }
    }
}