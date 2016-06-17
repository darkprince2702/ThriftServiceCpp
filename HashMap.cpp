//
// Created by ductn on 14/06/2016.
//

#include "HashMap.h"

using namespace profileservice;

HashMap::HashMap() {
    hashMapModel = HashMapModel::getInstance();
}

HashMap* HashMap::getInstance() {
    static HashMap instance;
    return &instance;
}

GetResult HashMap::getData(std::string key) {
    return hashMapModel->getData(key);
}

bool HashMap::setData(std::string key, std::string value) {
    return hashMapModel->setData(key, value);
}

bool HashMap::removeData(std::string key) {
    return hashMapModel->removeData(key);
}

