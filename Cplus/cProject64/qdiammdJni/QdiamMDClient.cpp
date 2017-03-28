///@system	 中金所行情源
///@company  上海量投网络科技有限公司
///@file	 CMs
///@brief	 接受中金所的行情，保存并提供客户端的介入
///@history 
///2016/6/8: marshal.liu创建
//////////////////////////////////////////////////////////////////////

#include <string.h>
#include "QdiamMDClient.h"
extern char * INI_FILE_NAME;

bool CQdiamMDClient::InitInstance(char *frontAddr,char *resumeType,int topicId,JavaVM *vm,jobject jniTemplate)
{			 		
	    char buffer[300];				
		CQdamFtdcMduserApi *pUserApi = CQdamFtdcMduserApi::CreateFtdcMduserApi("");		
		CQdamFtdcReqUserLoginField pUserLoginField;
	    //初始化请求对象
	    memset(&pUserLoginField, 0x0, sizeof(CQdamFtdcReqUserLoginField));
		strcpy(pUserLoginField.UserProductInfo, "msQdam");
		strcpy(pUserLoginField.UserID,"");
		strcpy(pUserLoginField.Password,"");
		strcpy(pUserLoginField.BrokerID,"");
		QdiamMDHandler *mdHandle = new QdiamMDHandler(pUserApi,pUserLoginField,vm,jniTemplate);
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
		if(strcmp(resumeType,"QDAM_TERT_RESTART")==0){
			pUserApi->SubscribeMarketDataTopic(topicId, QDAM_TERT_RESTART);
		}else if(strcmp(resumeType,"QDAM_TERT_RESUME")==0){
			pUserApi->SubscribeMarketDataTopic(topicId, QDAM_TERT_RESUME);
		}else{
			pUserApi->SubscribeMarketDataTopic(topicId, QDAM_TERT_QUICK);
		}
		

  		pUserApi->Init();		
		this->m_pUserApi = pUserApi;
		this->m_mdHandle = mdHandle;
		return true;
}

void CQdiamMDClient::ExitInstance()
{	
	m_pUserApi->Release();
	delete m_mdHandle;
}
