/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 上海量投网络科技有限公司
///@file FocusFtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Focus_FTDCSTRUCT_H)
#define Focus_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiDataType.h"

///响应信息
struct CFocusFtdcRspInfoField
{
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
};

///系统用户登录请求
struct CFocusFtdcReqUserLoginField
{
	///交易日
	TFocusFtdcDateType	TradingDay;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///密码
	TFocusFtdcPasswordType	Password;
	///用户端产品信息
	TFocusFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TFocusFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///动态密码
	TFocusFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TFocusFtdcIPAddressType	ClientIPAddress;
	///授权编码
	TFocusFtdcAuthCodeType	AuthCode;
};

///系统用户登录应答
struct CFocusFtdcRspUserLoginField
{
	///交易日
	TFocusFtdcDateType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///登录成功时间
	TFocusFtdcTimeType	LoginTime;
	///用户最大本地报单号
	TFocusFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///交易系统名称
	TFocusFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TFocusFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TFocusFtdcSequenceNoType	UserFlowSize;
	///登录附加信息
	TFocusFtdcLoginInfoType	LoginInfo;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
};

///用户登出请求
struct CFocusFtdcReqUserLogoutField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///用户登出请求
struct CFocusFtdcRspUserLogoutField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///强制用户退出
struct CFocusFtdcForceUserExitField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
};

///用户口令修改
struct CFocusFtdcUserPasswordUpdateField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///旧密码
	TFocusFtdcPasswordType	OldPassword;
	///新密码
	TFocusFtdcPasswordType	NewPassword;
};

///输入报单
struct CFocusFtdcInputOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
};

///报单操作
struct CFocusFtdcOrderActionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TFocusFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TFocusFtdcActionFlagType	ActionFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量变化
	TFocusFtdcVolumeType	VolumeChange;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
};

///内存表导出
struct CFocusFtdcMemDBField
{
	///内存表名
	TFocusFtdcMemTableNameType	MemTableName;
};

///投资者资金帐户出入金请求
struct CFocusFtdcReqAccountDepositField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///投资者资金帐户出入金应答
struct CFocusFtdcRspAccountDepositField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///实时上场
struct CFocusFtdcTBCommandField
{
	///DB命令序号
	TFocusFtdcCommandNoType	CommandNo;
	///操作日期
	TFocusFtdcDateType	CommandDate;
	///操作时间
	TFocusFtdcTimeType	CommandTime;
	///DB命令类型
	TFocusFtdcCommandTypeType	CommandType;
	///字段名
	TFocusFtdcFieldNameType	FieldName;
	///字段内容
	TFocusFtdcFieldContentType	FieldContent;
};

///出入金结果
struct CFocusFtdcInvestorAccountDepositResField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///资金流水号
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TFocusFtdcMoneyType	Amount;
	///出入金方向
	TFocusFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///合约状态
struct CFocusFtdcInstrumentStatusField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///品种代码
	TFocusFtdcProductIDType	ProductID;
	///品种名称
	TFocusFtdcProductNameType	ProductName;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TFocusFtdcYearType	DeliveryYear;
	///交割月
	TFocusFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TFocusFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TFocusFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TFocusFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TFocusFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TFocusFtdcPriceTickType	PriceTick;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///多头限仓
	TFocusFtdcVolumeType	LongPosLimit;
	///空头限仓
	TFocusFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TFocusFtdcDateType	CreateDate;
	///上市日
	TFocusFtdcDateType	OpenDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///开始交割日
	TFocusFtdcDateType	StartDelivDate;
	///最后交割日
	TFocusFtdcDateType	EndDelivDate;
	///挂牌基准价
	TFocusFtdcPriceType	BasisPrice;
	///当前是否交易
	TFocusFtdcBoolType	IsTrading;
	///基础商品代码
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TFocusFtdcPositionTypeType	PositionType;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
	///产品类型
	TFocusFtdcProductClassType	ProductClass;
	///期权行权方式
	TFocusFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///审批模式设置请求
struct CFocusFtdcAdviceRunModeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///自动或者手动
	TFocusFtdcAdviceRunModeType	RunMode;
};

///订阅合约状态
struct CFocusFtdcSubInstrumentStatusField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///进入本状态时间
	TFocusFtdcTimeType	EnterTime;
	///进入本状态原因
	TFocusFtdcEnterReasonType	EnterReason;
};

///行情基础属性
struct CFocusFtdcMarketDataBaseField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
};

