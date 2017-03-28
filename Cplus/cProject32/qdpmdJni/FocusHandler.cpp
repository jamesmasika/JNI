// mdusertest.cpp : 
//一个简单的例子，介绍FtdcMduserApi和FtdcMduserSpi接口的使用。

#include "FocusHandler.h"
#include <string.h>
#include <stdio.h>
#include "JniSystem.h"

extern char *INI_FILE_NAME;
//FocusMDHandler::FocusMDHandler();
FocusMDHandler::FocusMDHandler(CFocusFtdcUserApi *pUserApi,
						   const CFocusFtdcReqUserLoginField &pUserLoginField,
						  JavaVM *vm,jobject jniTemplate):m_pUserApi(pUserApi)
{
	m_reqUserLogin = pUserLoginField;
	this->m_vm = vm;	
	this->m_env = NULL;
	this->m_jniTemplate = jniTemplate;
}

FocusMDHandler::~FocusMDHandler() {
	this->m_pUserApi->Release();
}

// 当客户端与行情发布服务器建立起通信连接，客户端需要进行登录
void FocusMDHandler::OnFrontConnected()
{
	if(this->m_env==NULL){
	    JNIEnv* env = NULL;		
        jint result = m_vm->AttachCurrentThreadAsDaemon((void**)&env, NULL);		
		m_jniUtil.print(env,m_jniTemplate,"m_emv create");
		this->m_env = env;	
	}		
	m_jniUtil.print(m_env,m_jniTemplate,"MdFocus,OnFrontConnected!");	
    m_pUserApi->ReqUserLogin(&m_reqUserLogin, 0);
}

// 当客户端与行情发布服务器通信连接断开时，该方法被调用
void FocusMDHandler::OnFrontDisconnected() 
{
	//当发生这个情况后，API会自动重新连接，客户端可不做处理
    //m_jniUtil.print(m_vm,"MsFocus:OnFrontDisconnected.\n");	
}

// 当客户端发出登录请求之后，该方法会被调用，通知客户端登录是否成功
void FocusMDHandler::OnRspUserLogin(CFocusFtdcRspUserLoginField *pRspUserLogin, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{		
    if (pRspInfo==NULL || pRspInfo->ErrorID != 0)
    {
		m_jniUtil.print(m_env,m_jniTemplate,"MdFocus连接失败,重连中...");
		JniSystem jniSystem;
		jniSystem.jniSleep(3);
		m_pUserApi->ReqUserLogin(&m_reqUserLogin, 0);
		return;
    }	
	const char * pTradingDay = m_pUserApi->GetTradingDay();
	m_jniUtil.print(m_env,m_jniTemplate,"MdFocus登陆成功!");	

	//订阅合约信息
	char** contracts = new char*[1];
	char** uncontracts = new char*[1];
	contracts[0]="*";
// 	contracts[1]="IF1212";
// 	contracts[2]="IF1303";

	 
	//uncontracts[0]="EF1511";
	m_pUserApi->SubMarketData(contracts, 1);
	//m_pUserApi->UnSubMarketData(uncontracts, 1);
}
	

///用户退出应答
void FocusMDHandler::OnRspUserLogout(CFocusFtdcRspUserLogoutField *pRspUserLogout, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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

void FocusMDHandler::OnPackageStart(int nTopicID, int nSequenceNo){}

void FocusMDHandler::OnPackageEnd(int nTopicID, int nSequenceNo){}

// 深度行情通知，行情服务器会主动通知客户端
void FocusMDHandler::OnRtnDepthMarketData(CFocusFtdcDepthMarketDataField *pMarketDataReceive) 
{	
	if(pMarketDataReceive==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pMarketDataReceive is null");
		return;
	}
	JNIEnv* env = m_env;    
	jstring jeventType = env->NewStringUTF("marketData");

	jobject jmap = m_jniUtil.newHashMap(env);
	m_jniUtil.mapPut(env,jmap,"instrumentID",pMarketDataReceive->InstrumentID);
	m_jniUtil.mapPut(env,jmap,"tradingDay",pMarketDataReceive->TradingDay);
	//m_jniUtil.mapPut(env,jmap,"settlementGroupID",pMarketDataReceive->SettlementGroupID);
	//m_jniUtil.mapPut(env,jmap,"settlementID",pMarketDataReceive->SettlementID);
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
	m_jniUtil.mapPut(env,jmap,"updateTime",pMarketDataReceive->UpdateTime);
	m_jniUtil.mapPut(env,jmap,"updateMillisec",pMarketDataReceive->UpdateMillisec);	

	m_jniUtil.jcOnEventMsg(env,m_jniTemplate,jeventType,jmap);		

	//释放Local Reference
	env->DeleteLocalRef(jeventType);
	env->DeleteLocalRef(jmap);
}

// 针对用户请求的出错通知
void FocusMDHandler::OnRspError(CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
    // 客户端需进行错误处理
}

///订阅合约的相关信息
void FocusMDHandler::OnRspSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

	//释放Local Reference
	m_env->DeleteLocalRef(jeventType);
	m_env->DeleteLocalRef(jmap);
}

///订阅合约的相关信息
void FocusMDHandler::OnRspUnSubMarketData(CFocusFtdcSpecificInstrumentField *pSpecificInstrument, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	char buffer[300];    
	sprintf(buffer,"UnSub返回订阅合约:%s\n",pSpecificInstrument->InstrumentID);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);	
}


