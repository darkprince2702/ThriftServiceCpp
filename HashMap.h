//
// Created by ductn on 14/06/2016.
//

#ifndef PROFILESERVICE_HASHMAP_H
#define PROFILESERVICE_HASHMAP_H


#include "Buffer.h"
#include "HashMapModel.h"

namespace profileservice {

    class HashMap : public Buffer {
    private:
        HashMapModel *hashMapModel;
        HashMap();
    public:
        static HashMap *getInstance();
        GetResult getData(std::string key);
        bool setData(std::string key, std::string value);
        bool removeData(std::string key);
    };
}

#endif //THRIFTSERVICECPP_HASHMAP_H
