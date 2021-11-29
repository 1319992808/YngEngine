#pragma once
#include<memory>
#include<sstream>
#include<functional>
#include<assert.h>

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using FuncPtr = std::function<T>;

template<typename T, typename ... Args>
constexpr UniquePtr<T> MakeUnique(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

using String = std::string;

