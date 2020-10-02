#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>

#include "json.hpp"

#include "listnode.h"
#include "treenode.h"

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<class _T>
            inline std::vector<_T> toArray(std::string s)
            {
                auto j = nlohmann::json::parse(s);
                return j.get<std::vector<_T>>();
            }

            inline std::vector<std::string> split(const std::string& s, const std::string& seperator)
            {
                std::vector<std::string> output;

                std::string::size_type prev_pos = 0, pos = 0;

                while ((pos = s.find(seperator, pos)) != std::string::npos)
                {
                    std::string subString(s.substr(prev_pos, pos - prev_pos));

                    output.push_back(subString);

                    pos += seperator.length();
                    prev_pos = pos;
                }

                output.push_back(s.substr(prev_pos)); // Last word
                return output;
            }

            inline std::vector<std::string> split(const std::string& s, char seperator)
            {
                std::vector<std::string> output;

                std::string::size_type prev_pos = 0, pos = 0;

                while ((pos = s.find(seperator, pos)) != std::string::npos)
                {
                    std::string subString(s.substr(prev_pos, pos - prev_pos));
                    output.push_back(subString);

                    ++pos;
                    prev_pos = pos;
                }

                output.push_back(s.substr(prev_pos)); // Last word
                return output;
            }
            
            inline std::string replaceAllString(std::string str, const std::string& from, const std::string& to) 
            {
                size_t start_pos = 0;
                while ((start_pos = str.find(from, start_pos)) != std::string::npos) 
                {
                    str.replace(start_pos, from.length(), to);
                    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
                }

                return str;
            }

            inline std::vector<int> toIntArray(std::string s)
            {
                return toArray<int>(s);
            }

            inline std::vector<std::vector<int>> toInt2DArray(std::string s)
            {
                return toArray<std::vector<int>>(s);
            }

            inline std::vector<std::string> toStringArray(std::string s)
            {
                return toArray<std::string>(s);
            }

            inline std::vector<std::vector<std::string>> toString2DArray(std::string s)
            {
                return toArray<std::vector<std::string>>(s);
            }

            inline std::vector<char> toCharArray(std::string s)
            {
                auto strings = toArray<std::string>(s);
                std::vector<char> res;
                for (auto i : strings)
                {
                    res.push_back(i.front());
                }

                return res;
            }

            inline std::vector<std::vector<char>> toChar2DArray(std::string s)
            {
                auto strings = toArray<std::vector<std::string>>(s);
                std::vector<std::vector<char>> results;
                for (auto i : strings)
                {
                    std::vector<char> res;
                    for (auto j : i)
                    {
                        res.push_back(j.front());
                    }

                    results.push_back(res);
                }

                return results;
            }

            inline ListNode* toListNode(std::vector<int>& arr)
            {
                std::shared_ptr<ListNode> root(new ListNode(0));
                auto head = root.get();
                for (auto i : arr)
                {
                    head->next = new ListNode(i);
                    head = head->next;
                }

                return root->next;
            }

            inline ListNode* toListNode(std::string s)
            {
                auto arr = toIntArray(s);
                return toListNode(arr);
            }

            inline std::vector<ListNode*> toListNodeArray(std::string s)
            {
                std::vector<ListNode*> res;
                auto arrs = toInt2DArray(s);
                for (auto& arr : arrs)
                {
                    res.push_back(toListNode(arr));
                }

                return res;
            }

            inline TreeNode* toTreeNode(std::string data)
            {
                data = data.substr(1, data.size() - 2);
                std::vector<TreeNode*> nodes;

                std::string::size_type prev_pos = 0;
                std::string::size_type pos = 0;
                while ((pos = data.find(',', pos)) != std::string::npos)
                {
                    std::string sub = data.substr(prev_pos, pos - prev_pos);
                    ++pos;
                    prev_pos = pos;
                    if (sub == "null")
                    {
                        nodes.push_back(nullptr);
                    }
                    else
                    {
                        nodes.push_back(new TreeNode(stoi(sub)));
                    }
                }

                std::string last = data.substr(prev_pos);
                if (last.empty() == false)
                {
                    if (last == "null")
                    {
                        nodes.push_back(nullptr);
                    }
                    else
                    {
                        nodes.push_back(new TreeNode(stoi(last)));
                    }
                }

                int prevLevelTwiceIndex = 0;
                for (int i = 1; i < nodes.size(); ++i)
                {
                    while (nodes[prevLevelTwiceIndex / 2] == nullptr)
                    {
                        ++prevLevelTwiceIndex;
                    }

                    if (prevLevelTwiceIndex % 2 == 0)
                    {
                        nodes[prevLevelTwiceIndex / 2]->left = nodes[i];
                    }
                    else
                    {
                        nodes[prevLevelTwiceIndex / 2]->right = nodes[i];
                    }

                    ++prevLevelTwiceIndex;
                }

                return nodes.empty() ? nullptr : nodes.front();
            }
        }
    }
}