/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SaveFile.cpp
 * Author: ductn
 * 
 * Created on June 21, 2016, 5:41 PM
 */

#include "SaveFile.h"

using namespace profileservice;

#include <iostream>

SaveFile::SaveFile() : File("checkpoint") {
    load();
}

SaveFile* SaveFile::getInstance() {
    static SaveFile* instance = NULL;
    static std::mutex mutex;
    if (instance == NULL) {
        std::lock_guard<std::mutex> guard(mutex);
        if (instance == NULL) {
            instance = new SaveFile();
        }
    }
    return instance;
}

std::string SaveFile::getCheckPoint() {
    return checkPoint;
}

std::string SaveFile::getNewCheckPoint() {
    static std::mutex mutex;
    std::lock_guard<std::mutex> guard(mutex);
    time_t now = time(0);
    tm* timeInfo = std::localtime(&now);
    std::string year = std::to_string(timeInfo->tm_year + 1900);
    std::string month = ((timeInfo->tm_mon < 9) ? "0" : "") +
            std::to_string(timeInfo->tm_mon + 1);
    std::string day = ((timeInfo->tm_mday < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_mday);
    std::string hour = ((timeInfo->tm_hour < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_hour);
    std::string min = ((timeInfo->tm_min < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_min);
    std::string newCheckPoint = year + month + day + hour + min;
    checkPoint = newCheckPoint;
    return checkPoint;
}

bool SaveFile::load() {
    std::ifstream saveFile;

    saveFile.open(File::filePath, std::ios::in | std::ios::binary);
    if (saveFile.is_open()) {
        std::string line;
        std::getline(saveFile, line);
        checkPoint = line;
        saveFile.close();
        return true;
    } else {
        saveFile.close();
        getNewCheckPoint();
        return false;
    }
}

bool SaveFile::write() {
    std::ofstream saveFile;
    saveFile.open(File::filePath, std::ios::trunc | std::ios::binary);
    if (saveFile.is_open()) {
        saveFile.write(checkPoint.c_str(), checkPoint.size());
        saveFile.close();
        return true;
    } else {
        saveFile.close();
        return false;
    }
}