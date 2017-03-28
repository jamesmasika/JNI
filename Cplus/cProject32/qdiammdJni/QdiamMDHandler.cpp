// mdusertest.cpp : 
//һ���򵥵����ӣ�����FtdcMduserApi��FtdcMduserSpi�ӿڵ�ʹ�á�

#include "QdiamMDHandler.h"
#include <string.h>
#include <stdio.h>
#include "JniSystem.h"

extern char *INI_FILE_NAME;

QdiamMDHandler::QdiamMDHandler(CQdamFtdcMduserApi *pUserApi,
						   const CQdamFtdcReqUserLoginField &pUserLoginField,
						  JavaVM *vm,jobject jniTemplate):m_pUserApi(pUserApi)
{
	m_reqUserLogin = pUserLoginField;
	this->m_vm = vm;	
	this->m_env = NULL;
	this->m_jniTemplate = jniTemplate;
}

QdiamMDHandler::~QdiamMDHandler() {}

// ���ͻ��������鷢��������������ͨ�����ӣ��ͻ�����Ҫ���е�¼
void QdiamMDHandler::OnFrontConnected()
{
	if(this->m_env==NULL){
	    JNIEnv* env = NULL;		
        jint result = m_vm->AttachCurrentThreadAsDaemon((void**)&env, NULL);		
		m_jniUtil.print(env,m_jniTemplate,"m_emv create");
		this->m_env = env;	
	}		
	m_jniUtil.print(m_env,m_jniTemplate,"MdQdiam,OnFrontConnected!");	
    m_pUserApi->ReqUserLogin(&m_reqUserLogin, 0);
}

// ���ͻ��������鷢��������ͨ�����ӶϿ�ʱ���÷���������
void QdiamMDHandler::OnFrontDisconnected() 
{
	//��������������API���Զ��������ӣ��ͻ��˿ɲ�������
    //m_jniUtil.print(m_vm,"MsQdp:OnFrontDisconnected.\n");	
}

// ���ͻ��˷�����¼����֮�󣬸÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ�
void QdiamMDHandler::OnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{		
    if (pRspInfo==NULL || pRspInfo->ErrorID != 0)
    {		
		JniSystem jniSystem;
		jniSystem.jniSleep(3);
		m_pUserApi->ReqUserLogin(&m_reqUserLogin, 0);
		return;
    }	
	//const char * pTradingDay = m_pUserApi->GetTradingDay();
	m_jniUtil.print(m_env,m_jniTemplate,"MdQdiam�����½�ɹ�!");	

	//���ĺ�Լ��Ϣ
	char** contracts = new char*[1];
	//char** uncontracts = new char*[1];
	contracts[0]="*";
// 	contracts[1]="IF1212";
// 	contracts[2]="IF1303";

	 
	//uncontracts[0]="EF1511";
	m_pUserApi->SubMarketData(contracts, 1);
	//m_pUserApi->UnSubMarketData(uncontracts, 1);
}
	

///�û��˳�Ӧ��
void QdiamMDHandler::OnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	char buffer[300];
	m_jniUtil.print(m_env,m_jniTemplate,"OnRspUserLogout:\n");
	sprintf(buffer,"UserID:[%s] \n",pRspUserLogout->UserID);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);
	sprintf(buffer,"ParticipantID:[%s] \n",pRspUserLogout->BrokerID);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);
	sprintf(buffer,"ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);	
	sprintf(buffer,"RequestID=[%d], Chain=[%d]\n", nRequestID, bIsLast);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);	    
}

void QdiamMDHandler::OnPackageStart(int nTopicID, int nSequenceNo){}

void QdiamMDHandler::OnPackageEnd(int nTopicID, int nSequenceNo){}

