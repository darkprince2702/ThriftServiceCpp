/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DumpFile.h
 * Author: ductn
 *
 * Created on June 20, 2016, 10:44 AM
 */

#ifndef PROFILESERVICE_DUMPFILE_H
#define PROFILESERVICE_DUMPFILE_H

#include "File.h"
#include "HashMapModel.h"
#include "SaveFile.h"
#include <fcntl.h>
#include <mutex>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/container/detail/std_fwd.hpp>
#include <thrift/transport/TSimpleFileTransport.h>
#include <thrift/transport/TFileTransport.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>

namespace profileservice {

    class DumpFile : public File {
    public:
        static DumpFile* getInstance();
        bool load() override;
        bool write() override;
        void setFilePath(std::string path) override;
    private:
        DumpFile();
        boost::shared_ptr<std::unordered_map<std::string, std::string>> hashMap;
        std::mutex mutex;
        boost::shared_ptr<SaveFile> saveFile;
//        boost::shared_ptr<apache::thrift::transport::TFileTransport> fileTransport;
//        boost::shared_ptr<apache::thrift::protocol::TBinaryProtocol> binaryProtocol;
//        apache::thrift::protocol::TJSONProtocol* jsonProtocol;
    };
}
#endif /* DUMPFILE_H */

