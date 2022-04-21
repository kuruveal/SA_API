#pragma once

#include <string>
#ifdef CORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

CORE_API bool startsWith(std::string mainStr, std::string toMatch);
