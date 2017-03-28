#ifndef _TraderJniClient_H_
#define _TraderJniClient_H_

#include <jni.h>
#include "TraderJniApi.h"
#include "TraderJniSpi.h"

class TraderJniClient
{
public:
	TraderJniClient(){};
	~TraderJniClient(){};
	TraderJniApi * getTraderJniApi(){
		return this->m_traderJniApi;
	};
	TraderJniSpi * getTraderJniSpi(){
		return this->m_traderJniSpi;
	};
	//交易系统初始化
	virtual bool InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,JavaVM *vm,jobject jniTemplate);
	//交易系统退出
	virtual void ExitInstance();

private:
	TraderJniSpi *m_traderJniSpi;
	CQTFtdcUserApi *m_userApi;
	TraderJniApi *m_traderJniApi;
};

#endif