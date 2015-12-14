#ifndef TORRENT_PROTOCOL_CANCELPROTO_H_
#define TORRENT_PROTOCOL_CANCELPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class CancelProto : public ProtoBase{
public:
    CancelProto():ProtoBase()
    {
    }
    ~CancelProto(){}
    bool decode( walle::net :: Buffer * input)
    {
       _piece_index = input->readInt32();
       _offset = input->readInt32();
       _length = input->readInt32();
       return true;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 13;
        _header._msgCMD = CANCEL;
        _header.encode(output);
        output->appendInt32(_piece_index);
        output->appendInt32(_offset);
        output->appendInt32(_length);
        return true;
        
    }
    void setPiece(int32_t piece)
    {
        _piece_index = piece;
    }
    int32_t getPiece()
    {
        return _piece_index;
    }

    void setOffset(int32_t offset)
    {
        _offset = offset;
    }

    int32_t getOffet()
    {
        return _offset;
    }

    void setLength(int32_t len)
    {
        _length = len;
    }

    int32_t getLength()
    {
        return _length;
    }
protected:
    int32_t  _piece_index;
    int32_t  _offset;
    int32_t  _length;

};

}

#endif

