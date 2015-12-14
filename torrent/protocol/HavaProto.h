#ifndef TORRENT_PROTOCOL_HAVEPROTO_H_
#define TORRENT_PROTOCOL_HAVEPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class HaveProto : public ProtoBase{
public:
    HaveProto():ProtoBase()
    {
    }
    ~HaveProto(){}
    bool decode( walle::net :: Buffer * input)
    {
        (void)input;
    }

    bool encode(walle::net::Buffer*output)
    {
        return _header.encode(output); 
    }
protected:
    int32_t 

};

}

#endif

