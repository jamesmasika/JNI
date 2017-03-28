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

	//�����޸Ľӿ�
	virtual int reqUserPasswordUpdate(JNIEnv *env,jobject reqMap, jint nRequestID);
	//����¼������
	virtual int reqOrderInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	//������������
	virtual int reqOrderAction(JNIEnv *env,jobject reqMap, jint nRequestID);
	//��Ա�ʽ��ѯ����
	virtual int reqQryPartAccount(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�ͻ��ֲֲ�ѯ����
	virtual int reqQryClientPosition(JNIEnv *env,jobject reqMap, jint nRequestID);
	///������ѯ����
	virtual int reqQryOrder(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�ɽ�����ѯ����
	virtual int reqQryTrade(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�û���¼�������
	virtual int reqCheckUserLogin(JNIEnv *env,jobject reqMap, jint nRequestID);
	///IPO����¼��
	virtual int reqIPOInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	///IPO�깺����
	virtual int reqIPOAction(JNIEnv *env,jobject reqMap, jint nRequestID);
	///���ڽ���\�ֲֹ���
	virtual int reqOTCTradeInsert(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�ֲֶ���/�ⶳ/����/����
	virtual int reqPositionChange(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�ʽ𶳽ᡢ�ⶳ�������
	virtual int reqAccountDeposit(JNIEnv *env,jobject reqMap, jint nRequestID);
	///����������ͬ��״̬�ı�����
	virtual int reqSGDataSyncStatusUpdate(JNIEnv *env,jobject reqMap, jint nRequestID);
	///ǿ���û��˳�����
	virtual int reqForceUserExit(JNIEnv *env,jobject reqMap, jint nRequestID);
	///�����û��޸�����
	virtual int reqUserAction(JNIEnv *env,jobject reqMap, jint nRequestID);
private:
	CQTFtdcUserApi *m_userApi;
	JniUtil m_jniUtil;
};

#endif