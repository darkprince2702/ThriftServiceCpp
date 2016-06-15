//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_LEVELDBMODEL_H
#define THRIFTSERVICECPP_LEVELDBMODEL_H

#include <leveldb/db.h>
#include <mutex>
#include "ProfileServiceTypes.h"

class LevelDBModel {
private:
    leveldb::DB *db;
    leveldb::Options options;
    leveldb::Status status;
    std::mutex mtx;
    LevelDBModel();
public:
    static LevelDBModel *getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
};


#endif //THRIFTSERVICECPP_LEVELDBMODEL_H
