#include "TraderJniClient.h"
#include "QTFtdcUserApi.h"
#include "TraderJniSpi.h"
#include <string.h>

bool TraderJniClient::InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,JavaVM *vm,jobject jniTemplate){
	// ����һ��CQspFtdcUserApiʵ��
	this->m_userApi = CQTFtdcUserApi::CreateFtdcUserApi("","");
	this->m_traderJniApi = new TraderJniApi(this->m_userApi);
	// ��¼��Ϣ
	CQTFtdcReqUserLoginField pReqUserLogin;
	//��ʼ���������
	memset(&pReqUserLogin, 0, sizeof(CQTFtdcReqUserLoginField));
	strcpy(pReqUserLogin.UserID,userId);
	strcpy(pReqUserLogin.Password,password);
	strcpy(pReqUserLogin.ParticipantID,"");
	// ����һ���¼������ʵ��
	this->m_traderJniSpi = new TraderJniSpi(this->m_userApi,pReqUserLogin,vm,jniTemplate);
	// ע��һ�¼������ʵ��
	this->m_userApi->RegisterSpi(this->m_traderJniSpi);

	// ���ý���������ĵ�ַ
	char frontAddrBuff[300];
	sprintf(frontAddrBuff,"%s",frontAddr);
    char *tokseps = ",";
    char *tempFrontAddr = NULL;
    tempFrontAddr = strtok(frontAddrBuff,tokseps);
    while(tempFrontAddr!=NULL){		
        this->m_userApi->RegisterFront(tempFrontAddr);
        tempFrontAddr = strtok(NULL,tokseps);
    }
	
	//��ʼ��
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
