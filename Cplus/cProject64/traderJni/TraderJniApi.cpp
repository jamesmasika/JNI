#include "TraderJniApi.h"
#include <string.h>

TraderJniApi::TraderJniApi(CQTFtdcUserApi *userApi){
	this->m_userApi = userApi;
}

//密码修改接口
int TraderJniApi::reqUserPasswordUpdate(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *oldPassword = m_jniUtil.getStringByMap(env,reqMap,"oldPassword");
	const char *newPassword = m_jniUtil.getStringByMap(env,reqMap,"newPassword");

	CQTFtdcUserPasswordUpdateField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcUserPasswordUpdateField));
	strcpy(request.UserID, userID);
	strcpy(request.ParticipantID, participantID);
	strcpy(request.OldPassword, oldPassword);
	strcpy(request.NewPassword, newPassword);
	return this->m_userApi->ReqUserPasswordUpdate(&request,nRequestID);	 
}
//报单录入请求
int TraderJniApi::reqOrderInsert(JNIEnv *env,jobject reqMap, jint nRequestID){	 
	 const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");	 
	 const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");	 
	 const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");	 
	 const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");	 
	 const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	 char orderPriceType = m_jniUtil.getCharByMap(env,reqMap,"orderPriceType");
	 char direction = m_jniUtil.getCharByMap(env,reqMap,"direction");
	 const char *combOffsetFlag = m_jniUtil.getStringByMap(env,reqMap,"combOffsetFlag");
	 const char *combHedgeFlag = m_jniUtil.getStringByMap(env,reqMap,"combHedgeFlag");	 
	 double limitPrice = m_jniUtil.getDoubleByMap(env,reqMap,"limitPrice");	 
	 int volumeTotalOriginal = m_jniUtil.getIntByMap(env,reqMap,"volumeTotalOriginal");	
	 char timeCondition = m_jniUtil.getCharByMap(env,reqMap,"timeCondition");
	 const char *gTDDate = m_jniUtil.getStringByMap(env,reqMap,"GTDDate");
	 char volumeCondition = m_jniUtil.getCharByMap(env,reqMap,"volumeCondition");
	 int minVolume = m_jniUtil.getIntByMap(env,reqMap,"minVolume");	
	 char contingentCondition = m_jniUtil.getCharByMap(env,reqMap,"contingentCondition");
	 double stopPrice = m_jniUtil.getDoubleByMap(env,reqMap,"stopPrice");	 
	 char forceCloseReason = m_jniUtil.getCharByMap(env,reqMap,"forceCloseReason");
	 const char *orderLocalID = m_jniUtil.getStringByMap(env,reqMap,"orderLocalID");
	 int isAutoSuspend = m_jniUtil.getIntByMap(env,reqMap,"isAutoSuspend");
	 const char *businessUnit = m_jniUtil.getStringByMap(env,reqMap,"businessUnit");
	 	 

	 CQTFtdcInputOrderField pInputOrder;
	 //初始化请求对象
	 memset(&pInputOrder, 0, sizeof(CQTFtdcInputOrderField));
	 strcpy(pInputOrder.OrderSysID, orderSysID);	 
	 strcpy(pInputOrder.ParticipantID, participantID);
	 strcpy(pInputOrder.ClientID, clientID);
	 strcpy(pInputOrder.UserID, userID);
	 strcpy(pInputOrder.InstrumentID, instrumentID);
	 pInputOrder.OrderPriceType = orderPriceType;	 
	 pInputOrder.Direction = direction;	
	 strcpy(pInputOrder.CombOffsetFlag, combOffsetFlag);
	 strcpy(pInputOrder.CombHedgeFlag, combHedgeFlag);
	 pInputOrder.LimitPrice = limitPrice;
	 pInputOrder.VolumeTotalOriginal = volumeTotalOriginal;	 
	 pInputOrder.TimeCondition = timeCondition;
	 strcpy(pInputOrder.GTDDate, gTDDate);	 
	 pInputOrder.VolumeCondition = volumeCondition;	 
	 pInputOrder.MinVolume = minVolume;	 
	 pInputOrder.ContingentCondition = contingentCondition;	 
	 pInputOrder.StopPrice = stopPrice;	 
	 pInputOrder.ForceCloseReason = forceCloseReason;	 
	 strcpy(pInputOrder.OrderLocalID, orderLocalID);	 	 
	 pInputOrder.IsAutoSuspend = isAutoSuspend;	 
	 strcpy(pInputOrder.BusinessUnit, businessUnit);	

	 return this->m_userApi->ReqOrderInsert(&pInputOrder,nRequestID);	 
}

