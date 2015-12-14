#ifndef TORRENT_PROTOCOL_NOTINTERESTEDPROTO_H_
#define TORRENT_PROTOCOL_NOTINTERESTEDPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class NotInterestedProto : public ProtoBase{
public:
    NotInterestedProto():ProtoBase()
    {
    }
    ~NotInterestedProto(){}
    bool decode( walle::net :: Buffer * input)
    {
        (void)input;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 5;
        _header._msgCMD = NOT_INTERESTED;
        return _header.encode(output); 
    }

};

}

#endif

