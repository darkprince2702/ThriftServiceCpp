//
// Created by ductn on 14/06/2016.
//

#ifndef THRIFTSERVICECPP_DATABASE_H
#define THRIFTSERVICECPP_DATABASE_H

#include <string>
#include "ProfileServiceTypes.h"

class Database {
public:
    virtual GetResult getData(std::string key) = 0;
    virtual bool setData(std::string key, std::string value) = 0;
    virtual bool removeData(std::string key) = 0;
    static Database *getDatabase(std::string dbType);
};


#endif //THRIFTSERVICECPP_DATABASE_H
