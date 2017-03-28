/////////////////////////////////////////////////////////////////////////
///@system 交易所系统
///@company 上海量投网络科技有限公司
///@file QTFtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(QT_FTDCSTRUCT_H)
#define QT_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QTFtdcUserApiDataType.h"

///信息分发
struct CQTFtdcDisseminationField
{
	///序列系列号
	TQTFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TQTFtdcSequenceNoType	SequenceNo;
};

///响应信息
struct CQTFtdcRspInfoField
{
	///错误代码
	TQTFtdcErrorIDType	ErrorID;
	///错误信息
	TQTFtdcErrorMsgType	ErrorMsg;
};

///通讯阶段
struct CQTFtdcCommPhaseField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///通讯时段号
	TQTFtdcCommPhaseNoType	CommPhaseNo;
};

///交易所交易日
struct CQTFtdcExchangeTradingDayField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///交易所代码
	TQTFtdcExchangeIDType	ExchangeID;
};

///结算会话
struct CQTFtdcSettlementSessionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
};

///当前时间
struct CQTFtdcCurrentTimeField
{
	///当前日期
	TQTFtdcDateType	CurrDate;
	///当前时间
	TQTFtdcTimeType	CurrTime;
	///当前时间（毫秒）
	TQTFtdcMillisecType	CurrMillisec;
};

///用户登录请求
struct CQTFtdcReqUserLoginField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///密码
	TQTFtdcPasswordType	Password;
	///用户端产品信息
	TQTFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TQTFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TQTFtdcProtocolInfoType	ProtocolInfo;
	///数据中心代码
	TQTFtdcDataCenterIDType	DataCenterID;
};

///用户登录应答
struct CQTFtdcRspUserLoginField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///登录成功时间
	TQTFtdcTimeType	LoginTime;
	///最大本地报单号
	TQTFtdcOrderLocalIDType	MaxOrderLocalID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易系统名称
	TQTFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TQTFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TQTFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TQTFtdcSequenceNoType	UserFlowSize;
};

///用户登出请求
struct CQTFtdcReqUserLogoutField
{
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
};

///用户登出应答
struct CQTFtdcRspUserLogoutField
{
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
};

///输入报单
struct CQTFtdcInputOrderField
{
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///报单价格条件
	TQTFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///组合开平标志
	TQTFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TQTFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TQTFtdcPriceType	LimitPrice;
	///数量
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TQTFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TQTFtdcDateType	GTDDate;
	///成交量类型
	TQTFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TQTFtdcVolumeType	MinVolume;
	///触发条件
	TQTFtdcContingentConditionType	ContingentCondition;
	///止损价
	TQTFtdcPriceType	StopPrice;
	///强平原因
	TQTFtdcForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///自动挂起标志
	TQTFtdcBoolType	IsAutoSuspend;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///报单操作
struct CQTFtdcOrderActionField
{
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///报单操作标志
	TQTFtdcActionFlagType	ActionFlag;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///价格
	TQTFtdcPriceType	LimitPrice;
	///数量变化
	TQTFtdcVolumeType	VolumeChange;
	///操作本地编号
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///OTC报单
struct CQTFtdcOTCOrderField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///OTC报单编号
	TQTFtdcOTCOrderSysIDType	OTCOrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///开平标志
	TQTFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQTFtdcPriceType	Price;
	///数量
	TQTFtdcVolumeType	Volume;
	///对手方会员代码
	TQTFtdcParticipantIDType	OtherParticipantID;
	///对手方客户代码
	TQTFtdcClientIDType	OtherClientID;
	///对手方交易用户代码
	TQTFtdcUserIDType	OtherUserID;
	///对手方开平标志
	TQTFtdcOffsetFlagType	OtherOffsetFlag;
	///对手方套保标志
	TQTFtdcHedgeFlagType	OtherHedgeFlag;
	///本地OTC报单编号
	TQTFtdcOrderLocalIDType	OTCOrderLocalID;
	///OTC报单状态
	TQTFtdcOTCOrderStatusType	OTCOrderStatus;
	///插入时间
	TQTFtdcTimeType	InsertTime;
	///撤销时间
	TQTFtdcTimeType	CancelTime;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///对手方结算会员编号
	TQTFtdcParticipantIDType	OtherClearingPartID;
};

///输入报价
struct CQTFtdcInputQuoteField
{
	///报价编号
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///买入数量
	TQTFtdcVolumeType	BidVolume;
	///卖出数量
	TQTFtdcVolumeType	AskVolume;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///本地报价编号
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TQTFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	TQTFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	TQTFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TQTFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	TQTFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	TQTFtdcPriceType	AskPrice;
};

///报价操作
struct CQTFtdcQuoteActionField
{
	///报价编号
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///本地报价编号
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///报单操作标志
	TQTFtdcActionFlagType	ActionFlag;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///操作本地编号
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///输入执行宣告
struct CQTFtdcInputExecOrderField
{
	///合约编号
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///本地执行宣告编号
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///数量
	TQTFtdcVolumeType	Volume;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///执行宣告操作
struct CQTFtdcExecOrderActionField
{
	///执行宣告编号
	TQTFtdcExecOrderSysIDType	ExecOrderSysID;
	///本地执行宣告编号
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///报单操作标志
	TQTFtdcActionFlagType	ActionFlag;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///操作本地编号
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///用户登录退出
struct CQTFtdcUserLogoutField
{
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
};

///用户口令修改
struct CQTFtdcUserPasswordUpdateField
{
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///旧密码
	TQTFtdcPasswordType	OldPassword;
	///新密码
	TQTFtdcPasswordType	NewPassword;
};

///输入非标组合报单
struct CQTFtdcInputCombOrderField
{
	///组合报单编号
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///价格
	TQTFtdcPriceType	LimitPrice;
	///数量
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///本地报单编号
	TQTFtdcOrderLocalIDType	CombOrderLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///合约代码1
	TQTFtdcInstrumentIDType	InstrumentID1;
	///买卖方向1
	TQTFtdcDirectionType	Direction1;
	///分腿乘数1
	TQTFtdcLegMultipleType	LegMultiple1;
	///开平标志1
	TQTFtdcOffsetFlagType	OffsetFlag1;
	///投机套保标志1
	TQTFtdcHedgeFlagType	HedgeFlag1;
	///合约代码2
	TQTFtdcInstrumentIDType	InstrumentID2;
	///买卖方向2
	TQTFtdcDirectionType	Direction2;
	///分腿乘数2
	TQTFtdcLegMultipleType	LegMultiple2;
	///开平标志2
	TQTFtdcOffsetFlagType	OffsetFlag2;
	///投机套保标志2
	TQTFtdcHedgeFlagType	HedgeFlag2;
	///合约代码3
	TQTFtdcInstrumentIDType	InstrumentID3;
	///买卖方向3
	TQTFtdcDirectionType	Direction3;
	///分腿乘数3
	TQTFtdcLegMultipleType	LegMultiple3;
	///开平标志3
	TQTFtdcOffsetFlagType	OffsetFlag3;
	///投机套保标志3
	TQTFtdcHedgeFlagType	HedgeFlag3;
	///合约代码4
	TQTFtdcInstrumentIDType	InstrumentID4;
	///买卖方向4
	TQTFtdcDirectionType	Direction4;
	///分腿乘数4
	TQTFtdcLegMultipleType	LegMultiple4;
	///开平标志4
	TQTFtdcOffsetFlagType	OffsetFlag4;
	///投机套保标志4
	TQTFtdcHedgeFlagType	HedgeFlag4;
};

///强制用户退出
struct CQTFtdcForceUserExitField
{
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
};

///会员资金帐户入金
struct CQTFtdcAccountDepositField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///资金账号
	TQTFtdcAccountIDType	AccountID;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额，只有解冻后出金使用
	TQTFtdcMoneyType	Withdraw;
	///手续费
	TQTFtdcMoneyType	Fee;
	///资金操作类型
	TQTFtdcAccountActionTypeType	ActionType;
	///备注
	TQTFtdcComeFromType	Comments;
	///业务指向的表
	TQTFtdcTableNameType	BusinessTable;
	///业务表唯一索引
	TQTFtdcOrderSysIDType	BusinessKey;
};

///报单查询
struct CQTFtdcQryOrderField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///开始时间
	TQTFtdcTimeType	TimeStart;
	///结束时间
	TQTFtdcTimeType	TimeEnd;
};

///报价查询
struct CQTFtdcQryQuoteField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///报价编号
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
};

///成交查询
struct CQTFtdcQryTradeField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
	///成交编号
	TQTFtdcTradeIDType	TradeID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///开始时间
	TQTFtdcTimeType	TimeStart;
	///结束时间
	TQTFtdcTimeType	TimeEnd;
};