//报单操作请求
int TraderJniApi::reqOrderAction(JNIEnv *env,jobject reqMap, jint nRequestID){	   		
	 const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");
	 const char *orderLocalID = m_jniUtil.getStringByMap(env,reqMap,"orderLocalID");
	 char actionFlag = m_jniUtil.getCharByMap(env,reqMap,"actionFlag");
	 const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
     const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");	 
	 const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");	 
	 double limitPrice = m_jniUtil.getDoubleByMap(env,reqMap,"limitPrice");
	 int volumeChange = m_jniUtil.getIntByMap(env,reqMap,"volumeChange");
	 const char *actionLocalID = m_jniUtil.getStringByMap(env,reqMap,"actionLocalID");
	 const char *businessUnit = m_jniUtil.getStringByMap(env,reqMap,"businessUnit");
	 
	  	 	 	 	 
	 CQTFtdcOrderActionField pOrderAction;
	//初始化请求对象
	memset(&pOrderAction, 0, sizeof(CQTFtdcOrderActionField));
	 strcpy(pOrderAction.OrderSysID, orderSysID);
	 strcpy(pOrderAction.OrderLocalID, orderLocalID);	 
	 pOrderAction.ActionFlag = actionFlag;		  
	 strcpy(pOrderAction.ParticipantID, participantID);
	 strcpy(pOrderAction.ClientID, clientID);
	 strcpy(pOrderAction.UserID, userID);	 
	 pOrderAction.LimitPrice = limitPrice;	
	 pOrderAction.VolumeChange = volumeChange;	
	 strcpy(pOrderAction.ActionLocalID, actionLocalID);
	 strcpy(pOrderAction.BusinessUnit, businessUnit);
	 
	 
	 
	 return this->m_userApi->ReqOrderAction(&pOrderAction,nRequestID);
}

//会员资金查询请求
int TraderJniApi::reqQryPartAccount(JNIEnv *env,jobject reqMap, jint nRequestID){
	
	const char *partIDStart = m_jniUtil.getStringByMap(env,reqMap,"partIDStart");
	const char *partIDEnd = m_jniUtil.getStringByMap(env,reqMap,"partIDEnd");
	const char *accountID = m_jniUtil.getStringByMap(env,reqMap,"accountID");	

	CQTFtdcQryPartAccountField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcQryPartAccountField));
	strcpy(request.PartIDStart, partIDStart);
	strcpy(request.PartIDEnd, partIDEnd);
	strcpy(request.AccountID, accountID);	
	return this->m_userApi->ReqQryPartAccount(&request,nRequestID);	 
}

