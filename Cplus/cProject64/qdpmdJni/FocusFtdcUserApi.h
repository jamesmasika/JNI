/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company QuantDo
///@file FocusFtdcUserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20150520	���һ�	�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(FOCUS_FTDCUSERAPI_H)
#define FOCUS_FTDCUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiStruct.h"

#if defined(USERAPI_IS_LIB) && defined(WIN32)
#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif
#else
#define USER_API_EXPORT 
#endif


class CFocusFtdcUserSpi
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

	//�����ಥ�����ӿ� add by zbz 20150304
	virtual void OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};

	///����Ӧ��
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ǿ���û��˳�Ӧ��
	virtual void OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��Ựɾ��Ӧ��
	virtual void OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���󵼳��ڴ����ݿ�
	virtual void OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����ʽ��ʻ������Ӧ��
	virtual void OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ����Ȩ��Ӧ��
	virtual void OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ʵʱ�ϳ�Ӧ��
	virtual void OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ز���Ӧ��
	virtual void OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ģʽ����Ӧ��
	virtual void OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///�������֪ͨ
	virtual void OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Topic��ѯӦ��
	virtual void OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ּ�����
	virtual void OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) {};

	///֣�ݺ�Լ״̬
	virtual void OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///�˻������ر�
	virtual void OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {};

	///������Ϣ֪ͨ
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///������ָ��֪ͨ
	virtual void OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) {};

	///���ĺ�Լ����״̬֪ͨ
	virtual void OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ͷ�����˻���ѯӦ��
	virtual void OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����ʽ��˻���ѯӦ��
	virtual void OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������ѯӦ��
	virtual void OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲֲ߳�ѯӦ��
	virtual void OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���ѯӦ��
	virtual void OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����������ʲ�ѯӦ��
	virtual void OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߱�֤���ʲ�ѯӦ��
	virtual void OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߼����ϵ��ѯ
	virtual void OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˺ŷ���״��Ӧ��
	virtual void OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����û��ỰӦ��
	virtual void OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����Ӧ��
	virtual void OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߼����ϵ��ѯӦ��
	virtual void OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ƷӦ��
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������Ա��ѯӦ��
	virtual void OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ɽ���������ѯӦ��
	virtual void OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϳֲ���ϸ��ѯӦ��
	virtual void OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߽�������ѯӦ��
	virtual void OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������ҳ��ѯӦ��
	virtual void OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��(��ҳ)
	virtual void OnRspQryOrderPage(CFocusFtdcOrderField *pOrder, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��(��ҳ)
	virtual void OnRspQryTradePage(CFocusFtdcTradeField *pTrade, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲֲ߳�ѯӦ��(��ҳ)
	virtual void OnRspQryInvestorPositionPage(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ֲ���ϸ��ѯӦ��
	virtual void OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ۼ�����֪ͨ
	virtual void OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) {};

	///��Ȩָ������֪ͨ
	virtual void OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) {};

	///���ö��۲���Ӧ��
	virtual void OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ȩ���۲�����Ӧ��
	virtual void OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���㵥����ȨӦ��
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ϰ���ȨӦ��
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ȩ���Ӧ��
	virtual void OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������Ӧ��
	virtual void OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class USER_API_EXPORT CFocusFtdcUserApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@param pszUserApiType UserAPI����
	///@return ��������UserApi
	static CFocusFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion();
	
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
	virtual void RegisterSpi(CFocusFtdcUserSpi *pSpi) = 0;
	
	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, FOCUS_TE_RESUME_TYPE nResumeType) = 0;

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ���Ա����
	///@param nResumeType ����Ա���ش���ʽ  
	///        FOCUS_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        FOCUS_TERT_RESUME:���ϴ��յ�������
	///        FOCUS_TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeUserTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ��׺�Լ
	///@param char *ppInstrumentID[] ���ĺ�Լ�б�
	///@param nCount ��������
	///@return 0 �����ɹ�
	virtual int SubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;
	
	///ȡ�����Ľ��׺�Լ
	///@param char *ppInstrumentID[] ���ĺ�Լ�б�
	///@param nCount ��������
	///@return 0 �����ɹ�
	virtual int UnSubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;	
	
	///���ĺ�Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///�˶���Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;	
	
	
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
	
	///�û���¼����
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///���󵼳��ڴ����ݿ�
	virtual int ReqDumpMemDB(CFocusFtdcMemDBField *pMemDB, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///Ͷ�����ʽ��ʻ����������
	virtual int ReqAccountDeposit(CFocusFtdcReqAccountDepositField *pReqAccountDeposit, int nRequestID) = 0;

	///Ͷ����Ȩ������
	virtual int ReqInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, int nRequestID) = 0;

	///ʵʱ�ϳ�����
	virtual int ReqTBCommand(CFocusFtdcTBCommandField *pTBCommand, int nRequestID) = 0;

	///���ز�������
	virtual int ReqPingPong(CFocusFtdcPingPongField *pPingPong, int nRequestID) = 0;

	///����ģʽ��������
	virtual int ReqSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, int nRequestID) = 0;

	///���ĺ�Լ�������Ϣ
	virtual int ReqSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///�˶���Լ�������Ϣ
	virtual int ReqUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///Topic��ѯ����
	virtual int ReqTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///����Ͷ�����˻���ѯ����
	virtual int ReqQryUserInvestor(CFocusFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

	///Ͷ�����ʽ��˻���ѯ����
	virtual int ReqQryInvestorAccount(CFocusFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///��������ѯ����
	virtual int ReqQryExchange(CFocusFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///Ͷ���ֲֲ߳�ѯ����
	virtual int ReqQryInvestorPosition(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�û���ѯ����
	virtual int ReqQryUser(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///Ͷ�����������ʲ�ѯ����
	virtual int ReqQryInvestorFee(CFocusFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///Ͷ���߱�֤���ʲ�ѯ����
	virtual int ReqQryInvestorMargin(CFocusFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///Ͷ���߼����ϵ��ѯ
	virtual int ReqQryInvestor(CFocusFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///�˺ŷ���״����ѯ
	virtual int ReqQryAccountRisk(CFocusFtdcQryAccountRiskField *pQryAccountRisk, int nRequestID) = 0;

	///�����û��Ự��ѯ
	virtual int ReqQryUserSession(CFocusFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///��Լ�����ѯ
	virtual int ReqQryMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///Ͷ���߼����ϵ��ѯ����
	virtual int ReqQryInvestorRelation(CFocusFtdcQryInvestorRelationField *pQryInvestorRelation, int nRequestID) = 0;

	///��Ʒ��ѯ
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///����������Ա��ѯ����
	virtual int ReqQryAdviceTrader(CFocusFtdcQryAdviceTraderField *pQryAdviceTrader, int nRequestID) = 0;

	///���ɽ���������ѯ����
	virtual int ReqQryMaxVolume(CFocusFtdcQryMaxVolumeField *pQryMaxVolume, int nRequestID) = 0;

	///��ϳֲ���ϸ��ѯ����
	virtual int ReqQryCmbPositionDetail(CFocusFtdcQryCmbPositionDetailField *pQryCmbPositionDetail, int nRequestID) = 0;

	///Ͷ���߽�������ѯ����
	virtual int ReqQrySettlementInfo(CFocusFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///���ĺ�Լ�������Ϣ
	virtual int ReqSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///�˶���Լ�������Ϣ
	virtual int ReqUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///�������ҳ��ѯ����
	virtual int ReqQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, int nRequestID) = 0;

	///������ѯ����(��ҳ)
	virtual int ReqQryOrderPage(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����(��ҳ)
	virtual int ReqQryTradePage(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///Ͷ���ֲֲ߳�ѯ����(��ҳ)
	virtual int ReqQryInvestorPositionPage(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///�ֲ���ϸ��ѯ����
	virtual int ReqQryInvestorPositionDetail(CFocusFtdcQryPositionDetailField *pQryPositionDetail, int nRequestID) = 0;

	///���ö��۲�������
	virtual int ReqSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///������Ȩ���۲���������
	virtual int ReqSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///���㵥����Ȩ����
	virtual int ReqCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, int nRequestID) = 0;

	///�����ϰ���Ȩ����
	virtual int ReqCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, int nRequestID) = 0;

	///������Ȩ�������
	virtual int ReqCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, int nRequestID) = 0;

	///��������ģ��
	virtual int ReqMarketDataTest(CFocusFtdcDepthMarketDataField *pDepthMarketData, int nRequestID) = 0;

	///�������������
	virtual int ReqVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, int nRequestID) = 0;
protected:
	~CFocusFtdcUserApi(){};
};

#endif