void FocusMDHandler::OnRspQryTopic(CFocusFtdcDisseminationField *pDissemination, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	char buffer[300];    
	sprintf(buffer,"OnRspQryTopic:%d ,%d\n",pDissemination->SequenceSeries,pDissemination->SequenceNo);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);		
}


int FocusMDHandler::reqUserLogin(JNIEnv *env, jobject reqMap, int nRequestID)
{
	const char *UserID = m_jniUtil.getStringByMap(env, reqMap, "UserID");
	const char *Password = m_jniUtil.getStringByMap(env, reqMap, "Password");

	/*
	String	TradingDay,
	String	UserID,
	String	BrokerID,
	String	Password,
	String	UserProductInfo,
	String	InterfaceProductInfo,
	String	ProtocolInfo,
	String	IPAddress,
	String	MacAddress,
	int	DataCenterID,
	String	OneTimePassword,
	String	ClientIPAddress,
	String	AuthCode
	*/

	CFocusFtdcReqUserLoginField request;

	strcpy(request.UserID, UserID);
	strcpy(request.Password, Password);


	strcpy(request.TradingDay, UserID);
	strcpy(request.BrokerID, Password);
	strcpy(request.UserProductInfo, UserID);
	strcpy(request.InterfaceProductInfo, Password);
	strcpy(request.ProtocolInfo, UserID);
	strcpy(request.IPAddress, Password);

	strcpy(request.MacAddress, Password);
	strcpy(request.OneTimePassword, UserID);
	strcpy(request.ClientIPAddress, Password);

	strcpy(request.AuthCode, Password);
	request.DataCenterID = 12;

	return this->m_pUserApi->ReqUserLogin(&request, nRequestID);

}




