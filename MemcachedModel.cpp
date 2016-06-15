/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MemcachedHandler.cpp
 * Author: ductn
 *
 * Created on June 7, 2016, 2:16 PM
 */

#include "MemcachedModel.h"
#include <iostream>
#include <vector>

MemcachedModel::MemcachedModel() {
    mc = memcache::Memcache("localhost", 11211);
    mc.flush();
}


MemcachedModel *MemcachedModel::getInstance() {
    static MemcachedModel *instance;
    if(!instance)
        instance = new MemcachedModel();
    return instance;
}


GetResult MemcachedModel::getData(std::string key) {
    std::vector<char> result;
    GetResult return_;
    std::lock_guard<std::mutex> guard(mtx);
    bool success = mc.get(key, result);
    if (success) {
        return_.isNull = false;
        return_.value = std::string(result.data());
    } else {
        return_.isNull = true;
    }

    return return_;
}

bool MemcachedModel::setData(std::string key, std::string value) {
    std::lock_guard<std::mutex> guard(mtx);
    bool success = mc.set(key, std::vector<char>(value.begin(), value.end()), 0, 0);
    return success;
}

bool MemcachedModel::removeData(std::string key) {
    std::lock_guard<std::mutex> guard(mtx);
    bool success = mc.remove(key);
    return success;
}
