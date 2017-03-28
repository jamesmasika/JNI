#include "TraderJniSpi.h"
#include <string.h>
#include <stdlib.h>
#include "JniSystem.h"

TraderJniSpi::TraderJniSpi(CQTFtdcUserApi *userApi,
				const CQTFtdcReqUserLoginField &pReqUserLogin,
				JavaVM *vm,jobject jniTemplate){
		this->m_userApi = userApi;
		this->m_pReqUserLogin = pReqUserLogin;
		this->m_vm = vm;
		this->m_env = NULL;
		this->m_jniTemplate = jniTemplate;
		this->m_maxOrderLocalID = 0;
}


TraderJniSpi::~TraderJniSpi(){
	m_jniUtil.print(m_vm,m_jniTemplate,"~TraderJniSpi exec");	
}

// 当客户端与交易所务器建立起通信连接，客户端需要进行登录
void TraderJniSpi::OnFrontConnected(){
	if(this->m_env==NULL){
	    JNIEnv* env = NULL;		
        jint result = m_vm->AttachCurrentThreadAsDaemon((void**)&env, NULL);		
		m_jniUtil.print(env,m_jniTemplate,"m_emv create");
		this->m_env = env;	
	}	
	m_jniUtil.print(m_env,m_jniTemplate,"Trader OnFrontConnected!");	
    m_userApi->ReqUserLogin(&m_pReqUserLogin, 1);
}

void TraderJniSpi::OnFrontDisconnected(int nReason){
	char buffer[300];
    sprintf(buffer,"连接断开,返回码:[%d]",nReason);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);
}

//当客户端发出登录请求之后，该方法会被调用，通知客户端登录是否成功
void TraderJniSpi::OnRspUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    if (pRspInfo==NULL || pRspInfo->ErrorID != 0)
    {
        // 端登失败，客户端需进行错误处理
		char buffer[300];
		sprintf(buffer,"Trader连接失败,errorID:[%d] ErrorMsg:[%s] nRequestID:[%d],重连中...  ",pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID);
		m_jniUtil.print(m_env,m_jniTemplate,buffer);
		JniSystem jniSystem;
		jniSystem.jniSleep(3);
		m_userApi->ReqUserLogin(&m_pReqUserLogin, 0);
		return;
    }		 	
	this->m_maxOrderLocalID = atoi(pRspUserLogin->MaxOrderLocalID);	
	m_jniUtil.print(m_env,m_jniTemplate,"Trader登陆成功!");
}

//获取下一个本地报单编号
int TraderJniSpi::nextOrderLocalID(){	
	this->m_maxOrderLocalID ++;	
	return this->m_maxOrderLocalID;
}

///错误应答
void TraderJniSpi::OnRspError(CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	char buffer[300];
	sprintf(buffer,"OnRspError,errorID:[%d] ErrorMsg:[%s] nRequestID:[%d]  ",pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID);
	m_jniUtil.print(m_env,m_jniTemplate,buffer);
	jobject jmap = NULL;
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);
}

///用户密码修改应答
void TraderJniSpi::OnRspUserPasswordUpdate(CQTFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}

	jobject jmap = NULL;
	if(pUserPasswordUpdate!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"userID",pUserPasswordUpdate->UserID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pUserPasswordUpdate->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"oldPassword",pUserPasswordUpdate->OldPassword);
		m_jniUtil.mapPut(m_env,jmap,"newPassword",pUserPasswordUpdate->NewPassword);
	}

	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);		

	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///报单录入应答
