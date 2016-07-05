/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.h
 * Author: ductn
 *
 * Created on June 20, 2016, 2:30 PM
 */

#ifndef LOGFILE_H
#define LOGFILE_H

#include "File.h"
#include "Buffer.h"
#include "SaveFile.h"
#include <mutex>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/container/detail/std_fwd.hpp>
#include <list>

namespace profileservice {

    class LogFile : public File {
    public:
        static LogFile* getInstance();
        bool load() override;
        bool write() override;
        void setFilePath(std::string path) override;
        void addLog(std::string line);
        void clearLog();
    private:
        LogFile();
        boost::shared_ptr<std::list<std::string>> log;
        boost::shared_ptr<Buffer> buffer;
        std::mutex mutex;
        boost::shared_ptr<SaveFile> saveFile;
    };
}

#endif /* LOGFILE_H */

