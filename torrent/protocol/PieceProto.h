#ifndef TORRENT_PROTOCOL_PIECEPROTO_H_
#define TORRENT_PROTOCOL_PIECEPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class PieceProto : public ProtoBase{
public:
    PieceProto():ProtoBase()
    {
    }
    ~PieceProto(){}
    bool decode( walle::net :: Buffer * input)
    {
       int32_t blockLen = _header._msgLen - 13;
       _piece_index = input->readInt32();
       _offset = input->readInt32();
       _block.append(input->peek(), blockLen);
       input->retrive(blockLen);
       return true;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 13 + _block.size();
        _header._msgCMD = PIECE;
        _header.encode(output);
        output->appendInt32(_piece_index);
        output->appendInt32(_offset);
        output->append(_block);
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

    void setBlock(const string& b)
    {
        _block = b;
    }

    string &getBlock()
    {
        return _block;
    }
protected:
    int32_t  _piece_index;
    int32_t  _offset;
    string   _block;

};

}

#endif

