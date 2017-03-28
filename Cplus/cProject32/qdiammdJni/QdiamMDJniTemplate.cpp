#include "com_quantdo_qdiammd_jni_QdiamMDJniTemplate.h"
#include "JniUtil.h"
#include "QdiamMDClient.h"
#include "QdiamMDHandler.h"
#include "QdamFtdcMdApi.h"
#include "QdamFtdcUserApiDataType.h"
#include "QdamFtdcUserApiStruct.h"

JavaVM *Global_vm;
CQdiamMDClient *Global_mdClient;
jobject Global_jniTemplate;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved){	
	Global_vm = vm;
	return JNI_VERSION_1_8;
}

/*
 * Class:     com_quantdo_qsp_jni_QdpJniTemplate
 * Method:    ncQdpMdInit
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_quantdo_qdiammd_jni_QdiamMDJniTemplate_ncMdInit
  (JNIEnv *env, jclass jcls, jstring j_frontAddr,jstring j_resumeType,jint j_topicId){

	  JniUtil jniUtil;	  
	  Global_jniTemplate = jniUtil.initClassHelper(env,"com/quantdo/qdiammd/jni/QdiamMDJniTemplate");	  
	  jniUtil.print(env,Global_jniTemplate,"qdiam行情初始化开始..");

	  CQdiamMDClient *mdClient = new CQdiamMDClient();
	  Global_mdClient = mdClient;
	  const char *frontAddr = env->GetStringUTFChars(j_frontAddr,NULL);
	  const char *resumeType = env->GetStringUTFChars(j_resumeType,NULL);

	  Global_mdClient->InitInstance((char *)frontAddr,(char *)resumeType,j_topicId,Global_vm,Global_jniTemplate);

	  env->ReleaseStringUTFChars(j_frontAddr,frontAddr);
	  env->ReleaseStringUTFChars(j_resumeType,resumeType);

	  jniUtil.print(env,Global_jniTemplate,"qdiam行情初始化结束..");
}

/*
 * Class:     com_quantdo_qsp_jni_QdpJniTemplate
 * Method:    ncQdpMdDestory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_quantdo_qdiammd_jni_QdiamMDJniTemplate_ncMdDestory
  (JNIEnv *env, jclass jcls){
	  JniUtil jniUtil;	  
	  jniUtil.print(env,Global_jniTemplate,"qdiam行情注销开始..");
	  if(Global_mdClient!=NULL){
		  Global_mdClient->ExitInstance();
	      delete Global_mdClient;
	  }
	  jniUtil.print(env,Global_jniTemplate,"qdiam行情注销结束..");
}