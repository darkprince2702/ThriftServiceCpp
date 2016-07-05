/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.cpp
 * Author: ductn
 * 
 * Created on June 20, 2016, 4:49 PM
 */

#include "Timer.h"

using namespace profileservice;

Timer* Timer::getInstance() {
    static Timer* instance = NULL;
    static std::mutex mutex;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new Timer();
        }
    }

    return instance;
}

Timer::Timer() : interval(60),
timer(ioService, interval),
saveFile(SaveFile::getInstance()),
dumpFile(DumpFile::getInstance()),
logFile(LogFile::getInstance()) {
    timer.async_wait(boost::bind(&Timer::doTask, this));
}

void Timer::doTask() {
    // Do the task
    saveFile->write();
    dumpFile->write();
    logFile->write();
    std::string newCheckPoint = saveFile->getNewCheckPoint();
    dumpFile->setFilePath(newCheckPoint);
    logFile->setFilePath(newCheckPoint);
    // Reschedule the timer at "interval" time in future
    timer.expires_at(timer.expires_at() + interval);
    // Recall await
    timer.async_wait(boost::bind(&Timer::doTask, this));
}

void Timer::run() {
    std::thread taskThread = std::thread([this] {
        ioService.run();
    });
    threadID = taskThread.get_id();
    taskThread.detach();
}

void Timer::stop() {
    // TODO: kill thread with threadID
}