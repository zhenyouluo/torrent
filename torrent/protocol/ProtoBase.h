#ifndef TORRENT_PROTOCOL_PROTOBASE_H_
#define TORRENT_PROTOCOL_PROTOBASE_H_
#include <walle/net/Buffer.h>
using walle::net::Buffer;

namespace torrent {

enum ProtoCMD{
    CHOKE = 0, //blocked other peers down from self
    UNCHOKE = 1, //ublocked other peers
    INTERESTED = 2,
    NOT_INTERESTED = 3,
    HAVE = 4,
    BITFIELD = 5,
    REQUEST = 6,
    PIECE = 7,
    CANCEL = 8,
    PORT  = 9,    //only dht use it
    NONE,           // These are not part of the protocol
    KEEP_ALIVE      // Last command was a keep alive
};

class ProtoHeader {
public:
    ProtoHeader():_msgLen(0),_msgCMD(NONE){}
    ~ProtoHeader(){}
public:
    int32_t _msgLen;
    int32_t _msgCMD;

};
class ProtoBase {
public:
  virtual ~ProtoBase(){}
  
  virtual bool decode(walle::net::Buffer*input) = 0;
  virtual bool encode(walle::net::Buffer*output) = 0;

  ProtoHeader getHeader() { return _header; }

  void        setHeader(const ProtoHeader & h) { _header = h; }
  
protected:
   ProtoHeader _header; 

};

}
#endif