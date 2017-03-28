#include "com_quantdo_trader_jni_TraderJniTemplate.h"
#include "JniUtil.h"
#include "TraderJniClient.h"
#include <string.h>

JavaVM *Global_vm;
TraderJniClient *Global_traderJniClient;
jobject Global_jniTemplate;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved){	
	Global_vm = vm;
	return JNI_VERSION_1_8;
}

/*
 * Class:     com_quantdo_trader_jni_TraderJniTemplate
 * Method:    ncTraderInit
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_quantdo_trader_jni_TraderJniTemplate_ncTraderInit
  (JNIEnv *env, jclass jcls, jstring frontAddr, jstring userId, jstring password, jstring brokerId){
	  JniUtil jniUtil;	  
	  Global_jniTemplate = jniUtil.initClassHelper(env,"com/quantdo/trader/jni/TraderJniTemplate");	  
	  jniUtil.print(env,Global_jniTemplate,"trader��ʼ����ʼ..");
	  Global_traderJniClient = new TraderJniClient();	  
	  const char *c_frontAddr = env->GetStringUTFChars(frontAddr,NULL);
	  const char *c_userId = env->GetStringUTFChars(userId,NULL);
	  const char *c_password = env->GetStringUTFChars(password,NULL);
	  const char *c_brokerId = env->GetStringUTFChars(brokerId,NULL);

	  Global_traderJniClient->InitInstance((char *)c_frontAddr,(char *)c_userId,(char *)c_password,(char *)c_brokerId,Global_vm,Global_jniTemplate);
	  env->ReleaseStringUTFChars(frontAddr,c_frontAddr);
	  env->ReleaseStringUTFChars(userId,c_userId);
	  env->ReleaseStringUTFChars(password,c_password);
	  env->ReleaseStringUTFChars(brokerId,c_brokerId);

      jniUtil.print(env,Global_jniTemplate,"trader��ʼ������..");
}

/*
 * Class:     com_quantdo_trader_jni_TraderJniTemplate
 * Method:    ncTraderDestory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_quantdo_trader_jni_TraderJniTemplate_ncTraderDestory
  (JNIEnv *env, jclass jcls){
	  JniUtil jniUtil;	  
	  jniUtil.print(env,Global_jniTemplate,"traderע����ʼ..");
	  if(Global_traderJniClient!=NULL){
		  Global_traderJniClient->ExitInstance();
	      delete Global_traderJniClient;
	  }
	  jniUtil.print(env,Global_jniTemplate,"traderע������..");
}

/*
 * Class:     com_quantdo_trader_jni_TraderJniTemplate
 * Method:    ncReq
 * Signature: (Ljava/lang/String;Ljava/util/Map;I)V
 */
