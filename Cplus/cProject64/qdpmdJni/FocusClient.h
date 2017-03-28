///@system	 中金所行情源
///@company  上海量投网络科技有限公司
///@file	 CMs
///@brief	 接受qdpapi的行情，保存并提供客户端的介入
///@history 
///20150707:  施凌飞 创建
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

	//行情系统初始化
	virtual bool InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,int topicId,JavaVM *vm,jobject jniTemplate);
	//行情系统退出
	virtual void ExitInstance();	

private:
	FocusMDHandler *m_mdHandle;
	//运行的订阅号
	char m_number[256];
};

#endif