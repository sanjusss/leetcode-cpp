#pragma once
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include <fstream>
#include <string>
#include <vector>

#include "stringconvert.hpp"

using namespace boost::unit_test;
using namespace std;
using namespace leetcode;

#define DEFINE_TESTS_SUITE \
boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/,\
                                                   char* /*argv*/[]) {\
    auto params = loadParams(__FILE__);\
    boost::unit_test::framework::master_test_suite().add(\
        BOOST_PARAM_TEST_CASE(&test_function, params.begin(), params.end()));\
    return 0;\
}

vector<vector<string>> loadParams(const string& codeFile) {
    auto pos = codeFile.find_last_of('.');
    string casesFile = codeFile.substr(0, pos) + ".cases";
    ifstream input(casesFile);
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

    return params;
}
