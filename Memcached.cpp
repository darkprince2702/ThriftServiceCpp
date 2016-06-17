//
// Created by ductn on 14/06/2016.
//

#include "Memcached.h"

using namespace profileservice;

Memcached::Memcached() {
    memcachedModel = MemcachedModel::getInstance();
}

Memcached *Memcached::getInstance() {
    static Memcached instance;
    return &instance;
}

GetResult Memcached::getData(std::string key) {
    return memcachedModel->getData(key);
}


bool Memcached::setData(std::string key, std::string value) {
    return memcachedModel->setData(key, value);
}

bool Memcached::removeData(std::string key) {
    return memcachedModel->removeData(key);
}



