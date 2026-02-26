//
// Created by hp on 2026/2/26.
//

#ifndef LEARNING_LOGENUM_H
#define LEARNING_LOGENUM_H

#include  <iostream>
#include  <map>
#include <drogon/drogon.h>
#include <optional>

class LogEnumClass {
private:
    long code_ = 0l;
    std::string logCode_ = "learning-000001";
    std::string msg_ = "请求成功";
    drogon::HttpStatusCode statusCode_ = drogon::k200OK;

public:
    LogEnumClass(long code, std::string logCode, std::string msg, drogon::HttpStatusCode statusCode);

    class Builder {
    private:
        long code_ = 0l;
        std::string logCode_ = "learning-000001";
        std::string msg_ = "请求成功";
        drogon::HttpStatusCode statusCode_ = drogon::k200OK;
    public:
        Builder();
        Builder&& code(long code) &&;
        Builder&& logCode(const std::string &logCode) &&;
        Builder&& msg(const std::string &msg) &&;
        Builder&& statusCode(drogon::HttpStatusCode statusCode) &&;
        LogEnumClass build() &&;
    };

};

enum class LogEnum : long {
    SUCCESS = 0l,
    UNKNOW_ERROR = 1l,


};

const std::map<LogEnum, LogEnumClass> LOG_MAPPING = {
    {LogEnum::SUCCESS, LogEnumClass::Builder().code(0l).logCode("learning-000000").msg("请求成功").statusCode(drogon::k200OK).build()},
    {LogEnum::UNKNOW_ERROR, LogEnumClass::Builder().code(1l).logCode("learning-000001").msg("请求失败").statusCode(drogon::k500InternalServerError).build()},
};
#endif //LEARNING_LOGENUM_H