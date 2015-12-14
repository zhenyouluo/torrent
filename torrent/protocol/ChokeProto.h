#ifndef TORRENT_PROTOCOL_CHOKEPROTO_H_
#define TORRENT_PROTOCOL_CHOKEPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class ChokeProto : public ProtoBase{
public:
    ChokeProto():ProtoBase()
    {
    }
    ~ChokeProto(){}
    bool decode( walle::net :: Buffer * input)
    {
        (void)input;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 5;
        _header._msgCMD = CHOKE;
        return _header.encode(output);
    }

};

}

#endif