///行情查询
struct CQTFtdcQryMarketDataField
{
	///产品代码
	TQTFtdcProductIDType	ProductID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///客户查询
struct CQTFtdcQryClientField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TQTFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TQTFtdcClientIDType	ClientIDEnd;
};

///会员持仓查询
struct CQTFtdcQryPartPositionField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///客户持仓查询
struct CQTFtdcQryClientPositionField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TQTFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TQTFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
	///客户类型
	TQTFtdcClientTypeType	ClientType;
};

///交易资金查询
struct CQTFtdcQryPartAccountField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///资金帐号
	TQTFtdcAccountIDType	AccountID;
};

///合约查询
struct CQTFtdcQryInstrumentField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	TQTFtdcProductGroupIDType	ProductGroupID;
	///产品代码
	TQTFtdcProductIDType	ProductID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///合约状态查询
struct CQTFtdcQryInstrumentStatusField
{
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///结算组状态查询
struct CQTFtdcQrySGDataSyncStatusField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///用户在线查询
struct CQTFtdcQryUserSessionField
{
	///起始交易用户代码
	TQTFtdcUserIDType	UserIDStart;
	///结束交易用户代码
	TQTFtdcUserIDType	UserIDEnd;
};

///用户查询
struct CQTFtdcQryUserField
{
	///起始交易用户代码
	TQTFtdcUserIDType	UserIDStart;
	///结束交易用户代码
	TQTFtdcUserIDType	UserIDEnd;
};

///公告查询
struct CQTFtdcQryBulletinField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///市场代码
	TQTFtdcMarketIDType	MarketID;
	///公告编号
	TQTFtdcBulletinIDType	BulletinID;
	///公告类型
	TQTFtdcNewsTypeType	NewsType;
	///紧急程度
	TQTFtdcNewsUrgencyType	NewsUrgency;
};

///会员查询
struct CQTFtdcQryParticipantField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
};

///保值额度查询
struct CQTFtdcQryHedgeVolumeField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TQTFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TQTFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///合约价位查询
struct CQTFtdcQryMBLMarketDataField
{
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
	///买卖方向
	TQTFtdcDirectionType	Direction;
};

///信用限额查询
struct CQTFtdcQryCreditLimitField
{
	///交易会员编号
	TQTFtdcParticipantIDType	ParticipantID;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
};

///非标组合报单查询
struct CQTFtdcQryCombOrderField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///组合报单编号
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
};

///会员资金应答
struct CQTFtdcRspPartAccountField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TQTFtdcMoneyType	PreBalance;
	///当前保证金总额
	TQTFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TQTFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TQTFtdcMoneyType	Premium;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额
	TQTFtdcMoneyType	Withdraw;
	///期货结算准备金
	TQTFtdcMoneyType	Balance;
	///可用资金
	TQTFtdcMoneyType	Available;
	///资金帐号
	TQTFtdcAccountIDType	AccountID;
	///冻结的保证金
	TQTFtdcMoneyType	FrozenMargin;
	///冻结的权利金
	TQTFtdcMoneyType	FrozenPremium;
	///现货资金收支
	TQTFtdcMoneyType	SpotMoney;
	///冻结的现货资金
	TQTFtdcMoneyType	FrozenSpotMoney;
	///当日手续费支出
	TQTFtdcFeeType	Fee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenFee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenIPOMoney;
	///场下冻结资金
	TQTFtdcFeeType	FrozenMoney;
	///可取资金
	TQTFtdcMoneyType	Useable;
	///卖成交资金
	TQTFtdcMoneyType	SellMoney;
	///基本准备金
	TQTFtdcMoneyType	BaseReserve;
};

///会员持仓应答
struct CQTFtdcRspPartPositionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TQTFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TQTFtdcVolumeType	YdPosition;
	///今日持仓
	TQTFtdcVolumeType	Position;
	///多头冻结
	TQTFtdcVolumeType	LongFrozen;
	///空头冻结
	TQTFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TQTFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TQTFtdcVolumeType	YdShortFrozen;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易角色
	TQTFtdcTradingRoleType	TradingRole;
};

///客户持仓应答
struct CQTFtdcRspClientPositionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TQTFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TQTFtdcVolumeType	YdPosition;
	///今日持仓
	TQTFtdcVolumeType	Position;
	///多头冻结
	TQTFtdcVolumeType	LongFrozen;
	///空头冻结
	TQTFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TQTFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TQTFtdcVolumeType	YdShortFrozen;
	///当日买成交量
	TQTFtdcVolumeType	BuyTradeVolume;
	///当日卖成交量
	TQTFtdcVolumeType	SellTradeVolume;
	///持仓成本
	TQTFtdcMoneyType	PositionCost;
	///昨日持仓成本
	TQTFtdcMoneyType	YdPositionCost;
	///占用的保证金
	TQTFtdcMoneyType	UseMargin;
	///冻结的保证金
	TQTFtdcMoneyType	FrozenMargin;
	///多头冻结的保证金
	TQTFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TQTFtdcMoneyType	ShortFrozenMargin;
	///冻结的权利金
	TQTFtdcMoneyType	FrozenPremium;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///冻结的现货资金
	TQTFtdcMoneyType	FrozenSpotMoney;
	///冻结的手续费
	TQTFtdcMoneyType	FrozenFee;
	///当日可平仓量
	TQTFtdcVolumeType	AvailablePosition;
};