///客户持仓查询请求
int TraderJniApi::reqQryClientPosition(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *partIDStart = m_jniUtil.getStringByMap(env,reqMap,"partIDStart");
	const char *partIDEnd = m_jniUtil.getStringByMap(env,reqMap,"partIDEnd");
	const char *clientIDStart = m_jniUtil.getStringByMap(env,reqMap,"clientIDStart");	
	const char *clientIDEnd = m_jniUtil.getStringByMap(env,reqMap,"clientIDEnd");	
	const char *instIDStart = m_jniUtil.getStringByMap(env,reqMap,"instIDStart");
	const char *instIDEnd = m_jniUtil.getStringByMap(env,reqMap,"instIDEnd");
	char clientType = m_jniUtil.getCharByMap(env,reqMap,"clientType");

	CQTFtdcQryClientPositionField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcQryClientPositionField));
	strcpy(request.PartIDStart, partIDStart);
	strcpy(request.PartIDEnd, partIDEnd);
	strcpy(request.ClientIDStart, clientIDStart);	
	strcpy(request.ClientIDEnd, clientIDEnd);	
	strcpy(request.InstIDStart, instIDStart);	
	strcpy(request.InstIDEnd, instIDEnd);	
	request.ClientType=clientType;
	return this->m_userApi->ReqQryClientPosition(&request,nRequestID);	 	
}

///报单查询请求
int TraderJniApi::reqQryOrder(JNIEnv *env,jobject reqMap, jint nRequestID){	
	const char *partIDStart = m_jniUtil.getStringByMap(env,reqMap,"partIDStart");
	const char *partIDEnd = m_jniUtil.getStringByMap(env,reqMap,"partIDEnd");
	const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");
	const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *timeStart = m_jniUtil.getStringByMap(env,reqMap,"timeStart");
	const char *timeEnd = m_jniUtil.getStringByMap(env,reqMap,"timeEnd");

	CQTFtdcQryOrderField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcQryOrderField));
	strcpy(request.PartIDStart, partIDStart);
	strcpy(request.PartIDEnd, partIDEnd);
	strcpy(request.OrderSysID, orderSysID);
	strcpy(request.InstrumentID, instrumentID);
	strcpy(request.ClientID, clientID);
	strcpy(request.UserID, userID);
	strcpy(request.TimeStart, timeStart);
	strcpy(request.TimeEnd, timeEnd);
	return this->m_userApi->ReqQryOrder(&request,nRequestID);	 		
}
///成交单查询请求
int TraderJniApi::reqQryTrade(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *partIDStart = m_jniUtil.getStringByMap(env,reqMap,"partIDStart");
	const char *partIDEnd = m_jniUtil.getStringByMap(env,reqMap,"partIDEnd");
	const char *instIDStart = m_jniUtil.getStringByMap(env,reqMap,"instIDStart");
	const char *instIDEnd = m_jniUtil.getStringByMap(env,reqMap,"instIDEnd");
	const char *tradeID = m_jniUtil.getStringByMap(env,reqMap,"tradeID");
	const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *timeStart = m_jniUtil.getStringByMap(env,reqMap,"timeStart");
	const char *timeEnd = m_jniUtil.getStringByMap(env,reqMap,"timeEnd");

	CQTFtdcQryTradeField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcQryTradeField));
	strcpy(request.PartIDStart, partIDStart);
	strcpy(request.PartIDEnd, partIDEnd);
	strcpy(request.InstIDStart, instIDStart);
	strcpy(request.InstIDEnd, instIDEnd);
	strcpy(request.TradeID, tradeID);
	strcpy(request.ClientID, clientID);
	strcpy(request.UserID, userID);
	strcpy(request.TimeStart, timeStart);
	strcpy(request.TimeEnd, timeEnd);
	return this->m_userApi->ReqQryTrade(&request,nRequestID);	 	
}

///用户登录检查请求
int TraderJniApi::reqCheckUserLogin(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *tradingDay = m_jniUtil.getStringByMap(env,reqMap,"tradingDay");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *password = m_jniUtil.getStringByMap(env,reqMap,"password");
	const char *userProductInfo = m_jniUtil.getStringByMap(env,reqMap,"userProductInfo");
	const char *interfaceProductInfo = m_jniUtil.getStringByMap(env,reqMap,"interfaceProductInfo");
	const char *protocolInfo = m_jniUtil.getStringByMap(env,reqMap,"protocolInfo");
	int dataCenterID = m_jniUtil.getIntByMap(env,reqMap,"dataCenterID");

	CQTFtdcReqUserLoginField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcReqUserLoginField));
	strcpy(request.TradingDay, tradingDay);
	strcpy(request.UserID, userID);
	strcpy(request.ParticipantID, participantID);
	strcpy(request.Password, password);
	strcpy(request.UserProductInfo, userProductInfo);
	strcpy(request.InterfaceProductInfo, interfaceProductInfo);
	strcpy(request.ProtocolInfo, protocolInfo);
	request.DataCenterID = dataCenterID;

	return this->m_userApi->ReqCheckUserLogin(&request,nRequestID);
}

