/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company QuantDo
///@file FocusFtdcUserApi.h
///@brief 定义了客户端接口
///@history 
///20150520	徐忠华	创建该文件
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

	//新增多播心跳接口 add by zbz 20150304
	virtual void OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};

	///错误应答
	virtual void OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///强制用户退出应答
	virtual void OnRspForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户会话删除应答
	virtual void OnRspForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求导出内存数据库
	virtual void OnRspDumpMemDB(CFocusFtdcMemDBField *pMemDB, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者资金帐户出入金应答
	virtual void OnRspAccountDeposit(CFocusFtdcRspAccountDepositField *pRspAccountDeposit, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者权限应答
	virtual void OnRspInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///实时上场应答
	virtual void OnRspTBCommand(CFocusFtdcTBCommandField *pTBCommand, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///来回测试应答
	virtual void OnRspPingPong(CFocusFtdcPingPongField *pPingPong, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///审批模式设置应答
	virtual void OnRspSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///深度行情通知
	virtual void OnRtnMultiDepthMarketData(CFocusFtdcDepthMarketDataField *pDepthMarketData) {};

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Topic查询应答
	virtual void OnRspTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///分价行情
	virtual void OnRtnMBLMarketData(CFocusFtdcMBLMarketDataField *pMBLMarketData) {};

	///郑州合约状态
	virtual void OnRtnQmdInstrumentStatu(CFocusFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CFocusFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///成交回报
	virtual void OnRtnTrade(CFocusFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CFocusFtdcOrderField *pOrder) {};

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CFocusFtdcInputOrderField *pInputOrder, CFocusFtdcRspInfoField *pRspInfo) {};

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CFocusFtdcOrderActionField *pOrderAction, CFocusFtdcRspInfoField *pRspInfo) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CFocusFtdcInstrumentStatusField *pInstrumentStatus) {};

	///账户出入金回报
	virtual void OnRtnInvestorAccountDeposit(CFocusFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {};

	///警告消息通知
	virtual void OnRtnMessageNotify(CFocusFtdcMessageNotifyField *pMessageNotify) {};

	///工作流指令通知
	virtual void OnRtnAdviceOrder(CFocusFtdcAdviceOrderField *pAdviceOrder) {};

	///订阅合约交易状态通知
	virtual void OnRtnSubInstrumentStatus(CFocusFtdcSubInstrumentStatusField *pSubInstrumentStatus) {};

	///报单查询应答
	virtual void OnRspQryOrder(CFocusFtdcOrderField *pOrder, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CFocusFtdcTradeField *pTrade, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///可用投资者账户查询应答
	virtual void OnRspQryUserInvestor(CFocusFtdcRspUserInvestorField *pRspUserInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者资金账户查询应答
	virtual void OnRspQryInvestorAccount(CFocusFtdcRspInvestorAccountField *pRspInvestorAccount, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约查询应答
	virtual void OnRspQryInstrument(CFocusFtdcRspInstrumentField *pRspInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所查询应答
	virtual void OnRspQryExchange(CFocusFtdcRspExchangeField *pRspExchange, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者持仓查询应答
	virtual void OnRspQryInvestorPosition(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户查询应答
	virtual void OnRspQryUser(CFocusFtdcRspUserField *pRspUser, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者手续费率查询应答
	virtual void OnRspQryInvestorFee(CFocusFtdcRspInvestorFeeField *pRspInvestorFee, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者保证金率查询应答
	virtual void OnRspQryInvestorMargin(CFocusFtdcRspInvestorMarginField *pRspInvestorMargin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者及其关系查询
	virtual void OnRspQryInvestor(CFocusFtdcRspInvestorField *pRspInvestor, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///账号风险状况应答
	virtual void OnRspQryAccountRisk(CFocusFtdcRspAccountRiskField *pRspAccountRisk, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易用户会话应答
	virtual void OnRspQryUserSession(CFocusFtdcRspUserSessionField *pRspUserSession, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约行情应答
	virtual void OnRspQryMarketData(CFocusFtdcRspMarketDataField *pRspMarketData, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者及其关系查询应答
	virtual void OnRspQryInvestorRelation(CFocusFtdcRspInvestorRelationField *pRspInvestorRelation, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///产品应答
	virtual void OnRspQryProduct(CFocusFtdcRspProductField *pRspProduct, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///工作流交易员查询应答
	virtual void OnRspQryAdviceTrader(CFocusFtdcRspAdviceTraderField *pRspAdviceTrader, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///最大可交易数量查询应答
	virtual void OnRspQryMaxVolume(CFocusFtdcRspMaxVolumeField *pRspMaxVolume, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///组合持仓明细查询应答
	virtual void OnRspQryCmbPositionDetail(CFocusFtdcRspCmbPositionDetailField *pRspCmbPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者结算结果查询应答
	virtual void OnRspQrySettlementInfo(CFocusFtdcRspSettlementInfoField *pRspSettlementInfo, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅合约的相关信息
	virtual void OnRspSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结果集分页查询应答
	virtual void OnRspQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单查询应答(分页)
	virtual void OnRspQryOrderPage(CFocusFtdcOrderField *pOrder, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答(分页)
	virtual void OnRspQryTradePage(CFocusFtdcTradeField *pTrade, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者持仓查询应答(分页)
	virtual void OnRspQryInvestorPositionPage(CFocusFtdcRspInvestorPositionField *pRspInvestorPosition, CFocusFtdcQryResultPageField *pQryResultPage, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///持仓明细查询应答
	virtual void OnRspQryInvestorPositionDetail(CFocusFtdcRspPositionDetailField *pRspPositionDetail, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///理论价行情通知
	virtual void OnRtnTheoryPriceData(CFocusFtdcTheoryPriceDataField *pTheoryPriceData) {};

	///期权指标行情通知
	virtual void OnRtnOptionIndexData(CFocusFtdcOptionIndexDataField *pOptionIndexData) {};

	///设置定价参数应答
	virtual void OnRspSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设置期权理论波动率应答
	virtual void OnRspSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///计算单个期权应答
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///计算障碍期权应答
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///计算期权组合应答
	virtual void OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///波动率拟合应答
	virtual void OnRspVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class USER_API_EXPORT CFocusFtdcUserApi
{
public:
	///创建UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@param pszUserApiType UserAPI类型
	///@return 创建出的UserApi
	static CFocusFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion();
	
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
	virtual void RegisterSpi(CFocusFtdcUserSpi *pSpi) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, FOCUS_TE_RESUME_TYPE nResumeType) = 0;

	///订阅私有流。
	///@param nResumeType 私有流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribePrivateTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅交易员流。
	///@param nResumeType 交易员流重传方式  
	///        FOCUS_TERT_RESTART:从本交易日开始重传
	///        FOCUS_TERT_RESUME:从上次收到的续传
	///        FOCUS_TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeUserTopic(FOCUS_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅交易合约
	///@param char *ppInstrumentID[] 订阅合约列表
	///@param nCount 订阅数量
	///@return 0 操作成功
	virtual int SubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;
	
	///取消订阅交易合约
	///@param char *ppInstrumentID[] 订阅合约列表
	///@param nCount 订阅数量
	///@return 0 操作成功
	virtual int UnSubInstrumentStatus(char *ppInstrumentID[], int nCount) = 0;	
	
	///订阅合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///退订合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;	
	
	
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
	
	///用户登录请求
	virtual int ReqUserLogin(CFocusFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CFocusFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CFocusFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///强制用户退出请求
	virtual int ReqForceUserExit(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///用户会话删除请求
	virtual int ReqForceUserLogout(CFocusFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///请求导出内存数据库
	virtual int ReqDumpMemDB(CFocusFtdcMemDBField *pMemDB, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CFocusFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CFocusFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///投资者资金帐户出入金请求
	virtual int ReqAccountDeposit(CFocusFtdcReqAccountDepositField *pReqAccountDeposit, int nRequestID) = 0;

	///投资者权限请求
	virtual int ReqInvestorRight(CFocusFtdcInvestorRightField *pInvestorRight, int nRequestID) = 0;

	///实时上场请求
	virtual int ReqTBCommand(CFocusFtdcTBCommandField *pTBCommand, int nRequestID) = 0;

	///来回测试请求
	virtual int ReqPingPong(CFocusFtdcPingPongField *pPingPong, int nRequestID) = 0;

	///审批模式设置请求
	virtual int ReqSetAdviceRunMode(CFocusFtdcAdviceRunModeField *pAdviceRunMode, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///Topic查询请求
	virtual int ReqTopicSearch(CFocusFtdcTopicSearchField *pTopicSearch, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///可用投资者账户查询请求
	virtual int ReqQryUserInvestor(CFocusFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

	///投资者资金账户查询请求
	virtual int ReqQryInvestorAccount(CFocusFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///合约查询请求
	virtual int ReqQryInstrument(CFocusFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///交易所查询请求
	virtual int ReqQryExchange(CFocusFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///投资者持仓查询请求
	virtual int ReqQryInvestorPosition(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CFocusFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///用户查询请求
	virtual int ReqQryUser(CFocusFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///投资者手续费率查询请求
	virtual int ReqQryInvestorFee(CFocusFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///投资者保证金率查询请求
	virtual int ReqQryInvestorMargin(CFocusFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///投资者及其关系查询
	virtual int ReqQryInvestor(CFocusFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///账号风险状况查询
	virtual int ReqQryAccountRisk(CFocusFtdcQryAccountRiskField *pQryAccountRisk, int nRequestID) = 0;

	///交易用户会话查询
	virtual int ReqQryUserSession(CFocusFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///合约行情查询
	virtual int ReqQryMarketData(CFocusFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///投资者及其关系查询请求
	virtual int ReqQryInvestorRelation(CFocusFtdcQryInvestorRelationField *pQryInvestorRelation, int nRequestID) = 0;

	///产品查询
	virtual int ReqQryProduct(CFocusFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///工作流交易员查询请求
	virtual int ReqQryAdviceTrader(CFocusFtdcQryAdviceTraderField *pQryAdviceTrader, int nRequestID) = 0;

	///最大可交易数量查询请求
	virtual int ReqQryMaxVolume(CFocusFtdcQryMaxVolumeField *pQryMaxVolume, int nRequestID) = 0;

	///组合持仓明细查询请求
	virtual int ReqQryCmbPositionDetail(CFocusFtdcQryCmbPositionDetailField *pQryCmbPositionDetail, int nRequestID) = 0;

	///投资者结算结果查询请求
	virtual int ReqQrySettlementInfo(CFocusFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubInstrument(CFocusFtdcSubSpecificInstrumentField *pSubSpecificInstrument, int nRequestID) = 0;

	///结果集分页查询请求
	virtual int ReqQryResultPage(CFocusFtdcQryResultPageField *pQryResultPage, int nRequestID) = 0;

	///报单查询请求(分页)
	virtual int ReqQryOrderPage(CFocusFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求(分页)
	virtual int ReqQryTradePage(CFocusFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///投资者持仓查询请求(分页)
	virtual int ReqQryInvestorPositionPage(CFocusFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///持仓明细查询请求
	virtual int ReqQryInvestorPositionDetail(CFocusFtdcQryPositionDetailField *pQryPositionDetail, int nRequestID) = 0;

	///设置定价参数请求
	virtual int ReqSetPricingParam(CFocusFtdcPricingParamField *pPricingParam, int nRequestID) = 0;

	///设置期权理论波动率请求
	virtual int ReqSetOptionTheoryVol(CFocusFtdcOptionTheoryVolField *pOptionTheoryVol, int nRequestID) = 0;

	///计算单个期权请求
	virtual int ReqCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, int nRequestID) = 0;

	///计算障碍期权请求
	virtual int ReqCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, int nRequestID) = 0;

	///计算期权组合请求
	virtual int ReqCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, int nRequestID) = 0;

	///测试行情模拟
	virtual int ReqMarketDataTest(CFocusFtdcDepthMarketDataField *pDepthMarketData, int nRequestID) = 0;

	///波动率拟合请求
	virtual int ReqVolatilityFitting(CFocusFtdcVolatilityFittingField *pVolatilityFitting, int nRequestID) = 0;
protected:
	~CFocusFtdcUserApi(){};
};

#endif
