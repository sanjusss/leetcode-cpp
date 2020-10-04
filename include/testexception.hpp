#pragma once

#include <exception>
#include <string>

class TestException : public std::exception {
public:
    TestException(const std::string& msg) : m_msg(msg) {}
    TestException(const TestException& other) : m_msg(other.m_msg) {}

    const char* what() const noexcept override { return m_msg.c_str(); }

    TestException& operator=( const TestException& other ) noexcept {
        m_msg = other.m_msg;
        return *this;
    }

private:
    std::string m_msg;
};