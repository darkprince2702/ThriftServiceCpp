/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DatabaseModel.h
 * Author: ductn
 *
 * Created on June 17, 2016, 10:34 AM
 */

#ifndef PROFILESERVICE_DATABASEMODEL_H
#define PROFILESERVICE_DATABASEMODEL_H

#include "DatabaseService.h"
#include "profileservice_types.h"
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TFDTransport.h>
#include <mutex>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace profileservice;

namespace profileservice {

class DatabaseModel {
public:
    static DatabaseModel* getInstance();
    GetResult getData(std::string key);
    bool setData(std::string key, std::string value);
    bool removeData(std::string key);
private:
    boost::shared_ptr<TSocket> socket;
    boost::shared_ptr<TTransport> transport;
    boost::shared_ptr<TProtocol> protocol;
    databaseservice::DatabaseServiceClient client;
    DatabaseModel();
};

}

#endif /* DATABASEMODEL_H */