void TraderJniSpi::OnRspOrderInsert(CQTFtdcInputOrderField *pInputOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}

	jobject jmap = NULL;
	if(pInputOrder!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pInputOrder->OrderSysID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pInputOrder->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pInputOrder->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pInputOrder->UserID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pInputOrder->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"orderPriceType",pInputOrder->OrderPriceType);
		m_jniUtil.mapPut(m_env,jmap,"direction",pInputOrder->Direction);
		m_jniUtil.mapPut(m_env,jmap,"combOffsetFlag",pInputOrder->CombOffsetFlag);
		m_jniUtil.mapPut(m_env,jmap,"combHedgeFlag",pInputOrder->CombHedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"limitPrice",pInputOrder->LimitPrice);
		m_jniUtil.mapPut(m_env,jmap,"volumeTotalOriginal",pInputOrder->VolumeTotalOriginal);
		m_jniUtil.mapPut(m_env,jmap,"timeCondition",pInputOrder->TimeCondition);
		m_jniUtil.mapPut(m_env,jmap,"GTDDate",pInputOrder->GTDDate);
		m_jniUtil.mapPut(m_env,jmap,"volumeCondition",pInputOrder->VolumeCondition);
		m_jniUtil.mapPut(m_env,jmap,"minVolume",pInputOrder->MinVolume);
		m_jniUtil.mapPut(m_env,jmap,"contingentCondition",pInputOrder->ContingentCondition);
		m_jniUtil.mapPut(m_env,jmap,"stopPrice",pInputOrder->StopPrice);
		m_jniUtil.mapPut(m_env,jmap,"forceCloseReason",pInputOrder->ForceCloseReason);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pInputOrder->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"isAutoSuspend",pInputOrder->IsAutoSuspend);
		m_jniUtil.mapPut(m_env,jmap,"businessUnit",pInputOrder->BusinessUnit);	
	}


	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);		
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///报单操作应答
void TraderJniSpi::OnRspOrderAction(CQTFtdcOrderActionField *pOrderAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pOrderAction!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pOrderAction->OrderSysID);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pOrderAction->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"actionFlag",pOrderAction->ActionFlag);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pOrderAction->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pOrderAction->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pOrderAction->UserID);
		m_jniUtil.mapPut(m_env,jmap,"limitPrice",pOrderAction->LimitPrice);
		m_jniUtil.mapPut(m_env,jmap,"volumeChange",pOrderAction->VolumeChange);
		m_jniUtil.mapPut(m_env,jmap,"actionLocalID",pOrderAction->ActionLocalID);
		m_jniUtil.mapPut(m_env,jmap,"businessUnit",pOrderAction->BusinessUnit);
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);		
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///会员资金查询应答
void TraderJniSpi::OnRspQryPartAccount(CQTFtdcRspPartAccountField *pRspPartAccount, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){			
	int ErrorID=0;
	char *ErrorMsg="正确";
	if(pRspInfo!=NULL){
		ErrorID = pRspInfo->ErrorID;
		ErrorMsg = pRspInfo->ErrorMsg;
	}
	jobject jmap = NULL;
	if(pRspPartAccount!=NULL){		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pRspPartAccount->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pRspPartAccount->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pRspPartAccount->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"preBalance",pRspPartAccount->PreBalance);
		m_jniUtil.mapPut(m_env,jmap,"currMargin",pRspPartAccount->CurrMargin);
		m_jniUtil.mapPut(m_env,jmap,"closeProfit",pRspPartAccount->CloseProfit);
		m_jniUtil.mapPut(m_env,jmap,"premium",pRspPartAccount->Premium);
		m_jniUtil.mapPut(m_env,jmap,"deposit",pRspPartAccount->Deposit);
		m_jniUtil.mapPut(m_env,jmap,"withdraw",pRspPartAccount->Withdraw);
		m_jniUtil.mapPut(m_env,jmap,"balance",pRspPartAccount->Balance);
		m_jniUtil.mapPut(m_env,jmap,"available",pRspPartAccount->Available);
		m_jniUtil.mapPut(m_env,jmap,"accountID",pRspPartAccount->AccountID);
		m_jniUtil.mapPut(m_env,jmap,"frozenMargin",pRspPartAccount->FrozenMargin);
		m_jniUtil.mapPut(m_env,jmap,"frozenPremium",pRspPartAccount->FrozenPremium);
		m_jniUtil.mapPut(m_env,jmap,"baseReserve",pRspPartAccount->BaseReserve);
		m_jniUtil.mapPut(m_env,jmap,"sellMoney",pRspPartAccount->SellMoney);
	}	
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,ErrorID,ErrorMsg,nRequestID,bIsLast);					
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///客户持仓查询应答
void TraderJniSpi::OnRspQryClientPosition(CQTFtdcRspClientPositionField *pRspClientPosition, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	//if(pRspInfo==NULL){
	//	m_jniUtil.print(m_env,"pRspInfo is null");
	//	return;
	//}
	int ErrorID=0;
	char *ErrorMsg="正确";
	if(pRspInfo!=NULL){
		ErrorID = pRspInfo->ErrorID;
		ErrorMsg = pRspInfo->ErrorMsg;
	}

	jobject jmap = NULL;
	if(pRspClientPosition!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pRspClientPosition->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pRspClientPosition->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pRspClientPosition->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"hedgeFlag",pRspClientPosition->HedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"posiDirection",pRspClientPosition->PosiDirection);
		m_jniUtil.mapPut(m_env,jmap,"ydPosition",pRspClientPosition->YdPosition);
		m_jniUtil.mapPut(m_env,jmap,"position",pRspClientPosition->Position);
		m_jniUtil.mapPut(m_env,jmap,"longFrozen",pRspClientPosition->LongFrozen);
		m_jniUtil.mapPut(m_env,jmap,"shortFrozen",pRspClientPosition->ShortFrozen);
		m_jniUtil.mapPut(m_env,jmap,"ydLongFrozen",pRspClientPosition->YdLongFrozen);
		m_jniUtil.mapPut(m_env,jmap,"ydShortFrozen",pRspClientPosition->YdShortFrozen);
		m_jniUtil.mapPut(m_env,jmap,"buyTradeVolume",pRspClientPosition->BuyTradeVolume);
		m_jniUtil.mapPut(m_env,jmap,"sellTradeVolume",pRspClientPosition->SellTradeVolume);
		m_jniUtil.mapPut(m_env,jmap,"positionCost",pRspClientPosition->PositionCost);
		m_jniUtil.mapPut(m_env,jmap,"ydPositionCost",pRspClientPosition->YdPositionCost);
		m_jniUtil.mapPut(m_env,jmap,"useMargin",pRspClientPosition->UseMargin);
		m_jniUtil.mapPut(m_env,jmap,"frozenMargin",pRspClientPosition->FrozenMargin);
		m_jniUtil.mapPut(m_env,jmap,"longFrozenMargin",pRspClientPosition->LongFrozenMargin);
		m_jniUtil.mapPut(m_env,jmap,"shortFrozenMargin",pRspClientPosition->ShortFrozenMargin);
		m_jniUtil.mapPut(m_env,jmap,"frozenPremium",pRspClientPosition->FrozenPremium);		
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pRspClientPosition->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pRspClientPosition->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pRspClientPosition->ClientID); 
	}

	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,ErrorID,ErrorMsg,nRequestID,bIsLast);		
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///报单查询应答
void TraderJniSpi::OnRspQryOrder(CQTFtdcOrderField *pOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	
	int ErrorID=0;
	char *ErrorMsg="正确";
	if(pRspInfo!=NULL){
		ErrorID = pRspInfo->ErrorID;
		ErrorMsg = pRspInfo->ErrorMsg;
	}
	
	jobject jmap = NULL;
	if(pOrder!=NULL)
	{		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pOrder->TradingDay);	
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pOrder->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pOrder->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pOrder->OrderSysID);	
		m_jniUtil.mapPut(m_env,jmap,"participantID",pOrder->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pOrder->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pOrder->UserID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pOrder->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"orderPriceType",pOrder->OrderPriceType);
		m_jniUtil.mapPut(m_env,jmap,"direction",pOrder->Direction);
		m_jniUtil.mapPut(m_env,jmap,"combOffsetFlag",pOrder->CombOffsetFlag);
		m_jniUtil.mapPut(m_env,jmap,"combHedgeFlag",pOrder->CombHedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"limitPrice",pOrder->LimitPrice);
		m_jniUtil.mapPut(m_env,jmap,"volumeTotalOriginal",pOrder->VolumeTotalOriginal);
		m_jniUtil.mapPut(m_env,jmap,"timeCondition",pOrder->TimeCondition);
		m_jniUtil.mapPut(m_env,jmap,"gTDDate",pOrder->GTDDate);
		m_jniUtil.mapPut(m_env,jmap,"volumeCondition",pOrder->VolumeCondition);
		m_jniUtil.mapPut(m_env,jmap,"minVolume",pOrder->MinVolume);
		m_jniUtil.mapPut(m_env,jmap,"contingentCondition",pOrder->ContingentCondition);
		m_jniUtil.mapPut(m_env,jmap,"stopPrice",pOrder->StopPrice);
		m_jniUtil.mapPut(m_env,jmap,"forceCloseReason",pOrder->ForceCloseReason);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pOrder->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"isAutoSuspend",pOrder->IsAutoSuspend);
		m_jniUtil.mapPut(m_env,jmap,"orderSource",pOrder->OrderSource);
		m_jniUtil.mapPut(m_env,jmap,"orderStatus",pOrder->OrderStatus);
		m_jniUtil.mapPut(m_env,jmap,"orderType",pOrder->OrderType);
		m_jniUtil.mapPut(m_env,jmap,"volumeTraded",pOrder->VolumeTraded);
		m_jniUtil.mapPut(m_env,jmap,"volumeTotal",pOrder->VolumeTotal);
		m_jniUtil.mapPut(m_env,jmap,"insertDate",pOrder->InsertDate);
		m_jniUtil.mapPut(m_env,jmap,"insertTime",pOrder->InsertTime);
		m_jniUtil.mapPut(m_env,jmap,"activeTime",pOrder->ActiveTime);
		m_jniUtil.mapPut(m_env,jmap,"suspendTime",pOrder->SuspendTime);
		m_jniUtil.mapPut(m_env,jmap,"updateTime",pOrder->UpdateTime);
		m_jniUtil.mapPut(m_env,jmap,"cancelTime",pOrder->CancelTime);
		m_jniUtil.mapPut(m_env,jmap,"activeUserID",pOrder->ActiveUserID);
		m_jniUtil.mapPut(m_env,jmap,"priority",pOrder->Priority);
		m_jniUtil.mapPut(m_env,jmap,"timeSortID",pOrder->TimeSortID);
		m_jniUtil.mapPut(m_env,jmap,"clearingPartID",pOrder->ClearingPartID);
		m_jniUtil.mapPut(m_env,jmap,"businessUnit",pOrder->BusinessUnit); 
	}


	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,ErrorID,ErrorMsg,nRequestID,bIsLast);			
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
	
}
///成交单查询应答
void TraderJniSpi::OnRspQryTrade(CQTFtdcTradeField *pTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	int ErrorID=0;
	char *ErrorMsg="正确";
	if(pRspInfo!=NULL){
		ErrorID = pRspInfo->ErrorID;
		ErrorMsg = pRspInfo->ErrorMsg;
	}

	jobject jmap = NULL;
	if(pTrade!=NULL)
	{
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pTrade->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pTrade->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pTrade->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"tradeID",pTrade->TradeID);
		m_jniUtil.mapPut(m_env,jmap,"direction",pTrade->Direction);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pTrade->OrderSysID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pTrade->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pTrade->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"tradingRole",pTrade->TradingRole);
		m_jniUtil.mapPut(m_env,jmap,"accountID",pTrade->AccountID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pTrade->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"offsetFlag",pTrade->OffsetFlag);
		m_jniUtil.mapPut(m_env,jmap,"hedgeFlag",pTrade->HedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"price",pTrade->Price);
		m_jniUtil.mapPut(m_env,jmap,"volume",pTrade->Volume);
		m_jniUtil.mapPut(m_env,jmap,"tradeTime",pTrade->TradeTime);
		m_jniUtil.mapPut(m_env,jmap,"tradeType",pTrade->TradeType);
		m_jniUtil.mapPut(m_env,jmap,"priceSource",pTrade->PriceSource);
		m_jniUtil.mapPut(m_env,jmap,"userID",pTrade->UserID);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pTrade->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"clearingPartID",pTrade->ClearingPartID);
		m_jniUtil.mapPut(m_env,jmap,"businessUnit",pTrade->BusinessUnit); 
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,ErrorID,ErrorMsg,nRequestID,bIsLast);		
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///用户登录检查应答
void TraderJniSpi::OnRspCheckUserLogin(CQTFtdcRspUserLoginField *pRspUserLogin, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pRspUserLogin!=NULL)
	{
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pRspUserLogin->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"loginTime",pRspUserLogin->LoginTime);
		m_jniUtil.mapPut(m_env,jmap,"maxOrderLocalID",pRspUserLogin->MaxOrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pRspUserLogin->UserID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pRspUserLogin->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"tradingSystemName",pRspUserLogin->TradingSystemName);
		m_jniUtil.mapPut(m_env,jmap,"dataCenterID",pRspUserLogin->DataCenterID);
		m_jniUtil.mapPut(m_env,jmap,"privateFlowSize",pRspUserLogin->PrivateFlowSize);		
		m_jniUtil.mapPut(m_env,jmap,"userFlowSize",pRspUserLogin->UserFlowSize);
 
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);		
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///IPO订单录入
void TraderJniSpi::OnRspIPOInsert(CQTFtdcIPOOrderField *pIPOOrder, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pIPOOrder!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pIPOOrder->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pIPOOrder->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pIPOOrder->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pIPOOrder->OrderSysID);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pIPOOrder->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"actionLocalID",pIPOOrder->ActionLocalID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pIPOOrder->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pIPOOrder->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pIPOOrder->UserID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pIPOOrder->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"purchaseType",pIPOOrder->PurchaseType);
		m_jniUtil.mapPut(m_env,jmap,"orderStatus",pIPOOrder->OrderStatus);
		m_jniUtil.mapPut(m_env,jmap,"cancelType",pIPOOrder->CancelType);
		m_jniUtil.mapPut(m_env,jmap,"orderPrice",pIPOOrder->OrderPrice);
		m_jniUtil.mapPut(m_env,jmap,"orderVolume",pIPOOrder->OrderVolume);
		m_jniUtil.mapPut(m_env,jmap,"tradeVolume",pIPOOrder->TradeVolume);
		m_jniUtil.mapPut(m_env,jmap,"orderFrozenMoney",pIPOOrder->OrderFrozenMoney);
		m_jniUtil.mapPut(m_env,jmap,"prePayFee",pIPOOrder->PrePayFee);
		m_jniUtil.mapPut(m_env,jmap,"returnFee",pIPOOrder->ReturnFee);
		m_jniUtil.mapPut(m_env,jmap,"orderDate",pIPOOrder->OrderDate);
		m_jniUtil.mapPut(m_env,jmap,"insertTime",pIPOOrder->InsertTime);
		m_jniUtil.mapPut(m_env,jmap,"cancelDate",pIPOOrder->CancelDate);
		m_jniUtil.mapPut(m_env,jmap,"cancelTime",pIPOOrder->CancelTime);
		m_jniUtil.mapPut(m_env,jmap,"startSeqNo",pIPOOrder->StartSeqNo);
		m_jniUtil.mapPut(m_env,jmap,"endSeqNo",pIPOOrder->EndSeqNo);
		m_jniUtil.mapPut(m_env,jmap,"settleDate",pIPOOrder->SettleDate);
		m_jniUtil.mapPut(m_env,jmap,"orderSource",pIPOOrder->OrderSource);
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///IPO订单修改返回
void TraderJniSpi::OnRspIPOAction(CQTFtdcIPOActionField *pIPOAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pIPOAction!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pIPOAction->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pIPOAction->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pIPOAction->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pIPOAction->OrderSysID);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pIPOAction->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"actionLocalID",pIPOAction->ActionLocalID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pIPOAction->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pIPOAction->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pIPOAction->UserID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pIPOAction->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"purchaseType",pIPOAction->PurchaseType);
		m_jniUtil.mapPut(m_env,jmap,"orderStatus",pIPOAction->OrderStatus);
		m_jniUtil.mapPut(m_env,jmap,"cancelType",pIPOAction->CancelType);
		m_jniUtil.mapPut(m_env,jmap,"orderPrice",pIPOAction->OrderPrice);
		m_jniUtil.mapPut(m_env,jmap,"orderVolume",pIPOAction->OrderVolume);
		m_jniUtil.mapPut(m_env,jmap,"tradeVolume",pIPOAction->TradeVolume);
		m_jniUtil.mapPut(m_env,jmap,"orderFrozenMoney",pIPOAction->OrderFrozenMoney);
		m_jniUtil.mapPut(m_env,jmap,"prePayFee",pIPOAction->PrePayFee);
		m_jniUtil.mapPut(m_env,jmap,"returnFee",pIPOAction->ReturnFee);
		m_jniUtil.mapPut(m_env,jmap,"orderDate",pIPOAction->OrderDate);
		m_jniUtil.mapPut(m_env,jmap,"insertTime",pIPOAction->InsertTime);
		m_jniUtil.mapPut(m_env,jmap,"cancelDate",pIPOAction->CancelDate);
		m_jniUtil.mapPut(m_env,jmap,"cancelTime",pIPOAction->CancelTime);
		m_jniUtil.mapPut(m_env,jmap,"startSeqNo",pIPOAction->StartSeqNo);
		m_jniUtil.mapPut(m_env,jmap,"endSeqNo",pIPOAction->EndSeqNo);
		m_jniUtil.mapPut(m_env,jmap,"settleDate",pIPOAction->SettleDate);
		m_jniUtil.mapPut(m_env,jmap,"orderSource",pIPOAction->OrderSource);
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///场外成交对申报应答
void TraderJniSpi::OnRspOTCTradeInsert(CQTFtdcInputOTCTradeField *pInputOTCTrade, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pInputOTCTrade!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradeID",pInputOTCTrade->TradeID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pInputOTCTrade->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pInputOTCTrade->UserID);
		m_jniUtil.mapPut(m_env,jmap,"tradeLocalID",pInputOTCTrade->TradeLocalID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pInputOTCTrade->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"price",pInputOTCTrade->Price);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pInputOTCTrade->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"volume",pInputOTCTrade->Volume);
		m_jniUtil.mapPut(m_env,jmap,"buyParticipantID",pInputOTCTrade->BuyParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"buyClientID",pInputOTCTrade->BuyClientID);
		m_jniUtil.mapPut(m_env,jmap,"buyUserID",pInputOTCTrade->BuyUserID);
		m_jniUtil.mapPut(m_env,jmap,"buyOrderLocalID",pInputOTCTrade->BuyOrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"buyCombOffsetFlag",pInputOTCTrade->BuyCombOffsetFlag);
		m_jniUtil.mapPut(m_env,jmap,"buyCombHedgeFlag",pInputOTCTrade->BuyCombHedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"sellParticipantID",pInputOTCTrade->SellParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"sellClientID",pInputOTCTrade->SellClientID);
		m_jniUtil.mapPut(m_env,jmap,"sellUserID",pInputOTCTrade->SellUserID);
		m_jniUtil.mapPut(m_env,jmap,"sellCombOffsetFlag",pInputOTCTrade->SellCombOffsetFlag);
		m_jniUtil.mapPut(m_env,jmap,"sellCombHedgeFlag",pInputOTCTrade->SellCombHedgeFlag);
		m_jniUtil.mapPut(m_env,jmap,"sellOrderLocalID",pInputOTCTrade->SellOrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"OTCType",pInputOTCTrade->OTCType);
		m_jniUtil.mapPut(m_env,jmap,"status",pInputOTCTrade->Status);
		m_jniUtil.mapPut(m_env,jmap,"OTCErrorID",pInputOTCTrade->OTCErrorID);
		m_jniUtil.mapPut(m_env,jmap,"OTCErrorMsg",pInputOTCTrade->OTCErrorMsg);
		m_jniUtil.mapPut(m_env,jmap,"comments",pInputOTCTrade->Comments);
		m_jniUtil.mapPut(m_env,jmap,"tradeMoney",pInputOTCTrade->TradeMoney);		
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}

}

