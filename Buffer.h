//
// Created by ductn on 14/06/2016.
//

#ifndef PROFILESERVICE_BUFFER_H
#define PROFILESERVICE_BUFFER_H

#include <string>
#include "profileservice_types.h"

namespace profileservice {

    class Buffer {
    public:
        virtual GetResult getData(std::string key) = 0;
        virtual bool setData(std::string key, std::string value) = 0;
        virtual bool removeData(std::string key) = 0;
        static Buffer *getBuffer(std::string bufferType);
    };
}

#endif //THRIFTSERVICECPP_BUFFER_H