///合约查询应答
struct CQTFtdcRspInstrumentField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TQTFtdcProductIDType	ProductID;
	///产品组代码
	TQTFtdcProductGroupIDType	ProductGroupID;
	///基础商品代码
	TQTFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TQTFtdcProductClassType	ProductClass;
	///持仓类型
	TQTFtdcPositionTypeType	PositionType;
	///执行价
	TQTFtdcPriceType	StrikePrice;
	///期权类型
	TQTFtdcOptionsTypeType	OptionsType;
	///合约数量乘数
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TQTFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TQTFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TQTFtdcYearType	DeliveryYear;
	///交割月
	TQTFtdcMonthType	DeliveryMonth;
	///提前月份
	TQTFtdcAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	TQTFtdcBoolType	IsTrading;
	///创建日
	TQTFtdcDateType	CreateDate;
	///上市日
	TQTFtdcDateType	OpenDate;
	///到期日
	TQTFtdcDateType	ExpireDate;
	///开始交割日
	TQTFtdcDateType	StartDelivDate;
	///最后交割日
	TQTFtdcDateType	EndDelivDate;
	///挂牌基准价
	TQTFtdcPriceType	BasisPrice;
	///市价单最大下单量
	TQTFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TQTFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TQTFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TQTFtdcVolumeType	MinLimitOrderVolume;
	///最小变动价位
	TQTFtdcPriceType	PriceTick;
	///交割月自然人开仓
	TQTFtdcMonthCountType	AllowDelivPersonOpen;
	///开仓报单最小下单变动数量
	TQTFtdcVolumeType	OpenVolumeTick;
	///平仓报单最小下单变动数量
	TQTFtdcVolumeType	CloseVolumeTick;
	///撮合方式
	TQTFtdcTradingModelType	TradingModel;
	///开仓之后能平仓的交易日数
	TQTFtdcDurationType	OffsetDays;
};

///信息查询
struct CQTFtdcQryInformationField
{
	///起始信息代码
	TQTFtdcInformationIDType	InformationIDStart;
	///结束信息代码
	TQTFtdcInformationIDType	InformationIDEnd;
};

///信息查询
struct CQTFtdcInformationField
{
	///信息编号
	TQTFtdcInformationIDType	InformationID;
	///序列号
	TQTFtdcSequenceNoType	SequenceNo;
	///消息正文
	TQTFtdcContentType	Content;
	///正文长度
	TQTFtdcContentLengthType	ContentLength;
	///是否完成
	TQTFtdcBoolType	IsAccomplished;
};

///信用限额
struct CQTFtdcCreditLimitField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TQTFtdcMoneyType	PreBalance;
	///当前保证金总额
	TQTFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TQTFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TQTFtdcMoneyType	Premium;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额
	TQTFtdcMoneyType	Withdraw;
	///期货结算准备金
	TQTFtdcMoneyType	Balance;
	///可用资金
	TQTFtdcMoneyType	Available;
	///交易会员编号
	TQTFtdcParticipantIDType	ParticipantID;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///冻结的保证金
	TQTFtdcMoneyType	FrozenMargin;
	///冻结的权利金
	TQTFtdcMoneyType	FrozenPremium;
	///现货资金收支
	TQTFtdcMoneyType	SpotMoney;
	///冻结的现货资金
	TQTFtdcMoneyType	FrozenSpotMoney;
	///当日手续费支出
	TQTFtdcFeeType	Fee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenFee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenIPOMoney;
	///场下冻结资金
	TQTFtdcFeeType	FrozenMoney;
};

///客户查询应答
struct CQTFtdcRspClientField
{
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///客户名称
	TQTFtdcPartyNameType	ClientName;
	///证件类型
	TQTFtdcIdCardTypeType	IdentifiedCardType;
	///原证件号码
	TQTFtdcIdentifiedCardNoV1Type	UseLess;
	///交易角色
	TQTFtdcTradingRoleType	TradingRole;
	///客户类型
	TQTFtdcClientTypeType	ClientType;
	///是否活跃
	TQTFtdcBoolType	IsActive;
	///会员号
	TQTFtdcParticipantIDType	ParticipantID;
	///证件号码
	TQTFtdcIdentifiedCardNoType	IdentifiedCardNo;
};

///数据流回退
struct CQTFtdcFlowMessageCancelField
{
	///序列系列号
	TQTFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TQTFtdcDateType	TradingDay;
	///数据中心代码
	TQTFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TQTFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TQTFtdcSequenceNoType	EndSequenceNo;
};

///会员
struct CQTFtdcParticipantField
{
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///会员名称
	TQTFtdcParticipantNameType	ParticipantName;
	///会员简称
	TQTFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TQTFtdcMemberTypeType	MemberType;
	///是否活跃
	TQTFtdcBoolType	IsActive;
};

///用户
struct CQTFtdcUserField
{
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///交易用户类型
	TQTFtdcUserTypeType	UserType;
	///密码
	TQTFtdcPasswordType	Password;
	///交易员权限
	TQTFtdcUserActiveType	IsActive;
};

///客户
struct CQTFtdcClientField
{
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///客户名称
	TQTFtdcPartyNameType	ClientName;
	///证件类型
	TQTFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TQTFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TQTFtdcTradingRoleType	TradingRole;
	///客户类型
	TQTFtdcClientTypeType	ClientType;
	///是否活跃
	TQTFtdcBoolType	IsActive;
	///客户交易类型
	TQTFtdcHedgeFlagType	HedgeFlag;
};

///用户会话
struct CQTFtdcUserSessionField
{
	///前置编号
	TQTFtdcFrontIDType	FrontID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///交易用户类型
	TQTFtdcUserTypeType	UserType;
	///会话编号
	TQTFtdcSessionIDType	SessionID;
	///登录时间
	TQTFtdcTimeType	LoginTime;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///IP地址
	TQTFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TQTFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TQTFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TQTFtdcProtocolInfoType	ProtocolInfo;
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
};

///产品组
struct CQTFtdcProductGroupField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	TQTFtdcProductGroupIDType	ProductGroupID;
	///产品组名称
	TQTFtdcProductGroupNameType	ProductGroupName;
	///商品代码
	TQTFtdcCommodityIDType	CommodityID;
};

///产品
struct CQTFtdcProductField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TQTFtdcProductIDType	ProductID;
	///产品组代码
	TQTFtdcProductGroupIDType	ProductGroupID;
	///产品名称
	TQTFtdcProductNameType	ProductName;
	///产品类型
	TQTFtdcProductClassType	ProductClass;
};

///合约
struct CQTFtdcInstrumentField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TQTFtdcProductIDType	ProductID;
	///产品组代码
	TQTFtdcProductGroupIDType	ProductGroupID;
	///基础商品代码
	TQTFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TQTFtdcProductClassType	ProductClass;
	///持仓类型
	TQTFtdcPositionTypeType	PositionType;
	///执行价
	TQTFtdcPriceType	StrikePrice;
	///期权类型
	TQTFtdcOptionsTypeType	OptionsType;
	///合约数量乘数
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TQTFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TQTFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TQTFtdcYearType	DeliveryYear;
	///交割月
	TQTFtdcMonthType	DeliveryMonth;
	///提前月份
	TQTFtdcAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	TQTFtdcBoolType	IsTrading;
};

///组合交易合约的单腿
struct CQTFtdcCombinationLegField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///组合合约代码
	TQTFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	TQTFtdcLegIDType	LegID;
	///单腿合约代码
	TQTFtdcInstrumentIDType	LegInstrumentID;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///单腿乘数
	TQTFtdcLegMultipleType	LegMultiple;
	///推导层数
	TQTFtdcImplyLevelType	ImplyLevel;
};

