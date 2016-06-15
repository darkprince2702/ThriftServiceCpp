/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MemcachedModel.h
 * Author: ductn
 *
 * Created on June 9, 2016, 4:06 PM
 */

#ifndef CACHEMODEL_H
#define CACHEMODEL_H

#include <libmemcached/memcached.hpp>
#include <mutex>
#include "ProfileServiceTypes.h"


class MemcachedModel {
private:
    memcache::Memcache mc;
    std::mutex mtx;
    MemcachedModel();
public:
    static MemcachedModel *getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value0);
    bool removeData(std::string key);

};

#endif /* MEMCACHEDMODEL_H */