///计算单个期权请求
int FocusMDHandler::reqCalcOneOption(JNIEnv *env, jobject reqMap, jint nRequestID)
{
	const char *InstrumentID = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID");
	char CalculateTarget = m_jniUtil.getCharByMap(env, reqMap, "CalculateTarget");
	char ExerciseType = m_jniUtil.getCharByMap(env, reqMap, "ExerciseType");
	char OptionsType = m_jniUtil.getCharByMap(env, reqMap, "OptionsType");
	double UnderlyingPrice = m_jniUtil.getDoubleByMap(env, reqMap, "UnderlyingPrice");
	double StrikePrice = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice");
	double RiskFreeRate = m_jniUtil.getDoubleByMap(env, reqMap, "RiskFreeRate");
	double Dividend = m_jniUtil.getDoubleByMap(env, reqMap, "Dividend");
	double RemainDay = m_jniUtil.getDoubleByMap(env, reqMap, "RemainDay");
	const char *TradingDate = m_jniUtil.getStringByMap(env, reqMap, "TradingDate");
	const char *ExpireDate = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate");
	double Vol = m_jniUtil.getDoubleByMap(env, reqMap, "Vol");
	char PricingModel = m_jniUtil.getCharByMap(env, reqMap, "PricingModel");
	double OptionPrice = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice");
	double Delta = m_jniUtil.getDoubleByMap(env, reqMap, "Delta");
	double Gamma = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma");
	double Vega = m_jniUtil.getDoubleByMap(env, reqMap, "Vega");
	double Theta = m_jniUtil.getDoubleByMap(env, reqMap, "Theta");
	double Rho = m_jniUtil.getDoubleByMap(env, reqMap, "Rho");
	double Vanna = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna");
	double Valga = m_jniUtil.getDoubleByMap(env, reqMap, "Valga");

	CFocusFtdcBasePricingParamField request;

	strcpy(request.InstrumentID, InstrumentID);
	request.CalculateTarget = CalculateTarget;
	request.ExerciseType = ExerciseType;
	request.OptionsType = OptionsType;
	request.UnderlyingPrice = UnderlyingPrice;
	request.StrikePrice = StrikePrice;
	request.RiskFreeRate = RiskFreeRate;
	request.Dividend = Dividend;
	request.RemainDay = RemainDay;
	strcpy(request.TradingDate, TradingDate);
	strcpy(request.ExpireDate, ExpireDate);
	request.Vol = Vol;
	request.PricingModel = PricingModel;
	request.OptionPrice = OptionPrice;
	request.Delta = Delta;
	request.Gamma = Gamma;
	request.Vega = Vega;
	request.Theta = Theta;
	request.Rho = Rho;
	request.Vanna = Vanna;
	request.Valga = Valga;

	return this->m_pUserApi->ReqCalcOneOption(&request, nRequestID);

}

///计算障碍期权请求
int FocusMDHandler::reqCalcBarrierOption(JNIEnv *env, jobject reqMap, jint nRequestID)
{

	const char *InstrumentID = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID");
	char CalculateTarget = m_jniUtil.getCharByMap(env, reqMap, "CalculateTarget");
	char ExerciseType = m_jniUtil.getCharByMap(env, reqMap, "ExerciseType");
	char OptionsType = m_jniUtil.getCharByMap(env, reqMap, "OptionsType");
	double UnderlyingPrice = m_jniUtil.getDoubleByMap(env, reqMap, "UnderlyingPrice");
	double StrikePrice = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice");
	double RiskFreeRate = m_jniUtil.getDoubleByMap(env, reqMap, "RiskFreeRate");
	double Dividend = m_jniUtil.getDoubleByMap(env, reqMap, "Dividend");
	double RemainDay = m_jniUtil.getDoubleByMap(env, reqMap, "RemainDay");
	const char *TradingDate = m_jniUtil.getStringByMap(env, reqMap, "TradingDate");
	const char *ExpireDate = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate");
	double Vol = m_jniUtil.getDoubleByMap(env, reqMap, "Vol");
	char PricingModel = m_jniUtil.getCharByMap(env, reqMap, "PricingModel");
	double OptionPrice = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice");
	double Delta = m_jniUtil.getDoubleByMap(env, reqMap, "Delta");
	double Gamma = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma");
	double Vega = m_jniUtil.getDoubleByMap(env, reqMap, "Vega");
	double Theta = m_jniUtil.getDoubleByMap(env, reqMap, "Theta");
	double Rho = m_jniUtil.getDoubleByMap(env, reqMap, "Rho");
	double Vanna = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna");
	double Valga = m_jniUtil.getDoubleByMap(env, reqMap, "Valga");
	char BarrierType = m_jniUtil.getCharByMap(env, reqMap, "BarrierType");
	double LowerBarrierRate = m_jniUtil.getDoubleByMap(env, reqMap, "LowerBarrierRate");
	double UpperBarrierRate = m_jniUtil.getDoubleByMap(env, reqMap, "UpperBarrierRate");

	CFocusFtdcDoubleBarrierPricingParamField request;


	strcpy(request.InstrumentID, InstrumentID);
	request.CalculateTarget = CalculateTarget;
	request.ExerciseType = ExerciseType;
	request.OptionsType = OptionsType;
	request.UnderlyingPrice = UnderlyingPrice;
	request.StrikePrice = StrikePrice;
	request.RiskFreeRate = RiskFreeRate;
	request.Dividend = Dividend;
	request.RemainDay = RemainDay;
	strcpy(request.TradingDate, TradingDate);
	strcpy(request.ExpireDate, ExpireDate);
	request.Vol = Vol;
	request.PricingModel = PricingModel;
	request.OptionPrice = OptionPrice;
	request.Delta = Delta;
	request.Gamma = Gamma;
	request.Vega = Vega;
	request.Theta = Theta;
	request.Rho = Rho;
	request.Vanna = Vanna;
	request.Valga = Valga;
	request.BarrierType = BarrierType;
	request.LowerBarrierRate = LowerBarrierRate;
	request.UpperBarrierRate = UpperBarrierRate;

	return this->m_pUserApi->ReqCalcBarrierOption(&request, nRequestID);

}

