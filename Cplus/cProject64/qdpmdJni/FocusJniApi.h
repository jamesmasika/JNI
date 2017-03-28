#pragma once
#ifndef _FocusJniApi_H_
#define _FocusJniApi_H_

#include "FocusFtdcUserApi.h"
#include "JniUtil.h"
#include <jni.h>

#if  defined(WIN32)
#ifdef LIB_TRADER_JNI_API_EXPORT
#define TRADER_JNI_EXPORT __declspec(dllexport)
#else
#define TRADER_JNI_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_JNI_EXPORT 
#endif

class  FocusJniApi
{
public:
	FocusJniApi(CFocusFtdcUserApi *userApi);
	~FocusJniApi() {};

	///2017.03.24 add by  wangyl  
	///���㵥����Ȩ����
	virtual int reqCalcOneOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///�����ϰ���Ȩ����
	virtual int reqCalcBarrierOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	///������Ȩ�������
	virtual int reqCalcCombinationOption(JNIEnv *env, jobject reqMap, jint nRequestID);

	virtual int reqUserLogin(JNIEnv *env, jobject reqMap, int nRequestID);

private:
	CFocusFtdcUserApi *m_userApi;
	JniUtil m_jniUtil;
};


class FocusJniSpi : public CFocusFtdcUserSpi
{
	//2017.03.24 add by  wangyl  

	
	FocusJniSpi(CFocusFtdcUserApi *userApi,
		const CFocusFtdcReqUserLoginField &pReqUserLogin,
		JavaVM *vm, jobject jniTemplate)
	{
		this->m_userApi = userApi;
		this->m_pReqUserLogin = pReqUserLogin;
		this->m_vm = vm;
		this->m_env = NULL;
		this->m_jniTemplate = jniTemplate;
		this->m_maxOrderLocalID = 0;
	}
	

	///���㵥����ȨӦ��
	virtual void OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ϰ���ȨӦ��
	virtual void OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///������Ȩ���Ӧ��
	virtual void OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

private:
	CFocusFtdcUserApi *m_userApi;
	CFocusFtdcReqUserLoginField m_pReqUserLogin;
	JavaVM *m_vm;
	JNIEnv* m_env;
	JniUtil m_jniUtil;
	int	m_maxOrderLocalID;
	jobject m_jniTemplate;
};
#endif