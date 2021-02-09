#pragma once

#include <type_traits>

template <std::size_t N, class... Args>
struct ArgumentType_N;

template <std::size_t N, class Head, class... Args>
struct ArgumentType_N<N, Head, Args...> : ArgumentType_N<N - 1, Args...> {
};

template <class Head, class... Args>
struct ArgumentType_N<0, Head, Args...>{
    typedef Head type;
};

template <class T, std::size_t N>
struct ArgumentType;

template <class Res, class ClassName, class... Args, std::size_t N>
struct ArgumentType<Res(ClassName::*)(Args...), N> {
    typedef typename ArgumentType_N<N, std::remove_cv_t<std::remove_reference_t<Res>>, std::remove_cv_t<std::remove_reference_t<Args>>...>::type type;
};