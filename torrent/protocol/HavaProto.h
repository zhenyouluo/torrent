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
        assert(_header._msgLen == 5);
        if(input->readAbleBytes() < 4) {
            return false;
        }
        _piece_index = input->readInt32();
        return true;
    }

    bool encode(walle::net::Buffer*output)
    {
       _header._msgLen = 5;
       _header._msgCMD = HAVE;
       _header.encode(output);
       output->writeInt32(_piece_index); 
    }
    void setIndex(int32_t index) { _piece_index = index; }

    int32_t getIndex() { return _piece_index; }
protected:
    int32_t _piece_index;

};

}

#endif

