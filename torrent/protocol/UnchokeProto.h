#ifndef TORRENT_PROTOCOL_UNCHOKEPROTO_H_
#define TORRENT_PROTOCOL_UNCHOKEPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class UnchokeProto : public ProtoBase{
public:
    UnchokeProto():ProtoBase()
    {
    }
    ~ChokeProto(){}
    bool decode( walle::net :: Buffer * input)
    {
        (void)input;
    }

    bool encode(walle::net::Buffer*output)
    {
        return _header.encode(output);
    }

};

}

#endif