// �������֪ͨ�����������������֪ͨ�ͻ���
void QdiamMDHandler::OnRtnDepthMarketData(CQdamFtdcDepthMarketDataField *pMarketDataReceive) 
{	
	if(pMarketDataReceive==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pMarketDataReceive is null");
		return;
	}
	JNIEnv* env = m_env;    
	jstring jeventType = env->NewStringUTF("marketData");

	jobject jmap = m_jniUtil.newHashMap(env);	
	m_jniUtil.mapPut(env,jmap,"tradingDay",pMarketDataReceive->TradingDay);
	m_jniUtil.mapPut(env,jmap,"preSettlementPrice",pMarketDataReceive->PreSettlementPrice);
	m_jniUtil.mapPut(env,jmap,"preClosePrice",pMarketDataReceive->PreClosePrice);
	m_jniUtil.mapPut(env,jmap,"preOpenInterest",pMarketDataReceive->PreOpenInterest);
	m_jniUtil.mapPut(env,jmap,"preDelta",pMarketDataReceive->PreDelta);
	m_jniUtil.mapPut(env,jmap,"openPrice",pMarketDataReceive->OpenPrice);
	m_jniUtil.mapPut(env,jmap,"highestPrice",pMarketDataReceive->HighestPrice);
	m_jniUtil.mapPut(env,jmap,"lowestPrice",pMarketDataReceive->LowestPrice);	
	m_jniUtil.mapPut(env,jmap,"closePrice",pMarketDataReceive->ClosePrice);
	m_jniUtil.mapPut(env,jmap,"upperLimitPrice",pMarketDataReceive->UpperLimitPrice);
	m_jniUtil.mapPut(env,jmap,"lowerLimitPrice",pMarketDataReceive->LowerLimitPrice);
	m_jniUtil.mapPut(env,jmap,"settlementPrice",pMarketDataReceive->SettlementPrice);
	m_jniUtil.mapPut(env,jmap,"currDelta",pMarketDataReceive->CurrDelta);
	m_jniUtil.mapPut(env,jmap,"lastPrice",pMarketDataReceive->LastPrice);
	m_jniUtil.mapPut(env,jmap,"volume",pMarketDataReceive->Volume);
	m_jniUtil.mapPut(env,jmap,"turnover",pMarketDataReceive->Turnover);
	m_jniUtil.mapPut(env,jmap,"openInterest",pMarketDataReceive->OpenInterest);
	m_jniUtil.mapPut(env,jmap,"bidPrice1",pMarketDataReceive->BidPrice1);	
	m_jniUtil.mapPut(env,jmap,"bidVolume1",pMarketDataReceive->BidVolume1);
	m_jniUtil.mapPut(env,jmap,"bidPrice2",pMarketDataReceive->BidPrice2);
	m_jniUtil.mapPut(env,jmap,"bidVolume2",pMarketDataReceive->BidVolume2);
	m_jniUtil.mapPut(env,jmap,"bidPrice3",pMarketDataReceive->BidPrice3);
	m_jniUtil.mapPut(env,jmap,"bidVolume3",pMarketDataReceive->BidVolume3);
	m_jniUtil.mapPut(env,jmap,"bidPrice4",pMarketDataReceive->BidPrice4);
	m_jniUtil.mapPut(env,jmap,"bidVolume4",pMarketDataReceive->BidVolume4);
	m_jniUtil.mapPut(env,jmap,"bidPrice5",pMarketDataReceive->BidPrice5);
	m_jniUtil.mapPut(env,jmap,"bidVolume5",pMarketDataReceive->BidVolume5);
	m_jniUtil.mapPut(env,jmap,"askPrice1",pMarketDataReceive->AskPrice1);
	m_jniUtil.mapPut(env,jmap,"askVolume1",pMarketDataReceive->AskVolume1);
	m_jniUtil.mapPut(env,jmap,"askPrice2",pMarketDataReceive->AskPrice2);
	m_jniUtil.mapPut(env,jmap,"askVolume2",pMarketDataReceive->AskVolume2);
	m_jniUtil.mapPut(env,jmap,"askPrice3",pMarketDataReceive->AskPrice3);
	m_jniUtil.mapPut(env,jmap,"askVolume3",pMarketDataReceive->AskVolume3);
	m_jniUtil.mapPut(env,jmap,"askPrice4",pMarketDataReceive->AskPrice4);
	m_jniUtil.mapPut(env,jmap,"askVolume4",pMarketDataReceive->AskVolume4);
	m_jniUtil.mapPut(env,jmap,"askPrice5",pMarketDataReceive->AskPrice5);
	m_jniUtil.mapPut(env,jmap,"askVolume5",pMarketDataReceive->AskVolume5);
	m_jniUtil.mapPut(env,jmap,"instrumentID",pMarketDataReceive->InstrumentID);
	m_jniUtil.mapPut(env,jmap,"updateTime",pMarketDataReceive->UpdateTime);
	m_jniUtil.mapPut(env,jmap,"updateMillisec",pMarketDataReceive->UpdateMillisec);	
	m_jniUtil.mapPut(env,jmap,"exchangeID",pMarketDataReceive->ExchangeID);
	m_jniUtil.jcOnEventMsg(env,m_jniTemplate,jeventType,jmap);		

	//�ͷ�Local Reference
	env->DeleteLocalRef(jeventType);
	env->DeleteLocalRef(jmap);
}

// ����û�����ĳ���֪ͨ
void QdiamMDHandler::OnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	char buffer[300];
    m_jniUtil.print(m_env,m_jniTemplate,"OnRspError:\n");
	sprintf(buffer,"ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);	    
    sprintf(buffer,"RequestID=[%d], Chain=[%d]\n", nRequestID, bIsLast);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);    
    // �ͻ�������д�����
}

///���ĺ�Լ�������Ϣ
void QdiamMDHandler::OnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(pSpecificInstrument==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pSpecificInstrument is null");
		return;
	}	
	jstring jeventType = m_env->NewStringUTF("subInstrumentID");	
	jobject jmap = m_jniUtil.newHashMap(m_env);
	if(pSpecificInstrument!=NULL){
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pSpecificInstrument->InstrumentID);	
	}	
	m_jniUtil.jcOnEventMsg(m_env,m_jniTemplate,jeventType,jmap);	

	//�ͷ�Local Reference
	m_env->DeleteLocalRef(jeventType);
	m_env->DeleteLocalRef(jmap);
}

///���ĺ�Լ�������Ϣ
void QdiamMDHandler::OnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	char buffer[300];    
	sprintf(buffer,"UnSub���ض��ĺ�Լ:%s\n",pSpecificInstrument->InstrumentID);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);	
}


void QdiamMDHandler::OnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	char buffer[300];    
	sprintf(buffer,"OnRspQryTopic:%d ,%d\n",pDissemination->SequenceSeries,pDissemination->SequenceNo);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);		
}
