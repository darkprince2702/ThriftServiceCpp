/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.cpp
 * Author: ductn
 * 
 * Created on June 20, 2016, 2:30 PM
 */

#include "LogFile.h"

using namespace profileservice;

LogFile::LogFile() : log(new std::list<std::string>),
saveFile(SaveFile::getInstance()),
buffer(Buffer::getBuffer("HashMap")) {
    File::setFilePath("log/" + saveFile->getCheckPoint());
}

LogFile* LogFile::getInstance() {
    static LogFile* instance = NULL;
    static std::mutex mutex;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new LogFile();
        }
    }

    return instance;
}

bool LogFile::load() {
    std::lock_guard<std::mutex> guard(mutex);
    std::ifstream logFile;
    // Open file in binary mode
    logFile.open(File::filePath, std::ios::in | std::ios::binary);
    if (logFile.is_open()) {
        std::string line;
        // Get line by line in opened file
        while (std::getline(logFile, line)) {
            std::vector<std::string> tokens;
            // Split gotten line into tokens
            boost::split(tokens, line, boost::is_any_of("(),\0"));
            if (tokens[0] == "setData") { // It's set task
                buffer->setData(tokens[1], tokens[2]);
            } else if (tokens[0] == "removeData") { // It's remove task
                buffer->removeData(tokens[1]);
            }
        }
        logFile.close();
        return true;
    } else {
        return false;
    }
}

bool LogFile::write() {
    std::lock_guard<std::mutex> guard(mutex);
    std::ofstream logFile;
    // Open file in binary and truncate mode
    logFile.open(File::filePath, std::ios::out | std::ios::trunc |
            std::ios::binary);
    if (logFile.is_open()) {
        // Iterate through log list, put all tasks in a string
        // Prevent interrupt while writing
        std::string writeContent;
        while (!log->empty()) {
            std::string line = log->front();
            log->pop_front();
            writeContent += line;
            writeContent += "\n";
        }
        // Write all tasks to file
        logFile << writeContent;
        return true;
    } else {
        return false;
    }
}

void LogFile::addLog(std::string line) {
    std::lock_guard<std::mutex> guard(mutex);
    log->push_back(line);

    std::ofstream logFile;
    logFile.open(File::filePath, std::ios::out | std::ios::app |
            std::ios::binary);
    if (logFile.is_open()) {
        logFile << line << "\n";
    }
}

void LogFile::clearLog() {
    std::lock_guard<std::mutex> guard(mutex);
    // TODO: delete all node
    log->clear();
}

void LogFile::setFilePath(std::string path) {
    std::lock_guard<std::mutex> guard(mutex);
    File::filePath = "log/" + path;
}