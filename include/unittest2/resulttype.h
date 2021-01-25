#pragma once

template <class T>
struct ResultType;

template <class Res, class ClassName, class... Args>
struct ResultType<Res(ClassName::*)(Args...)> {
    typedef Res type;
};