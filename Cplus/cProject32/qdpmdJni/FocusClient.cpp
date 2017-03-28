///@system	 中金所行情源
///@company  上海量投网络科技有限公司
///@file	 CMs
///@brief	 接受中金所的行情，保存并提供客户端的介入
///@history 
///2015/7/7: 施凌飞创建
//////////////////////////////////////////////////////////////////////

#include <string.h>
#include "FocusClient.h"
extern char * INI_FILE_NAME;

bool CFocusMDClient::InitInstance(char *frontAddr,char *userId,char *password,char *brokerId,int topicId,JavaVM *vm,jobject jniTemplate)
{			 		
	    char buffer[300];				
		CFocusFtdcUserApi *pUserApi = CFocusFtdcUserApi::CreateFtdcUserApi("");		
		CFocusFtdcReqUserLoginField pUserLoginField;
	    //初始化请求对象
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
		
		//订阅				
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
