/*
 * @Author: sanjusss
 * @Date: 2021-01-23 09:36:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-23 10:53:04
 * @FilePath: \include\unittest2\caserunner.hpp
 */
#pragma once
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <vector>
#include <any>

#include "../stringconvert.hpp"
#include "../testexception.hpp"
#include "fromstring.hpp"
#include "tostring.hpp"

template <class T, int N>
class CaseRunner;

template <class Res, class ClassName, class... Args, int OutputIndex>
class CaseRunner<Res (ClassName::*)(Args...), OutputIndex> {
private:
    template <class ReturnType, class Invoker, class Input>
    struct Runner {
        static ReturnType invoke(Invoker fun, Input& input) {
            return std::apply(fun, input);
        }
    };

    template <class Invoker, class Input>
    struct Runner<void, Invoker, Input> {
        static decltype(auto) invoke(Invoker fun, Input& input) {
            std::apply(fun, input);
            return std::get<OutputIndex>(input);
        }
    };

public:
    template <class Invoker, class Checker>
    CaseRunner(Invoker fun, Checker check, const std::string& codeFile) {
        decltype(loadParams(codeFile)) params;
        try {
            params = loadParams(codeFile);
        } catch (const std::exception&) {
            std::cout << "Fail to load test cases file." << std::endl;
            return;
        }

        int success = 0;
        int fail = 0;
        for (int i = 0; i < params.size(); ++i) {
            if (runCase(fun, check, i + 1, params[i])) {
                ++success;
            }
            else {
                ++fail;
            }
        }

        std::cout << params.size() << " finished, " << success << " success, " << fail << " fail." << std::endl;
    }

private:
    std::string testCasesFile(const std::string& codeFile) {
        auto dirPos = codeFile.find_last_of("\\/");
        auto fileName = codeFile.substr(dirPos + 1);
        auto numPos = fileName.find_first_of("_-.");
        auto caseFile = codeFile.substr(0, dirPos + 1) + fileName.substr(0, numPos) + ".cases";
        return caseFile;
    }

    std::vector<std::vector<std::string>> loadParams(const std::string& codeFile) {
        using namespace std;
        using namespace leetcode;

        ifstream input(testCasesFile(codeFile));
        string line;
        getline(input, line);
        vector<string> words = split(line, ",");

        int caseLineSize = stoi(words[0]);
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

    template <class T, std::size_t N>
    void fillInput(T& t, std::vector<unittest::FreeHandler>& handlers,const std::vector<std::string>& params) {
        auto p = FromString<std::tuple_element_t<N + 1, T>>::convert(params[N]);
        std::get<N + 1>(t) = std::get<0>(p);
        handlers.emplace_back(std::get<1>(p));
    }

    template <class T, std::size_t... I>
    void fillAllInputs(T& t, std::vector<unittest::FreeHandler>& handlers, const std::vector<std::string>& params, std::index_sequence<I...>) {
        (fillInput<T, I>(t, handlers, params), ...);
    }

    template <class Invoker, class Checker>
    bool runCase(Invoker fun, Checker check, int index, const std::vector<std::string>& params) {
        using namespace std;
        try {
            int i = 0;
            std::vector<unittest::FreeHandler> freeHandlers;
            tuple<ClassName*, remove_cv_t<remove_reference_t<Args>>...> input;
            ClassName instance;
            get<0>(input) = &instance;
            fillAllInputs(input, freeHandlers, params, index_sequence_for<remove_cv_t<remove_reference_t<Args>>...>());
            auto begin = chrono::system_clock::now();
            auto actual = Runner<Res, Invoker, decltype(input)>::invoke(fun, input);
            auto end = chrono::system_clock::now();
            auto ms = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

            std::any anyInput = std::ref(input);
            auto [success, errorMessage, finalFree] = check(actual, params.back(), anyInput);
            try {
                for (auto& handler : freeHandlers) {
                    handler();
                }

                finalFree();
            }
            catch (...) {
                cout << "Error occurs when free params' memory." << endl;
            }
            
            if (success) {
                cout << "Test " << index << " passed.(" << ms << " ms)" << endl;
                return true;
            }
            else {
                cout << "Test " << index << " failed.(" << ms << " ms) " << errorMessage << endl;
                return false;
            }
        } catch (const std::exception& e) {
            cout << "Test " << index << " has an exception :" << e.what() << endl;
            return false;
        }
    }
};
