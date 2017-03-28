#ifndef _TraderJniSpi_H_
#define _TraderJniSpi_H_

#include "QTFtdcUserApi.h"
#include "JniUtil.h"

#if defined(TRADERJNI_IS_LIB) && defined(WIN32)
#ifdef LIB_TRADER_JNI_API_EXPORT
#define TRADER_JNI_EXPORT __declspec(dllexport)
#else
#define TRADER_JNI_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_JNI_EXPORT 
#endif

class TraderJniSpi : public CQTFtdcUserSpi
{
public:
    // ���캯������Ҫһ����Ч��ָ��CFtdcMduserApiʵ����ָ��
    TraderJniSpi(CQTFtdcUserApi *userApi,
				const CQTFtdcReqUserLoginField &pReqUserLogin,
				JavaVM *vm,jobject jniTemplate);
    ~TraderJniSpi();
    // ���ͻ��������鷢��������������ͨ�����ӣ��ͻ�����Ҫ���е�¼
    void OnFrontConnected();

    // ���ͻ��������鷢��������ͨ�����ӶϿ�ʱ���÷���������
    void OnFrontDisconnected(int nReason);

    // ���ͻ��˷�����¼����֮�󣬸÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ�
    void OnRspUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//��ȡ��һ�����ر������
	virtual int nextOrderLocalID();

	///����Ӧ��
	void OnRspError(CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û������޸�Ӧ��
    virtual void OnRspUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��Ӧ��
	void OnRspOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	void OnRspOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ա�ʽ��ѯӦ��
    void OnRspQryPartAccount(CQTFtdcRspPartAccountField *pRspPartAccount, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ��ֲֲ�ѯӦ��
	virtual void OnRspQryClientPosition(CQTFtdcRspClientPositionField *pRspClientPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///������ѯӦ��
	virtual void OnRspQryOrder(CQTFtdcOrderField *pOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CQTFtdcTradeField *pTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û���¼���Ӧ��
	virtual void OnRspCheckUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///IPO����¼��
	virtual void OnRspIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///IPO�����޸ķ���
	virtual void OnRspIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����ɽ����걨Ӧ��
	virtual void OnRspOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ֲֻ�תӦ��
	virtual void OnRspPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û������Ӧ��
    virtual void OnRspAccountDeposit(CQTFtdcInvestorDepositResField *pInvestorDepositRes, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����������ͬ��״̬�ı�Ӧ��
	virtual void OnRspSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ǿ���û��˳�Ӧ��
	virtual void OnRspForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����û��޸�Ӧ��
	virtual void OnRspUserAction(CQTFtdcUserActionField *pUserAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
private:
	
    // ָ��CFtdcMduserApiʵ����ָ��
    CQTFtdcUserApi *m_userApi;
	CQTFtdcReqUserLoginField m_pReqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	int	m_maxOrderLocalID;
	jobject m_jniTemplate;
	 
};

#endif