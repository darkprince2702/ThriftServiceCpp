//
// Created by ductn on 14/06/2016.
//

#include "HashMapModel.h"

using namespace profileservice;

HashMapModel::HashMapModel() {
//    hashMap = new std::unordered_map<std::string, std::string>();
}

HashMapModel *HashMapModel::getInstance() {
    static HashMapModel instance;
    return &instance;
}

GetResult HashMapModel::getData(std::string key) {
    GetResult return_;
    std::lock_guard<std::mutex> guard(mutex);
    auto search = hashMap.find(key);
    if (search != hashMap.end()) {
        return_.__set_isNull(false);
        return_.__set_value(search->second);
    } else {
        return_.isNull = true;
    }
    return return_;
}

bool HashMapModel::setData(std::string key, std::string value) {
    std::lock_guard<std::mutex> guard(mutex);
    hashMap[key] = value;
    return true;
}

bool HashMapModel::removeData(std::string key) {
    std::lock_guard<std::mutex> guard(mutex);
    hashMap.erase(key);
    return true;
}

