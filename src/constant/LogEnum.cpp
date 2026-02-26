//
// Created by hp on 2026/2/26.
//

#include <utility>

#include "../../include/LogEnum.h"
LogEnumClass::LogEnumClass(long code, std::string logCode, std::string msg, drogon::HttpStatusCode statusCode) : code_(code) , logCode_(std::move(logCode)), msg_(std::move(msg)), statusCode_(statusCode) {
}

LogEnumClass::Builder::Builder() = default;

LogEnumClass::Builder &&LogEnumClass::Builder::code(long code) && {
    code_ = code;
    return std::move(*this);
}

LogEnumClass::Builder &&LogEnumClass::Builder::logCode(const std::string &logCode) && {
    logCode_ = logCode;
    return std::move(*this);
}

LogEnumClass::Builder &&LogEnumClass::Builder::msg(const std::string &msg) && {
    msg_ = msg;
    return std::move(*this);
}

LogEnumClass::Builder &&LogEnumClass::Builder::statusCode(drogon::HttpStatusCode statusCode) && {
    statusCode_ = statusCode;
    return std::move(*this);
}


LogEnumClass LogEnumClass::Builder::build() && {
    if (code_ < 0) throw std::invalid_argument("code should be bigger than 0");
    if (logCode_.empty()) throw std::invalid_argument("logCode cannot be empty");
    if (msg_.empty()) throw std::invalid_argument("msg cannot be empty");
    // if (statusCode_  nullptr) throw std::invalid_argument("statusCode must not be nullptr");
    return {code_, logCode_, msg_, statusCode_};
}
