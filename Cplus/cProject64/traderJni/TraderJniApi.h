#ifndef _TraderJniApi_H_
#define _TraderJniApi_H_

#include "QTFtdcUserApi.h"
#include "JniUtil.h"
#include <jni.h>

#if defined(TRADERJNI_IS_LIB) && defined(WIN32)
#ifdef LIB_TRADER_JNI_API_EXPORT
#define TRADER_JNI_EXPORT __declspec(dllexport)
#else
#define TRADER_JNI_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_JNI_EXPORT 
#endif

class TraderJniApi
{
public:
     TraderJniApi(CQTFtdcUserApi *userApi);
	~TraderJniApi(){};

	//密码修改接口
	virtual int reqUserPasswordUpdate(JNIEnv *env,jobject reqMap, jint nRequestID);
	//报单录入请求
	virtual int reqOrderInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	//报单操作请求
	virtual int reqOrderAction(JNIEnv *env,jobject reqMap, jint nRequestID);
	//会员资金查询请求
	virtual int reqQryPartAccount(JNIEnv *env,jobject reqMap, jint nRequestID);
	///客户持仓查询请求
	virtual int reqQryClientPosition(JNIEnv *env,jobject reqMap, jint nRequestID);
	///报单查询请求
	virtual int reqQryOrder(JNIEnv *env,jobject reqMap, jint nRequestID);
	///成交单查询请求
	virtual int reqQryTrade(JNIEnv *env,jobject reqMap, jint nRequestID);
	///用户登录检查请求
	virtual int reqCheckUserLogin(JNIEnv *env,jobject reqMap, jint nRequestID);
	///IPO订单录入
	virtual int reqIPOInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	///IPO申购撤单
	virtual int reqIPOAction(JNIEnv *env,jobject reqMap, jint nRequestID);
	///大宗交易\持仓过户
	virtual int reqOTCTradeInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	///持仓冻结/解冻/减持/限售
	virtual int reqPositionChange(JNIEnv *env,jobject reqMap, jint nRequestID);
	///资金冻结、解冻、出入金
	virtual int reqAccountDeposit(JNIEnv *env,jobject reqMap, jint nRequestID);
	///结算组数据同步状态改变请求
	virtual int reqSGDataSyncStatusUpdate(JNIEnv *env,jobject reqMap, jint nRequestID);
	///强制用户退出请求
	virtual int reqForceUserExit(JNIEnv *env,jobject reqMap, jint nRequestID);
	///交易用户修改请求
	virtual int reqUserAction(JNIEnv *env,jobject reqMap, jint nRequestID);
private:
	CQTFtdcUserApi *m_userApi;
	JniUtil m_jniUtil;
};

#endif