///行情静态属性
struct CFocusFtdcMarketDataStaticField
{
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CFocusFtdcMarketDataLastMatchField
{
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CFocusFtdcMarketDataBestPriceField
{
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CFocusFtdcMarketDataBid23Field
{
	///申买价二
	TFocusFtdcPriceType	BidPrice2;
	///申买量二
	TFocusFtdcVolumeType	BidVolume2;
	///申买价三
	TFocusFtdcPriceType	BidPrice3;
	///申买量三
	TFocusFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CFocusFtdcMarketDataAsk23Field
{
	///申卖价二
	TFocusFtdcPriceType	AskPrice2;
	///申卖量二
	TFocusFtdcVolumeType	AskVolume2;
	///申卖价三
	TFocusFtdcPriceType	AskPrice3;
	///申卖量三
	TFocusFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CFocusFtdcMarketDataBid45Field
{
	///申买价四
	TFocusFtdcPriceType	BidPrice4;
	///申买量四
	TFocusFtdcVolumeType	BidVolume4;
	///申买价五
	TFocusFtdcPriceType	BidPrice5;
	///申买量五
	TFocusFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CFocusFtdcMarketDataAsk45Field
{
	///申卖价四
	TFocusFtdcPriceType	AskPrice4;
	///申卖量四
	TFocusFtdcVolumeType	AskVolume4;
	///申卖价五
	TFocusFtdcPriceType	AskPrice5;
	///申卖量五
	TFocusFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CFocusFtdcMarketDataUpdateTimeField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///深度行情
struct CFocusFtdcDepthMarketDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
	///申买价二
	TFocusFtdcPriceType	BidPrice2;
	///申买量二
	TFocusFtdcVolumeType	BidVolume2;
	///申买价三
	TFocusFtdcPriceType	BidPrice3;
	///申买量三
	TFocusFtdcVolumeType	BidVolume3;
	///申卖价二
	TFocusFtdcPriceType	AskPrice2;
	///申卖量二
	TFocusFtdcVolumeType	AskVolume2;
	///申卖价三
	TFocusFtdcPriceType	AskPrice3;
	///申卖量三
	TFocusFtdcVolumeType	AskVolume3;
	///申买价四
	TFocusFtdcPriceType	BidPrice4;
	///申买量四
	TFocusFtdcVolumeType	BidVolume4;
	///申买价五
	TFocusFtdcPriceType	BidPrice5;
	///申买量五
	TFocusFtdcVolumeType	BidVolume5;
	///申卖价四
	TFocusFtdcPriceType	AskPrice4;
	///申卖量四
	TFocusFtdcVolumeType	AskVolume4;
	///申卖价五
	TFocusFtdcPriceType	AskPrice5;
	///申卖量五
	TFocusFtdcVolumeType	AskVolume5;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///总卖出数量
	TFocusFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TFocusFtdcVolumeType	VolumeBidLot;
};

///订阅合约的相关信息
struct CFocusFtdcSpecificInstrumentField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者权限
struct CFocusFtdcInvestorRightField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///是否使用净持仓报单,投顾账户有效
	TFocusFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TFocusFtdcTradingRightType	TradingRight;
	///是否检查资金
	TFocusFtdcBoolType	CheckAccount;
	///是否检查持仓
	TFocusFtdcBoolType	CheckPosition;
	///报单是否报警
	TFocusFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TFocusFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TFocusFtdcDistributeTypeType	DistributeType;
};

///交易所代码
struct CFocusFtdcMarketDataExchangeIDField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
};

///共享内存行情查询
struct CFocusFtdcShmDepthMarketDataField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///订阅号
	TFocusFtdcTopicIDType	TopicID;
};

///TOPIC查询
struct CFocusFtdcTopicSearchField
{
	///订阅号
	TFocusFtdcTopicIDType	TopicID;
};

///分价行情
struct CFocusFtdcMBLMarketDataField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///价格
	TFocusFtdcPriceType	Price;
	///数量
	TFocusFtdcVolumeType	Volume;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///套利合约买卖总量
struct CFocusFtdcMarketDataCMBVolumeField
{
	///总卖出数量
	TFocusFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TFocusFtdcVolumeType	VolumeBidLot;
};

///合约状态
struct CFocusFtdcQmdInstrumentStateField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
};

///订阅合约的相关信息
struct CFocusFtdcSubSpecificInstrumentField
{
	///合约代码
	TFocusFtdcSubInstrumentIDType	InstrumentID;
};

///成交
struct CFocusFtdcTradeField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///成交价格
	TFocusFtdcPriceType	TradePrice;
	///成交数量
	TFocusFtdcVolumeType	TradeVolume;
	///成交时间
	TFocusFtdcTimeType	TradeTime;
	///清算会员编号
	TFocusFtdcParticipantIDType	ClearingPartID;
	///成交金额
	TFocusFtdcMoneyType	TradeAmnt;
	///交易类型
	TFocusFtdcTradeTypeType	TradeType;
};

///报单
struct CFocusFtdcOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///报单来源
	TFocusFtdcOrderSourceType	OrderSource;
	///报单状态
	TFocusFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///撤单用户编号
	TFocusFtdcUserIDType	CancelUserID;
	///已经成交数量
	TFocusFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TFocusFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TFocusFtdcVolumeType	VolumeCancled;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TFocusFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TFocusFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///请求编号
	TFocusFtdcRequestIDType	RequestID;
	///每手手续费
	TFocusFtdcMoneyType	EachFee;
	///每手保证金
	TFocusFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TFocusFtdcMoneyType	EachPremium;
	///下单IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TFocusFtdcMacAddressType	MacAddress;
	///营业部代码
	TFocusFtdcBranchIDType	BranchID;
	///记录编号
	TFocusFtdcSequenceNoType	RecNum;
};

