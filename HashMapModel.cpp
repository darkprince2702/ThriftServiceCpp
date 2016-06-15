//
// Created by ductn on 14/06/2016.
//

#include "HashMapModel.h"

HashMapModel::HashMapModel() {
//    hashMap = new std::unordered_map<std::string, std::string>();
}

HashMapModel *HashMapModel::getInstance() {
    static HashMapModel *instance = NULL;
    if (instance == NULL) {
        lock {
            
            instance = new HashMapModel();
        }
    }
    return instance;
}

GetResult HashMapModel::getData(std::string key) {
    GetResult return_;
    std::lock_guard<std::mutex> guard(mutex);
    auto search = hashMap.find(key);
    if (search != hashMap.end()) {
        return_.isNull =     false;
        return_.value = search->second;
    } else {
        return_.isNull = true;
    }
    return return_;
}

bool HashMapModel::setData(std::string key, std::string value) {
    std::lock_guard<std::mutex> guard(mutex);
    auto search = hashMap.find(key);
    // If data exist in memory, update it if value changed
    if (search != hashMap.end() && search->second != value)
        hashMap[key] = value;
    else {
        hashMap[key] = value;
    }
}

bool HashMapModel::removeData(std::string key) {
    std::lock_guard<std::mutex> guard(mutex);
    auto search = hashMap.find(key);
    // If data exist in memory, delete it
    if (search != hashMap.end())
        hashMap.erase(key);
}