///账户资金信息
struct CQTFtdcAccountInfoField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TQTFtdcMoneyType	PreBalance;
	///当前保证金总额
	TQTFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TQTFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TQTFtdcMoneyType	Premium;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额
	TQTFtdcMoneyType	Withdraw;
	///期货结算准备金
	TQTFtdcMoneyType	Balance;
	///可用资金
	TQTFtdcMoneyType	Available;
	///开户日期
	TQTFtdcDateType	DateAccountOpen;
	///上次结算的日期
	TQTFtdcDateType	PreDate;
	///上结算的编号
	TQTFtdcSettlementIDType	PreSettlementID;
	///上次保证金总额
	TQTFtdcMoneyType	PreMargin;
	///期货保证金
	TQTFtdcMoneyType	FuturesMargin;
	///期权保证金
	TQTFtdcMoneyType	OptionsMargin;
	///持仓盈亏
	TQTFtdcMoneyType	PositionProfit;
	///当日盈亏
	TQTFtdcMoneyType	Profit;
	///利息收入
	TQTFtdcMoneyType	Interest;
	///手续费
	TQTFtdcMoneyType	Fee;
	///总质押金额
	TQTFtdcMoneyType	TotalCollateral;
	///用质押抵的保证金金额
	TQTFtdcMoneyType	CollateralForMargin;
	///上次资金利息积数
	TQTFtdcMoneyType	PreAccmulateInterest;
	///资金利息积数
	TQTFtdcMoneyType	AccumulateInterest;
	///质押手续费积数
	TQTFtdcMoneyType	AccumulateFee;
	///冻结资金
	TQTFtdcMoneyType	ForzenDeposit;
	///帐户状态
	TQTFtdcAccountStatusType	AccountStatus;
	///资金帐号
	TQTFtdcAccountIDType	AccountID;
};

///会员合约持仓
struct CQTFtdcPartPositionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TQTFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TQTFtdcVolumeType	YdPosition;
	///今日持仓
	TQTFtdcVolumeType	Position;
	///多头冻结
	TQTFtdcVolumeType	LongFrozen;
	///空头冻结
	TQTFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TQTFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TQTFtdcVolumeType	YdShortFrozen;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易角色
	TQTFtdcTradingRoleType	TradingRole;
};

///客户合约持仓
struct CQTFtdcClientPositionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TQTFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TQTFtdcVolumeType	YdPosition;
	///今日持仓
	TQTFtdcVolumeType	Position;
	///多头冻结
	TQTFtdcVolumeType	LongFrozen;
	///空头冻结
	TQTFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TQTFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TQTFtdcVolumeType	YdShortFrozen;
	///当日买成交量
	TQTFtdcVolumeType	BuyTradeVolume;
	///当日卖成交量
	TQTFtdcVolumeType	SellTradeVolume;
	///持仓成本
	TQTFtdcMoneyType	PositionCost;
	///昨日持仓成本
	TQTFtdcMoneyType	YdPositionCost;
	///占用的保证金
	TQTFtdcMoneyType	UseMargin;
	///冻结的保证金
	TQTFtdcMoneyType	FrozenMargin;
	///多头冻结的保证金
	TQTFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TQTFtdcMoneyType	ShortFrozenMargin;
	///冻结的权利金
	TQTFtdcMoneyType	FrozenPremium;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///冻结的现货资金
	TQTFtdcMoneyType	FrozenSpotMoney;
	///冻结的手续费
	TQTFtdcMoneyType	FrozenFee;
	///当日可平仓量
	TQTFtdcVolumeType	AvailablePosition;
};

///保值额度量
struct CQTFtdcHedgeVolumeField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///多头保值额度最初申请量
	TQTFtdcVolumeType	LongVolumeOriginal;
	///空头保值额度最初申请量
	TQTFtdcVolumeType	ShortVolumeOriginal;
	///多头保值额度
	TQTFtdcVolumeType	LongVolume;
	///空头保值额度
	TQTFtdcVolumeType	ShortVolume;
};

///市场行情
struct CQTFtdcMarketDataField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///最新价
	TQTFtdcPriceType	LastPrice;
	///昨结算
	TQTFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQTFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TQTFtdcPriceType	OpenPrice;
	///最高价
	TQTFtdcPriceType	HighestPrice;
	///最低价
	TQTFtdcPriceType	LowestPrice;
	///数量
	TQTFtdcVolumeType	Volume;
	///成交金额
	TQTFtdcMoneyType	Turnover;
	///持仓量
	TQTFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TQTFtdcPriceType	ClosePrice;
	///今结算
	TQTFtdcPriceType	SettlementPrice;
	///涨停板价
	TQTFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQTFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TQTFtdcRatioType	PreDelta;
	///今虚实度
	TQTFtdcRatioType	CurrDelta;
	///最后修改时间
	TQTFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQTFtdcMillisecType	UpdateMillisec;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///深度市场行情
struct CQTFtdcDepthMarketDataField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///最新价
	TQTFtdcPriceType	LastPrice;
	///昨结算
	TQTFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQTFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TQTFtdcPriceType	OpenPrice;
	///最高价
	TQTFtdcPriceType	HighestPrice;
	///最低价
	TQTFtdcPriceType	LowestPrice;
	///数量
	TQTFtdcVolumeType	Volume;
	///成交金额
	TQTFtdcMoneyType	Turnover;
	///持仓量
	TQTFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TQTFtdcPriceType	ClosePrice;
	///今结算
	TQTFtdcPriceType	SettlementPrice;
	///涨停板价
	TQTFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQTFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TQTFtdcRatioType	PreDelta;
	///今虚实度
	TQTFtdcRatioType	CurrDelta;
	///最后修改时间
	TQTFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQTFtdcMillisecType	UpdateMillisec;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///申买价一
	TQTFtdcPriceType	BidPrice1;
	///申买量一
	TQTFtdcVolumeType	BidVolume1;
	///申卖价一
	TQTFtdcPriceType	AskPrice1;
	///申卖量一
	TQTFtdcVolumeType	AskVolume1;
	///申买价二
	TQTFtdcPriceType	BidPrice2;
	///申买量二
	TQTFtdcVolumeType	BidVolume2;
	///申卖价二
	TQTFtdcPriceType	AskPrice2;
	///申卖量二
	TQTFtdcVolumeType	AskVolume2;
	///申买价三
	TQTFtdcPriceType	BidPrice3;
	///申买量三
	TQTFtdcVolumeType	BidVolume3;
	///申卖价三
	TQTFtdcPriceType	AskPrice3;
	///申卖量三
	TQTFtdcVolumeType	AskVolume3;
	///申买价四
	TQTFtdcPriceType	BidPrice4;
	///申买量四
	TQTFtdcVolumeType	BidVolume4;
	///申卖价四
	TQTFtdcPriceType	AskPrice4;
	///申卖量四
	TQTFtdcVolumeType	AskVolume4;
	///申买价五
	TQTFtdcPriceType	BidPrice5;
	///申买量五
	TQTFtdcVolumeType	BidVolume5;
	///申卖价五
	TQTFtdcPriceType	AskPrice5;
	///申卖量五
	TQTFtdcVolumeType	AskVolume5;
	///产品名称
	TQTFtdcInstrumentNameType	InstrumentName;
};

///分价表
struct CQTFtdcMBLMarketDataField
{
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///价格
	TQTFtdcPriceType	Price;
	///数量
	TQTFtdcVolumeType	Volume;
};

///别名定义
struct CQTFtdcAliasDefineField
{
	///起始位置
	TQTFtdcStartPosType	StartPos;
	///别名
	TQTFtdcAliasType	Alias;
	///原文
	TQTFtdcOriginalTextType	OriginalText;
};

///行情基础属性
struct CQTFtdcMarketDataBaseField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///昨结算
	TQTFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQTFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TQTFtdcRatioType	PreDelta;
	///产品名称
	TQTFtdcInstrumentNameType	InstrumentName;
};