///数据流回退
struct CFocusFtdcFlowMessageCancelField
{
	///序列系列号
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TFocusFtdcDateType	TradingDay;
	///数据中心代码
	TFocusFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TFocusFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TFocusFtdcSequenceNoType	EndSequenceNo;
};

///信息分发
struct CFocusFtdcDisseminationField
{
	///序列系列号
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TFocusFtdcSequenceNoType	SequenceNo;
};

///警告消息通知
struct CFocusFtdcMessageNotifyField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///累加次数
	TFocusFtdcTotalNumsType	Nums;
	///警告级别
	TFocusFtdcErrorLevelType	WarnLevel;
	///警告编号
	TFocusFtdcErrorIDType	WarnID;
	///警告信息
	TFocusFtdcLargeErrorMsgType	WarnMsg;
	///警告时间
	TFocusFtdcTimeType	WarnTime;
};

///工作流指令通知
struct CFocusFtdcAdviceOrderField
{
	///投顾用户代码
	TFocusFtdcUserIDType	InvestorAdvicer;
	///投资经理
	TFocusFtdcUserIDType	InvestorManager;
	///交易员
	TFocusFtdcUserIDType	UserTrader;
	///冻结数量
	TFocusFtdcVolumeType	VolumeFrozen;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户本地报单号
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///有效期类型
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TFocusFtdcDateType	GTDDate;
	///成交量类型
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TFocusFtdcVolumeType	MinVolume;
	///止损价
	TFocusFtdcPriceType	StopPrice;
	///强平原因
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TFocusFtdcBoolType	IsAutoSuspend;
	///业务单元
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TFocusFtdcBusinessTypeType	BusinessType;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///插入时间
	TFocusFtdcTimeType	InsertTime;
	///报单来源
	TFocusFtdcOrderSourceType	OrderSource;
	///报单状态
	TFocusFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TFocusFtdcTimeType	CancelTime;
	///撤单用户编号
	TFocusFtdcUserIDType	CancelUserID;
	///已经成交数量
	TFocusFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TFocusFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TFocusFtdcVolumeType	VolumeCancled;
	///错误代码
	TFocusFtdcErrorIDType	ErrorID;
	///错误信息
	TFocusFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TFocusFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TFocusFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///请求编号
	TFocusFtdcRequestIDType	RequestID;
	///每手手续费
	TFocusFtdcMoneyType	EachFee;
	///每手保证金
	TFocusFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TFocusFtdcMoneyType	EachPremium;
	///下单IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TFocusFtdcMacAddressType	MacAddress;
	///营业部代码
	TFocusFtdcBranchIDType	BranchID;
	///记录编号
	TFocusFtdcSequenceNoType	RecNum;
	///指令单用户信息
	TFocusFtdcAdviceUserInfoType	AdviceUserInfo;
};

///报单查询
struct CFocusFtdcQryOrderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///成交查询
struct CFocusFtdcQryTradeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///合约查询
struct CFocusFtdcQryInstrumentField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///合约查询应答
struct CFocusFtdcRspInstrumentField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///品种代码
	TFocusFtdcProductIDType	ProductID;
	///品种名称
	TFocusFtdcProductNameType	ProductName;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TFocusFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TFocusFtdcYearType	DeliveryYear;
	///交割月
	TFocusFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TFocusFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TFocusFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TFocusFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TFocusFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TFocusFtdcPriceTickType	PriceTick;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///多头限仓
	TFocusFtdcVolumeType	LongPosLimit;
	///空头限仓
	TFocusFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TFocusFtdcDateType	CreateDate;
	///上市日
	TFocusFtdcDateType	OpenDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///开始交割日
	TFocusFtdcDateType	StartDelivDate;
	///最后交割日
	TFocusFtdcDateType	EndDelivDate;
	///挂牌基准价
	TFocusFtdcPriceType	BasisPrice;
	///当前是否交易
	TFocusFtdcBoolType	IsTrading;
	///基础商品代码
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TFocusFtdcPositionTypeType	PositionType;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
	///产品类型
	TFocusFtdcProductClassType	ProductClass;
	///期权行权方式
	TFocusFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///投资者资金查询
