#include "TraderJniClient.h"
#include "QTFtdcUserApi.h"
#include "TraderJniSpi.h"
#include <string.h>

bool TraderJniClient::InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,JavaVM *vm,jobject jniTemplate){
	// 产生一个CQspFtdcUserApi实例
	this->m_userApi = CQTFtdcUserApi::CreateFtdcUserApi("","");
	this->m_traderJniApi = new TraderJniApi(this->m_userApi);
	// 登录信息
	CQTFtdcReqUserLoginField pReqUserLogin;
	//初始化请求对象
	memset(&pReqUserLogin, 0, sizeof(CQTFtdcReqUserLoginField));
	strcpy(pReqUserLogin.UserID,userId);
	strcpy(pReqUserLogin.Password,password);
	strcpy(pReqUserLogin.ParticipantID,"");
	// 产生一个事件处理的实例
	this->m_traderJniSpi = new TraderJniSpi(this->m_userApi,pReqUserLogin,vm,jniTemplate);
	// 注册一事件处理的实例
	this->m_userApi->RegisterSpi(this->m_traderJniSpi);

	// 设置交易所服务的地址
	char frontAddrBuff[300];
	sprintf(frontAddrBuff,"%s",frontAddr);
    char *tokseps = ",";
    char *tempFrontAddr = NULL;
    tempFrontAddr = strtok(frontAddrBuff,tokseps);
    while(tempFrontAddr!=NULL){		
        this->m_userApi->RegisterFront(tempFrontAddr);
        tempFrontAddr = strtok(NULL,tokseps);
    }
	
	//初始化
	this->m_userApi->Init(0);

	return true;
}

void TraderJniClient::ExitInstance(){
	if(this->m_userApi!=NULL){
		this->m_userApi->Release();
	}
	if(this->m_traderJniSpi!=NULL){		
		delete this->m_traderJniSpi;
	}
}
