// mdusertest.cpp : 
//һ���򵥵����ӣ�����CFtdcMduserApi��CFtdcMduserSpi�ӿڵ�ʹ�á�

#ifndef _FocusMDHandler_H_
#define _FocusMDHandler_H_

//#include "FocusFtdcMdApi.h"
#include "FocusFtdcUserApi.h"
#include <jni.h>
#include "JniUtil.h"

class FocusMDHandler : public CFocusFtdcUserSpi 
{
public:
    // ���캯������Ҫһ����Ч��ָ��CFtdcMduserApiʵ����ָ��
    FocusMDHandler(CFocusFtdcUserApi *pUserApi,
				const CFocusFtdcReqUserLoginField &pUserLoginField,
				JavaVM *vm,jobject jniTemplate);
    ~FocusMDHandler();
    // ���ͻ��������鷢��������������ͨ�����ӣ��ͻ�����Ҫ���е�¼
    void OnFrontConnected();

    // ���ͻ��������鷢��������ͨ�����ӶϿ�ʱ���÷���������
    void OnFrontDisconnected();

	void OnPackageStart(int nTopicID, int nSequenceNo);
	
	void OnPackageEnd(int nTopicID, int nSequenceNo);

	void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ���ͻ��˷�����¼����֮�󣬸÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ�
    void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��˳�Ӧ��
	void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	// �������֪ͨ�����������������֪ͨ�ͻ���
    void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pMarketData);
  
	// ����û�����ĳ���֪ͨ
    void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///���ĺ�Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///2017.03.24 add by  wangyl  




	///���㵥����ȨӦ��
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ϰ���ȨӦ��
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///������Ȩ���Ӧ��
	virtual void OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///���㵥����Ȩ����
	virtual int reqCalcOneOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///�����ϰ���Ȩ����
	virtual int reqCalcBarrierOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///������Ȩ�������
	virtual int reqCalcCombinationOption(JNIEnv *env, jobject reqMap, jint nRequestID);

private:
	
    // ָ��CFtdcMduserApiʵ����ָ��
    CFocusFtdcUserApi *m_pUserApi;
	CFocusFtdcReqUserLoginField m_reqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	jobject m_jniTemplate;

	int	m_maxOrderLocalID;
	 
};
#endif