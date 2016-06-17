//
// Created by ductn on 14/06/2016.
//

#ifndef PROFILESERVICE_DATABASE_H
#define PROFILESERVICE_DATABASE_H

#include <string>
#include "profileservice_types.h"
#include "DatabaseModel.h"
#include <mutex>

namespace profileservice {

    class Database {
    public:
        GetResult getData(std::string key);
        bool setData(std::string key, std::string value);
        bool removeData(std::string key);
        static Database* getInstance();
    private:
        Database();
        boost::shared_ptr<DatabaseModel> dbModel;
    };
}

#endif //THRIFTSERVICECPP_DATABASE_H