///计算期权组合请求
int FocusMDHandler::reqCalcCombinationOption(JNIEnv *env, jobject reqMap, jint nRequestID)
{
	char CalculateTarget = m_jniUtil.getCharByMap(env, reqMap, "CalculateTarget");
	char ExerciseType = m_jniUtil.getCharByMap(env, reqMap, "ExerciseType");
	double UnderlyingPrice = m_jniUtil.getDoubleByMap(env, reqMap, "UnderlyingPrice");
	double RiskFreeRate = m_jniUtil.getDoubleByMap(env, reqMap, "RiskFreeRate");
	double Dividend = m_jniUtil.getDoubleByMap(env, reqMap, "Dividend");
	const char *TradingDate = m_jniUtil.getStringByMap(env, reqMap, "TradingDate");
	char PricingModel = m_jniUtil.getCharByMap(env, reqMap, "PricingModel");
	double CombinationPrice = m_jniUtil.getDoubleByMap(env, reqMap, "CombinationPrice");
	const char *InstrumentID_Leg1 = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID_Leg1");
	char OptionsType_Leg1 = m_jniUtil.getCharByMap(env, reqMap, "OptionsType_Leg1");
	char Direction_Leg1 = m_jniUtil.getCharByMap(env, reqMap, "Direction_Leg1");
	double StrikePrice_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice_Leg1");
	const char *ExpireDate_Leg1 = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate_Leg1");
	double Vol_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Vol_Leg1");
	double OptionPrice_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice_Leg1");
	double Delta_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Delta_Leg1");
	double Gamma_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma_Leg1");
	double Vega_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Vega_Leg1");
	double Theta_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Theta_Leg1");
	double Rho_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Rho_Leg1");
	double Vanna_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna_Leg1");
	double Valga_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap, "Valga_Leg1");
	const char *InstrumentID_Leg2 = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID_Leg2");
	char OptionsType_Leg2 = m_jniUtil.getCharByMap(env, reqMap, "OptionsType_Leg2");
	char Direction_Leg2 = m_jniUtil.getCharByMap(env, reqMap, "Direction_Leg2");
	double StrikePrice_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice_Leg2");
	const char *ExpireDate_Leg2 = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate_Leg2");
	double Vol_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Vol_Leg2");
	double OptionPrice_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice_Leg2");
	double Delta_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Delta_Leg2");
	double Gamma_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma_Leg2");
	double Vega_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Vega_Leg2");
	double Theta_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Theta_Leg2");
	double Rho_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Rho_Leg2");
	double Vanna_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna_Leg2");
	double Valga_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap, "Valga_Leg2");
	const char *InstrumentID_Leg3 = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID_Leg3");
	char OptionsType_Leg3 = m_jniUtil.getCharByMap(env, reqMap, "OptionsType_Leg3");
	char Direction_Leg3 = m_jniUtil.getCharByMap(env, reqMap, "Direction_Leg3");
	double StrikePrice_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice_Leg3");
	const char *ExpireDate_Leg3 = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate_Leg3");
	double Vol_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Vol_Leg3");
	double OptionPrice_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice_Leg3");
	double Delta_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Delta_Leg3");
	double Gamma_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma_Leg3");
	double Vega_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Vega_Leg3");
	double Theta_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Theta_Leg3");
	double Rho_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Rho_Leg3");
	double Vanna_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna_Leg3");
	double Valga_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap, "Valga_Leg3");
	const char *InstrumentID_Leg4 = m_jniUtil.getStringByMap(env, reqMap, "InstrumentID_Leg4");
	char OptionsType_Leg4 = m_jniUtil.getCharByMap(env, reqMap, "OptionsType_Leg4");
	char Direction_Leg4 = m_jniUtil.getCharByMap(env, reqMap, "Direction_Leg4");
	double StrikePrice_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "StrikePrice_Leg4");
	const char *ExpireDate_Leg4 = m_jniUtil.getStringByMap(env, reqMap, "ExpireDate_Leg4");
	double Vol_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Vol_Leg4");
	double OptionPrice_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "OptionPrice_Leg4");
	double Delta = m_jniUtil.getDoubleByMap(env, reqMap, "Delta");
	double Gamma_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Gamma_Leg4");
	double Vega_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Vega_Leg4");
	double Theta_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Theta_Leg4");
	double Rho_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Rho_Leg4");
	double Vanna_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Vanna_Leg4");
	double Valga_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap, "Valga_Leg4");

	CFocusFtdcCombinationParamField request;

	request.CalculateTarget = CalculateTarget;
	request.ExerciseType = ExerciseType;
	request.UnderlyingPrice = UnderlyingPrice;
	request.RiskFreeRate = RiskFreeRate;
	request.Dividend = Dividend;
	strcpy(request.TradingDate, TradingDate);
	request.PricingModel = PricingModel;
	request.CombinationPrice = CombinationPrice;
	strcpy(request.InstrumentID_Leg1, InstrumentID_Leg1);
	request.OptionsType_Leg1 = OptionsType_Leg1;
	request.Direction_Leg1 = Direction_Leg1;
	request.StrikePrice_Leg1 = StrikePrice_Leg1;
	strcpy(request.ExpireDate_Leg1, ExpireDate_Leg1);
	request.Vol_Leg1 = Vol_Leg1;
	request.OptionPrice_Leg1 = OptionPrice_Leg1;
	request.Delta_Leg1 = Delta_Leg1;
	request.Gamma_Leg1 = Gamma_Leg1;
	request.Vega_Leg1 = Vega_Leg1;
	request.Theta_Leg1 = Theta_Leg1;
	request.Rho_Leg1 = Rho_Leg1;
	request.Vanna_Leg1 = Vanna_Leg1;
	request.Valga_Leg1 = Valga_Leg1;
	strcpy(request.InstrumentID_Leg2, InstrumentID_Leg2);
	request.OptionsType_Leg2 = OptionsType_Leg2;
	request.Direction_Leg2 = Direction_Leg2;
	request.StrikePrice_Leg2 = StrikePrice_Leg2;
	strcpy(request.ExpireDate_Leg2, ExpireDate_Leg2);
	request.Vol_Leg2 = Vol_Leg2;
	request.OptionPrice_Leg2 = OptionPrice_Leg2;
	request.Delta_Leg2 = Delta_Leg2;
	request.Gamma_Leg2 = Gamma_Leg2;
	request.Vega_Leg2 = Vega_Leg2;
	request.Theta_Leg2 = Theta_Leg2;
	request.Rho_Leg2 = Rho_Leg2;
	request.Vanna_Leg2 = Vanna_Leg2;
	request.Valga_Leg2 = Valga_Leg2;
	strcpy(request.InstrumentID_Leg3, InstrumentID_Leg3);
	request.OptionsType_Leg3 = OptionsType_Leg3;
	request.Direction_Leg3 = Direction_Leg3;
	request.StrikePrice_Leg3 = StrikePrice_Leg3;
	strcpy(request.ExpireDate_Leg3, ExpireDate_Leg3);
	request.Vol_Leg3 = Vol_Leg3;
	request.OptionPrice_Leg3 = OptionPrice_Leg3;
	request.Delta_Leg3 = Delta_Leg3;
	request.Gamma_Leg3 = Gamma_Leg3;
	request.Vega_Leg3 = Vega_Leg3;
	request.Theta_Leg3 = Theta_Leg3;
	request.Rho_Leg3 = Rho_Leg3;
	request.Vanna_Leg3 = Vanna_Leg3;
	request.Valga_Leg3 = Valga_Leg3;
	strcpy(request.InstrumentID_Leg4, InstrumentID_Leg4);
	request.OptionsType_Leg4 = OptionsType_Leg4;
	request.Direction_Leg4 = Direction_Leg4;
	request.StrikePrice_Leg4 = StrikePrice_Leg4;
	strcpy(request.ExpireDate_Leg4, ExpireDate_Leg4);
	request.Vol_Leg4 = Vol_Leg4;
	request.OptionPrice_Leg4 = OptionPrice_Leg4;
	request.Delta = Delta;
	request.Gamma_Leg4 = Gamma_Leg4;
	request.Vega_Leg4 = Vega_Leg4;
	request.Theta_Leg4 = Theta_Leg4;
	request.Rho_Leg4 = Rho_Leg4;
	request.Vanna_Leg4 = Vanna_Leg4;
	request.Valga_Leg4 = Valga_Leg4;

	return this->m_pUserApi->ReqCalcCombinationOption(&request, nRequestID);
}