///持仓划转应答
void TraderJniSpi::OnRspPositionChange(CQTFtdcPositionChangeField *pPositionChange, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pPositionChange!=NULL){
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pPositionChange->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pPositionChange->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pPositionChange->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pPositionChange->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"clientID",pPositionChange->ClientID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pPositionChange->UserID);
		m_jniUtil.mapPut(m_env,jmap,"instrumentID",pPositionChange->InstrumentID);
		m_jniUtil.mapPut(m_env,jmap,"transVolume",pPositionChange->TransVolume);
		m_jniUtil.mapPut(m_env,jmap,"transType",pPositionChange->TransType);
		m_jniUtil.mapPut(m_env,jmap,"orderLocalID",pPositionChange->OrderLocalID);
		m_jniUtil.mapPut(m_env,jmap,"orderSource",pPositionChange->OrderSource);
		m_jniUtil.mapPut(m_env,jmap,"depotPwd",pPositionChange->DepotPwd);
		m_jniUtil.mapPut(m_env,jmap,"warrantID",pPositionChange->WarrantID);
		m_jniUtil.mapPut(m_env,jmap,"transStatus",pPositionChange->TransStatus);
		m_jniUtil.mapPut(m_env,jmap,"transFrozenMoney",pPositionChange->TransFrozenMoney);
		m_jniUtil.mapPut(m_env,jmap,"prePayFee",pPositionChange->PrePayFee);
		m_jniUtil.mapPut(m_env,jmap,"orderDate",pPositionChange->OrderDate);
		m_jniUtil.mapPut(m_env,jmap,"insertTime",pPositionChange->InsertTime);
		m_jniUtil.mapPut(m_env,jmap,"orderSysID",pPositionChange->OrderSysID);

	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///用户出入金应答