///行情静态属性
struct CQTFtdcMarketDataStaticField
{
	///今开盘
	TQTFtdcPriceType	OpenPrice;
	///最高价
	TQTFtdcPriceType	HighestPrice;
	///最低价
	TQTFtdcPriceType	LowestPrice;
	///今收盘
	TQTFtdcPriceType	ClosePrice;
	///涨停板价
	TQTFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQTFtdcPriceType	LowerLimitPrice;
	///今结算
	TQTFtdcPriceType	SettlementPrice;
	///今虚实度
	TQTFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CQTFtdcMarketDataLastMatchField
{
	///最新价
	TQTFtdcPriceType	LastPrice;
	///数量
	TQTFtdcVolumeType	Volume;
	///成交金额
	TQTFtdcMoneyType	Turnover;
	///持仓量
	TQTFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CQTFtdcMarketDataBestPriceField
{
	///申买价一
	TQTFtdcPriceType	BidPrice1;
	///申买量一
	TQTFtdcVolumeType	BidVolume1;
	///申卖价一
	TQTFtdcPriceType	AskPrice1;
	///申卖量一
	TQTFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CQTFtdcMarketDataBid23Field
{
	///申买价二
	TQTFtdcPriceType	BidPrice2;
	///申买量二
	TQTFtdcVolumeType	BidVolume2;
	///申买价三
	TQTFtdcPriceType	BidPrice3;
	///申买量三
	TQTFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CQTFtdcMarketDataAsk23Field
{
	///申卖价二
	TQTFtdcPriceType	AskPrice2;
	///申卖量二
	TQTFtdcVolumeType	AskVolume2;
	///申卖价三
	TQTFtdcPriceType	AskPrice3;
	///申卖量三
	TQTFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CQTFtdcMarketDataBid45Field
{
	///申买价四
	TQTFtdcPriceType	BidPrice4;
	///申买量四
	TQTFtdcVolumeType	BidVolume4;
	///申买价五
	TQTFtdcPriceType	BidPrice5;
	///申买量五
	TQTFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CQTFtdcMarketDataAsk45Field
{
	///申卖价四
	TQTFtdcPriceType	AskPrice4;
	///申卖量四
	TQTFtdcVolumeType	AskVolume4;
	///申卖价五
	TQTFtdcPriceType	AskPrice5;
	///申卖量五
	TQTFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CQTFtdcMarketDataUpdateTimeField
{
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TQTFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQTFtdcMillisecType	UpdateMillisec;
};

///报价
struct CQTFtdcQuoteField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///报价编号
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///买入数量
	TQTFtdcVolumeType	BidVolume;
	///卖出数量
	TQTFtdcVolumeType	AskVolume;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///本地报价编号
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TQTFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	TQTFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	TQTFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TQTFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	TQTFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	TQTFtdcPriceType	AskPrice;
	///插入时间
	TQTFtdcTimeType	InsertTime;
	///撤销时间
	TQTFtdcTimeType	CancelTime;
	///成交时间
	TQTFtdcTimeType	TradeTime;
	///买方报单编号
	TQTFtdcOrderSysIDType	BidOrderSysID;
	///卖方报单编号
	TQTFtdcOrderSysIDType	AskOrderSysID;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
};

///成交
struct CQTFtdcTradeField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///成交编号
	TQTFtdcTradeIDType	TradeID;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易角色
	TQTFtdcTradingRoleType	TradingRole;
	///资金帐号
	TQTFtdcAccountIDType	AccountID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TQTFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQTFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQTFtdcPriceType	Price;
	///数量
	TQTFtdcVolumeType	Volume;
	///成交时间
	TQTFtdcTimeType	TradeTime;
	///成交类型
	TQTFtdcTradeTypeType	TradeType;
	///成交价来源
	TQTFtdcPriceSourceType	PriceSource;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///手续费
	TQTFtdcFeeType	Fee;
	///浮动盈亏
	TQTFtdcMoneyType	CloseProfit;
};

///报单
struct CQTFtdcOrderField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///报单价格条件
	TQTFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TQTFtdcDirectionType	Direction;
	///组合开平标志
	TQTFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TQTFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TQTFtdcPriceType	LimitPrice;
	///数量
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TQTFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TQTFtdcDateType	GTDDate;
	///成交量类型
	TQTFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TQTFtdcVolumeType	MinVolume;
	///触发条件
	TQTFtdcContingentConditionType	ContingentCondition;
	///止损价
	TQTFtdcPriceType	StopPrice;
	///强平原因
	TQTFtdcForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///自动挂起标志
	TQTFtdcBoolType	IsAutoSuspend;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///报单状态
	TQTFtdcOrderStatusType	OrderStatus;
	///报单类型
	TQTFtdcOrderTypeType	OrderType;
	///今成交数量
	TQTFtdcVolumeType	VolumeTraded;
	///剩余数量
	TQTFtdcVolumeType	VolumeTotal;
	///报单日期
	TQTFtdcDateType	InsertDate;
	///插入时间
	TQTFtdcTimeType	InsertTime;
	///激活时间
	TQTFtdcTimeType	ActiveTime;
	///挂起时间
	TQTFtdcTimeType	SuspendTime;
	///最后修改时间
	TQTFtdcTimeType	UpdateTime;
	///撤销时间
	TQTFtdcTimeType	CancelTime;
	///最后修改交易用户代码
	TQTFtdcUserIDType	ActiveUserID;
	///优先权
	TQTFtdcPriorityType	Priority;
	///按时间排队的序号
	TQTFtdcTimeSortIDType	TimeSortID;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///执行宣告
struct CQTFtdcExecOrderField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///合约编号
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///本地执行宣告编号
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///数量
	TQTFtdcVolumeType	Volume;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///执行宣告编号
	TQTFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TQTFtdcDateType	InsertDate;
	///插入时间
	TQTFtdcTimeType	InsertTime;
	///撤销时间
	TQTFtdcTimeType	CancelTime;
	///执行结果
	TQTFtdcExecResultType	ExecResult;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
};

///非标组合报单
struct CQTFtdcCombOrderField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///组合报单编号
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///价格
	TQTFtdcPriceType	LimitPrice;
	///数量
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///本地报单编号
	TQTFtdcOrderLocalIDType	CombOrderLocalID;
	///业务单元
	TQTFtdcBusinessUnitType	BusinessUnit;
	///合约代码1
	TQTFtdcInstrumentIDType	InstrumentID1;
	///买卖方向1
	TQTFtdcDirectionType	Direction1;
	///分腿乘数1
	TQTFtdcLegMultipleType	LegMultiple1;
	///开平标志1
	TQTFtdcOffsetFlagType	OffsetFlag1;
	///投机套保标志1
	TQTFtdcHedgeFlagType	HedgeFlag1;
	///合约代码2
	TQTFtdcInstrumentIDType	InstrumentID2;
	///买卖方向2
	TQTFtdcDirectionType	Direction2;
	///分腿乘数2
	TQTFtdcLegMultipleType	LegMultiple2;
	///开平标志2
	TQTFtdcOffsetFlagType	OffsetFlag2;
	///投机套保标志2
	TQTFtdcHedgeFlagType	HedgeFlag2;
	///合约代码3
	TQTFtdcInstrumentIDType	InstrumentID3;
	///买卖方向3
	TQTFtdcDirectionType	Direction3;
	///分腿乘数3
	TQTFtdcLegMultipleType	LegMultiple3;
	///开平标志3
	TQTFtdcOffsetFlagType	OffsetFlag3;
	///投机套保标志3
	TQTFtdcHedgeFlagType	HedgeFlag3;
	///合约代码4
	TQTFtdcInstrumentIDType	InstrumentID4;
	///买卖方向4
	TQTFtdcDirectionType	Direction4;
	///分腿乘数4
	TQTFtdcLegMultipleType	LegMultiple4;
	///开平标志4
	TQTFtdcOffsetFlagType	OffsetFlag4;
	///投机套保标志4
	TQTFtdcHedgeFlagType	HedgeFlag4;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///今成交数量
	TQTFtdcVolumeType	VolumeTraded;
	///剩余数量
	TQTFtdcVolumeType	VolumeTotal;
	///报单日期
	TQTFtdcDateType	InsertDate;
	///插入时间
	TQTFtdcTimeType	InsertTime;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
};

///管理报单
struct CQTFtdcAdminOrderField
{
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///管理报单命令
	TQTFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///交易会员编号
	TQTFtdcParticipantIDType	ParticipantID;
	///金额
	TQTFtdcMoneyType	Amount;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///管理报单输入
struct CQTFtdcInputAdminOrderField
{
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///管理报单命令
	TQTFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	TQTFtdcParticipantIDType	ClearingPartID;
	///交易会员编号
	TQTFtdcParticipantIDType	ParticipantID;
	///金额
	TQTFtdcMoneyType	Amount;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///公告
struct CQTFtdcBulletinField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///公告编号
	TQTFtdcBulletinIDType	BulletinID;
	///序列号
	TQTFtdcSequenceNoType	SequenceNo;
	///公告类型
	TQTFtdcNewsTypeType	NewsType;
	///紧急程度
	TQTFtdcNewsUrgencyType	NewsUrgency;
	///发送时间
	TQTFtdcTimeType	SendTime;
	///消息摘要
	TQTFtdcAbstractType	Abstract;
	///消息来源
	TQTFtdcComeFromType	ComeFrom;
	///消息正文
	TQTFtdcContentType	Content;
	///WEB地址
	TQTFtdcURLLinkType	URLLink;
	///市场代码
	TQTFtdcMarketIDType	MarketID;
};

///交易所数据同步状态
struct CQTFtdcExchangeDataSyncStatusField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///交易所代码
	TQTFtdcExchangeIDType	ExchangeID;
	///交易所数据同步状态
	TQTFtdcExchangeDataSyncStatusType	ExchangeDataSyncStatus;
};

///结算组数据同步状态
struct CQTFtdcSGDataSyncStatusField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///结算组数据同步状态
	TQTFtdcSGDataSyncStatusType	SGDataSyncStatus;
};

///合约状态
struct CQTFtdcInstrumentStatusField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TQTFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TQTFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TQTFtdcTimeType	EnterTime;
	///进入本状态原因
	TQTFtdcInstStatusEnterReasonType	EnterReason;
};

///客户持仓查询
struct CQTFtdcQryClientPositionV1Field
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TQTFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TQTFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///询价
struct CQTFtdcInputReqForQuoteField
{
	///询价编号
	TQTFtdcQuoteSysIDType	ReqForQuoteID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///交易日期
	TQTFtdcTradingDayType	TradingDay;
	///询价时间
	TQTFtdcTimeType	ReqForQuoteTime;
};

///导出内存表
struct CQTFtdcDumpMemTableField
{
	///内存表名称
	TQTFtdcTableNameType	TableName;
};

///合约状态请求
struct CQTFtdcIPOOrderField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///报单编号
	TQTFtdcDateSeqNoType	OrderSysID;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///申购类型
	TQTFtdcPurchaseTypeType	PurchaseType;
	///报单状态
	TQTFtdcOrderStatusType	OrderStatus;
	///撤单类型
	TQTFtdcCancelTypeType	CancelType;
	///价格
	TQTFtdcPriceType	OrderPrice;
	///数量
	TQTFtdcVolumeType	OrderVolume;
	///数量
	TQTFtdcVolumeType	TradeVolume;
	///冻结金额
	TQTFtdcMoneyType	OrderFrozenMoney;
	///预付手续费
	TQTFtdcMoneyType	PrePayFee;
	///返还手续费
	TQTFtdcMoneyType	ReturnFee;
	///委托日期
	TQTFtdcDateType	OrderDate;
	///委托时间
	TQTFtdcTimeType	InsertTime;
	///撤单日期
	TQTFtdcDateType	CancelDate;
	///撤单时间
	TQTFtdcTimeType	CancelTime;
	///开始序号
	TQTFtdcIPOSeqNoType	StartSeqNo;
	///结束序号
	TQTFtdcIPOSeqNoType	EndSeqNo;
	///结算日期
	TQTFtdcDateType	SettleDate;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///返还金额
	TQTFtdcMoneyType	ReturnMoney;
};

