//
// Created by ductn on 14/06/2016.
//

#include "Database.h"
#include "LevelDB.h"

Database *Database::getDatabase(std::string dbType) {
    if (dbType == "LevelDB") {
        return LevelDB::getInstance();
    } else {
        return nullptr;
    }
}



