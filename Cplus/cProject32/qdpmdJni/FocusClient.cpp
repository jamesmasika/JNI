///@system	 �н�������Դ
///@company  �Ϻ���Ͷ����Ƽ����޹�˾
///@file	 CMs
///@brief	 �����н��������飬���沢�ṩ�ͻ��˵Ľ���
///@history 
///2015/7/7: ʩ��ɴ���
//////////////////////////////////////////////////////////////////////

#include <string.h>
#include "FocusClient.h"
extern char * INI_FILE_NAME;

bool CFocusMDClient::InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,int topicId,JavaVM *vm,jobject jniTemplate)
{			 		
	    char buffer[300];				
		CFocusFtdcUserApi *pUserApi = CFocusFtdcUserApi::CreateFtdcUserApi("");		
		CFocusFtdcReqUserLoginField pUserLoginField;
	    //��ʼ���������
	    memset(&pUserLoginField, 0, sizeof(CFocusFtdcReqUserLoginField));
		strcpy(pUserLoginField.UserProductInfo, "msFocus");
		strcpy(pUserLoginField.UserID,userId);
		strcpy(pUserLoginField.Password,password);
		strcpy(pUserLoginField.BrokerID,brokerId);
		FocusMDHandler *mdHandle = new FocusMDHandler(pUserApi,pUserLoginField,vm,jniTemplate);
		pUserApi->RegisterSpi(mdHandle);

		//MdFront
	    char frontAddrBuff[300];
	    sprintf(frontAddrBuff,"%s",frontAddr);
        char *tokseps = ",";
        char *tempFrontAddr = NULL;
        tempFrontAddr = strtok(frontAddrBuff,tokseps);
        while(tempFrontAddr!=NULL){		
           pUserApi->RegisterFront(tempFrontAddr);
           tempFrontAddr = strtok(NULL,tokseps);
        }		
		
		//����				
		pUserApi->SubscribeMarketDataTopic(topicId, FOCUS_TERT_RESTART);
		pUserApi->SubscribeMarketDataTopic(200, FOCUS_TERT_RESTART);

  		pUserApi->Init(0);		
		//this->m_pUserApi = pUserApi;
		this->m_mdHandle = mdHandle;
		return true;
}

void CFocusMDClient::ExitInstance()
{	
	//m_pUserApi->Release();
	delete m_mdHandle;
}
