#ifndef TORRENT_PROTOCOL_PORTPROTO_H_
#define TORRENT_PROTOCOL_PORTPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class PortProto : public ProtoBase{
public:
    PortProto():ProtoBase()
    {
    }
    ~PortProto(){}
    bool decode( walle::net :: Buffer * input)
    {
       _port = input->readInt16();  
       return true;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 3;
        _header._msgCMD = PORT;
        _header.encode(output);
        output->appendInt16(_port);
        return true;
        
    }


    void setPort(int16_t port)
    {
        _port = port;
    }

    int32_t gePort()
    {
        return _port;
    }
protected:

    int16_t  _port;

};

}

#endif

