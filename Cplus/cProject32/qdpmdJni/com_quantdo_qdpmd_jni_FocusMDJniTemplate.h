/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "JniUtil.h"
#include "FocusClient.h"
#include "FocusHandler.h"


//#include "FocusFtdcMdApi.h"
//#include "FocusFtdcUserApiDataType.h"
//#include "FocusFtdcUserApiStruct.h"

#include "FocusFtdcUserApi.h"
#include "FocusFtdcUserApiDataType.h"
#include "FocusFtdcUserApiStruct.h"

/* Header for class com_quantdo_qsp_jni_FocusJniTemplate */

#ifndef _Included_com_quantdo_qdpmd_jni_FocusMDJniTemplate
#define _Included_com_quantdo_qdpmd_jni_FocusMDJniTemplate

#ifdef DLL_IMPLEMENT

#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
	#endif
	/*
	* Class:     com_quantdo_qsp_jni_FocusJniTemplate
	* Method:    ncFocusMdInit
	* Signature: (Ljava/lang/String;)V
	*/
	JNIEXPORT void JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_ncFocusMdInit
	(JNIEnv *, jclass, jstring, jstring, jstring);

	/*com_quantdo_focusmd_jni
	* Class:     com_quantdo_qsp_jni_FocusJniTemplate
	* Method:    ncFocusMdDestory
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_ncFocusMdDestory
	(JNIEnv *, jclass);

	/*
	* Class:
	* Method:    ncFocusMdDestory
	* Signature: ()V
	*/
	bool DLL_API Client_InitInstance(char *frontAddr, char *userId, char *password, char *brokerId, int topicId);

	/*
	* Class:
	* Method:    ncFocusMdDestory
	* Signature: ()V
	*/

	JNIEXPORT jint JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_login
	(JNIEnv *, jclass, jobject, jint);



	void DLL_API Client_ExitInstance();

	int  DLL_API ReqLogin(char *frontAddr, int userId, char * password);
	
	int  DLL_API ReqCalcOption(int userid, CFocusFtdcInputOrderField *pInputOrder, int nRequestID);
	#ifdef __cplusplus
}
#endif


#endif
