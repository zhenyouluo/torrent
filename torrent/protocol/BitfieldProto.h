#ifndef TORRENT_PROTOCOL_BITFIELDPROTO_H_
#define TORRENT_PROTOCOL_BITFIELDPROTO_H_
#include <torrent/protocol/ProtoBase.h>

namespace torrent {

class BitfieldProto : public ProtoBase{
public:
    BitfieldProto():ProtoBase()
    {
    }
    ~BitfieldProto(){}
    bool decode( walle::net :: Buffer * input)
    {
       int len = _header._msgLen - 5;
       const char *data = input->peek();
       _bitfield.clear();
       //readAbleBytes must > 5;
       _bitfield.append(input->peek(), len);
       input->retrieve(len);
       return true;
    }

    bool encode(walle::net::Buffer*output)
    {
        _header._msgLen = 5 + _bitfield.size();
        _header._msgCMD = BITFIELD;
        _header.encode(output);
        output->append(_bitfield.c_str(), _bitfield.size());
        return true;
        
    }
    void setBitfield(const string & b) { _bitfield = b; }
    string getBitfield() { return _bitfield; }
protected:
    string _bitfield;    

};

}

#endif

