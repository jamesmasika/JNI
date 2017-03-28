///@system	 �н�������Դ
///@company  �Ϻ���Ͷ����Ƽ����޹�˾
///@file	 CMs
///@brief	 ����qdpapi�����飬���沢�ṩ�ͻ��˵Ľ���
///@history 
///20150707:  ʩ��� ����
//////////////////////////////////////////////////////////////////////

#ifndef _FocusClient_H_
#define _FocusClient_H_

//#include "FocusFtdcMdApi.h"
#include "FocusFtdcUserApi.h"
//#include "FocusJniApi.h"
#include "FocusHandler.h"
#include "jni.h"

class CFocusMDClient
{
public:
	CFocusMDClient(){};
	~CFocusMDClient(){};

	//FocusJniApi * getFocusJniApi() {
	//	return this->m_focusJniApi;
	//};
	//FocusJniSpi * getFocusJniSpi() {
	//	return this->m_focusJniSpi;
	//};



	FocusMDHandler * getFocusMDHandler()
	{
		return this->m_mdHandle;
	}

	//����ϵͳ��ʼ��
	virtual bool InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,int topicId,JavaVM *vm,jobject jniTemplate);
	//����ϵͳ�˳�
	virtual void ExitInstance();	

private:
	FocusMDHandler *m_mdHandle;
	//���еĶ��ĺ�
	char m_number[256];
};

#endif