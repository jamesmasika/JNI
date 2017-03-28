// mdusertest.cpp : 
//一个简单的例子，介绍CFtdcMduserApi和CFtdcMduserSpi接口的使用。

#ifndef _FocusMDHandler_H_
#define _FocusMDHandler_H_

//#include "FocusFtdcMdApi.h"
#include "FocusFtdcUserApi.h"
#include <jni.h>
#include "JniUtil.h"

class FocusMDHandler : public CFocusFtdcUserSpi 
{
public:
    // 构造函数，需要一个有效的指向CFtdcMduserApi实例的指针
    FocusMDHandler(CFocusFtdcUserApi *pUserApi,
				const CFocusFtdcReqUserLoginField &pUserLoginField,
				JavaVM *vm,jobject jniTemplate);
    ~FocusMDHandler();
    // 当客户端与行情发布服务器建立起通信连接，客户端需要进行登录
    void OnFrontConnected();

    // 当客户端与行情发布服务器通信连接断开时，该方法被调用
    void OnFrontDisconnected();

	void OnPackageStart(int nTopicID, int nSequenceNo);
	
	void OnPackageEnd(int nTopicID, int nSequenceNo);

	void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // 当客户端发出登录请求之后，该方法会被调用，通知客户端登录是否成功
    void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户退出应答
	void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	// 深度行情通知，行情服务器会主动通知客户端
    void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pMarketData);
  
	// 针对用户请求的出错通知
    void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///订阅合约的相关信息
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///2017.03.24 add by  wangyl  




	///计算单个期权应答
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///计算障碍期权应答
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///计算期权组合应答
	virtual void OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///计算单个期权请求
	virtual int reqCalcOneOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///计算障碍期权请求
	virtual int reqCalcBarrierOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///计算期权组合请求
	virtual int reqCalcCombinationOption(JNIEnv *env, jobject reqMap, jint nRequestID);

private:
	
    // 指向CFtdcMduserApi实例的指针
    CFocusFtdcUserApi *m_pUserApi;
	CFocusFtdcReqUserLoginField m_reqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	jobject m_jniTemplate;

	int	m_maxOrderLocalID;
	 
};
#endif