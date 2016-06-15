//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_MEMCACHED_H
#define THRIFTSERVICECPP_MEMCACHED_H

#include "Cache.h"
#include "MemcachedModel.h"

class Memcached : public Cache {
private:
    Memcached();
    MemcachedModel *memcachedModel;
public:
    static Memcached *getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
};


#endif //THRIFTSERVICECPP_MEMCACHED_H
