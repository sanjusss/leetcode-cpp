#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            std::vector<std::string> split(const std::string& s, const std::string& seperator)
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

                output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

                return output;
            }

            std::vector<int> toIntArray(std::string s)
            {
                if (s[0] == '[')
                {
                    s.erase(0, 1);
                }

                if (s[s.length() - 1] == ']')
                {
                    s.erase(s.length() - 1, 1);
                }

                std::vector<std::string> strs = split(s, ",");
                std::vector<int> res;
                for (auto i : strs)
                {
                    res.push_back(stoi(i));
                }

                return res;
            }

            std::vector<std::vector<int>> toInt2DArray(std::string s)
            {
                if (s.substr(0, 2) == "[[")
                {
                    s.erase(0, 2);
                }

                if (s.substr(s.length() - 2, 2) == "]]")
                {
                    s.erase(s.length() - 2, 2);
                }

                std::vector<std::string> strs = split(s, "],[");
                std::vector<std::vector<int>> res;
                for (auto i : strs)
                {
                    res.push_back(toIntArray(i));
                }

                return res;
            }

            std::vector<std::string> toStringArray(std::string s)
            {
                s.erase(std::remove(s.begin(), s.end(), '['), s.end());
                s.erase(std::remove(s.begin(), s.end(), ']'), s.end());
                s.erase(std::remove(s.begin(), s.end(), '"'), s.end());
                return split(s, ",");
            }

            std::vector<std::vector<std::string>> toString2DArray(std::string s)
            {
                if (s.substr(0, 2) == "[[")
                {
                    s.erase(0, 2);
                }

                if (s.substr(s.length() - 2, 2) == "]]")
                {
                    s.erase(s.length() - 2, 2);
                }

                std::vector<std::string> strs = split(s, "],[");
                std::vector<std::vector<std::string>> res;
                for (auto i : strs)
                {
                    res.push_back(toStringArray(i));
                }

                return res;
            }

            std::vector<char> toCharArray(std::string s)
            {
                auto strs = toStringArray(s);
                std::vector<char> res;
                for (auto i : strs)
                {
                    res.push_back(i[0]);
                }

                return res;
            }

            std::vector<std::vector<char>> toChar2DArray(std::string s)
            {
                if (s.substr(0, 2) == "[[")
                {
                    s.erase(0, 2);
                }

                if (s.substr(s.length() - 2, 2) == "]]")
                {
                    s.erase(s.length() - 2, 2);
                }

                std::vector<std::string> strs = split(s, "],[");
                std::vector<std::vector<char>> res;
                for (auto i : strs)
                {
                    res.push_back(toCharArray(i));
                }

                return res;
            }
        }
    }
}