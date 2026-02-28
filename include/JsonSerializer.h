//
// Created by hp on 2026/2/28.
//

#ifndef LEARNING_JSONSERIALIZER_H
#define LEARNING_JSONSERIALIZER_H

#include <nlohmann/json.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//
// namespace nlohmann {
//     template <>
//     struct adl_serializer<boost::posix_time::ptime> {
//         static void to_json(json& j, const boost::posix_time::ptime& p) {
//             if (p.is_not_a_date_time()) {
//                 j = nullptr;
//             } else {
//                 j = boost::posix_time::to_iso_string(p);
//             }
//         }
//
//         static void from_json(const json& j, boost::posix_time::ptime& p) {
//             if (j.is_null()) {
//                 p = boost::posix_time::ptime();
//             } else {
//                 p = boost::posix_time::time_from_string(j.get<std::string>());
//             }
//         }
//     };
// }

#include <type_traits>
#include <sstream>
#include <stdexcept>
#include <string>

namespace detail {
    inline std::string addUnderscore(const std::string& name) {
        if (!name.empty() && name.back() != '_') {
            return name + "_";
        }
        return name;
    }

    inline std::string trimUnderscore(const std::string& name) {
        if (!name.empty() && name.back() == '_') {
            return name.substr(0, name.size() - 1);
        }
        return name;
    }

    template<typename T>
    T stringTo(const std::string& s) {
        if constexpr (std::is_same_v<T, int>) return std::stoi(s);
        else if constexpr (std::is_same_v<T, long>) return std::stol(s);
        else if constexpr (std::is_same_v<T, long long>) return std::stoll(s);
        else if constexpr (std::is_same_v<T, float>) return std::stof(s);
        else if constexpr (std::is_same_v<T, double>) return std::stod(s);
        else if constexpr (std::is_same_v<T, bool>) return s == "true" || s == "1" || s == "yes";
        else if constexpr (std::is_same_v<T, unsigned long long>) return std::stoull(s);
        else return s;
    }
}

namespace nlohmann {
    template <>
    struct adl_serializer<boost::posix_time::ptime> {
        static void to_json(json& j, const boost::posix_time::ptime& p) {
            if (p.is_not_a_date_time()) j = nullptr;
            else j = boost::posix_time::to_iso_string(p);
        }

        static void from_json(const json& j, boost::posix_time::ptime& p) {
            if (j.is_null()) p = boost::posix_time::ptime();
            else if (j.is_string()) p = boost::posix_time::time_from_string(j.get<std::string>());
            else throw std::runtime_error("Invalid ptime format");
        }
    };
}

// 兼容方式读取 JSON：先尝试不带下划线的 key，再尝试带下划线的
// JSON 传 "id" → 匹配 C++ 的 "id_"
// JSON 传 "id_" → 也匹配 C++ 的 "id_"
template<typename T>
T jsonGet(const nlohmann::json& j, const std::string& fieldName, const T& defaultValue) {
    std::string cppField = detail::addUnderscore(fieldName);

    // 优先尝试不带下划线（JSON 标准格式）
    if (j.contains(fieldName)) {
        const auto& val = j[fieldName];
        if (val.is_null()) return defaultValue;
        if (val.is_string() && !std::is_same_v<T, std::string>) {
            return detail::stringTo<T>(val.get<std::string>());
        }
        return val.get<T>();
    }

    // 其次尝试带下划线（C++ 成员变量格式）
    if (j.contains(cppField)) {
        const auto& val = j[cppField];
        if (val.is_null()) return defaultValue;
        if (val.is_string() && !std::is_same_v<T, std::string>) {
            return detail::stringTo<T>(val.get<std::string>());
        }
        return val.get<T>();
    }

    // 字段不存在，返回默认值
    return defaultValue;
}

// 兼容方式写入 JSON：自动把带下划线的字段名转为不带下划线
// C++ 的 "id_" → 输出 JSON 为 "id"
template<typename T>
void jsonSet(nlohmann::json& j, const std::string& cppField, const T& value) {
    std::string jsonField = detail::trimUnderscore(cppField);
    j[jsonField] = value;
}

// 简化宏
// 用法: JSON_GET(j, id_, unsigned long long)  ← 写 C++ 字段名
#define JSON_GET(j, field, type) jsonGet<type>(j, #field, type{})

#define JSON_GET_DEFAULT(j, field, type, defaultVal) jsonGet<type>(j, #field, defaultVal)

// 用法: JSON_SET(j, userObj, id_)  ← 写 C++ 字段名，自动转为 "id"
#define JSON_SET(j, obj, field) jsonSet(j, #field, obj.field)
#endif //LEARNING_JSONSERIALIZER_H