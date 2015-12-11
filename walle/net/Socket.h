#ifndef WALLE_NET_SOCKET_H_
#define WALLE_NET_SOCKET_H_
#include <string>
#include <walle/sys/Logging.h>
#include <walle/net/Addrinet.h>
struct tcp_info;
namespace walle {
namespace net {

class Socket {

public:
    /*
     * ���캯��
     */
     Socket(bool own = false);

    /*
     * ��������
     */
    ~Socket();
    /*
     * �رն�д
     */
    bool connect( AddrInet& addr) ;
    bool bind( AddrInet& addr) ;
    bool listen(int backlog = 5);

    int accept(AddrInet& peeraddr);

    void shutdown();
    void close();

    /*
     * ��socketHandle,��ipaddress���õ���socket��
     *
     * @param  socketHandle: socket���ļ����
     * @param hostAddress: ��������ַ
     */

    void setFd(int socketHandle);

    /*
     * �����ļ����
     *
     * @return �ļ����
     */
    int getFd();
    /*
     * д����
     */
    int write(const void *data, int len);

    /*
     * ������
     */
    int read(void *data, int len);

    /*
     * SetSoKeepAlive
     */
    bool setKeepAlive(bool on) {
        return setIntOption(SO_KEEPALIVE, on ? 1 : 0);
    }

    /*
     * setReuseAddress
     */
    bool setReuseAddress(bool on) {
        return setIntOption(SO_REUSEADDR, on ? 1 : 0);
    }

    /*
     * setSoLinger
     */
    bool setSoLinger (bool doLinger, int seconds);

    /*
     * setTcpNoDelay
     */
    bool setTcpNoDelay(bool noDelay);

    /*
     * setTcpQuickAck
     */
    bool setTcpQuickAck(bool quickAck);

    /*
     * setIntOption
     */
    bool setIntOption(int option, int value);

    /*
     * setTimeOption
     */
    bool setTimeOption(int option, int milliseconds);

    /*
     * �Ƿ�����
     */
    bool setSoBlocking(bool on =false);
    /*
     * ���Socket����Ƿ񴴽�
     */
    bool checkSocketHandle();
    bool getTcpInfo(struct tcp_info*) const;
    bool getTcpInfoString(char* buf, int len) const;
    /*
     * �õ�Socket����
     */
    int getSoError();
    int        _savedErr;
protected:
    int        _socketHandle;    // socket�ļ����
    bool       _own;

};
}
}

#endif /*SOCKET_H_*/