///IPO订单录入
int TraderJniApi::reqIPOInsert(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *tradingDay = m_jniUtil.getStringByMap(env,reqMap,"tradingDay");
	const char *settlementGroupID = m_jniUtil.getStringByMap(env,reqMap,"settlementGroupID");
	int settlementID = m_jniUtil.getIntByMap(env,reqMap,"settlementID");
	const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");
	const char *orderLocalID = m_jniUtil.getStringByMap(env,reqMap,"orderLocalID");
	const char *actionLocalID = m_jniUtil.getStringByMap(env,reqMap,"actionLocalID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	char purchaseType = m_jniUtil.getCharByMap(env,reqMap,"purchaseType");
	char orderStatus = m_jniUtil.getCharByMap(env,reqMap,"orderStatus");
	char cancelType = m_jniUtil.getCharByMap(env,reqMap,"cancelType");
	double orderPrice = m_jniUtil.getDoubleByMap(env,reqMap,"orderPrice");
	int orderVolume = m_jniUtil.getIntByMap(env,reqMap,"orderVolume");
	int tradeVolume = m_jniUtil.getIntByMap(env,reqMap,"tradeVolume");
    double orderFrozenMoney = m_jniUtil.getDoubleByMap(env,reqMap,"orderFrozenMoney");
	double prePayFee = m_jniUtil.getDoubleByMap(env,reqMap,"prePayFee");
	double returnFee = m_jniUtil.getDoubleByMap(env,reqMap,"returnFee");
	const char *orderDate = m_jniUtil.getStringByMap(env,reqMap,"orderDate");
	const char *insertTime = m_jniUtil.getStringByMap(env,reqMap,"insertTime");
	const char *cancelDate = m_jniUtil.getStringByMap(env,reqMap,"cancelDate");
	const char *cancelTime = m_jniUtil.getStringByMap(env,reqMap,"cancelTime");
    const char *startSeqNo = m_jniUtil.getStringByMap(env,reqMap,"startSeqNo");
	const char *endSeqNo = m_jniUtil.getStringByMap(env,reqMap,"endSeqNo");
	const char *settleDate = m_jniUtil.getStringByMap(env,reqMap,"settleDate");
	char orderSource = m_jniUtil.getCharByMap(env,reqMap,"orderSource");
	

	CQTFtdcIPOOrderField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcIPOOrderField));
	strcpy(request.TradingDay, tradingDay);
	strcpy(request.SettlementGroupID, settlementGroupID);
	request.SettlementID = settlementID;
	strcpy(request.OrderSysID, orderSysID);
	strcpy(request.OrderLocalID, orderLocalID);
	strcpy(request.ActionLocalID, actionLocalID);
	strcpy(request.ParticipantID, participantID);
	strcpy(request.ClientID, clientID);
	strcpy(request.UserID, userID);
	strcpy(request.InstrumentID, instrumentID);
	request.PurchaseType = purchaseType;
	request.OrderStatus = orderStatus;
	request.CancelType = cancelType;
	request.OrderPrice = orderPrice;
	request.OrderVolume = orderVolume;
	request.TradeVolume = tradeVolume;
	request.OrderFrozenMoney = orderFrozenMoney;
	request.PrePayFee = prePayFee;
	request.ReturnFee = returnFee;
	strcpy(request.OrderDate, orderDate);
	strcpy(request.InsertTime, insertTime);
	strcpy(request.CancelDate, cancelDate);
	strcpy(request.CancelDate, cancelDate);
	strcpy(request.StartSeqNo, startSeqNo);
	strcpy(request.EndSeqNo, endSeqNo);
	strcpy(request.SettleDate, settleDate);
	request.OrderSource = orderSource;
	

	return this->m_userApi->ReqIPOInsert(&request,nRequestID);
}