struct CFocusFtdcQryInvestorAccountField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者资金应答
struct CFocusFtdcRspInvestorAccountField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///上次结算准备金
	TFocusFtdcMoneyType	PreBalance;
	///上日可用资金
	TFocusFtdcMoneyType	PreAvailable;
	///入金金额
	TFocusFtdcMoneyType	Deposit;
	///出金金额
	TFocusFtdcMoneyType	Withdraw;
	///占用保证金
	TFocusFtdcMoneyType	Margin;
	///期权权利金收支
	TFocusFtdcMoneyType	Premium;
	///手续费
	TFocusFtdcMoneyType	Fee;
	///冻结的保证金
	TFocusFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TFocusFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TFocusFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TFocusFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TFocusFtdcMoneyType	PositionProfit;
	///可用资金
	TFocusFtdcMoneyType	Available;
	///结算准备金
	TFocusFtdcMoneyType	Balance;
	///多头占用保证金
	TFocusFtdcMoneyType	LongMargin;
	///空头占用保证金
	TFocusFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TFocusFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TFocusFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TFocusFtdcMoneyType	DynamicRights;
	///风险度
	TFocusFtdcRatioType	Risk;
	///其他费用
	TFocusFtdcMoneyType	OtherFee;
	///质押金额
	TFocusFtdcMoneyType	Mortgage;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///可取资金
	TFocusFtdcMoneyType	WithdrawQuota;
	///过户费
	TFocusFtdcMoneyType	TransferFee;
	///冻结的过户费
	TFocusFtdcMoneyType	FrozenTransferFee;
	///印花税
	TFocusFtdcMoneyType	StampTax;
	///冻结的印花税
	TFocusFtdcMoneyType	FrozenStampTax;
};

///可用投资者查询
struct CFocusFtdcQryUserInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
};

///可用投资者应答
struct CFocusFtdcRspUserInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///默认用户代码
	TFocusFtdcUserIDType	NextUserID;
	///是否可下单
	TFocusFtdcAdviceUserOrderModeType	OrderMode;
	///自动或者手动
	TFocusFtdcAdviceRunModeType	RunMode;
	///工作流断线处理标示符
	TFocusFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
};

///投资者关系查询
struct CFocusFtdcQryInvestorRelationField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者关系应答
struct CFocusFtdcRspInvestorRelationField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///父投资者编号
	TFocusFtdcInvestorIDType	ParentInvestorID;
};

///交易所查询请求
struct CFocusFtdcQryExchangeField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
};

///交易所查询应答
struct CFocusFtdcRspExchangeField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TFocusFtdcExchangeNameType	ExchangeName;
};

///投资者持仓查询请求
struct CFocusFtdcQryInvestorPositionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者持仓查询应答
struct CFocusFtdcRspInvestorPositionField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TFocusFtdcMoneyType	UsedMargin;
	///总持仓量
	TFocusFtdcVolumeType	Position;
	///总持仓成本
	TFocusFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TFocusFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TFocusFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TFocusFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TFocusFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TFocusFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TFocusFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TFocusFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TFocusFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TFocusFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TFocusFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TFocusFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TFocusFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TFocusFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TFocusFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TFocusFtdcMoneyType	CloseProfit;
};

///用户查询
struct CFocusFtdcQryUserField
{
	///交易用户代码
	TFocusFtdcUserIDType	StartUserID;
	///交易用户代码
	TFocusFtdcUserIDType	EndUserID;
};

///用户
struct CFocusFtdcRspUserField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///用户登录密码
	TFocusFtdcPasswordType	Password;
	///是否活跃
	TFocusFtdcIsActiveType	IsActive;
	///用户名称
	TFocusFtdcUserNameType	UserName;
	///用户类型
	TFocusFtdcUserTypeType	UserType;
	///营业部
	TFocusFtdcDepartmentType	Department;
	///授权功能集
	TFocusFtdcGrantFuncSetType	GrantFuncSet;
	///最大在线数
	TFocusFtdcNumberType	MaxOnline;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///是否检查连接产品
	TFocusFtdcBoolType	CheckProductInfo;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///是否检查IP和MAC
	TFocusFtdcBoolType	CheckIPMacAddr;
	///错误登陆次数限制
	TFocusFtdcNumberType	LoginErrorLimit;
	///目前错误登陆次数
	TFocusFtdcNumberType	LoginErrorCount;
};

