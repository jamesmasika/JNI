// mdusertest.cpp : 
//һ���򵥵����ӣ�����CFtdcMduserApi��CFtdcMduserSpi�ӿڵ�ʹ�á�

#ifndef _QdiamMDHandler_H_
#define _QdiamMDHandler_H_

#include "QdamFtdcMdApi.h"
#include <jni.h>
#include "JniUtil.h"

class QdiamMDHandler : public CQdamFtdcMduserSpi
{
public:
    // ���캯������Ҫһ����Ч��ָ��CFtdcMduserApiʵ����ָ��
    QdiamMDHandler(CQdamFtdcMduserApi *pUserApi,
				const CQdamFtdcReqUserLoginField &pUserLoginField,
				JavaVM *vm,jobject jniTemplate);
    ~QdiamMDHandler();
    // ���ͻ��������鷢��������������ͨ�����ӣ��ͻ�����Ҫ���е�¼
    void OnFrontConnected();

    // ���ͻ��������鷢��������ͨ�����ӶϿ�ʱ���÷���������
    void OnFrontDisconnected();

	void OnPackageStart(int nTopicID, int nSequenceNo);
	
	void OnPackageEnd(int nTopicID, int nSequenceNo);

	void OnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ���ͻ��˷�����¼����֮�󣬸÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ�
    void OnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��˳�Ӧ��
	void OnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	// �������֪ͨ�����������������֪ͨ�ͻ���
    void OnRtnDepthMarketData(CQdamFtdcDepthMarketDataField *pMarketData);
  
	// ����û�����ĳ���֪ͨ
    void OnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///���ĺ�Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

private:
	
    // ָ��CFtdcMduserApiʵ����ָ��
    CQdamFtdcMduserApi *m_pUserApi;
	CQdamFtdcReqUserLoginField m_reqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	jobject m_jniTemplate;
	 
};
#endif