///IPO申购撤单
int TraderJniApi::reqIPOAction(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *tradingDay = m_jniUtil.getStringByMap(env,reqMap,"tradingDay");
	const char *settlementGroupID = m_jniUtil.getStringByMap(env,reqMap,"settlementGroupID");
	int settlementID = m_jniUtil.getIntByMap(env,reqMap,"settlementID");
	const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");
	const char *orderLocalID = m_jniUtil.getStringByMap(env,reqMap,"orderLocalID");
	const char *actionLocalID = m_jniUtil.getStringByMap(env,reqMap,"actionLocalID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	char purchaseType = m_jniUtil.getCharByMap(env,reqMap,"purchaseType");
	char orderStatus = m_jniUtil.getCharByMap(env,reqMap,"orderStatus");
	char cancelType = m_jniUtil.getCharByMap(env,reqMap,"cancelType");
	double orderPrice = m_jniUtil.getDoubleByMap(env,reqMap,"orderPrice");
	int orderVolume = m_jniUtil.getIntByMap(env,reqMap,"orderVolume");
	int tradeVolume = m_jniUtil.getIntByMap(env,reqMap,"tradeVolume");
    double orderFrozenMoney = m_jniUtil.getDoubleByMap(env,reqMap,"orderFrozenMoney");
	double prePayFee = m_jniUtil.getDoubleByMap(env,reqMap,"prePayFee");
	double returnFee = m_jniUtil.getDoubleByMap(env,reqMap,"returnFee");
	const char *orderDate = m_jniUtil.getStringByMap(env,reqMap,"orderDate");
	const char *insertTime = m_jniUtil.getStringByMap(env,reqMap,"insertTime");
	const char *cancelDate = m_jniUtil.getStringByMap(env,reqMap,"cancelDate");
	const char *cancelTime = m_jniUtil.getStringByMap(env,reqMap,"cancelTime");
    const char *startSeqNo = m_jniUtil.getStringByMap(env,reqMap,"startSeqNo");
	const char *endSeqNo = m_jniUtil.getStringByMap(env,reqMap,"endSeqNo");
	const char *settleDate = m_jniUtil.getStringByMap(env,reqMap,"settleDate");
	char orderSource = m_jniUtil.getCharByMap(env,reqMap,"orderSource");

	CQTFtdcIPOActionField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcIPOActionField));
	strcpy(request.TradingDay, tradingDay);
	strcpy(request.SettlementGroupID, settlementGroupID);
	request.SettlementID = settlementID;
	strcpy(request.OrderSysID, orderSysID);
	strcpy(request.OrderLocalID, orderLocalID);
	strcpy(request.ActionLocalID, actionLocalID);
	strcpy(request.ParticipantID, participantID);
	strcpy(request.ClientID, clientID);
	strcpy(request.UserID, userID);
	strcpy(request.InstrumentID, instrumentID);
	request.PurchaseType = purchaseType;
	request.OrderStatus = orderStatus;
	request.CancelType = cancelType;
	request.OrderPrice = orderPrice;
	request.OrderVolume = orderVolume;
	request.TradeVolume = tradeVolume;
	request.OrderFrozenMoney = orderFrozenMoney;
	request.PrePayFee = prePayFee;
	request.ReturnFee = returnFee;
	strcpy(request.OrderDate, orderDate);
	strcpy(request.InsertTime, insertTime);
	strcpy(request.CancelDate, cancelDate);
	strcpy(request.CancelDate, cancelDate);
	strcpy(request.StartSeqNo, startSeqNo);
	strcpy(request.EndSeqNo, endSeqNo);
	strcpy(request.SettleDate, settleDate);
	request.OrderSource = orderSource;

	return this->m_userApi->ReqIPOAction(&request,nRequestID);
}