///IPO合约信息
struct CQTFtdcIPOInstrumentField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///产品名称
	TQTFtdcInstrumentNameType	InstrumentName;
	///发行价
	TQTFtdcPriceType	LaunchPrice;
	///发行数量
	TQTFtdcVolumeType	LaunchAmt;
	///申购开始日期
	TQTFtdcDateType	StartPurchaseDate;
	///申购结束日期
	TQTFtdcDateType	EndPurchaseDate;
	///产品状态
	TQTFtdcPorductStatusType	InstrumentStatus;
	///最大申购数量
	TQTFtdcVolumeType	MaxPurchaseAmt;
	///最小申购数量
	TQTFtdcVolumeType	MinPurchaseAmt;
	///最小变动数量
	TQTFtdcVolumeType	MinChangeAmt;
	///申购每手手续费
	TQTFtdcRatioType	PurchaseFeeAmt;
	///申购手续费率
	TQTFtdcRatioType	PurchaseFeeRate;
	///申购开始时间
	TQTFtdcTimeType	StartPurchaseTime;
	///申购结束时间
	TQTFtdcTimeType	EndPurchaseTime;
	///合约乘数
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///报价数量
	TQTFtdcVolumeType	QtyUnit;
};

///IPO合约信息查询
struct CQTFtdcQryIPOInstrumentField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO客户申购数量返回
struct CQTFtdcIPORightField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO订单修改
struct CQTFtdcIPOActionField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///报单编号
	TQTFtdcDateSeqNoType	OrderSysID;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///申购类型
	TQTFtdcPurchaseTypeType	PurchaseType;
	///报单状态
	TQTFtdcOrderStatusType	OrderStatus;
	///撤单类型
	TQTFtdcCancelTypeType	CancelType;
	///价格
	TQTFtdcPriceType	OrderPrice;
	///数量
	TQTFtdcVolumeType	OrderVolume;
	///数量
	TQTFtdcVolumeType	TradeVolume;
	///冻结金额
	TQTFtdcMoneyType	OrderFrozenMoney;
	///预付手续费
	TQTFtdcMoneyType	PrePayFee;
	///返还手续费
	TQTFtdcMoneyType	ReturnFee;
	///委托日期
	TQTFtdcDateType	OrderDate;
	///委托时间
	TQTFtdcTimeType	InsertTime;
	///撤单日期
	TQTFtdcDateType	CancelDate;
	///撤单时间
	TQTFtdcTimeType	CancelTime;
	///开始序号
	TQTFtdcIPOSeqNoType	StartSeqNo;
	///结束序号
	TQTFtdcIPOSeqNoType	EndSeqNo;
	///结算日期
	TQTFtdcDateType	SettleDate;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///返还金额
	TQTFtdcMoneyType	ReturnMoney;
};

