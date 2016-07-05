/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SaveFile.h
 * Author: ductn
 *
 * Created on June 21, 2016, 5:41 PM
 */

#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "File.h"
#include "SaveFile.h"
#include <fstream>
#include <mutex>
#include <ctime>

namespace profileservice {

    class SaveFile : public File {
    public:
        static SaveFile* getInstance();
        std::string getCheckPoint();
        std::string getNewCheckPoint();
        bool load();
        bool write();
        std::string checkPoint;
    private:
        SaveFile();
    };
}
#endif /* SAVEFILE_H */

