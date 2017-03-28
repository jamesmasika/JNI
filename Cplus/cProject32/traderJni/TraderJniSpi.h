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
    // 构造函数，需要一个有效的指向CFtdcMduserApi实例的指针
    TraderJniSpi(CQTFtdcUserApi *userApi,
				const CQTFtdcReqUserLoginField &pReqUserLogin,
				JavaVM *vm,jobject jniTemplate);
    ~TraderJniSpi();
    // 当客户端与行情发布服务器建立起通信连接，客户端需要进行登录
    void OnFrontConnected();

    // 当客户端与行情发布服务器通信连接断开时，该方法被调用
    void OnFrontDisconnected(int nReason);

    // 当客户端发出登录请求之后，该方法会被调用，通知客户端登录是否成功
    void OnRspUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//获取下一个本地报单编号
	virtual int nextOrderLocalID();

	///错误应答
	void OnRspError(CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户密码修改应答
    virtual void OnRspUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单录入应答
	void OnRspOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单操作应答
	void OnRspOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///会员资金查询应答
    void OnRspQryPartAccount(CQTFtdcRspPartAccountField *pRspPartAccount, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///客户持仓查询应答
	virtual void OnRspQryClientPosition(CQTFtdcRspClientPositionField *pRspClientPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单查询应答
	virtual void OnRspQryOrder(CQTFtdcOrderField *pOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///成交单查询应答
	virtual void OnRspQryTrade(CQTFtdcTradeField *pTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户登录检查应答
	virtual void OnRspCheckUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///IPO订单录入
	virtual void OnRspIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///IPO订单修改返回
	virtual void OnRspIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///场外成交对申报应答
	virtual void OnRspOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///持仓划转应答
	virtual void OnRspPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户出入金应答
    virtual void OnRspAccountDeposit(CQTFtdcInvestorDepositResField *pInvestorDepositRes, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///结算组数据同步状态改变应答
	virtual void OnRspSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///强制用户退出应答
	virtual void OnRspForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///交易用户修改应答
	virtual void OnRspUserAction(CQTFtdcUserActionField *pUserAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
private:
	
    // 指向CFtdcMduserApi实例的指针
    CQTFtdcUserApi *m_userApi;
	CQTFtdcReqUserLoginField m_pReqUserLogin;	
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	int	m_maxOrderLocalID;
	jobject m_jniTemplate;
	 
};

#endif