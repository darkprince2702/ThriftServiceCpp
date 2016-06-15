//
// Created by ductn on 14/06/2016.
//

#include "LevelDBModel.h"

LevelDBModel::LevelDBModel() {
    options.create_if_missing = true;
    status = leveldb::DB::Open(options, "/data/db", &db);
}

LevelDBModel *LevelDBModel::getInstance() {
    static LevelDBModel *instance;
    if (!instance)
        instance = new LevelDBModel();
    return instance;
}

GetResult LevelDBModel::getData(std::string key) {
    std::string result;
    GetResult return_;
    // Lock before access db
    std::lock_guard<std::mutex> guard(mtx);
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &result);

    if (s.ok()) {
        return_.isNull = false;
        return_.value = result;
    } else {
        return_.isNull = true;
    }
    return return_;
}

bool LevelDBModel::setData(std::string key, std::string value) {
    // Lock before access db
    std::lock_guard<std::mutex> guard(mtx);

    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
    return s.ok();
}

bool LevelDBModel::removeData(std::string key) {
    // Lock before access db
    std::lock_guard<std::mutex> guard(mtx);

    leveldb::Status s = db->Delete(leveldb::WriteOptions(), key);
    return s.ok();
}