#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include <nlohmann/json.hpp>

namespace leetcode {
template <class T>
class FunctionTest {
    using Method =
        std::function<void(T*&, const std::string&, const std::string&)>;

public:
    FunctionTest(const std::string& inputs, const std::string& expecteds,
                 const std::string& calls,
                 const std::unordered_map<std::string, Method>& methods =
                     std::unordered_map<std::string, Method>())
        : m_methods(methods) {
        initInputs(inputs);
        initExpecteds(expecteds);
        initCalls(calls);
    }

    ~FunctionTest() { delete m_obj; }

    void addMethod(const std::string& name, Method method) {
        m_methods[name] = method;
    }

    void check() {
        for (int i = 0; i < m_calls.size(); ++i) {
            m_methods[m_calls[i]](m_obj, m_inputs[i], m_expecteds[i]);
        }
    }

private:
    void initCalls(const std::string& calls) {
        auto j = nlohmann::json::parse(calls);
        m_calls = j.get<std::vector<std::string>>();
    }

    void initInputs(const std::string& inputs) {
        m_inputs.clear();
        auto j = nlohmann::json::parse(inputs);
        for (auto i : j) {
            m_inputs.push_back(i.dump());
        }
    }

    void initExpecteds(const std::string& expecteds) {
        m_expecteds.clear();
        auto j = nlohmann::json::parse(expecteds);
        for (auto i : j) {
            m_expecteds.push_back(i.dump());
        }
    }

private:
    std::unordered_map<std::string, Method> m_methods;
    std::vector<std::string> m_calls;
    std::vector<std::string> m_inputs;
    std::vector<std::string> m_expecteds;
    T* m_obj = nullptr;
};
}  // namespace leetcode