void TraderJniSpi::OnRspAccountDeposit(CQTFtdcInvestorDepositResField *pInvestorDepositRes, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pInvestorDepositRes!=NULL){		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pInvestorDepositRes->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pInvestorDepositRes->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pInvestorDepositRes->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"preBalance",pInvestorDepositRes->PreBalance);
		m_jniUtil.mapPut(m_env,jmap,"currMargin",pInvestorDepositRes->CurrMargin);
		m_jniUtil.mapPut(m_env,jmap,"closeProfit",pInvestorDepositRes->CloseProfit);
		m_jniUtil.mapPut(m_env,jmap,"premium",pInvestorDepositRes->Premium);
		m_jniUtil.mapPut(m_env,jmap,"deposit",pInvestorDepositRes->Deposit);
		m_jniUtil.mapPut(m_env,jmap,"withdraw",pInvestorDepositRes->Withdraw);
		m_jniUtil.mapPut(m_env,jmap,"balance",pInvestorDepositRes->Balance);
		m_jniUtil.mapPut(m_env,jmap,"available",pInvestorDepositRes->Available);
		m_jniUtil.mapPut(m_env,jmap,"accountID",pInvestorDepositRes->AccountID);
		m_jniUtil.mapPut(m_env,jmap,"frozenMargin",pInvestorDepositRes->FrozenMargin);
		m_jniUtil.mapPut(m_env,jmap,"frozenPremium",pInvestorDepositRes->FrozenPremium);
		m_jniUtil.mapPut(m_env,jmap,"spotMoney",pInvestorDepositRes->SpotMoney);
		m_jniUtil.mapPut(m_env,jmap,"frozenSpotMoney",pInvestorDepositRes->FrozenSpotMoney);
		m_jniUtil.mapPut(m_env,jmap,"fee",pInvestorDepositRes->Fee);
		m_jniUtil.mapPut(m_env,jmap,"frozenFee",pInvestorDepositRes->FrozenFee);
		m_jniUtil.mapPut(m_env,jmap,"frozenIPOMoney",pInvestorDepositRes->FrozenIPOMoney);
		m_jniUtil.mapPut(m_env,jmap,"frozenMoney",pInvestorDepositRes->FrozenMoney);
		m_jniUtil.mapPut(m_env,jmap,"sellMoney",pInvestorDepositRes->SellMoney);
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///结算组数据同步状态改变应答
void TraderJniSpi::OnRspSGDataSyncStatusUpdate(CQTFtdcSGDataSyncStatusField *pSGDataSyncStatus, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pSGDataSyncStatus!=NULL){		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"settlementGroupID",pSGDataSyncStatus->SettlementGroupID);
		m_jniUtil.mapPut(m_env,jmap,"tradingDay",pSGDataSyncStatus->TradingDay);
		m_jniUtil.mapPut(m_env,jmap,"settlementID",pSGDataSyncStatus->SettlementID);
		m_jniUtil.mapPut(m_env,jmap,"SGDataSyncStatus",pSGDataSyncStatus->SGDataSyncStatus);		 
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///强制用户退出应答
void TraderJniSpi::OnRspForceUserExit(CQTFtdcForceUserExitField *pForceUserExit, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pForceUserExit!=NULL){		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pForceUserExit->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pForceUserExit->UserID); 
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}

