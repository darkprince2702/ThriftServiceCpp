/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DumpFile.cpp
 * Author: ductn
 * 
 * Created on June 20, 2016, 10:44 AM
 */

#include "DumpFile.h"

using namespace profileservice;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;

DumpFile::DumpFile() : saveFile(SaveFile::getInstance()),
hashMap(HashMapModel::getUnorderMap()) {
    File::setFilePath("dump/" + saveFile->getCheckPoint());
}

DumpFile* DumpFile::getInstance() {
    static DumpFile* instance = NULL;
    static std::mutex mutex;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new DumpFile();
        }
    }

    return instance;
}

//bool DumpFile::load() {
//    std::lock_guard<std::mutex> guard(mutex); // Lock before process
//    std::ifstream dumpFile;
//    // Open file in binary mode
//    dumpFile.open(File::filePath, std::ios::in | std::ios::binary);
//    if (dumpFile.is_open()) {
//        std::string line;
//        // Get line by line in opened file
//        while (std::getline(dumpFile, line)) {
//            std::vector<std::string> tokens;
//            // Split gotten line into tokens
//            boost::split(tokens, line, boost::is_any_of("\t"));
//            if (tokens.size() == 2) { // Valid line must have 2 tokens
//                hashMap->insert(std::make_pair(tokens[0], tokens[1])); // Insert to hash map
//            }
//        }
//        dumpFile.close();
//        return true;
//    } else {
//        return false;
//    }
//}

bool DumpFile::load() {
    boost::shared_ptr<TSimpleFileTransport> fileTrans =
            boost::make_shared<TSimpleFileTransport>(File::filePath, true, false);
    boost::shared_ptr<TJSONProtocol> proto =
            boost::make_shared<TJSONProtocol>(fileTrans);
    std::lock_guard<std::mutex> guard(mutex);
    boost::shared_ptr<Profile> profile = boost::make_shared<Profile>();
    try {
        while (profile->read(proto.get())) {
            hashMap->insert(std::make_pair(profile->id, profile->name));
        }
    } catch (...) {
        // Nothing to read
    }
    return true;
}

//bool DumpFile::write() {
//    std::lock_guard<std::mutex> guard(mutex); // Lock before process
//    std::ofstream dumpFile;
//    // Open file in binary and truncate mode
//    dumpFile.open(File::filePath, std::ios::out | std::ios::trunc |
//            std::ios::binary);
//    if (dumpFile.is_open()) {
//        // Iterate through hash map, write key and value to file
//        for (auto it : *hashMap) {
//            // dumpFile << it.first << "\t" << it.second << "\n";
//            std::string content = it.first + "\t" + it.second + "\n";
//            dumpFile.write(content.c_str(), content.size());
//        }
//        dumpFile.close();
//        return true;
//    } else {
//        return false;
//    }
//}

bool DumpFile::write() {
    boost::shared_ptr<TSimpleFileTransport> fileTrans =
            boost::make_shared<TSimpleFileTransport>(File::filePath, true, true);
    boost::shared_ptr<TJSONProtocol> proto =
            boost::make_shared<TJSONProtocol>(fileTrans);
    boost::shared_ptr<Profile> profile;
    for (auto it : *hashMap) {
        profile = boost::make_shared<Profile>();
        profile->__set_id(it.first);
        profile->__set_name(it.second);
        profile->write(proto.get());
        profile.reset();
    }
    return true;
}

void DumpFile::setFilePath(std::string path) {
    std::lock_guard<std::mutex> guard(mutex);
    File::filePath = "dump/" + path;
    // Change fd of transport
    //    int fd = THRIFT_OPEN(File::filePath.c_str(), O_RDWR,
    //            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    //    fileTransport->setFD(fd);
    //    outTransport->setFD(fd);
}