/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DatabaseModel.cpp
 * Author: ductn
 * 
 * Created on June 17, 2016, 10:34 AM
 */

#include "DatabaseModel.h"

DatabaseModel::DatabaseModel() : socket(new TSocket("127.0.0.1", 9091)),
transport(new TFramedTransport(socket)), protocol(new TBinaryProtocol(transport)),
client(protocol) {
    transport->open();
}

DatabaseModel* DatabaseModel::getInstance() {
    static std::mutex mutex;
    static DatabaseModel* instance;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new DatabaseModel();
        }
    }
    return instance;
}

GetResult DatabaseModel::getData(std::string key) {
    databaseservice::GetResult result;
    client.getData(result, key);
    GetResult _return;
    _return.__set_isNull(result.isNull);
    if (!result.isNull) {
        _return.__set_value(result.value);
    }
    return _return;
}

bool DatabaseModel::setData(std::string key, std::string value) {
    return client.setData(key, value);
}

bool DatabaseModel::removeData(std::string key) {
    return client.removeData(key);
}