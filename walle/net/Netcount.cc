#include <walle/net/Netcount.h>
#include <walle/sys/Logging.h>
using namespace walle::sys;
namespace walle{
namespace net {
	NetCount NetCount::_gNetCount;
	
	/*
	 * ���캯��
	 */
	NetCount::NetCount() {
		clear();
	}
	
	/*
	 * ��������
	 */
	NetCount::~NetCount() {
	}
	
	/*
	 * ��statд��log��
	 */
	void NetCount::log() {
		LOG_INFO<<"dataReadCnt: "<<_dataReadCnt.get()<<"dataWriteCnt: "<< _dataWriteCnt.get();
	}
	
	/*
	 * ���
	 */
	void NetCount::clear() {
		_dataReadCnt.getAndSet(0);
		_dataWriteCnt.getAndSet(0);
	}
}
}