///投资者手续费率查询
struct CFocusFtdcQryInvestorFeeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///投资者手续费率
struct CFocusFtdcRspInvestorFeeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TFocusFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TFocusFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TFocusFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TFocusFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TFocusFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TFocusFtdcRatioType	OTFeeAmt;
};

///投资者保证金率查询
struct CFocusFtdcQryInvestorMarginField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
};

///投资者保证金率
struct CFocusFtdcRspInvestorMarginField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///多头占用保证金按比例
	TFocusFtdcRatioType	LongMarginRate;
	///多头保证金按手数
	TFocusFtdcRatioType	LongMarginAmt;
	///空头占用保证金按比例
	TFocusFtdcRatioType	ShortMarginRate;
	///空头保证金按手数
	TFocusFtdcRatioType	ShortMarginAmt;
};

///投资者查询
struct CFocusFtdcQryInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///投资者应答
struct CFocusFtdcRspInvestorField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///投资者名称
	TFocusFtdcInvestorNameType	InvestorName;
	///投资者类型
	TFocusFtdcInvestorTypeType	InvestorType;
	///投资者组编号
	TFocusFtdcInvestorIDType	GroupID;
	///投资者组名
	TFocusFtdcInvestorNameType	GroupName;
	///别名
	TFocusFtdcAliasType	Alias;
	///连接类型
	TFocusFtdcLinkTypeType	LinkType;
	///资金账户编号
	TFocusFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TFocusFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TFocusFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TFocusFtdcTradingRightType	TradingRight;
	///是否检查资金
	TFocusFtdcBoolType	CheckAccount;
	///是否检查持仓
	TFocusFtdcBoolType	CheckPosition;
	///报单是否报警
	TFocusFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TFocusFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TFocusFtdcDistributeTypeType	DistributeType;
};

///账号风险状况查询
struct CFocusFtdcQryAccountRiskField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///账号风险状况应答
struct CFocusFtdcRspAccountRiskField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///资金帐号
	TFocusFtdcAccountIDType	AccountID;
	///设置准备金
	TFocusFtdcMoneyType	SetBalance;
	///开仓红线
	TFocusFtdcMoneyType	OpenAvailable;
	///平仓红线
	TFocusFtdcMoneyType	OffsetAvailable;
	///账户状态
	TFocusFtdcAccountStatusType	AccountStatus;
	///动态权益
	TFocusFtdcMoneyType	DynamicRights;
	///账户权限
	TFocusFtdcTradingRightType	TradingRight;
};

///交易用户会话查询
struct CFocusFtdcQryUserSessionField
{
	///交易用户代码
	TFocusFtdcUserIDType	StartUserID;
	///交易用户代码
	TFocusFtdcUserIDType	EndUserID;
};

///交易用户会话应答
struct CFocusFtdcRspUserSessionField
{
	///经纪公司代码
	TFocusFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TFocusFtdcUserIDType	UserID;
	///交易用户类型
	TFocusFtdcUserTypeType	UserType;
	///会话编号
	TFocusFtdcSessionIDType	SessionID;
	///前置编号
	TFocusFtdcFrontIDType	FrontID;
	///登录时间
	TFocusFtdcTimeType	LoginTime;
	///IP地址
	TFocusFtdcIPAddressType	IPAddress;
	///Mac地址
	TFocusFtdcMacAddressType	MacAddress;
	///用户端产品信息
	TFocusFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TFocusFtdcProtocolInfoType	ProtocolInfo;
};

///行情查询
struct CFocusFtdcQryMarketDataField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///行情应答
struct CFocusFtdcRspMarketDataField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///昨结算
	TFocusFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TFocusFtdcPriceType	PreClosePrice;
	///昨持仓量
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TFocusFtdcRatioType	PreDelta;
	///今开盘
	TFocusFtdcPriceType	OpenPrice;
	///最高价
	TFocusFtdcPriceType	HighestPrice;
	///最低价
	TFocusFtdcPriceType	LowestPrice;
	///今收盘
	TFocusFtdcPriceType	ClosePrice;
	///涨停板价
	TFocusFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TFocusFtdcPriceType	LowerLimitPrice;
	///今结算
	TFocusFtdcPriceType	SettlementPrice;
	///今虚实度
	TFocusFtdcRatioType	CurrDelta;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
	///成交金额
	TFocusFtdcMoneyType	Turnover;
	///持仓量
	TFocusFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TFocusFtdcPriceType	BidPrice1;
	///申买量一
	TFocusFtdcVolumeType	BidVolume1;
	///申卖价一
	TFocusFtdcPriceType	AskPrice1;
	///申卖量一
	TFocusFtdcVolumeType	AskVolume1;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TFocusFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TFocusFtdcMillisecType	UpdateMillisec;
};

