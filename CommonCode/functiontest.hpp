#pragma once

#include <functional>
#include <string>
#include <unordered_map>

template<class T>
class FunctionTest
{
    using Method = std::function<void(T&, const std::string&)>;
public:
    FunctionTest(T& obj, const std::string& inputs, const std::string& methods, const std::string& expecteds) : 
        m_obj(obj)
    {

    }

    void addMethod(const std::string& name, Method method)
    {
        m_methods[name] = method;
    }

    void check()
    {

    }

private:
    std::unordered_map<std::string, Method> m_methods;
    T& m_obj;
};