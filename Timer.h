/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.h
 * Author: ductn
 *
 * Created on June 20, 2016, 4:49 PM
 */

#ifndef TIMER_H
#define TIMER_H

#include <mutex>
#include <thread>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "LogFile.h"
#include "DumpFile.h"
#include "SaveFile.h"

namespace profileservice {

    class Timer {
    public:
        static Timer* getInstance();
        void doTask();
        void run();
        void stop();
    private:
        Timer();
        boost::asio::io_service ioService;
        boost::posix_time::seconds interval;
        boost::asio::deadline_timer timer;
        boost::shared_ptr<DumpFile> dumpFile;
        boost::shared_ptr<LogFile> logFile;
        boost::shared_ptr<SaveFile> saveFile;
        std::thread::id threadID;
    };
}

#endif /* TIMER_H */

