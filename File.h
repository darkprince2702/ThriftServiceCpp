/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Files.h
 * Author: ductn
 *
 * Created on June 20, 2016, 10:25 AM
 */

#ifndef PROFILESERVICE_FILE_H
#define PROFILESERVICE_FILE_H

#include <string>

namespace profileservice {

    class File {
    public:
        File();
        File(std::string filePath);
        virtual bool load() = 0;
        virtual bool write() = 0;
        virtual void setFilePath(std::string path);
    protected:
        std::string filePath;
    };
}
#endif /* FILES_H */

