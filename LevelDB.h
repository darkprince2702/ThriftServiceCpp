//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_LEVELDB_H
#define THRIFTSERVICECPP_LEVELDB_H


#include "Database.h"
#include "LevelDBModel.h"

class LevelDB : public Database{
private:
    static LevelDB *instance;
    LevelDBModel *dbModel;
    LevelDB();
public:
    static LevelDB *getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
};


#endif //THRIFTSERVICECPP_LEVELDB_H
