//
// Created by ductn on 14/06/2016.
//

#include "Buffer.h"
#include "HashMap.h"

using namespace profileservice;

Buffer *Buffer::getBuffer(std::string bufferType) {
    if (bufferType == "HashMap") {
        return HashMap::getInstance();
    } else {
        return NULL;
    }
}