///计算单个期权应答
void FocusMDHandler::OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if (pBasePricingParam != NULL)
	{
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID", pBasePricingParam->InstrumentID);
		m_jniUtil.mapPut(m_env, jmap, "CalculateTarget", pBasePricingParam->CalculateTarget);
		m_jniUtil.mapPut(m_env, jmap, "ExerciseType", pBasePricingParam->ExerciseType);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType", pBasePricingParam->OptionsType);
		m_jniUtil.mapPut(m_env, jmap, "UnderlyingPrice", pBasePricingParam->UnderlyingPrice);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice", pBasePricingParam->StrikePrice);
		m_jniUtil.mapPut(m_env, jmap, "RiskFreeRate", pBasePricingParam->RiskFreeRate);
		m_jniUtil.mapPut(m_env, jmap, "Dividend", pBasePricingParam->Dividend);
		m_jniUtil.mapPut(m_env, jmap, "RemainDay", pBasePricingParam->RemainDay);
		m_jniUtil.mapPut(m_env, jmap, "TradingDate", pBasePricingParam->TradingDate);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate", pBasePricingParam->ExpireDate);
		m_jniUtil.mapPut(m_env, jmap, "Vol", pBasePricingParam->Vol);
		m_jniUtil.mapPut(m_env, jmap, "PricingModel", pBasePricingParam->PricingModel);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice", pBasePricingParam->OptionPrice);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice", pBasePricingParam->OptionPrice);

		/*
		TFocusFtdcGreekValueType	Delta;
		///Gamma
		TFocusFtdcGreekValueType	Gamma;
		///Vega
		TFocusFtdcGreekValueType	Vega;
		///Theta
		TFocusFtdcGreekValueType	Theta;
		///Rho
		TFocusFtdcGreekValueType	Rho;
		///Vanna
		TFocusFtdcGreekValueType	Vanna;
		///Valga
		TFocusFtdcGreekValueType	Valga;
		*/
		m_jniUtil.mapPut(m_env, jmap, "Delta", pBasePricingParam->Delta);
		m_jniUtil.mapPut(m_env, jmap, "Gamma", pBasePricingParam->Gamma);
		m_jniUtil.mapPut(m_env, jmap, "Vega", pBasePricingParam->Vega);
		m_jniUtil.mapPut(m_env, jmap, "Theta", pBasePricingParam->Theta);
		m_jniUtil.mapPut(m_env, jmap, "Rho", pBasePricingParam->Rho);
		m_jniUtil.mapPut(m_env, jmap, "Vanna", pBasePricingParam->Vanna);
		m_jniUtil.mapPut(m_env, jmap, "Valga", pBasePricingParam->Valga);
	}
	m_jniUtil.jcOnResponse(m_env, m_jniTemplate, jmap, pRspInfo->ErrorID, pRspInfo->ErrorMsg, nRequestID, bIsLast);
	if (jmap != NULL) {
		m_env->DeleteLocalRef(jmap);
	}

}