///IPO中签结果查询
struct CQTFtdcIPOTradeField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///报单编号
	TQTFtdcDateSeqNoType	OrderSysID;
	///成交编号
	TQTFtdcTradeIDType	TradeID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///成交日期
	TQTFtdcDateType	TradeDate;
	///成交时间
	TQTFtdcTimeType	TradeTime;
	///申购类型
	TQTFtdcPurchaseTypeType	PurchaseType;
	///成交价格
	TQTFtdcPriceType	TradePrice;
	///成交数量
	TQTFtdcVolumeType	Volume;
	///成交金额
	TQTFtdcMoneyType	TradeMoney;
	///成交类型
	TQTFtdcIPOTradeTypeType	IPOTradeType;
	///手续费
	TQTFtdcMoneyType	Fee;
	///委托日期
	TQTFtdcDateType	InsertDate;
};

///IPO订单查询
struct CQTFtdcQryIPOOrderField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///报单编号
	TQTFtdcDateSeqNoType	OrderSysID;
	///产品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///开始日期
	TQTFtdcDateType	TimeStart;
	///结束日期
	TQTFtdcDateType	TimeEnd;
};

///IPO申购权限查询
struct CQTFtdcQryIPORightField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO成交查询
struct CQTFtdcQryIPOTradeField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///成交编号
	TQTFtdcTradeIDType	TradeID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///开始时间
	TQTFtdcDateType	TimeStart;
	///结束时间
	TQTFtdcDateType	TimeEnd;
	///报单编号
	TQTFtdcDateSeqNoType	OrderSysID;
};

///资金账户出入金请求信息
struct CQTFtdcInvestorDepositField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///资金账号
	TQTFtdcAccountIDType	AccountID;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额，只有解冻后出金使用
	TQTFtdcMoneyType	Withdraw;
	///手续费
	TQTFtdcMoneyType	Fee;
	///资金操作类型
	TQTFtdcAccountActionTypeType	ActionType;
	///备注
	TQTFtdcComeFromType	Comments;
	///业务指向的表
	TQTFtdcTableNameType	BusinessTable;
	///业务表唯一索引
	TQTFtdcOrderSysIDType	BusinessKey;
};

///资金账户出入金应答信息
struct CQTFtdcInvestorDepositResField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TQTFtdcMoneyType	PreBalance;
	///当前保证金总额
	TQTFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TQTFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TQTFtdcMoneyType	Premium;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额
	TQTFtdcMoneyType	Withdraw;
	///期货结算准备金
	TQTFtdcMoneyType	Balance;
	///可用资金
	TQTFtdcMoneyType	Available;
	///资金帐号
	TQTFtdcAccountIDType	AccountID;
	///冻结的保证金
	TQTFtdcMoneyType	FrozenMargin;
	///冻结的权利金
	TQTFtdcMoneyType	FrozenPremium;
	///现货资金收支
	TQTFtdcMoneyType	SpotMoney;
	///冻结的现货资金
	TQTFtdcMoneyType	FrozenSpotMoney;
	///当日手续费支出
	TQTFtdcFeeType	Fee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenFee;
	///当日手续费冻结
	TQTFtdcFeeType	FrozenIPOMoney;
	///场下冻结资金
	TQTFtdcFeeType	FrozenMoney;
	///可取资金
	TQTFtdcMoneyType	Useable;
	///卖成交资金
	TQTFtdcMoneyType	SellMoney;
};

///输入场外成交对
struct CQTFtdcInputOTCTradeField
{
	///成交编号
	TQTFtdcOrderSysIDType	TradeID;
	///买方会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///成交对本地编号
	TQTFtdcOrderLocalIDType	TradeLocalID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///价格
	TQTFtdcPriceType	Price;
	///数量
	TQTFtdcVolumeType	Volume;
	///买方会员代码
	TQTFtdcParticipantIDType	BuyParticipantID;
	///买方客户代码
	TQTFtdcClientIDType	BuyClientID;
	///买方交易用户代码
	TQTFtdcUserIDType	BuyUserID;
	///买方本地报单编号
	TQTFtdcOrderLocalIDType	BuyOrderLocalID;
	///买方组合开平标志
	TQTFtdcCombOffsetFlagType	BuyCombOffsetFlag;
	///买方组合投机套保标志
	TQTFtdcCombHedgeFlagType	BuyCombHedgeFlag;
	///卖方方会员代码
	TQTFtdcParticipantIDType	SellParticipantID;
	///卖方客户代码
	TQTFtdcClientIDType	SellClientID;
	///卖方交易用户代码
	TQTFtdcUserIDType	SellUserID;
	///卖方组合开平标志
	TQTFtdcCombOffsetFlagType	SellCombOffsetFlag;
	///卖方组合套保标志
	TQTFtdcCombHedgeFlagType	SellCombHedgeFlag;
	///卖方本地报单编号
	TQTFtdcOrderLocalIDType	SellOrderLocalID;
	///OTC类型
	TQTFtdcOTCTypeType	OTCType;
	///状态
	TQTFtdcOTCStatusType	Status;
	///错误代码
	TQTFtdcErrorIDType	OTCErrorID;
	///错误信息
	TQTFtdcErrorMsgType	OTCErrorMsg;
	///备注
	TQTFtdcComeFromType	Comments;
	///成交金额
	TQTFtdcMoneyType	TradeMoney;
};

///场外成交对
struct CQTFtdcOTCTradeField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///成交编号
	TQTFtdcOrderSysIDType	TradeID;
	///买方会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///成交对本地编号
	TQTFtdcOrderLocalIDType	TradeLocalID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///价格
	TQTFtdcPriceType	Price;
	///数量
	TQTFtdcVolumeType	Volume;
	///买方会员代码
	TQTFtdcParticipantIDType	BuyParticipantID;
	///买方客户代码
	TQTFtdcClientIDType	BuyClientID;
	///买方交易用户代码
	TQTFtdcUserIDType	BuyUserID;
	///买方本地报单编号
	TQTFtdcOrderLocalIDType	BuyOrderLocalID;
	///买方组合开平标志
	TQTFtdcCombOffsetFlagType	BuyCombOffsetFlag;
	///买方组合投机套保标志
	TQTFtdcCombHedgeFlagType	BuyCombHedgeFlag;
	///卖方方会员代码
	TQTFtdcParticipantIDType	SellParticipantID;
	///卖方客户代码
	TQTFtdcClientIDType	SellClientID;
	///卖方交易用户代码
	TQTFtdcUserIDType	SellUserID;
	///卖方组合开平标志
	TQTFtdcCombOffsetFlagType	SellCombOffsetFlag;
	///卖方组合套保标志
	TQTFtdcCombHedgeFlagType	SellCombHedgeFlag;
	///卖方本地报单编号
	TQTFtdcOrderLocalIDType	SellOrderLocalID;
	///OTC类型
	TQTFtdcOTCTypeType	OTCType;
	///状态
	TQTFtdcOTCStatusType	Status;
	///错误代码
	TQTFtdcErrorIDType	OTCErrorID;
	///错误信息
	TQTFtdcErrorMsgType	OTCErrorMsg;
	///备注
	TQTFtdcComeFromType	Comments;
	///成交金额
	TQTFtdcMoneyType	TradeMoney;
	///开仓手续费
	TQTFtdcMoneyType	OpenFee;
	///平仓手续费
	TQTFtdcMoneyType	OffsetFee;
	///转让盈亏
	TQTFtdcMoneyType	OpenProfit;
	///转让盈亏
	TQTFtdcMoneyType	OffsetProfit;
	///委托日期
	TQTFtdcDateType	OrderDate;
	///委托时间
	TQTFtdcTimeType	InsertTime;
};

