//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_CACHE_H
#define THRIFTSERVICECPP_CACHE_H

#include <string>
#include "ProfileServiceTypes.h"

class Cache {
public:
    virtual GetResult getData(std::string key) = 0;
    virtual bool setData(std::string key, std::string value) = 0;
    virtual bool removeData(std::string key) = 0;
    static Cache *getCache(std::string cacheType);
};

#endif //THRIFTSERVICECPP_CACHE_H