JNIEXPORT void JNICALL Java_com_quantdo_trader_jni_TraderJniTemplate_ncReq
  (JNIEnv *env, jobject jobj, jstring funName, jobject reqMap, jint nRequestID){
	  JniUtil jniUtil;	  
      jniUtil.print(env,Global_jniTemplate,"adjust start>");
      const char *c_funName = env->GetStringUTFChars(funName,NULL);
	  //const char *c_funName = env->G
	  int result = -1;
	  //�û���¼�������
	  if(strcmp(c_funName,"reqCheckUserLogin")==0){
	      jniUtil.print(env,Global_jniTemplate,"exec reqCheckUserLogin>");
		  result = Global_traderJniClient->getTraderJniApi()->reqCheckUserLogin(env,reqMap,nRequestID);
	  //�����޸�
      }else if(strcmp(c_funName,"reqUserPasswordUpdate")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqUserPasswordUpdate>");
		  result = Global_traderJniClient->getTraderJniApi()->reqUserPasswordUpdate(env,reqMap,nRequestID);
	  //����¼��
	  }else if(strcmp(c_funName,"reqOrderInsert")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqOrderInsert>");
		  result = Global_traderJniClient->getTraderJniApi()->reqOrderInsert(env,reqMap,nRequestID);
	  //�����޸�
	  }else if(strcmp(c_funName,"reqOrderAction")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqOrderAction>");
		  result = Global_traderJniClient->getTraderJniApi()->reqOrderAction(env,reqMap,nRequestID);
	  //��Ա�ʽ��ѯ
	  }else if(strcmp(c_funName,"reqQryPartAccount")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqQryPartAccount>");
		  result = Global_traderJniClient->getTraderJniApi()->reqQryPartAccount(env,reqMap,nRequestID);
	  //�ͻ��ֲֲ�ѯ
	  }else if(strcmp(c_funName,"reqQryClientPosition")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqQryClientPosition>");
		  result = Global_traderJniClient->getTraderJniApi()->reqQryClientPosition(env,reqMap,nRequestID);
	  //������ѯ
	  }else if(strcmp(c_funName,"reqQryOrder")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqQryOrder>");
		  result = Global_traderJniClient->getTraderJniApi()->reqQryOrder(env,reqMap,nRequestID);
	  //�ɽ�����ѯ
	  }else if(strcmp(c_funName,"reqQryTrade")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqQryTrade>");
		  result = Global_traderJniClient->getTraderJniApi()->reqQryTrade(env,reqMap,nRequestID);
	   //IPO����¼��
	  }else if(strcmp(c_funName,"reqIPOInsert")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqIPOInsert>");
		  result = Global_traderJniClient->getTraderJniApi()->reqIPOInsert(env,reqMap,nRequestID);
	   //IPO�깺����
	  }else if(strcmp(c_funName,"reqIPOAction")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqIPOAction>");
		  result = Global_traderJniClient->getTraderJniApi()->reqIPOAction(env,reqMap,nRequestID);
	  //���ڽ���\�ֲֹ���
	  }else if(strcmp(c_funName,"reqOTCTradeInsert")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqOTCTradeInsert>");
		  result = Global_traderJniClient->getTraderJniApi()->reqOTCTradeInsert(env,reqMap,nRequestID);
	  //�ֲֶ���/�ⶳ/����/����
	  }else if(strcmp(c_funName,"reqPositionChange")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqPositionChange>");
		  result = Global_traderJniClient->getTraderJniApi()->reqPositionChange(env,reqMap,nRequestID);
	  //�ʽ𶳽ᡢ�ⶳ�������
	  }else if(strcmp(c_funName,"reqAccountDeposit")==0){	  		  
		  jniUtil.print(env,Global_jniTemplate,"exec reqAccountDeposit>");
		  result = Global_traderJniClient->getTraderJniApi()->reqAccountDeposit(env,reqMap,nRequestID);
	  //����������ͬ��״̬
	  }else if(strcmp(c_funName,"reqSGDataSyncStatusUpdate")==0){	  
		  jniUtil.print(env,Global_jniTemplate,"exec reqSGDataSyncStatusUpdate>");
		  result = Global_traderJniClient->getTraderJniApi()->reqSGDataSyncStatusUpdate(env,reqMap,nRequestID);
	  //ǿ���û��˳�����
	  }else if(strcmp(c_funName,"reqForceUserExit")==0){	  
		  jniUtil.print(env,Global_jniTemplate,"exec reqForceUserExit>");
		  result = Global_traderJniClient->getTraderJniApi()->reqForceUserExit(env,reqMap,nRequestID);
	  //�����û��޸�����
	  }else if(strcmp(c_funName,"reqUserAction")==0){	  
		  jniUtil.print(env,Global_jniTemplate,"exec reqUserAction>");
		  result = Global_traderJniClient->getTraderJniApi()->reqUserAction(env,reqMap,nRequestID);
	  }
	  
	  env->ReleaseStringUTFChars(funName,c_funName);
	  if(result!=0){
		  jniUtil.print(env,Global_jniTemplate,"������ʧ��>");
	  }else{
		  jniUtil.print(env,Global_jniTemplate,"�����ͳɹ�>");
	  }	  
	  jniUtil.print(env,Global_jniTemplate,"adjust end>");
}

/*
 * Class:     com_quantdo_trader_jni_TraderJniTemplate
 * Method:    ncNextOrderLocalID
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_quantdo_trader_jni_TraderJniTemplate_ncNextOrderLocalID
  (JNIEnv *env, jobject jobj){
	  int oid = Global_traderJniClient->getTraderJniSpi()->nextOrderLocalID();
	  return oid;
}