///计算障碍期权应答
void FocusMDHandler::OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if (pDoubleBarrierPricingParam != NULL)
	{
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID", pDoubleBarrierPricingParam->InstrumentID);
		m_jniUtil.mapPut(m_env, jmap, "CalculateTarget", pDoubleBarrierPricingParam->CalculateTarget);
		m_jniUtil.mapPut(m_env, jmap, "ExerciseType", pDoubleBarrierPricingParam->ExerciseType);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType", pDoubleBarrierPricingParam->OptionsType);
		m_jniUtil.mapPut(m_env, jmap, "UnderlyingPrice", pDoubleBarrierPricingParam->UnderlyingPrice);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice", pDoubleBarrierPricingParam->StrikePrice);
		m_jniUtil.mapPut(m_env, jmap, "RiskFreeRate", pDoubleBarrierPricingParam->RiskFreeRate);
		m_jniUtil.mapPut(m_env, jmap, "Dividend", pDoubleBarrierPricingParam->Dividend);
		m_jniUtil.mapPut(m_env, jmap, "RemainDay", pDoubleBarrierPricingParam->RemainDay);
		m_jniUtil.mapPut(m_env, jmap, "TradingDate", pDoubleBarrierPricingParam->TradingDate);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate", pDoubleBarrierPricingParam->ExpireDate);
		m_jniUtil.mapPut(m_env, jmap, "Vol", pDoubleBarrierPricingParam->Vol);
		m_jniUtil.mapPut(m_env, jmap, "PricingModel", pDoubleBarrierPricingParam->PricingModel);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice", pDoubleBarrierPricingParam->OptionPrice);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice", pDoubleBarrierPricingParam->OptionPrice);
		m_jniUtil.mapPut(m_env, jmap, "Delta", pDoubleBarrierPricingParam->Delta);
		m_jniUtil.mapPut(m_env, jmap, "Gamma", pDoubleBarrierPricingParam->Gamma);
		m_jniUtil.mapPut(m_env, jmap, "Vega", pDoubleBarrierPricingParam->Vega);
		m_jniUtil.mapPut(m_env, jmap, "Theta", pDoubleBarrierPricingParam->Theta);
		m_jniUtil.mapPut(m_env, jmap, "Rho", pDoubleBarrierPricingParam->Rho);
		m_jniUtil.mapPut(m_env, jmap, "Vanna", pDoubleBarrierPricingParam->Vanna);
		m_jniUtil.mapPut(m_env, jmap, "Valga", pDoubleBarrierPricingParam->Valga);
		m_jniUtil.mapPut(m_env, jmap, "BarrierType", pDoubleBarrierPricingParam->BarrierType);
		m_jniUtil.mapPut(m_env, jmap, "LowerBarrierRate", pDoubleBarrierPricingParam->LowerBarrierRate);
		m_jniUtil.mapPut(m_env, jmap, "UpperBarrierRate", pDoubleBarrierPricingParam->UpperBarrierRate);

	}

	m_jniUtil.jcOnResponse(m_env, m_jniTemplate, jmap, pRspInfo->ErrorID, pRspInfo->ErrorMsg, nRequestID, bIsLast);
	if (jmap != NULL) {
		m_env->DeleteLocalRef(jmap);
	}

}

