#ifndef TORRENT_PROTOFACTORY_H_
#define TORRENT_PROTOFACTORY_H_
#include <torrent/protocol/ProtoBase.h>
#include <walle/net/Buffer.h>

namespace torrent {

class ProtoFactory{
public:
    static ProtoBase *deCode(walle::net::Buffer *buf,int& err)
    {
        err = 0;
        ProtoHeader header;
        bool ret = header.decode(buf);
        if(!ret) {
            return NULL;
        }
        ProtoBase *pt = NULL;
        
        if(header._msgCMD == CHOKE ) {

            pt = new ChokeProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 
        } else if(header._msgCMD == UNCHOKE) {
            pt = new UnchokeProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 
        }else if(header._msgCMD == INTERESTED) {
            pt = new InterestedProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       } else if(header._msgCMD == NOT_INTERESTED) {
            pt = new NotInterestedProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == CANCEL) {
            pt = new CancelProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == HAVE) {
            pt = new HaveProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == PIECE) {
            pt = new PieceProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       } else if(header._msgCMD == BITFIELD) {
            pt = new BitfieldProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == PORT) {
            pt = new PortProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == PIECE) {
            pt = new PieceProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }else if(header._msgCMD == REQUEST) {
            pt = new RequestProto;
            if(!pt) {
                
                err = -1;
            }
            pt->setHeader(header);
            pt->decode(buf);
            return pt; 

       }
                
        return NULL;   
    }
};
}
#endif