///产品查询
struct CFocusFtdcQryProductField
{
	///产品代码
	TFocusFtdcProductIDType	ProductID;
};

///产品应答
struct CFocusFtdcRspProductField
{
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///产品代码
	TFocusFtdcProductIDType	ProductID;
	///投资者发行的产品名称
	TFocusFtdcProductNameType	ProductName;
	///币种
	TFocusFtdcCurrencyType	Currency;
	///汇率
	TFocusFtdcRatioType	ExchangeRate;
};

///内部来回消息
struct CFocusFtdcPingPongField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///编号
	TFocusFtdcSequenceNoType	SequenceNo;
	///用户自定义域
	TFocusFtdcCustomType	UserCustom;
};

///最大可交易数量查询请求
struct CFocusFtdcQryMaxVolumeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
};

///最大可交易数量查询应答
struct CFocusFtdcRspMaxVolumeField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开平标志
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///价格
	TFocusFtdcPriceType	LimitPrice;
	///数量
	TFocusFtdcVolumeType	Volume;
};

///工作流交易员查询请求
struct CFocusFtdcQryAdviceTraderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///登录经纪公司编号
	TFocusFtdcBrokerIDType	LogBrokerID;
	///登录用户代码
	TFocusFtdcUserIDType	LogUserID;
};

///工作流交易员查询应答
struct CFocusFtdcRspAdviceTraderField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///用户代码
	TFocusFtdcUserIDType	UserID;
	///关联用户代码
	TFocusFtdcUserIDType	RelationUserID;
	///关联用户名称
	TFocusFtdcUserNameType	RelationUserName;
};

///组合持仓明细查询请求
struct CFocusFtdcQryCmbPositionDetailField
{
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
};

///组合持仓明细查询应答
struct CFocusFtdcRspCmbPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	CmbInstrumentID;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///报单编号
	TFocusFtdcOrderSysIDType	OrderSysID;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///持仓量
	TFocusFtdcVolumeType	Position;
	///单腿编号
	TFocusFtdcNumberType	LegQty;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询请求
struct CFocusFtdcQrySettlementInfoField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
};

///投资者结算结果查询应答
struct CFocusFtdcRspSettlementInfoField
{
	///交易日期
	TFocusFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///序号
	TFocusFtdcSequenceNoType	SequenceNo;
	///消息正文
	TFocusFtdcContentType	Content;
};

///查询结果集分页
struct CFocusFtdcQryResultPageField
{
	///结果集编号
	TFocusFtdcSessionIDType	ResultID;
	///总记录数
	TFocusFtdcNumberType	Count;
	///总页数
	TFocusFtdcNumberType	Pages;
	///剩余页数
	TFocusFtdcNumberType	Remain;
};

///查询持仓明细请求
struct CFocusFtdcQryPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///查询持仓明细应答
struct CFocusFtdcRspPositionDetailField
{
	///经纪公司编号
	TFocusFtdcBrokerIDType	BrokerID;
	///交易所代码
	TFocusFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TFocusFtdcInvestorIDType	InvestorID;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TFocusFtdcDirectionType	Direction;
	///开仓日期
	TFocusFtdcDateType	OpenDate;
	///成交编号
	TFocusFtdcTradeIDType	TradeID;
	///数量
	TFocusFtdcVolumeType	Volume;
	///开仓价
	TFocusFtdcMoneyType	OpenPrice;
	///交易日
	TFocusFtdcDateType	TradingDay;
	///交易类型
	TFocusFtdcTradeTypeType	TradeType;
	///组合合约代码
	TFocusFtdcInstrumentIDType	CombInstrumentID;
	///逐日盯市平仓盈亏
	TFocusFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TFocusFtdcMoneyType	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	TFocusFtdcMoneyType	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	TFocusFtdcMoneyType	PositionProfitByTrade;
	///投资者保证金
	TFocusFtdcMoneyType	Margin;
	///交易所保证金
	TFocusFtdcMoneyType	ExchMargin;
	///保证金率
	TFocusFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TFocusFtdcMoneyType	MarginRateByVolume;
	///昨结算价
	TFocusFtdcPriceType	LastSettlementPrice;
	///结算价
	TFocusFtdcPriceType	SettlementPrice;
	///平仓量
	TFocusFtdcVolumeType	CloseVolume;
	///平仓金额
	TFocusFtdcMoneyType	CloseAmount;
};