///交易用户修改应答
void TraderJniSpi::OnRspUserAction(CQTFtdcUserActionField *pUserAction, CQTFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	if(pRspInfo==NULL){
		m_jniUtil.print(m_env,m_jniTemplate,"pRspInfo is null");
		return;
	}
	jobject jmap = NULL;
	if(pUserAction!=NULL){		
		jmap = m_jniUtil.newHashMap(m_env);
		m_jniUtil.mapPut(m_env,jmap,"participantID",pUserAction->ParticipantID);
		m_jniUtil.mapPut(m_env,jmap,"userID",pUserAction->UserID); 
		m_jniUtil.mapPut(m_env,jmap,"userType",pUserAction->UserType); 
		m_jniUtil.mapPut(m_env,jmap,"password",pUserAction->Password); 
		m_jniUtil.mapPut(m_env,jmap,"isActive",pUserAction->IsActive); 
		m_jniUtil.mapPut(m_env,jmap,"userActionType",pUserAction->UserActionType);
		m_jniUtil.mapPut(m_env,jmap,"oldPassword",pUserAction->OldPassword);
	}
	m_jniUtil.jcOnResponse(m_env,m_jniTemplate,jmap,pRspInfo->ErrorID,pRspInfo->ErrorMsg,nRequestID,bIsLast);	
	if(jmap!=NULL){
		m_env->DeleteLocalRef(jmap);
	}
}
