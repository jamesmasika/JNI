/////////////////////////////////////////////////////////////////////////
///@system 交易所系统
///@company 上海量投网络科技有限公司
///@file QTFtdcUserApi.h
///@brief 定义了客户端接口
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
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};

	///没有权限的多播订阅主题
	///@param nTopicID 被主题代码
	virtual void OnStopMultiTopic(int nTopicID){};
	

	///错误应答
	virtual void OnRspError(CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CQTFtdcRspUserLogoutField *pRspUserLogout, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价录入应答
	virtual void OnRspQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价操作应答
	virtual void OnRspQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OTC报单录入应答
	virtual void OnRspOTCOrderInsert(CQTFtdcOTCOrderField *pOTCOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告录入应答
	virtual void OnRspExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告操作应答
	virtual void OnRspExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///管理报单录入应答
	virtual void OnRspAdminOrderInsert(CQTFtdcInputAdminOrderField *pInputAdminOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非标组合报单录入应答
	virtual void OnRspCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CQTFtdcDisseminationField *pDissemination, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告请求应答
	virtual void OnRspBulletin(CQTFtdcBulletinField *pBulletin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告信息应答
	virtual void OnRspInformation(CQTFtdcInformationField *pInformation, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约交易状态改变应答
	virtual void OnRspInstrumentStatusUpdate(CQTFtdcInstrumentStatusField *pInstrumentStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///强制用户退出应答
	virtual void OnRspForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户会话删除应答
	virtual void OnRspForceUserLogout(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所数据同步状态改变应答
	virtual void OnRspExchangeDataSyncStatusUpdate(CQTFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结算组数据同步状态改变应答
	virtual void OnRspSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员资金查询应答
	virtual void OnRspQryPartAccount(CQTFtdcRspPartAccountField *pRspPartAccount, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单查询应答
	virtual void OnRspQryOrder(CQTFtdcOrderField *pOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价查询应答
	virtual void OnRspQryQuote(CQTFtdcQuoteField *pQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CQTFtdcTradeField *pTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户查询应答
	virtual void OnRspQryClient(CQTFtdcRspClientField *pRspClient, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员持仓查询应答
	virtual void OnRspQryPartPosition(CQTFtdcRspPartPositionField *pRspPartPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户持仓查询应答
	virtual void OnRspQryClientPosition(CQTFtdcRspClientPositionField *pRspClientPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约查询应答
	virtual void OnRspQryInstrument(CQTFtdcRspInstrumentField *pRspInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约交易状态查询应答
	virtual void OnRspQryInstrumentStatus(CQTFtdcInstrumentStatusField *pInstrumentStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结算组状态查询应答
	virtual void OnRspQrySGDataSyncStatus(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保值额度应答
	virtual void OnRspQryHedgeVolume(CQTFtdcHedgeVolumeField *pHedgeVolume, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///信用限额查询应答
	virtual void OnRspQryCreditLimit(CQTFtdcCreditLimitField *pCreditLimit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非标组合报单查询应答
	virtual void OnRspQryCombOrder(CQTFtdcCombOrderField *pCombOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///普通行情查询应答
	virtual void OnRspQryMarketData(CQTFtdcMarketDataField *pMarketData, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告查询请求应答
	virtual void OnRspQryBulletin(CQTFtdcBulletinField *pBulletin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CQTFtdcDisseminationField *pDissemination, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户在线查询应答
	virtual void OnRspQryUserSession(CQTFtdcUserSessionField *pUserSession, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户查询应答
	virtual void OnRspQryUser(CQTFtdcUserField *pUser, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员查询应答
	virtual void OnRspQryParticipant(CQTFtdcParticipantField *pParticipant, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约价位查询应答
	virtual void OnRspQryMBLMarketData(CQTFtdcMBLMarketDataField *pMBLMarketData, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///信息查询应答
	virtual void OnRspQryInformation(CQTFtdcInformationField *pInformation, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交回报
	virtual void OnRtnTrade(CQTFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CQTFtdcOrderField *pOrder) {};

	///执行宣告回报
	virtual void OnRtnExecOrder(CQTFtdcExecOrderField *pExecOrder) {};

	///报价回报
	virtual void OnRtnQuote(CQTFtdcQuoteField *pQuote) {};

	///非标组合报单回报
	virtual void OnRtnCombOrder(CQTFtdcCombOrderField *pCombOrder) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CQTFtdcInstrumentStatusField *pInstrumentStatus) {};

	///增加合约通知
	virtual void OnRtnInsInstrument(CQTFtdcInstrumentField *pInstrument) {};

	///删除合约通知
	virtual void OnRtnDelInstrument(CQTFtdcInstrumentField *pInstrument) {};

	///增加合约单腿通知
	virtual void OnRtnInsCombinationLeg(CQTFtdcCombinationLegField *pCombinationLeg) {};

	///删除合约单腿通知
	virtual void OnRtnDelCombinationLeg(CQTFtdcCombinationLegField *pCombinationLeg) {};

	///别名定义通知
	virtual void OnRtnAliasDefine(CQTFtdcAliasDefineField *pAliasDefine) {};

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CQTFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///公告通知
	virtual void OnRtnBulletin(CQTFtdcBulletinField *pBulletin) {};

	///普通行情通知
	virtual void OnRtnMarketData(CQTFtdcMarketDataField *pMarketData) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CQTFtdcDepthMarketDataField *pDepthMarketData) {};

	///管理报单通知
	virtual void OnRtnAdminOrder(CQTFtdcAdminOrderField *pAdminOrder) {};

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo) {};

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, CQTFtdcRspInfoField *pRspInfo) {};

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, CQTFtdcRspInfoField *pRspInfo) {};

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, CQTFtdcRspInfoField *pRspInfo) {};

	///非标组合报单录入错误回报
	virtual void OnErrRtnCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///询价应答
	virtual void OnRspForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///询价通知
	virtual void OnRtnForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote) {};

	///导出内存表请求应答
	virtual void OnRspDumpMemTable(CQTFtdcDumpMemTableField *pDumpMemTable, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO订单录入
	virtual void OnRspIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO产品信息查询
	virtual void OnRspQryIPOInstrument(CQTFtdcIPOInstrumentField *pIPOInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO订单修改返回
	virtual void OnRspIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO订单插入错误回报
	virtual void OnErrRtnIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo) {};

	///IPO订单修改错误回报
	virtual void OnErrRtnIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo) {};

	///IPO合约修改返回
	virtual void OnRspIPOInstAction(CQTFtdcIPOInstrumentField *pIPOInstrument, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IPO报单查询应答
	virtual void OnRspQryIPOOrder(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录检查应答
	virtual void OnRspCheckUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户出入金应答
	virtual void OnRspAccountDeposit(CQTFtdcInvestorDepositResField *pInvestorDepositRes, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///场外成交对申报应答
	virtual void OnRspOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///场外成交回报
	virtual void OnRtnOTCTrade(CQTFtdcOTCTradeField *pOTCTrade) {};

	///场外成交错误回报
	virtual void OnErrRtnOTCTrade(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo) {};

	///持仓划转应答
	virtual void OnRspPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///持仓划转应答
	virtual void OnErrRtnPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo) {};

	///注册仓单应答
	virtual void OnRspPickRequestInsert(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///提货单撤销、自提、在线配送、确认配送等应答
	virtual void OnRspPickRequestAction(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///仓单过户
	virtual void OnRspDepotTrans(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///仓单查询返回
	virtual void OnRspQryPickRequest(CQTFtdcPickRequestField *pPickRequest, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///持仓划转查询应答
	virtual void OnRspQryPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大宗交易、持仓过户查询应答
	virtual void OnRspQryOTCTrade(CQTFtdcOTCTradeField *pOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///出入金查询应答
	virtual void OnRspQryAccountDepositDetail(CQTFtdcAccountDepositDetailField *pAccountDepositDetail, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易用户修改应答
	virtual void OnRspUserAction(CQTFtdcUserActionField *pUserAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大宗交易、持仓过户普通投资者查询应答
	virtual void OnRspQryOtherTrade(CQTFtdcOTCTradeField *pOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class USER_API_EXPORT CQTFtdcUserApi
{
public:
	///创建UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@param pszUserApiType UserAPI类型
	///@return 创建出的UserApi
	static CQTFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;

	//多播设置开关
	virtual void SetMultiCast(bool bMultiCast=false) = 0;
	virtual void RegMultiTopicID(int TopicID)=0;
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init(int nPrivatePort) = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterFront优先于RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CQTFtdcUserSpi *pSpi) = 0;
	
	///加载证书
	///@param pszCertFileName 用户证书文件名
	///@param pszKeyFileName 用户私钥文件名
	///@param pszCaFileName 可信任CA证书文件名
	///@param pszKeyFilePassword 用户私钥文件密码
	///@return 0 操作成功
	///@return -1 可信任CA证书载入失败
	///@return -2 用户证书载入失败
	///@return -3 用户私钥载入失败	
	///@return -4 用户证书校验失败
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        QT_TERT_RESTART:从本交易日开始重传
	///        QT_TERT_RESUME:从上次收到的续传
	///        QT_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, QT_TE_RESUME_TYPE nResumeType) = 0;

	///订阅私有流。
	///@param nResumeType 私有流重传方式  
	///        QT_TERT_RESTART:从本交易日开始重传
	///        QT_TERT_RESUME:从上次收到的续传
	///        QT_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribePrivateTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        QT_TERT_RESTART:从本交易日开始重传
	///        QT_TERT_RESUME:从上次收到的续传
	///        QT_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅交易员流。
	///@param nResumeType 交易员流重传方式  
	///        QT_TERT_RESTART:从本交易日开始重传
	///        QT_TERT_RESUME:从上次收到的续传
	///        QT_TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeUserTopic(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///打开请求日志文件
	///@param pszReqLogFileName 请求日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///打开应答日志文件
	///@param pszRspLogFileName 应答日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;
	
	///订阅询价流。
	///@param nResumeType 询价流重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:只传送登录后询价流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到询价流的数据。	
	virtual void SubscribeForQuote(QT_TE_RESUME_TYPE nResumeType) = 0;
	
	///用户登录请求
	virtual int ReqUserLogin(CQTFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CQTFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CQTFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CQTFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///报价录入请求
	virtual int ReqQuoteInsert(CQTFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///报价操作请求
	virtual int ReqQuoteAction(CQTFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///OTC报单录入请求
	virtual int ReqOTCOrderInsert(CQTFtdcOTCOrderField *pOTCOrder, int nRequestID) = 0;

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///执行宣告录入请求
	virtual int ReqExecOrderInsert(CQTFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///执行宣告操作请求
	virtual int ReqExecOrderAction(CQTFtdcExecOrderActionField *pExecOrderAction, int nRequestID) = 0;

	///管理报单录入请求
	virtual int ReqAdminOrderInsert(CQTFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID) = 0;

	///非标组合报单录入请求
	virtual int ReqCombOrderInsert(CQTFtdcInputCombOrderField *pInputCombOrder, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CQTFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///交易所公告请求
	virtual int ReqBulletin(CQTFtdcBulletinField *pBulletin, int nRequestID) = 0;

	///交易所信息请求
	virtual int ReqInformation(CQTFtdcInformationField *pInformation, int nRequestID) = 0;

	///合约交易状态改变请求
	virtual int ReqInstrumentStatusUpdate(CQTFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID) = 0;

	///强制用户退出请求
	virtual int ReqForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///用户会话删除请求
	virtual int ReqForceUserLogout(CQTFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///交易所数据同步状态改变请求
	virtual int ReqExchangeDataSyncStatusUpdate(CQTFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID) = 0;

	///结算组数据同步状态改变请求
	virtual int ReqSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID) = 0;

	///会员资金查询请求
	virtual int ReqQryPartAccount(CQTFtdcQryPartAccountField *pQryPartAccount, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CQTFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///报价查询请求
	virtual int ReqQryQuote(CQTFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CQTFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///会员客户查询请求
	virtual int ReqQryClient(CQTFtdcQryClientField *pQryClient, int nRequestID) = 0;

	///会员持仓查询请求
	virtual int ReqQryPartPosition(CQTFtdcQryPartPositionField *pQryPartPosition, int nRequestID) = 0;

	///客户持仓查询请求
	virtual int ReqQryClientPosition(CQTFtdcQryClientPositionField *pQryClientPosition, int nRequestID) = 0;

	///合约查询请求
	virtual int ReqQryInstrument(CQTFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///合约交易状态查询请求
	virtual int ReqQryInstrumentStatus(CQTFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID) = 0;

	///结算组状态查询请求
	virtual int ReqQrySGDataSyncStatus(CQTFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID) = 0;

	///保值额度查询
	virtual int ReqQryHedgeVolume(CQTFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID) = 0;

	///信用限额查询请求
	virtual int ReqQryCreditLimit(CQTFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID) = 0;

	///非标组合报单查询请求
	virtual int ReqQryCombOrder(CQTFtdcQryCombOrderField *pQryCombOrder, int nRequestID) = 0;

	///普通行情查询请求
	virtual int ReqQryMarketData(CQTFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///交易所公告查询请求
	virtual int ReqQryBulletin(CQTFtdcQryBulletinField *pQryBulletin, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CQTFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///用户在线查询请求
	virtual int ReqQryUserSession(CQTFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///用户查询请求
	virtual int ReqQryUser(CQTFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///会员查询请求
	virtual int ReqQryParticipant(CQTFtdcQryParticipantField *pQryParticipant, int nRequestID) = 0;

	///合约价位查询
	virtual int ReqQryMBLMarketData(CQTFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID) = 0;

	///信息查询
	virtual int ReqQryInformation(CQTFtdcQryInformationField *pQryInformation, int nRequestID) = 0;

	///询价请求
	virtual int ReqForQuote(CQTFtdcInputReqForQuoteField *pInputReqForQuote, int nRequestID) = 0;

	///客户持仓查询请求
	virtual int ReqQryClientPositionV1(CQTFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID) = 0;

	///导出内存表请求
	virtual int ReqDumpMemTable(CQTFtdcDumpMemTableField *pDumpMemTable, int nRequestID) = 0;

	///IPO订单录入
	virtual int ReqIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, int nRequestID) = 0;

	///IPO产品信息查询
	virtual int ReqQryIPOInstrument(CQTFtdcQryIPOInstrumentField *pQryIPOInstrument, int nRequestID) = 0;

	///IPO订单修改请求
	virtual int ReqIPOAction(CQTFtdcIPOActionField *pIPOAction, int nRequestID) = 0;

	///IPO合约修改请求
	virtual int ReqIPOInstAction(CQTFtdcIPOInstrumentField *pIPOInstrument, int nRequestID) = 0;

	///IPO报单查询请求
	virtual int ReqQryIPOOrder(CQTFtdcQryIPOOrderField *pQryIPOOrder, int nRequestID) = 0;

	///用户登录检查请求
	virtual int ReqCheckUserLogin(CQTFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///用户出入金请求
	virtual int ReqAccountDeposit(CQTFtdcInvestorDepositField *pInvestorDeposit, int nRequestID) = 0;

	///场外成交对申报
	virtual int ReqOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, int nRequestID) = 0;

	///持仓划转请求
	virtual int ReqPositionChange(CQTFtdcPositionChangeField *pPositionChange, int nRequestID) = 0;

	///注册仓单请求
	virtual int ReqPickRequestInsert(CQTFtdcPickRequestField *pPickRequest, int nRequestID) = 0;

	///提货单撤销、自提、在线配送、确认配送等请求
	virtual int ReqPickRequestAction(CQTFtdcPickRequestField *pPickRequest, int nRequestID) = 0;

	///仓单过户
	virtual int ReqDepotTrans(CQTFtdcPositionChangeField *pPositionChange, int nRequestID) = 0;

	///仓单查询请求
	virtual int ReqQryPickRequest(CQTFtdcQryPickRequestField *pQryPickRequest, int nRequestID) = 0;

	///持仓划转查询请求
	virtual int ReqQryPositionChange(CQTFtdcQryPositionChangeField *pQryPositionChange, int nRequestID) = 0;

	///大宗交易、持仓过户查询请求
	virtual int ReqQryOTCTrade(CQTFtdcQryOTCTradeField *pQryOTCTrade, int nRequestID) = 0;

	///出入金查询请求
	virtual int ReqQryAccountDepositDetail(CQTFtdcQryAccountDepositDetailField *pQryAccountDepositDetail, int nRequestID) = 0;

	///交易用户修改请求
	virtual int ReqUserAction(CQTFtdcUserActionField *pUserAction, int nRequestID) = 0;

	///大宗交易、持仓过户普通投资者查询请求
	virtual int ReqQryOtherTrade(CQTFtdcQryOtherTradeField *pQryOtherTrade, int nRequestID) = 0;
protected:
	~CQTFtdcUserApi(){};
};


#endif