///理论价行情
struct CFocusFtdcTheoryPriceDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///理论价
	TFocusFtdcPriceType	TheoryPrice;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
	///标的最新价
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///标的买1价
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///标的卖1价
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///剩余时间
	TFocusFtdcTimeValueType	RemainDay;
};

///期权指标行情
struct CFocusFtdcOptionIndexDataField
{
	///交易日
	TFocusFtdcTradingDayType	TradingDay;
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma;
	///Vega
	TFocusFtdcGreekValueType	Vega;
	///Theta
	TFocusFtdcGreekValueType	Theta;
	///Rho
	TFocusFtdcGreekValueType	Rho;
	///买1价波动率
	TFocusFtdcVolatilityType	BidVol;
	///卖1价波动率
	TFocusFtdcVolatilityType	AskVol;
	///中间价波动率
	TFocusFtdcVolatilityType	MidVol;
	///最新价波动率
	TFocusFtdcVolatilityType	LastVol;
	///最新价
	TFocusFtdcPriceType	LastPrice;
	///买1价
	TFocusFtdcPriceType	BidPrice1;
	///卖1价
	TFocusFtdcPriceType	AskPrice1;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
	///标的最新价
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///标的买1价
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///标的卖1价
	TFocusFtdcPriceType	UnderlyingAskPrice1;
};

///定价参数
struct CFocusFtdcPricingParamField
{
	///期权系列
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///一级价格
	TFocusFtdcPriceTypeType	PriceLevel1;
	///二级价格
	TFocusFtdcPriceTypeType	PriceLevel2;
	///三级价格
	TFocusFtdcPriceTypeType	PriceLevel3;
	///计算日历
	TFocusFtdcDateTypeType	CalcDayType;
	///年总天数
	TFocusFtdcVolumeType	YearTotalDay;
	///计时方式
	TFocusFtdcTimingPatternType	CalcTimeType;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///定价模型
	TFocusFtdcPricingMethodType	PricingEngine;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///波动率精度
	TFocusFtdcToleranceType	VolTolerance;
};

///期权理论波动率
struct CFocusFtdcOptionTheoryVolField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///理论波动率
	TFocusFtdcVolatilityType	TheoryVol;
};

///定价基本参数
struct CFocusFtdcBasePricingParamField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///计算目标
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///标的价格
	TFocusFtdcPriceType	UnderlyingPrice;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///交易日
	TFocusFtdcDateType	TradingDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///波动率
	TFocusFtdcVolatilityType	Vol;
	///定价模型
	TFocusFtdcPricingMethodType	PricingModel;
	///期权价值
	TFocusFtdcPriceType	OptionPrice;
	///Delta
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
};

///双障碍期权定价参数
struct CFocusFtdcDoubleBarrierPricingParamField
{
	///合约代码
	TFocusFtdcInstrumentIDType	InstrumentID;
	///计算目标
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///期权类型
	TFocusFtdcOptionsTypeType	OptionsType;
	///标的价格
	TFocusFtdcPriceType	UnderlyingPrice;
	///执行价
	TFocusFtdcPriceType	StrikePrice;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///剩余天数
	TFocusFtdcTimeValueType	RemainDay;
	///交易日
	TFocusFtdcDateType	TradingDate;
	///到期日
	TFocusFtdcDateType	ExpireDate;
	///波动率
	TFocusFtdcVolatilityType	Vol;
	///定价模型
	TFocusFtdcPricingMethodType	PricingModel;
	///期权价值
	TFocusFtdcPriceType	OptionPrice;
	///Delta
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
	///障碍类型
	TFocusFtdcBarrierTypeType	BarrierType;
	///障碍下沿值
	TFocusFtdcRatioType	LowerBarrierRate;
	///障碍上沿值
	TFocusFtdcRatioType	UpperBarrierRate;
};

