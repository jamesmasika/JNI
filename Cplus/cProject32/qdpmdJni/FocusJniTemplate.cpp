
#define DLL_IMPLEMENT

#include "com_quantdo_qdpmd_jni_FocusMDJniTemplate.h"
#include "JniUtil.h"
#include "FocusClient.h"
#include "FocusHandler.h"


#include "FocusFtdcUserApi.h"
#include "FocusFtdcUserApiDataType.h"
#include "FocusFtdcUserApiStruct.h"
#include "stdio.h"
#include "string.h"

JavaVM *Global_vm;
CFocusMDClient *Global_mdClient;
jobject Global_jniTemplate;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
	Global_vm = vm;
	return JNI_VERSION_1_8;
}

/*
* Class:     com_quantdo_qsp_jni_FocusJniTemplate
* Method:    ncFocusMdInit
* Signature: (Ljava/lang/String;)V
Java_com_quantdo_focusmd_jni_ncFocusMdInit
*/
JNIEXPORT void JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_ncFocusMdInit
(JNIEnv *env, jclass jcls, jstring j_frontAddr, jstring j_userId, jstring j_password) {

	JniUtil jniUtil;
	Global_jniTemplate = jniUtil.initClassHelper(env, "com/quantdo/focusmd/jni");
	jniUtil.print(env, Global_jniTemplate, "qdp��ʼ����ʼ..");

	CFocusMDClient *mdClient = new CFocusMDClient();
	Global_mdClient = mdClient;
	const char *frontAddr = env->GetStringUTFChars(j_frontAddr, NULL);
	const char *userId = env->GetStringUTFChars(j_userId, NULL);
	const char *password = env->GetStringUTFChars(j_password, NULL);
	const char *brokerId = "";//env->GetStringUTFChars(j_brokerId, NULL);
	int j_topicId = 1;
	Global_mdClient->InitInstance((char *)frontAddr, (char *)userId, (char *)password, (char *)brokerId, j_topicId, Global_vm, Global_jniTemplate);

	env->ReleaseStringUTFChars(j_frontAddr, frontAddr);
	env->ReleaseStringUTFChars(j_userId, userId);
	env->ReleaseStringUTFChars(j_password, password);
	//env->ReleaseStringUTFChars(j_brokerId, brokerId);

	jniUtil.print(env, Global_jniTemplate, "qdp��ʼ������..");
}

/*
* Class:     com_quantdo_qsp_jni_FocusJniTemplate
* Method:    ncFocusMdDestory
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_ncFocusMdDestory
(JNIEnv *env, jclass jcls) {
	JniUtil jniUtil;
	jniUtil.print(env, Global_jniTemplate, "qdpע����ʼ..\n");
	if (Global_mdClient != NULL) {
		Global_mdClient->ExitInstance();
		delete Global_mdClient;
	}
	jniUtil.print(env, Global_jniTemplate, "qdpע������..\n");
}

JNIEXPORT jint JNICALL Java_com_quantdo_focusmd_jni_FocusMDJniTemplate_login
(JNIEnv *env, jclass jcls, jobject obj, jint Reqid)
{

	JniUtil jniUtil;
	//Global_jniTemplate = jniUtil.initClassHelper(env, "com/quantdo/focusmd/jni");
	jniUtil.print(env, Global_jniTemplate, "login start>");
	int result = -1;
	result = Global_mdClient->getFocusMDHandler()->reqUserLogin(env, obj, Reqid);
	//result = Global_mdClient->getFocusMDHandler()->reqCalcBarrierOption();
	//result = Global_mdClient->
	//���ͷ�  string ��Դ
	//env->ReleaseStringUTFChars(funName, c_funName);
	if (result != 0) {
		jniUtil.print(env, Global_jniTemplate, "������ʧ��>");
	}
	else {
		jniUtil.print(env, Global_jniTemplate, "�����ͳɹ�>");
	}

	jniUtil.print(env, Global_jniTemplate, "login end>");
	return result;

}