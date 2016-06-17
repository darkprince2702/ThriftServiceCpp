//
// Created by ductn on 14/06/2016.
//

#include "Database.h"

using namespace profileservice;

Database::Database() : dbModel(DatabaseModel::getInstance()) {
}

Database* Database::getInstance() {
    static std::mutex mutex;
    static Database* instance;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new Database();
        }
    }
    
    return instance;
}

GetResult Database::getData(std::string key) {
    return dbModel->getData(key);
}

bool Database::setData(std::string key, std::string value) {
    return dbModel->setData(key, value);
}

bool Database::removeData(std::string key) {
    return dbModel->removeData(key);
}


