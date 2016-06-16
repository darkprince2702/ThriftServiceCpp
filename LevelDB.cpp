//
// Created by ductn on 14/06/2016.
//

#include "LevelDB.h"

LevelDB* LevelDB::instance = new LevelDB();

LevelDB::LevelDB() {
    dbModel = LevelDBModel::getInstance();
}

LevelDB *LevelDB::getInstance() {
    return instance;
}

GetResult LevelDB::getData(std::string key) {
    return dbModel->getData(key);
}

bool LevelDB::setData(std::string key, std::string value) {
    return dbModel->setData(key, value);
}

bool LevelDB::removeData(std::string key) {
    return dbModel->removeData(key);
}