///大宗交易\持仓过户
int TraderJniApi::reqOTCTradeInsert(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *tradeID = m_jniUtil.getStringByMap(env,reqMap,"tradeID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *tradeLocalID = m_jniUtil.getStringByMap(env,reqMap,"tradeLocalID");
	const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	double price = m_jniUtil.getDoubleByMap(env,reqMap,"price");
	int volume = m_jniUtil.getIntByMap(env,reqMap,"volume");
	const char *buyParticipantID = m_jniUtil.getStringByMap(env,reqMap,"buyParticipantID");
	const char *buyClientID = m_jniUtil.getStringByMap(env,reqMap,"buyClientID");
	const char *buyUserID = m_jniUtil.getStringByMap(env,reqMap,"buyUserID");
	const char *buyOrderLocalID = m_jniUtil.getStringByMap(env,reqMap,"buyOrderLocalID");
	const char *buyCombOffsetFlag = m_jniUtil.getStringByMap(env,reqMap,"buyCombOffsetFlag");
	const char *buyCombHedgeFlag = m_jniUtil.getStringByMap(env,reqMap,"buyCombHedgeFlag");
	const char *sellParticipantID = m_jniUtil.getStringByMap(env,reqMap,"sellParticipantID");
	const char *sellClientID = m_jniUtil.getStringByMap(env,reqMap,"sellClientID");
	const char *sellUserID = m_jniUtil.getStringByMap(env,reqMap,"sellUserID");
	const char *sellCombOffsetFlag = m_jniUtil.getStringByMap(env,reqMap,"sellCombOffsetFlag");
	const char *sellCombHedgeFlag = m_jniUtil.getStringByMap(env,reqMap,"sellCombHedgeFlag");
	const char *sellOrderLocalID = m_jniUtil.getStringByMap(env,reqMap,"sellOrderLocalID");
	char oTCType = m_jniUtil.getCharByMap(env,reqMap,"OTCType");	
	char status = m_jniUtil.getCharByMap(env,reqMap,"status");
	int oTCErrorID = m_jniUtil.getIntByMap(env,reqMap,"OTCErrorID");
	const char *oTCErrorMsg = m_jniUtil.getStringByMap(env,reqMap,"OTCErrorMsg");
	const char *comments = m_jniUtil.getStringByMap(env,reqMap,"comments");
	double tradeMoney = m_jniUtil.getDoubleByMap(env,reqMap,"tradeMoney");	

	CQTFtdcInputOTCTradeField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcInputOTCTradeField));
	strcpy(request.TradeID, tradeID);
	strcpy(request.ParticipantID, participantID);
	strcpy(request.UserID, userID);
	strcpy(request.TradeLocalID, tradeLocalID);
	strcpy(request.InstrumentID, instrumentID);
	request.Price = price;
	request.Volume = volume;
	strcpy(request.BuyParticipantID, buyParticipantID);
	strcpy(request.BuyClientID, buyClientID);
	strcpy(request.BuyUserID, buyUserID);
	strcpy(request.BuyOrderLocalID, buyOrderLocalID);
	strcpy(request.BuyCombOffsetFlag, buyCombOffsetFlag);
	strcpy(request.BuyCombHedgeFlag, buyCombHedgeFlag);
	strcpy(request.SellParticipantID, sellParticipantID);
	strcpy(request.SellClientID, sellClientID);
	strcpy(request.SellUserID, sellUserID);
	strcpy(request.SellCombOffsetFlag, sellCombOffsetFlag);
	strcpy(request.SellCombHedgeFlag, sellCombHedgeFlag);
	strcpy(request.SellOrderLocalID, sellOrderLocalID);
	request.OTCType = oTCType;
	request.Status = status;
	request.OTCErrorID = oTCErrorID;
	strcpy(request.OTCErrorMsg, oTCErrorMsg);
	strcpy(request.Comments, comments);
	request.TradeMoney = tradeMoney;
	return this->m_userApi->ReqOTCTradeInsert(&request,nRequestID);
}
///持仓冻结/解冻/减持/限售
int TraderJniApi::reqPositionChange(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *tradingDay = m_jniUtil.getStringByMap(env,reqMap,"tradingDay");
	const char *settlementGroupID = m_jniUtil.getStringByMap(env,reqMap,"settlementGroupID");
	int settlementID = m_jniUtil.getIntByMap(env,reqMap,"settlementID");
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *clientID = m_jniUtil.getStringByMap(env,reqMap,"clientID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	const char *instrumentID = m_jniUtil.getStringByMap(env,reqMap,"instrumentID");
	int transVolume = m_jniUtil.getIntByMap(env,reqMap,"transVolume");
	char transType = m_jniUtil.getCharByMap(env,reqMap,"transType");
	const char *orderLocalID = m_jniUtil.getStringByMap(env,reqMap,"orderLocalID");
	char orderSource = m_jniUtil.getCharByMap(env,reqMap,"orderSource");
	const char *depotPwd = m_jniUtil.getStringByMap(env,reqMap,"depotPwd");
	const char *warrantID = m_jniUtil.getStringByMap(env,reqMap,"warrantID");
	char transStatus = m_jniUtil.getCharByMap(env,reqMap,"transStatus");
	double transFrozenMoney = m_jniUtil.getDoubleByMap(env,reqMap,"transFrozenMoney");
	double prePayFee = m_jniUtil.getDoubleByMap(env,reqMap,"prePayFee");
	const char *orderDate = m_jniUtil.getStringByMap(env,reqMap,"orderDate");
	const char *insertTime = m_jniUtil.getStringByMap(env,reqMap,"insertTime");
	const char *orderSysID = m_jniUtil.getStringByMap(env,reqMap,"orderSysID");
	const char *businessTable = m_jniUtil.getStringByMap(env,reqMap,"businessTable");
	const char *businessKey = m_jniUtil.getStringByMap(env,reqMap,"businessKey");
	char posDealType = m_jniUtil.getCharByMap(env,reqMap,"posDealType");
	char accountActionType = m_jniUtil.getCharByMap(env,reqMap,"accountActionType");
	const char *comments = m_jniUtil.getStringByMap(env,reqMap,"comments");

	CQTFtdcPositionChangeField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcPositionChangeField));
	strcpy(request.TradingDay, tradingDay);
	strcpy(request.SettlementGroupID, settlementGroupID);
	request.SettlementID = settlementID;
	strcpy(request.ParticipantID, participantID);
	strcpy(request.ClientID, clientID);
	strcpy(request.UserID, userID);
	strcpy(request.InstrumentID, instrumentID);
	request.TransVolume = transVolume;
	request.TransType = transType;
	strcpy(request.OrderLocalID, orderLocalID);
	request.OrderSource = orderSource;
	strcpy(request.DepotPwd, depotPwd);
	strcpy(request.WarrantID, warrantID);
	request.TransStatus = transStatus;
	request.TransFrozenMoney = transFrozenMoney;
	request.PrePayFee = prePayFee;
	strcpy(request.OrderDate, orderDate);
	strcpy(request.InsertTime, insertTime);
	strcpy(request.OrderSysID, orderSysID);		
	strcpy(request.BusinessTable, businessTable);
	strcpy(request.BusinessKey, businessKey);
	request.PosDealType = posDealType;
	request.AccountActionType = accountActionType;
	strcpy(request.Comments, comments);

	return this->m_userApi->ReqPositionChange(&request,nRequestID);
}
///资金冻结、解冻、出入金
int TraderJniApi::reqAccountDeposit(JNIEnv *env,jobject reqMap, jint nRequestID){
	const char *settlementGroupID = m_jniUtil.getStringByMap(env,reqMap,"settlementGroupID");
	const char *accountID = m_jniUtil.getStringByMap(env,reqMap,"accountID");
	double deposit = m_jniUtil.getDoubleByMap(env,reqMap,"deposit");
	char actionType = m_jniUtil.getCharByMap(env,reqMap,"actionType");
	double withdraw = m_jniUtil.getDoubleByMap(env,reqMap,"withdraw");
	double fee = m_jniUtil.getDoubleByMap(env,reqMap,"fee");
	const char *businessTable = m_jniUtil.getStringByMap(env,reqMap,"businessTable");
	const char *businessKey = m_jniUtil.getStringByMap(env,reqMap,"businessKey");

	CQTFtdcInvestorDepositField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcInvestorDepositField));
	strcpy(request.SettlementGroupID, settlementGroupID);
	strcpy(request.AccountID, accountID);
	request.Deposit = deposit;
	request.Withdraw = withdraw;
	request.Fee = fee;
	request.ActionType = actionType;
	strcpy(request.BusinessTable, businessTable);
	strcpy(request.BusinessKey, businessKey);
	return this->m_userApi->ReqAccountDeposit(&request,nRequestID);
}

