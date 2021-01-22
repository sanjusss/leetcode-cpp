#pragma once
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <tuple>
#include <functional>

#include "../stringconvert.hpp"
#include "../testexception.hpp"
#include "fromstring.hpp"
#include "tostring.hpp"

template <class T, int N>
class CaseRunner;

template <class Res, class... Args, int Output>
class CaseRunner<Res(Args...), Output> {
public:
    CaseRunner(std::function<Res(Args...)> fun, const std::string& codeFile) {
        auto params = loadParams(codeFile);
        for (int i = 0; i < params.size(); ++i) {
            runCase(fun, i + 1, params[i]);
        }

        std::cout << "finished" << std::endl;
    }

private:
    std::vector<std::vector<std::string>> loadParams(const std::string& codeFile) {
        using namespace std;
        using namespace leetcode;

        std::filesystem::path codePath = codeFile;
        string fileName = codePath.filename().string();
        auto pos = fileName.find_first_of("_-.");
        string casesFile = codePath.parent_path().append(fileName.substr(0, pos) + ".cases").string();

        ifstream input(casesFile);
        string line;
        getline(input, line);
        vector<string> words = split(line, ",");

        int caseLineSize = stoi(words[0]);
        int actualSize = sizeof...(Args);
        if (typeid(Res) != typeid(void)) {
            ++actualSize;
        }

        if (caseLineSize != actualSize) {
            throw TestException("Line count sign for each line has ans error.");
        }

        bool needTrim = words.size() < 2 || words[1] != "notrim";

        vector<vector<string>> params;
        while (input) {
            vector<string> param;
            for (int i = 0; i < caseLineSize && getline(input, line); ++i) {
                if (needTrim) {
                    trim(line, '\"');
                }

                param.push_back(move(line));
            }

            if (param.size() == caseLineSize) {
                params.push_back(move(param));
            }
        }

        return move(params);
    }

    bool runCase(std::function<Res(Args...)> fun, int index, const std::vector<std::string>& params) {
        using namespace std;
        try {
            int i = 0;
            function<Res()> call = bind(fun, param<Args>(i++, params) ...);
            auto begin = chrono::system_clock::now();
            auto actual = call();
            auto end = chrono::system_clock::now();
            cout << "Test " << index << " passed.(" << chrono::duration_cast<chrono::milliseconds>(end - begin).count()
                 << " ms)" << endl;
            return true;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return false;
        }
    }

    template <class T>
    T param(int i, const std::vector<std::string>& params) {
        if (i == 0) {
            return FromString<T>::convert(string());
        }
        else {
            return FromString<T>::convert(params[i - 1]);
        }
    }
};