///计算期权组合应答
void FocusMDHandler::OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if (pCombinationParam != NULL)
	{
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env, jmap, "CalculateTarget", pCombinationParam->CalculateTarget);
		m_jniUtil.mapPut(m_env, jmap, "ExerciseType", pCombinationParam->ExerciseType);
		m_jniUtil.mapPut(m_env, jmap, "UnderlyingPrice", pCombinationParam->UnderlyingPrice);
		m_jniUtil.mapPut(m_env, jmap, "RiskFreeRate", pCombinationParam->RiskFreeRate);
		m_jniUtil.mapPut(m_env, jmap, "Dividend", pCombinationParam->Dividend);
		m_jniUtil.mapPut(m_env, jmap, "TradingDate", pCombinationParam->TradingDate);
		m_jniUtil.mapPut(m_env, jmap, "PricingModel", pCombinationParam->PricingModel);
		m_jniUtil.mapPut(m_env, jmap, "CombinationPrice", pCombinationParam->CombinationPrice);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID_Leg1", pCombinationParam->InstrumentID_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType_Leg1", pCombinationParam->OptionsType_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Direction_Leg1", pCombinationParam->Direction_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice_Leg1", pCombinationParam->StrikePrice_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate_Leg1", pCombinationParam->ExpireDate_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Vol_Leg1", pCombinationParam->Vol_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice_Leg1", pCombinationParam->OptionPrice_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Delta_Leg1", pCombinationParam->Delta_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Gamma_Leg1", pCombinationParam->Gamma_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Vega_Leg1", pCombinationParam->Vega_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Theta_Leg1", pCombinationParam->Theta_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Rho_Leg1", pCombinationParam->Rho_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Vanna_Leg1", pCombinationParam->Vanna_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "Valga_Leg1", pCombinationParam->Valga_Leg1);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID_Leg2", pCombinationParam->InstrumentID_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType_Leg2", pCombinationParam->OptionsType_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Direction_Leg2", pCombinationParam->Direction_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice_Leg2", pCombinationParam->StrikePrice_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate_Leg2", pCombinationParam->ExpireDate_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Vol_Leg2", pCombinationParam->Vol_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice_Leg2", pCombinationParam->OptionPrice_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Delta_Leg2", pCombinationParam->Delta_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Gamma_Leg2", pCombinationParam->Gamma_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Vega_Leg2", pCombinationParam->Vega_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Theta_Leg2", pCombinationParam->Theta_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Rho_Leg2", pCombinationParam->Rho_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Vanna_Leg2", pCombinationParam->Vanna_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "Valga_Leg2", pCombinationParam->Valga_Leg2);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID_Leg3", pCombinationParam->InstrumentID_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType_Leg3", pCombinationParam->OptionsType_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Direction_Leg3", pCombinationParam->Direction_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice_Leg3", pCombinationParam->StrikePrice_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate_Leg3", pCombinationParam->ExpireDate_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Vol_Leg3", pCombinationParam->Vol_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice_Leg3", pCombinationParam->OptionPrice_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Delta_Leg3", pCombinationParam->Delta_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Gamma_Leg3", pCombinationParam->Gamma_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Vega_Leg3", pCombinationParam->Vega_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Theta_Leg3", pCombinationParam->Theta_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Rho_Leg3", pCombinationParam->Rho_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Vanna_Leg3", pCombinationParam->Vanna_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "Valga_Leg3", pCombinationParam->Valga_Leg3);
		m_jniUtil.mapPut(m_env, jmap, "InstrumentID_Leg4", pCombinationParam->InstrumentID_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "OptionsType_Leg4", pCombinationParam->OptionsType_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Direction_Leg4", pCombinationParam->Direction_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "StrikePrice_Leg4", pCombinationParam->StrikePrice_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "ExpireDate_Leg4", pCombinationParam->ExpireDate_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Vol_Leg4", pCombinationParam->Vol_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "OptionPrice_Leg4", pCombinationParam->OptionPrice_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Delta", pCombinationParam->Delta);
		m_jniUtil.mapPut(m_env, jmap, "Gamma_Leg4", pCombinationParam->Gamma_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Vega_Leg4", pCombinationParam->Vega_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Theta_Leg4", pCombinationParam->Theta_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Rho_Leg4", pCombinationParam->Rho_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Vanna_Leg4", pCombinationParam->Vanna_Leg4);
		m_jniUtil.mapPut(m_env, jmap, "Valga_Leg4", pCombinationParam->Valga_Leg4);

	}
	m_jniUtil.jcOnResponse(m_env, m_jniTemplate, jmap, pRspInfo->ErrorID, pRspInfo->ErrorMsg, nRequestID, bIsLast);
	if (jmap != NULL) {
		m_env->DeleteLocalRef(jmap);
	}

}
