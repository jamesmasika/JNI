///@system	 �н�������Դ
///@company  �Ϻ���Ͷ����Ƽ����޹�˾
///@file	 CMs
///@brief	 ����qdpapi�����飬���沢�ṩ�ͻ��˵Ľ���
///@history 
///20160608:  marshal.liu ����
//////////////////////////////////////////////////////////////////////

#ifndef _QdiamClient_H_
#define _QdiamClient_H_

#include "QdamFtdcMdApi.h"
#include "QdiamMDHandler.h"
#include "jni.h"

class CQdiamMDClient
{
public:
	CQdiamMDClient(){};
	~CQdiamMDClient(){};
	//����ϵͳ��ʼ��
	virtual bool InitInstance(char *frontAddr,char *resumeType,int topicId,JavaVM *vm,jobject jniTemplate);
	//����ϵͳ�˳�
	virtual void ExitInstance();	

private:
	QdiamMDHandler *m_mdHandle;
	CQdamFtdcMduserApi *m_pUserApi;
	//���еĶ��ĺ�
	char m_number[256];
};

#endif