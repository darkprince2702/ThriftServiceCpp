/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Files.cpp
 * Author: ductn
 * 
 * Created on June 20, 2016, 10:25 AM
 */

#include "File.h"

using namespace profileservice;

File::File() {
    // Nothing to do
}

File::File(std::string filePath) {
    this->filePath = filePath;
}

void File::setFilePath(std::string path) {
    filePath = path;
}