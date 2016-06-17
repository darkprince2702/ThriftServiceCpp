/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef databaseservice_TYPES_H
#define databaseservice_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace databaseservice {

class GetResult;

typedef struct _GetResult__isset {
  _GetResult__isset() : value(false) {}
  bool value :1;
} _GetResult__isset;

class GetResult {
 public:

  GetResult(const GetResult&);
  GetResult& operator=(const GetResult&);
  GetResult() : isNull(0), value() {
  }

  virtual ~GetResult() throw();
  bool isNull;
  std::string value;

  _GetResult__isset __isset;

  void __set_isNull(const bool val);

  void __set_value(const std::string& val);

  bool operator == (const GetResult & rhs) const
  {
    if (!(isNull == rhs.isNull))
      return false;
    if (__isset.value != rhs.__isset.value)
      return false;
    else if (__isset.value && !(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const GetResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GetResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GetResult &a, GetResult &b);

inline std::ostream& operator<<(std::ostream& out, const GetResult& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
