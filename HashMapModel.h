//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_HASHMAPMODEL_H
#define THRIFTSERVICECPP_HASHMAPMODEL_H

#include <string>
#include <unordered_map>
#include <mutex>
#include "ProfileServiceTypes.h"

class HashMapModel {
private:
    static HashMapModel *instance = NULL:
    HashMapModel();
    std::unordered_map<std::string, std::string> hashMap;
    std::mutex mutex;
public:
    static HashMapModel *getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
};


#endif //THRIFTSERVICECPP_HASHMAPMODEL_H