///期权组合定价参数
struct CFocusFtdcCombinationParamField
{
	///计算目标
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///行权方式
	TFocusFtdcExerciseTypeType	ExerciseType;
	///标的价格
	TFocusFtdcPriceType	UnderlyingPrice;
	///无风险利率
	TFocusFtdcRatioType	RiskFreeRate;
	///股息率
	TFocusFtdcRatioType	Dividend;
	///交易日
	TFocusFtdcDateType	TradingDate;
	///定价模型
	TFocusFtdcPricingMethodType	PricingModel;
	///期权组合的价格
	TFocusFtdcPriceType	CombinationPrice;
	///腿1合约代码
	TFocusFtdcInstrumentIDType	InstrumentID_Leg1;
	///腿1期权类型
	TFocusFtdcOptionsTypeType	OptionsType_Leg1;
	///腿1买卖方向
	TFocusFtdcDirectionType	Direction_Leg1;
	///腿1执行价
	TFocusFtdcPriceType	StrikePrice_Leg1;
	///腿1到期日
	TFocusFtdcDateType	ExpireDate_Leg1;
	///腿1波动率
	TFocusFtdcVolatilityType	Vol_Leg1;
	///腿1期权价值
	TFocusFtdcPriceType	OptionPrice_Leg1;
	///腿1Delta
	TFocusFtdcGreekValueType	Delta_Leg1;
	///腿1Gamma
	TFocusFtdcGreekValueType	Gamma_Leg1;
	///腿1Vega
	TFocusFtdcGreekValueType	Vega_Leg1;
	///腿1Theta
	TFocusFtdcGreekValueType	Theta_Leg1;
	///腿1Rho
	TFocusFtdcGreekValueType	Rho_Leg1;
	///腿1Vanna
	TFocusFtdcGreekValueType	Vanna_Leg1;
	///腿1Valga
	TFocusFtdcGreekValueType	Valga_Leg1;
	///腿2合约代码
	TFocusFtdcInstrumentIDType	InstrumentID_Leg2;
	///腿2期权类型
	TFocusFtdcOptionsTypeType	OptionsType_Leg2;
	///腿2买卖方向
	TFocusFtdcDirectionType	Direction_Leg2;
	///腿2执行价
	TFocusFtdcPriceType	StrikePrice_Leg2;
	///腿2到期日
	TFocusFtdcDateType	ExpireDate_Leg2;
	///腿2波动率
	TFocusFtdcVolatilityType	Vol_Leg2;
	///腿2期权价值
	TFocusFtdcPriceType	OptionPrice_Leg2;
	///腿2Delta
	TFocusFtdcGreekValueType	Delta_Leg2;
	///Gamma
	TFocusFtdcGreekValueType	Gamma_Leg2;
	///腿2Vega
	TFocusFtdcGreekValueType	Vega_Leg2;
	///腿2Theta
	TFocusFtdcGreekValueType	Theta_Leg2;
	///腿2Rho
	TFocusFtdcGreekValueType	Rho_Leg2;
	///腿2Vanna
	TFocusFtdcGreekValueType	Vanna_Leg2;
	///腿2Valga
	TFocusFtdcGreekValueType	Valga_Leg2;
	///腿3合约代码
	TFocusFtdcInstrumentIDType	InstrumentID_Leg3;
	///腿3期权类型
	TFocusFtdcOptionsTypeType	OptionsType_Leg3;
	///腿3买卖方向
	TFocusFtdcDirectionType	Direction_Leg3;
	///腿3执行价
	TFocusFtdcPriceType	StrikePrice_Leg3;
	///腿3到期日
	TFocusFtdcDateType	ExpireDate_Leg3;
	///腿3波动率
	TFocusFtdcVolatilityType	Vol_Leg3;
	///腿3期权价值
	TFocusFtdcPriceType	OptionPrice_Leg3;
	///腿3Delta
	TFocusFtdcGreekValueType	Delta_Leg3;
	///腿3Gamma
	TFocusFtdcGreekValueType	Gamma_Leg3;
	///腿3Vega
	TFocusFtdcGreekValueType	Vega_Leg3;
	///腿3Theta
	TFocusFtdcGreekValueType	Theta_Leg3;
	///腿3Rho
	TFocusFtdcGreekValueType	Rho_Leg3;
	///腿3Vanna
	TFocusFtdcGreekValueType	Vanna_Leg3;
	///腿3Valga
	TFocusFtdcGreekValueType	Valga_Leg3;
	///腿4合约代码
	TFocusFtdcInstrumentIDType	InstrumentID_Leg4;
	///腿4期权类型
	TFocusFtdcOptionsTypeType	OptionsType_Leg4;
	///腿4买卖方向
	TFocusFtdcDirectionType	Direction_Leg4;
	///腿4执行价
	TFocusFtdcPriceType	StrikePrice_Leg4;
	///腿4到期日
	TFocusFtdcDateType	ExpireDate_Leg4;
	///腿4波动率
	TFocusFtdcVolatilityType	Vol_Leg4;
	///腿4期权价值
	TFocusFtdcPriceType	OptionPrice_Leg4;
	///腿4Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma_Leg4;
	///腿4Vega
	TFocusFtdcGreekValueType	Vega_Leg4;
	///腿4Theta
	TFocusFtdcGreekValueType	Theta_Leg4;
	///腿4Rho
	TFocusFtdcGreekValueType	Rho_Leg4;
	///腿4Vanna
	TFocusFtdcGreekValueType	Vanna_Leg4;
	///腿4Valga
	TFocusFtdcGreekValueType	Valga_Leg4;
};



#endif
