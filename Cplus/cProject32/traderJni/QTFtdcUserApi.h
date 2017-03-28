/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file QTFtdcUserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(QT_FTDCUSERAPI_H)
#define QT_FTDCUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QTFtdcUserApiStruct.h"

#if defined(USERAPI_IS_LIB) && defined(WIN32)
#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif
#else
#define USER_API_EXPORT 
#endif


class CQTFtdcUserSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};

	///û��Ȩ�޵Ķಥ��������
	///@param nTopicID ���������
	virtual void OnStopMultiTopic(int nTopicID){};
	

	///����Ӧ��
	virtual void OnRspError(CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CQTFtdcRspUserLogoutField *pRspUserLogout, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲���Ӧ��
	virtual void OnRspQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OTC����¼��Ӧ��
	virtual void OnRspOTCOrderInsert(CQTFtdcOTCOrderField *pOTCOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ������¼��Ӧ��
	virtual void OnRspExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ���������Ӧ��
	virtual void OnRspExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������¼��Ӧ��
	virtual void OnRspAdminOrderInsert(CQTFtdcInputAdminOrderField *pInputAdminOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ǳ���ϱ���¼��Ӧ��
	virtual void OnRspCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CQTFtdcDisseminationField *pDissemination, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ӧ��
	virtual void OnRspBulletin(CQTFtdcBulletinField *pBulletin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������������ϢӦ��
	virtual void OnRspInformation(CQTFtdcInformationField *pInformation, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����״̬�ı�Ӧ��
	virtual void OnRspInstrumentStatusUpdate(CQTFtdcInstrumentStatusField *pInstrumentStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ǿ���û��˳�Ӧ��
	virtual void OnRspForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��Ựɾ��Ӧ��
	virtual void OnRspForceUserLogout(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������ͬ��״̬�ı�Ӧ��
	virtual void OnRspExchangeDataSyncStatusUpdate(CQTFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������ͬ��״̬�ı�Ӧ��
	virtual void OnRspSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ʽ��ѯӦ��
	virtual void OnRspQryPartAccount(CQTFtdcRspPartAccountField *pRspPartAccount, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CQTFtdcOrderField *pOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲�ѯӦ��
	virtual void OnRspQryQuote(CQTFtdcQuoteField *pQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CQTFtdcTradeField *pTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ͻ���ѯӦ��
	virtual void OnRspQryClient(CQTFtdcRspClientField *pRspClient, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ֲֲ�ѯӦ��
	virtual void OnRspQryPartPosition(CQTFtdcRspPartPositionField *pRspPartPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ��ֲֲ�ѯӦ��
	virtual void OnRspQryClientPosition(CQTFtdcRspClientPositionField *pRspClientPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CQTFtdcRspInstrumentField *pRspInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����״̬��ѯӦ��
	virtual void OnRspQryInstrumentStatus(CQTFtdcInstrumentStatusField *pInstrumentStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������״̬��ѯӦ��
	virtual void OnRspQrySGDataSyncStatus(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ֵ���Ӧ��
	virtual void OnRspQryHedgeVolume(CQTFtdcHedgeVolumeField *pHedgeVolume, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����޶��ѯӦ��
	virtual void OnRspQryCreditLimit(CQTFtdcCreditLimitField *pCreditLimit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ǳ���ϱ�����ѯӦ��
	virtual void OnRspQryCombOrder(CQTFtdcCombOrderField *pCombOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ͨ�����ѯӦ��
	virtual void OnRspQryMarketData(CQTFtdcMarketDataField *pMarketData, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����������ѯ����Ӧ��
	virtual void OnRspQryBulletin(CQTFtdcBulletinField *pBulletin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CQTFtdcDisseminationField *pDissemination, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û����߲�ѯӦ��
	virtual void OnRspQryUserSession(CQTFtdcUserSessionField *pUserSession, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���ѯӦ��
	virtual void OnRspQryUser(CQTFtdcUserField *pUser, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��ѯӦ��
	virtual void OnRspQryParticipant(CQTFtdcParticipantField *pParticipant, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��λ��ѯӦ��
	virtual void OnRspQryMBLMarketData(CQTFtdcMBLMarketDataField *pMBLMarketData, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ϣ��ѯӦ��
	virtual void OnRspQryInformation(CQTFtdcInformationField *pInformation, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CQTFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CQTFtdcOrderField *pOrder) {};

	///ִ������ر�
	virtual void OnRtnExecOrder(CQTFtdcExecOrderField *pExecOrder) {};

	///���ۻر�
	virtual void OnRtnQuote(CQTFtdcQuoteField *pQuote) {};

	///�Ǳ���ϱ����ر�
	virtual void OnRtnCombOrder(CQTFtdcCombOrderField *pCombOrder) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CQTFtdcInstrumentStatusField *pInstrumentStatus) {};

	///���Ӻ�Լ֪ͨ
	virtual void OnRtnInsInstrument(CQTFtdcInstrumentField *pInstrument) {};

	///ɾ����Լ֪ͨ
	virtual void OnRtnDelInstrument(CQTFtdcInstrumentField *pInstrument) {};

	///���Ӻ�Լ����֪ͨ
	virtual void OnRtnInsCombinationLeg(CQTFtdcCombinationLegField *pCombinationLeg) {};

	///ɾ����Լ����֪ͨ
	virtual void OnRtnDelCombinationLeg(CQTFtdcCombinationLegField *pCombinationLeg) {};

	///��������֪ͨ
	virtual void OnRtnAliasDefine(CQTFtdcAliasDefineField *pAliasDefine) {};

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CQTFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///����֪ͨ
	virtual void OnRtnBulletin(CQTFtdcBulletinField *pBulletin) {};

	///��ͨ����֪ͨ
	virtual void OnRtnMarketData(CQTFtdcMarketDataField *pMarketData) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CQTFtdcDepthMarketDataField *pDepthMarketData) {};

	///������֪ͨ
	virtual void OnRtnAdminOrder(CQTFtdcAdminOrderField *pAdminOrder) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo) {};

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, CQTFtdcRspInfoField *pRspInfo) {};

	///���۲�������ر�
	virtual void OnErrRtnQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, CQTFtdcRspInfoField *pRspInfo) {};

	///ִ������¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///ִ�������������ر�
	virtual void OnErrRtnExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, CQTFtdcRspInfoField *pRspInfo) {};

	///�Ǳ���ϱ���¼�����ر�
	virtual void OnErrRtnCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///ѯ��Ӧ��
	virtual void OnRspForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ѯ��֪ͨ
	virtual void OnRtnForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote) {};

	///�����ڴ������Ӧ��
	virtual void OnRspDumpMemTable(CQTFtdcDumpMemTableField *pDumpMemTable, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO����¼��
	virtual void OnRspIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO��Ʒ��Ϣ��ѯ
	virtual void OnRspQryIPOInstrument(CQTFtdcIPOInstrumentField *pIPOInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO�����޸ķ���
	virtual void OnRspIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO�����������ر�
	virtual void OnErrRtnIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///IPO�����޸Ĵ���ر�
	virtual void OnErrRtnIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo) {};

	///IPO��Լ�޸ķ���
	virtual void OnRspIPOInstAction(CQTFtdcIPOInstrumentField *pIPOInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO������ѯӦ��
	virtual void OnRspQryIPOOrder(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼���Ӧ��
	virtual void OnRspCheckUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������Ӧ��
	virtual void OnRspAccountDeposit(CQTFtdcInvestorDepositResField *pInvestorDepositRes, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɽ����걨Ӧ��
	virtual void OnRspOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ɽ��ر�
	virtual void OnRtnOTCTrade(CQTFtdcOTCTradeField *pOTCTrade) {};

	///����ɽ�����ر�
	virtual void OnErrRtnOTCTrade(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo) {};

	///�ֲֻ�תӦ��
	virtual void OnRspPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֲֻ�תӦ��
	virtual void OnErrRtnPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo) {};

	///ע��ֵ�Ӧ��
	virtual void OnRspPickRequestInsert(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������ᡢ�������͡�ȷ�����͵�Ӧ��
	virtual void OnRspPickRequestAction(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֵ�����
	virtual void OnRspDepotTrans(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֵ���ѯ����
	virtual void OnRspQryPickRequest(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֲֻ�ת��ѯӦ��
	virtual void OnRspQryPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ڽ��ס��ֲֹ�����ѯӦ��
	virtual void OnRspQryOTCTrade(CQTFtdcOTCTradeField *pOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��
	virtual void OnRspQryAccountDepositDetail(CQTFtdcAccountDepositDetailField *pAccountDepositDetail, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����û��޸�Ӧ��
	virtual void OnRspUserAction(CQTFtdcUserActionField *pUserAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ڽ��ס��ֲֹ�����ͨͶ���߲�ѯӦ��
	virtual void OnRspQryOtherTrade(CQTFtdcOTCTradeField *pOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class USER_API_EXPORT CQTFtdcUserApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@param pszUserApiType UserAPI����
	///@return ��������UserApi
	static CQTFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;

	//�ಥ���ÿ���
	virtual void SetMultiCast(bool bMultiCast=false) = 0;
	virtual void RegMultiTopicID(int TopicID)=0;
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init(int nPrivatePort) = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CQTFtdcUserSpi *pSpi) = 0;
	
	///����֤��
	///@param pszCertFileName �û�֤���ļ���
	///@param pszKeyFileName �û�˽Կ�ļ���
	///@param pszCaFileName ������CA֤���ļ���
	///@param pszKeyFilePassword �û�˽Կ�ļ�����
	///@return 0 �����ɹ�
	///@return -1 ������CA֤������ʧ��
	///@return -2 �û�֤������ʧ��
	///@return -3 �û�˽Կ����ʧ��	
	///@return -4 �û�֤��У��ʧ��
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword) = 0;
	
	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        QT_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QT_TERT_RESUME:���ϴ��յ�������
	///        QT_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, QT_TE_RESUME_TYPE nResumeType) = 0;

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        QT_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QT_TERT_RESUME:���ϴ��յ�������
	///        QT_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        QT_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QT_TERT_RESUME:���ϴ��յ�������
	///        QT_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ���Ա����
	///@param nResumeType ����Ա���ش���ʽ  
	///        QT_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QT_TERT_RESUME:���ϴ��յ�������
	///        QT_TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeUserTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///����������ʱʱ�䡣
	///@param timeout ������ʱʱ��(��)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///��������־�ļ�
	///@param pszReqLogFileName ������־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///��Ӧ����־�ļ�
	///@param pszRspLogFileName Ӧ����־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;
	
	///����ѯ������
	///@param nResumeType ѯ�����ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:ֻ���͵�¼��ѯ����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�ѯ���������ݡ�	
	virtual void SubscribeForQuote(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///�û���¼����
	virtual int ReqUserLogin(CQTFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CQTFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CQTFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CQTFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///����¼������
	virtual int ReqQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///���۲�������
	virtual int ReqQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///OTC����¼������
	virtual int ReqOTCOrderInsert(CQTFtdcOTCOrderField *pOTCOrder, int nRequestID) = 0;

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///ִ������¼������
	virtual int ReqExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///ִ�������������
	virtual int ReqExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, int nRequestID) = 0;

	///������¼������
	virtual int ReqAdminOrderInsert(CQTFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID) = 0;

	///�Ǳ���ϱ���¼������
	virtual int ReqCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CQTFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///��������������
	virtual int ReqBulletin(CQTFtdcBulletinField *pBulletin, int nRequestID) = 0;

	///��������Ϣ����
	virtual int ReqInformation(CQTFtdcInformationField *pInformation, int nRequestID) = 0;

	///��Լ����״̬�ı�����
	virtual int ReqInstrumentStatusUpdate(CQTFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID) = 0;

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CQTFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///����������ͬ��״̬�ı�����
	virtual int ReqExchangeDataSyncStatusUpdate(CQTFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID) = 0;

	///����������ͬ��״̬�ı�����
	virtual int ReqSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID) = 0;

	///��Ա�ʽ��ѯ����
	virtual int ReqQryPartAccount(CQTFtdcQryPartAccountField *pQryPartAccount, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CQTFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///���۲�ѯ����
	virtual int ReqQryQuote(CQTFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CQTFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///��Ա�ͻ���ѯ����
	virtual int ReqQryClient(CQTFtdcQryClientField *pQryClient, int nRequestID) = 0;

	///��Ա�ֲֲ�ѯ����
	virtual int ReqQryPartPosition(CQTFtdcQryPartPositionField *pQryPartPosition, int nRequestID) = 0;

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPosition(CQTFtdcQryClientPositionField *pQryClientPosition, int nRequestID) = 0;

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CQTFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///��Լ����״̬��ѯ����
	virtual int ReqQryInstrumentStatus(CQTFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID) = 0;

	///������״̬��ѯ����
	virtual int ReqQrySGDataSyncStatus(CQTFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID) = 0;

	///��ֵ��Ȳ�ѯ
	virtual int ReqQryHedgeVolume(CQTFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID) = 0;

	///�����޶��ѯ����
	virtual int ReqQryCreditLimit(CQTFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID) = 0;

	///�Ǳ���ϱ�����ѯ����
	virtual int ReqQryCombOrder(CQTFtdcQryCombOrderField *pQryCombOrder, int nRequestID) = 0;

	///��ͨ�����ѯ����
	virtual int ReqQryMarketData(CQTFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///�����������ѯ����
	virtual int ReqQryBulletin(CQTFtdcQryBulletinField *pQryBulletin, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CQTFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�û����߲�ѯ����
	virtual int ReqQryUserSession(CQTFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///�û���ѯ����
	virtual int ReqQryUser(CQTFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///��Ա��ѯ����
	virtual int ReqQryParticipant(CQTFtdcQryParticipantField *pQryParticipant, int nRequestID) = 0;

	///��Լ��λ��ѯ
	virtual int ReqQryMBLMarketData(CQTFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID) = 0;

	///��Ϣ��ѯ
	virtual int ReqQryInformation(CQTFtdcQryInformationField *pQryInformation, int nRequestID) = 0;

	///ѯ������
	virtual int ReqForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote, int nRequestID) = 0;

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPositionV1(CQTFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID) = 0;

	///�����ڴ������
	virtual int ReqDumpMemTable(CQTFtdcDumpMemTableField *pDumpMemTable, int nRequestID) = 0;

	///IPO����¼��
	virtual int ReqIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, int nRequestID) = 0;

	///IPO��Ʒ��Ϣ��ѯ
	virtual int ReqQryIPOInstrument(CQTFtdcQryIPOInstrumentField *pQryIPOInstrument, int nRequestID) = 0;

	///IPO�����޸�����
	virtual int ReqIPOAction(CQTFtdcIPOActionField *pIPOAction, int nRequestID) = 0;

	///IPO��Լ�޸�����
	virtual int ReqIPOInstAction(CQTFtdcIPOInstrumentField *pIPOInstrument, int nRequestID) = 0;

	///IPO������ѯ����
	virtual int ReqQryIPOOrder(CQTFtdcQryIPOOrderField *pQryIPOOrder, int nRequestID) = 0;

	///�û���¼�������
	virtual int ReqCheckUserLogin(CQTFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///�û����������
	virtual int ReqAccountDeposit(CQTFtdcInvestorDepositField *pInvestorDeposit, int nRequestID) = 0;

	///����ɽ����걨
	virtual int ReqOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, int nRequestID) = 0;

	///�ֲֻ�ת����
	virtual int ReqPositionChange(CQTFtdcPositionChangeField *pPositionChange, int nRequestID) = 0;

	///ע��ֵ�����
	virtual int ReqPickRequestInsert(CQTFtdcPickRequestField *pPickRequest, int nRequestID) = 0;

	///��������������ᡢ�������͡�ȷ�����͵�����
	virtual int ReqPickRequestAction(CQTFtdcPickRequestField *pPickRequest, int nRequestID) = 0;

	///�ֵ�����
	virtual int ReqDepotTrans(CQTFtdcPositionChangeField *pPositionChange, int nRequestID) = 0;

	///�ֵ���ѯ����
	virtual int ReqQryPickRequest(CQTFtdcQryPickRequestField *pQryPickRequest, int nRequestID) = 0;

	///�ֲֻ�ת��ѯ����
	virtual int ReqQryPositionChange(CQTFtdcQryPositionChangeField *pQryPositionChange, int nRequestID) = 0;

	///���ڽ��ס��ֲֹ�����ѯ����
	virtual int ReqQryOTCTrade(CQTFtdcQryOTCTradeField *pQryOTCTrade, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryAccountDepositDetail(CQTFtdcQryAccountDepositDetailField *pQryAccountDepositDetail, int nRequestID) = 0;

	///�����û��޸�����
	virtual int ReqUserAction(CQTFtdcUserActionField *pUserAction, int nRequestID) = 0;

	///���ڽ��ס��ֲֹ�����ͨͶ���߲�ѯ����
	virtual int ReqQryOtherTrade(CQTFtdcQryOtherTradeField *pQryOtherTrade, int nRequestID) = 0;
protected:
	~CQTFtdcUserApi(){};
};


#endif
