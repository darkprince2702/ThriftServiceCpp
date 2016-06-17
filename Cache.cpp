//
// Created by ductn on 14/06/2016.
//

#include "Cache.h"
#include "Memcached.h"

using namespace profileservice;

Cache *Cache::getCache(std::string cacheType) {
    if (cacheType == "Memcached") {
        return Memcached::getInstance();
    } else {
        return nullptr;
    }
}