///结算组数据同步状态改变请求
int TraderJniApi::reqSGDataSyncStatusUpdate(JNIEnv *env,jobject reqMap, jint nRequestID){	
	const char *settlementGroupID = m_jniUtil.getStringByMap(env,reqMap,"settlementGroupID");
	const char *tradingDay = m_jniUtil.getStringByMap(env,reqMap,"tradingDay");
	int settlementID = m_jniUtil.getIntByMap(env,reqMap,"settlementID");
	char SGDataSyncStatus = m_jniUtil.getCharByMap(env,reqMap,"SGDataSyncStatus");

	CQTFtdcSGDataSyncStatusField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcSGDataSyncStatusField));
	strcpy(request.SettlementGroupID, settlementGroupID);
	strcpy(request.TradingDay, tradingDay);
	request.SettlementID = settlementID;
	request.SGDataSyncStatus = SGDataSyncStatus;
	return this->m_userApi->ReqSGDataSyncStatusUpdate(&request,nRequestID);
}

///强制用户退出请求
int TraderJniApi::reqForceUserExit(JNIEnv *env,jobject reqMap, jint nRequestID){	
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");

	CQTFtdcForceUserExitField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcForceUserExitField));
	strcpy(request.ParticipantID, participantID);
	strcpy(request.UserID, userID);
	return this->m_userApi->ReqForceUserExit(&request,nRequestID);
}

///交易用户修改请求
int TraderJniApi::reqUserAction(JNIEnv *env,jobject reqMap, jint nRequestID){	
	const char *participantID = m_jniUtil.getStringByMap(env,reqMap,"participantID");
	const char *userID = m_jniUtil.getStringByMap(env,reqMap,"userID");
	char userType = m_jniUtil.getCharByMap(env,reqMap,"userType");
	const char *password = m_jniUtil.getStringByMap(env,reqMap,"password");
	int isActive = m_jniUtil.getIntByMap(env,reqMap,"isActive");
	char userActionType = m_jniUtil.getCharByMap(env,reqMap,"userActionType");
	const char *oldPassword = m_jniUtil.getStringByMap(env,reqMap,"oldPassword");

	CQTFtdcUserActionField request;
	//初始化请求对象
	memset(&request, 0, sizeof(CQTFtdcUserActionField));
	strcpy(request.ParticipantID, participantID);
	strcpy(request.UserID, userID);
	request.UserType = userType;
	strcpy(request.Password, password);
	request.IsActive = isActive;
	request.UserActionType = userActionType;
	strcpy(request.OldPassword, oldPassword);
	return this->m_userApi->ReqUserAction(&request,nRequestID);
}