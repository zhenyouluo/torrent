#ifndef TORRENT_PROTOCOL_PROTOBASE_H_
#define TORRENT_PROTOCOL_PROTOBASE_H_
#include <walle/net/Buffer.h>
#include <stdint.h>
#include <assert.h>

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
    bool encode(walle::net::Buffer*output)
    {
        char intstr[4];
        intstr[3] = _msgLen%256;
        intstr[2] = (_msgLen - intstr[3])/256%256;
        intstr[1] = (_msgLen - intstr[3] - intstr[2]*256)/256/256%256;
        intstr[0] = (_msgLen - intstr[3] - intstr[2]*256 - intstr[1]*256*256)/256/256/256%256;

        output->append(intstr,4);
        output->appendInt8((char)_msgCMD);
        return true;
    }

    bool decode(walle::net::Buffer*input)
    {
        if(input->readableBytes() < 4) {
            return false;
        }
        const char *p = input->peek();
        _msgLen = p[0]*256*256*256 + p[1]*256*256 + p[2]*256 + p[3];
        
        if(_msgLen == 0) {
            input->retrieve(4);
            _msgCMD = KEEP_ALIVE;

            return true;
        }
        //decode cmd;
        if(_msgLen > input->readableBytes()) {
            return false;
        }
        input->retrieve(4);
        _msgCMD = input->readInt8();
        
        return true;
        
    }
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