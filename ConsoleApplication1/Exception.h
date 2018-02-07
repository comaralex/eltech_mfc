#pragma once
#include "stdafx.h"
#include <string>

class Exception {
public:
	const std::string message;
protected:
	Exception(std::string className) : message("Exception: " + className) {}
};

class InvalidIndexToGetException : public Exception {
public:
	InvalidIndexToGetException(std::string className) :
		Exception(className)
	{};
};