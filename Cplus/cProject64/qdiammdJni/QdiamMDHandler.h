// mdusertest.cpp : 
//一个简单的例子，介绍CFtdcMduserApi和CFtdcMduserSpi接口的使用。

#ifndef _QdiamMDHandler_H_
#define _QdiamMDHandler_H_

#include "QdamFtdcMdApi.h"
#include <jni.h>
#include "JniUtil.h"

class QdiamMDHandler : public CQdamFtdcMduserSpi
{
public:
    // 构造函数，需要一个有效的指向CFtdcMduserApi实例的指针
    QdiamMDHandler(CQdamFtdcMduserApi *pUserApi,
				const CQdamFtdcReqUserLoginField &pUserLoginField,
				JavaVM *vm,jobject jniTemplate);
    ~QdiamMDHandler();
    // 当客户端与行情发布服务器建立起通信连接，客户端需要进行登录
    void OnFrontConnected();

    // 当客户端与行情发布服务器通信连接断开时，该方法被调用
    void OnFrontDisconnected();

	void OnPackageStart(int nTopicID, int nSequenceNo);
	
	void OnPackageEnd(int nTopicID, int nSequenceNo);

	void OnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // 当客户端发出登录请求之后，该方法会被调用，通知客户端登录是否成功
    void OnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户退出应答
	void OnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	// 深度行情通知，行情服务器会主动通知客户端
    void OnRtnDepthMarketData(CQdamFtdcDepthMarketDataField *pMarketData);
  
	// 针对用户请求的出错通知
    void OnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///订阅合约的相关信息
	virtual void OnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

private:
	
    // 指向CFtdcMduserApi实例的指针
    CQdamFtdcMduserApi *m_pUserApi;
	CQdamFtdcReqUserLoginField m_reqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	jobject m_jniTemplate;
	 
};
#endif