///持仓划转
struct CQTFtdcPositionChangeField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///合约代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///划转数量
	TQTFtdcVolumeType	TransVolume;
	///业务类型
	TQTFtdcBusinessTypeType	TransType;
	///本地报单编号
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///提货单密码
	TQTFtdcPasswordType	DepotPwd;
	///仓单凭证
	TQTFtdcDateSeqNoType	WarrantID;
	///报单状态
	TQTFtdcTransStatusType	TransStatus;
	///处理金额,提货单注销时为返回资金
	TQTFtdcMoneyType	TransFrozenMoney;
	///手续费,提货单取消时为注销费
	TQTFtdcMoneyType	PrePayFee;
	///委托日期
	TQTFtdcDateType	OrderDate;
	///委托时间
	TQTFtdcTimeType	InsertTime;
	///报单编号
	TQTFtdcOrderSysIDType	OrderSysID;
	///业务指向的表
	TQTFtdcTableNameType	BusinessTable;
	///业务表唯一索引
	TQTFtdcOrderSysIDType	BusinessKey;
	///持仓处理方式
	TQTFtdcPosDealTypeType	PosDealType;
	///资金处理方式
	TQTFtdcAccountActionTypeType	AccountActionType;
	///备注
	TQTFtdcComeFromType	Comments;
};

///仓单注册
struct CQTFtdcPickRequestField
{
	///交易日
	TQTFtdcDateType	TradingDay;
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TQTFtdcSettlementIDType	SettlementID;
	///商品代码
	TQTFtdcInstrumentIDType	InstrumentID;
	///交割数量
	TQTFtdcVolumeType	DeliveryVolume;
	///仓库编号
	TQTFtdcSerialNoType	HouseID;
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///交割件数
	TQTFtdcVolumeType	DeliveryUnits;
	///提货日期
	TQTFtdcDateType	PickDate;
	///交收单位
	TQTFtdcQuantityUnitType	Unit;
	///提货单状态
	TQTFtdcWarrantStatusType	RequestStat;
	///仓单凭证
	TQTFtdcDateSeqNoType	PickRequestID;
	///注册日期
	TQTFtdcDateType	RegDate;
	///委托时间
	TQTFtdcTimeType	RequestTime;
	///报单来源
	TQTFtdcOrderSourceType	OrderSource;
	///仓储费
	TQTFtdcFeeType	StoreFee;
	///保险费
	TQTFtdcFeeType	InsuranceFee;
	///托管费
	TQTFtdcFeeType	CustodyFee;
	///注册费
	TQTFtdcFeeType	RegFee;
	///注销费
	TQTFtdcFeeType	CancelFee;
	///过户费
	TQTFtdcFeeType	TransferFee;
	///配送费
	TQTFtdcFeeType	DeliveryFee;
	///交收价格
	TQTFtdcPriceType	DeliveryPrice;
	///交易所代码
	TQTFtdcExchangeIDType	ExchID;
	///密码输错次数
	TQTFtdcVolumeType	WrongPwdCount;
	///密码输错日期
	TQTFtdcDateType	WrongPwdDate;
	///注销日期
	TQTFtdcDateType	CancelDate;
	///注销时间
	TQTFtdcTimeType	CancelTime;
	///提货单密码
	TQTFtdcPasswordType	PickPwd;
	///提货类型
	TQTFtdcWarrantTypeType	PickType;
	///提货人姓名
	TQTFtdcClientNameType	PickerName;
	///性别
	TQTFtdcSexTypeType	Gender;
	///证件类型
	TQTFtdcIdCardTypeType	CertType;
	///证件号码
	TQTFtdcIdentifiedCardNoType	CertCode;
	///操作类型
	TQTFtdcWarrantOperType	OperateType;
	///配送状态
	TQTFtdcWarrantStatusType	DeliveryStatus;
	///电话号码
	TQTFtdcTelphoneNumType	Phone;
	///收货地址
	TQTFtdcAddressType	Addr;
	///邮编
	TQTFtdcPostNumType	PostCode;
	///收货单位
	TQTFtdcDescriptionType	ReceiveCom;
	///审核员代码
	TQTFtdcOperatorIDType	VerifierID;
	///发货日期
	TQTFtdcDateType	DeliveryDate;
};

///仓单查询
struct CQTFtdcQryPickRequestField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///提货单状态
	TQTFtdcWarrantStatusType	RequestStat;
	///仓单凭证
	TQTFtdcDateSeqNoType	PickRequestID;
	///注册开始日期
	TQTFtdcDateType	TimeStart;
	///注册结束日期
	TQTFtdcDateType	TimeEnd;
};

///持仓划转
struct CQTFtdcQryPositionChangeField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///注册开始日期
	TQTFtdcDateType	TimeStart;
	///注册结束日期
	TQTFtdcDateType	TimeEnd;
};

///大宗交易、持仓过户查询
struct CQTFtdcQryOTCTradeField
{
	///起始会员代码
	TQTFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TQTFtdcParticipantIDType	PartIDEnd;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///成交编号
	TQTFtdcOrderSysIDType	TradeID;
};

///出入金查询
struct CQTFtdcQryAccountDepositDetailField
{
	///资金账号
	TQTFtdcAccountIDType	AccountID;
	///出入金流水序号
	TQTFtdcSequenceNoType	SequenceNo;
	///委托开始日期
	TQTFtdcDateType	TimeStart;
	///委托开始日期
	TQTFtdcDateType	TimeEnd;
};

///出入金
struct CQTFtdcAccountDepositDetailField
{
	///结算组代码
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///资金账号
	TQTFtdcAccountIDType	AccountID;
	///入金金额
	TQTFtdcMoneyType	Deposit;
	///出金金额，只有解冻后出金使用
	TQTFtdcMoneyType	Withdraw;
	///手续费
	TQTFtdcMoneyType	Fee;
	///资金操作类型
	TQTFtdcAccountActionTypeType	ActionType;
	///备注
	TQTFtdcComeFromType	Comments;
	///业务指向的表
	TQTFtdcTableNameType	BusinessTable;
	///业务表唯一索引
	TQTFtdcOrderSysIDType	BusinessKey;
	///出入金流水序号
	TQTFtdcSequenceNoType	SequenceNo;
	///处理结果
	TQTFtdcTransStatusType	Status;
	///委托日期
	TQTFtdcDateType	OrderDate;
	///委托时间
	TQTFtdcTimeType	InsertTime;
};

///交易用户修改
struct CQTFtdcUserActionField
{
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///交易用户类型
	TQTFtdcUserTypeType	UserType;
	///密码
	TQTFtdcPasswordType	Password;
	///交易员权限
	TQTFtdcUserActiveType	IsActive;
	///修改模式
	TQTFtdcUserActionTypeType	UserActionType;
	///旧密码
	TQTFtdcPasswordType	OldPassword;
};

///大宗交易、持仓过户查询
struct CQTFtdcQryOtherTradeField
{
	///会员代码
	TQTFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQTFtdcClientIDType	ClientID;
	///交易用户代码
	TQTFtdcUserIDType	UserID;
	///起始合约代码
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///结束合约代码
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///成交编号
	TQTFtdcOrderSysIDType	TradeID;
};



#endif
