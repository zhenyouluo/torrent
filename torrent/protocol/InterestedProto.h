#ifndef TORRENT_PROTOCOL_INTERESTEDPROTO_H_
#define TORRENT_PROTOCOL_INTERESTEDPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class InterestedProto : public ProtoBase{
public:
    InterestedProto():ProtoBase()
    {
    }
    ~InterestedProto(){}
    bool decode( walle::net :: Buffer * input)
    {
        (void)input;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 5;
        _header._msgCMD = INTERESTED;
        return _header.encode(output); 
    }

};

}

#endif

