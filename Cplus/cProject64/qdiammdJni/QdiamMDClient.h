///@system	 中金所行情源
///@company  上海量投网络科技有限公司
///@file	 CMs
///@brief	 接受qdpapi的行情，保存并提供客户端的介入
///@history 
///20160608:  marshal.liu 创建
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
	//行情系统初始化
	virtual bool InitInstance(char *frontAddr,char *resumeType,int topicId,JavaVM *vm,jobject jniTemplate);
	//行情系统退出
	virtual void ExitInstance();	

private:
	QdiamMDHandler *m_mdHandle;
	CQdamFtdcMduserApi *m_pUserApi;
	//运行的订阅号
	char m_number[256];
};

#endif