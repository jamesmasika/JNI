/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file FocusFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Focus_FTDCSTRUCT_H)
#define Focus_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FocusFtdcUserApiDataType.h"

///��Ӧ��Ϣ
struct CFocusFtdcRspInfoField
{
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
};

///ϵͳ�û���¼����
struct CFocusFtdcReqUserLoginField
{
	///������
	TFocusFtdcDateType	TradingDay;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����
	TFocusFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TFocusFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TFocusFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TFocusFtdcIPAddressType	ClientIPAddress;
	///��Ȩ����
	TFocusFtdcAuthCodeType	AuthCode;
};

///ϵͳ�û���¼Ӧ��
struct CFocusFtdcRspUserLoginField
{
	///������
	TFocusFtdcDateType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TFocusFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TFocusFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TFocusFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TFocusFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TFocusFtdcSequenceNoType	UserFlowSize;
	///��¼������Ϣ
	TFocusFtdcLoginInfoType	LoginInfo;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
};

///�û��ǳ�����
struct CFocusFtdcReqUserLogoutField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///�û��ǳ�����
struct CFocusFtdcRspUserLogoutField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///ǿ���û��˳�
struct CFocusFtdcForceUserExitField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
};

///�û������޸�
struct CFocusFtdcUserPasswordUpdateField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///������
	TFocusFtdcPasswordType	OldPassword;
	///������
	TFocusFtdcPasswordType	NewPassword;
};

///���뱨��
struct CFocusFtdcInputOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
};

///��������
struct CFocusFtdcOrderActionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TFocusFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TFocusFtdcActionFlagType	ActionFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///�����仯
	TFocusFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
};

///�ڴ����
struct CFocusFtdcMemDBField
{
	///�ڴ����
	TFocusFtdcMemTableNameType	MemTableName;
};

///Ͷ�����ʽ��ʻ����������
struct CFocusFtdcReqAccountDepositField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///Ͷ�����ʽ��ʻ������Ӧ��
struct CFocusFtdcRspAccountDepositField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///ʵʱ�ϳ�
struct CFocusFtdcTBCommandField
{
	///DB�������
	TFocusFtdcCommandNoType	CommandNo;
	///��������
	TFocusFtdcDateType	CommandDate;
	///����ʱ��
	TFocusFtdcTimeType	CommandTime;
	///DB��������
	TFocusFtdcCommandTypeType	CommandType;
	///�ֶ���
	TFocusFtdcFieldNameType	FieldName;
	///�ֶ�����
	TFocusFtdcFieldContentType	FieldContent;
};

///�������
struct CFocusFtdcInvestorAccountDepositResField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TFocusFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TFocusFtdcMoneyType	Amount;
	///�������
	TFocusFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///��Լ״̬
struct CFocusFtdcInstrumentStatusField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TFocusFtdcProductIDType	ProductID;
	///Ʒ������
	TFocusFtdcProductNameType	ProductName;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///�������
	TFocusFtdcYearType	DeliveryYear;
	///������
	TFocusFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TFocusFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TFocusFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TFocusFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TFocusFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TFocusFtdcPriceTickType	PriceTick;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TFocusFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TFocusFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TFocusFtdcDateType	CreateDate;
	///������
	TFocusFtdcDateType	OpenDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///��ʼ������
	TFocusFtdcDateType	StartDelivDate;
	///��󽻸���
	TFocusFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TFocusFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TFocusFtdcBoolType	IsTrading;
	///������Ʒ����
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TFocusFtdcPositionTypeType	PositionType;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///����
	TFocusFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TFocusFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TFocusFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///����ģʽ��������
struct CFocusFtdcAdviceRunModeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�Զ������ֶ�
	TFocusFtdcAdviceRunModeType	RunMode;
};

///���ĺ�Լ״̬
struct CFocusFtdcSubInstrumentStatusField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///���뱾״̬ʱ��
	TFocusFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TFocusFtdcEnterReasonType	EnterReason;
};

///�����������
struct CFocusFtdcMarketDataBaseField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
};

///���龲̬����
struct CFocusFtdcMarketDataStaticField
{
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CFocusFtdcMarketDataLastMatchField
{
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CFocusFtdcMarketDataBestPriceField
{
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
};

///�����������������
struct CFocusFtdcMarketDataBid23Field
{
	///����۶�
	TFocusFtdcPriceType	BidPrice2;
	///��������
	TFocusFtdcVolumeType	BidVolume2;
	///�������
	TFocusFtdcPriceType	BidPrice3;
	///��������
	TFocusFtdcVolumeType	BidVolume3;
};

///������������������
struct CFocusFtdcMarketDataAsk23Field
{
	///�����۶�
	TFocusFtdcPriceType	AskPrice2;
	///��������
	TFocusFtdcVolumeType	AskVolume2;
	///��������
	TFocusFtdcPriceType	AskPrice3;
	///��������
	TFocusFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CFocusFtdcMarketDataBid45Field
{
	///�������
	TFocusFtdcPriceType	BidPrice4;
	///��������
	TFocusFtdcVolumeType	BidVolume4;
	///�������
	TFocusFtdcPriceType	BidPrice5;
	///��������
	TFocusFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CFocusFtdcMarketDataAsk45Field
{
	///��������
	TFocusFtdcPriceType	AskPrice4;
	///��������
	TFocusFtdcVolumeType	AskVolume4;
	///��������
	TFocusFtdcPriceType	AskPrice5;
	///��������
	TFocusFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CFocusFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///�������
struct CFocusFtdcDepthMarketDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
	///����۶�
	TFocusFtdcPriceType	BidPrice2;
	///��������
	TFocusFtdcVolumeType	BidVolume2;
	///�������
	TFocusFtdcPriceType	BidPrice3;
	///��������
	TFocusFtdcVolumeType	BidVolume3;
	///�����۶�
	TFocusFtdcPriceType	AskPrice2;
	///��������
	TFocusFtdcVolumeType	AskVolume2;
	///��������
	TFocusFtdcPriceType	AskPrice3;
	///��������
	TFocusFtdcVolumeType	AskVolume3;
	///�������
	TFocusFtdcPriceType	BidPrice4;
	///��������
	TFocusFtdcVolumeType	BidVolume4;
	///�������
	TFocusFtdcPriceType	BidPrice5;
	///��������
	TFocusFtdcVolumeType	BidVolume5;
	///��������
	TFocusFtdcPriceType	AskPrice4;
	///��������
	TFocusFtdcVolumeType	AskVolume4;
	///��������
	TFocusFtdcPriceType	AskPrice5;
	///��������
	TFocusFtdcVolumeType	AskVolume5;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///����������
	TFocusFtdcVolumeType	VolumeAskLot;
	///����������
	TFocusFtdcVolumeType	VolumeBidLot;
};

///���ĺ�Լ�������Ϣ
struct CFocusFtdcSpecificInstrumentField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ����Ȩ��
struct CFocusFtdcInvestorRightField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TFocusFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TFocusFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TFocusFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TFocusFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TFocusFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TFocusFtdcDistributeTypeType	DistributeType;
};

///����������
struct CFocusFtdcMarketDataExchangeIDField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
};

///�����ڴ������ѯ
struct CFocusFtdcShmDepthMarketDataField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///���ĺ�
	TFocusFtdcTopicIDType	TopicID;
};

///TOPIC��ѯ
struct CFocusFtdcTopicSearchField
{
	///���ĺ�
	TFocusFtdcTopicIDType	TopicID;
};

///�ּ�����
struct CFocusFtdcMBLMarketDataField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///�۸�
	TFocusFtdcPriceType	Price;
	///����
	TFocusFtdcVolumeType	Volume;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///������Լ��������
struct CFocusFtdcMarketDataCMBVolumeField
{
	///����������
	TFocusFtdcVolumeType	VolumeAskLot;
	///����������
	TFocusFtdcVolumeType	VolumeBidLot;
};

///��Լ״̬
struct CFocusFtdcQmdInstrumentStateField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
};

///���ĺ�Լ�������Ϣ
struct CFocusFtdcSubSpecificInstrumentField
{
	///��Լ����
	TFocusFtdcSubInstrumentIDType	InstrumentID;
};

///�ɽ�
struct CFocusFtdcTradeField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�ɽ��۸�
	TFocusFtdcPriceType	TradePrice;
	///�ɽ�����
	TFocusFtdcVolumeType	TradeVolume;
	///�ɽ�ʱ��
	TFocusFtdcTimeType	TradeTime;
	///�����Ա���
	TFocusFtdcParticipantIDType	ClearingPartID;
	///�ɽ����
	TFocusFtdcMoneyType	TradeAmnt;
	///��������
	TFocusFtdcTradeTypeType	TradeType;
};

///����
struct CFocusFtdcOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///������Դ
	TFocusFtdcOrderSourceType	OrderSource;
	///����״̬
	TFocusFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�����û����
	TFocusFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TFocusFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TFocusFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TFocusFtdcVolumeType	VolumeCancled;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TFocusFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TFocusFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///������
	TFocusFtdcRequestIDType	RequestID;
	///ÿ��������
	TFocusFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TFocusFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TFocusFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TFocusFtdcBranchIDType	BranchID;
	///��¼���
	TFocusFtdcSequenceNoType	RecNum;
};

///����������
struct CFocusFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///������
	TFocusFtdcDateType	TradingDay;
	///�������Ĵ���
	TFocusFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TFocusFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TFocusFtdcSequenceNoType	EndSequenceNo;
};

///��Ϣ�ַ�
struct CFocusFtdcDisseminationField
{
	///����ϵ�к�
	TFocusFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TFocusFtdcSequenceNoType	SequenceNo;
};

///������Ϣ֪ͨ
struct CFocusFtdcMessageNotifyField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ۼӴ���
	TFocusFtdcTotalNumsType	Nums;
	///���漶��
	TFocusFtdcErrorLevelType	WarnLevel;
	///������
	TFocusFtdcErrorIDType	WarnID;
	///������Ϣ
	TFocusFtdcLargeErrorMsgType	WarnMsg;
	///����ʱ��
	TFocusFtdcTimeType	WarnTime;
};

///������ָ��֪ͨ
struct CFocusFtdcAdviceOrderField
{
	///Ͷ���û�����
	TFocusFtdcUserIDType	InvestorAdvicer;
	///Ͷ�ʾ���
	TFocusFtdcUserIDType	InvestorManager;
	///����Ա
	TFocusFtdcUserIDType	UserTrader;
	///��������
	TFocusFtdcVolumeType	VolumeFrozen;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û����ر�����
	TFocusFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///��Ч������
	TFocusFtdcTimeConditionType	TimeCondition;
	///GTD����
	TFocusFtdcDateType	GTDDate;
	///�ɽ�������
	TFocusFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TFocusFtdcVolumeType	MinVolume;
	///ֹ���
	TFocusFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TFocusFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TFocusFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TFocusFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TFocusFtdcBusinessTypeType	BusinessType;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����ʱ��
	TFocusFtdcTimeType	InsertTime;
	///������Դ
	TFocusFtdcOrderSourceType	OrderSource;
	///����״̬
	TFocusFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TFocusFtdcTimeType	CancelTime;
	///�����û����
	TFocusFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TFocusFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TFocusFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TFocusFtdcVolumeType	VolumeCancled;
	///�������
	TFocusFtdcErrorIDType	ErrorID;
	///������Ϣ
	TFocusFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TFocusFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TFocusFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///������
	TFocusFtdcRequestIDType	RequestID;
	///ÿ��������
	TFocusFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TFocusFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TFocusFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TFocusFtdcBranchIDType	BranchID;
	///��¼���
	TFocusFtdcSequenceNoType	RecNum;
	///ָ��û���Ϣ
	TFocusFtdcAdviceUserInfoType	AdviceUserInfo;
};

///������ѯ
struct CFocusFtdcQryOrderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///�ɽ���ѯ
struct CFocusFtdcQryTradeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯ
struct CFocusFtdcQryInstrumentField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯӦ��
struct CFocusFtdcRspInstrumentField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TFocusFtdcProductIDType	ProductID;
	///Ʒ������
	TFocusFtdcProductNameType	ProductName;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TFocusFtdcInstrumentNameType	InstrumentName;
	///�������
	TFocusFtdcYearType	DeliveryYear;
	///������
	TFocusFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TFocusFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TFocusFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TFocusFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TFocusFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TFocusFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TFocusFtdcPriceTickType	PriceTick;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TFocusFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TFocusFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TFocusFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TFocusFtdcDateType	CreateDate;
	///������
	TFocusFtdcDateType	OpenDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///��ʼ������
	TFocusFtdcDateType	StartDelivDate;
	///��󽻸���
	TFocusFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TFocusFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TFocusFtdcBoolType	IsTrading;
	///������Ʒ����
	TFocusFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TFocusFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TFocusFtdcPositionTypeType	PositionType;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///����
	TFocusFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TFocusFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TFocusFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TFocusFtdcMarginCombTypeType	MarginCombType;
};

///Ͷ�����ʽ��ѯ
struct CFocusFtdcQryInvestorAccountField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ�����ʽ�Ӧ��
struct CFocusFtdcRspInvestorAccountField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///�ϴν���׼����
	TFocusFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TFocusFtdcMoneyType	PreAvailable;
	///�����
	TFocusFtdcMoneyType	Deposit;
	///������
	TFocusFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TFocusFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TFocusFtdcMoneyType	Premium;
	///������
	TFocusFtdcMoneyType	Fee;
	///����ı�֤��
	TFocusFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TFocusFtdcMoneyType	FrozenPremium;
	///����������
	TFocusFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TFocusFtdcMoneyType	Available;
	///����׼����
	TFocusFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TFocusFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TFocusFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TFocusFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TFocusFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TFocusFtdcMoneyType	DynamicRights;
	///���ն�
	TFocusFtdcRatioType	Risk;
	///��������
	TFocusFtdcMoneyType	OtherFee;
	///��Ѻ���
	TFocusFtdcMoneyType	Mortgage;
	///����
	TFocusFtdcCurrencyType	Currency;
	///��ȡ�ʽ�
	TFocusFtdcMoneyType	WithdrawQuota;
	///������
	TFocusFtdcMoneyType	TransferFee;
	///����Ĺ�����
	TFocusFtdcMoneyType	FrozenTransferFee;
	///ӡ��˰
	TFocusFtdcMoneyType	StampTax;
	///�����ӡ��˰
	TFocusFtdcMoneyType	FrozenStampTax;
};

///����Ͷ���߲�ѯ
struct CFocusFtdcQryUserInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
};

///����Ͷ����Ӧ��
struct CFocusFtdcRspUserInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///Ĭ���û�����
	TFocusFtdcUserIDType	NextUserID;
	///�Ƿ���µ�
	TFocusFtdcAdviceUserOrderModeType	OrderMode;
	///�Զ������ֶ�
	TFocusFtdcAdviceRunModeType	RunMode;
	///���������ߴ����ʾ��
	TFocusFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
};

///Ͷ���߹�ϵ��ѯ
struct CFocusFtdcQryInvestorRelationField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ���߹�ϵӦ��
struct CFocusFtdcRspInvestorRelationField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Ͷ���߱��
	TFocusFtdcInvestorIDType	ParentInvestorID;
};

///��������ѯ����
struct CFocusFtdcQryExchangeField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
};

///��������ѯӦ��
struct CFocusFtdcRspExchangeField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///����������
	TFocusFtdcExchangeNameType	ExchangeName;
};

///Ͷ���ֲֲ߳�ѯ����
struct CFocusFtdcQryInvestorPositionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲֲ߳�ѯӦ��
struct CFocusFtdcRspInvestorPositionField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TFocusFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TFocusFtdcVolumeType	Position;
	///�ֲֳܳɱ�
	TFocusFtdcPriceType	PositionCost;
	///��ʼ��ֲ���(���ղ���)
	TFocusFtdcVolumeType	YdPosition;
	///��ʼ���ճֲֳɱ�(���ղ���)
	TFocusFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TFocusFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TFocusFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TFocusFtdcVolumeType	FrozenClosing;
	///�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfit;
	///�����Ȩ����
	TFocusFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TFocusFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TFocusFtdcOrderLocalIDType	LastOrderLocalID;
	///�ֲֿܳ�ƽ������(����ƽ�ֶ���ֲ�)
	TFocusFtdcVolumeType	PositionClose;
	///��ֲֿ�ƽ������(����ƽ�ֶ���ֲ�)
	TFocusFtdcVolumeType	YdPositionClose;
	///��ֲ�ƽ�ֶ���ֲ�
	TFocusFtdcVolumeType	YdFrozenClosing;
	///���տ�������(����������)
	TFocusFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TFocusFtdcVolumeType	CloseVolume;
	///ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfit;
};

///�û���ѯ
struct CFocusFtdcQryUserField
{
	///�����û�����
	TFocusFtdcUserIDType	StartUserID;
	///�����û�����
	TFocusFtdcUserIDType	EndUserID;
};

///�û�
struct CFocusFtdcRspUserField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�û���¼����
	TFocusFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TFocusFtdcIsActiveType	IsActive;
	///�û�����
	TFocusFtdcUserNameType	UserName;
	///�û�����
	TFocusFtdcUserTypeType	UserType;
	///Ӫҵ��
	TFocusFtdcDepartmentType	Department;
	///��Ȩ���ܼ�
	TFocusFtdcGrantFuncSetType	GrantFuncSet;
	///���������
	TFocusFtdcNumberType	MaxOnline;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///�Ƿ������Ӳ�Ʒ
	TFocusFtdcBoolType	CheckProductInfo;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�Ƿ���IP��MAC
	TFocusFtdcBoolType	CheckIPMacAddr;
	///�����½��������
	TFocusFtdcNumberType	LoginErrorLimit;
	///Ŀǰ�����½����
	TFocusFtdcNumberType	LoginErrorCount;
};

///Ͷ�����������ʲ�ѯ
struct CFocusFtdcQryInvestorFeeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///Ͷ������������
struct CFocusFtdcRspInvestorFeeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���������Ѱ�����
	TFocusFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TFocusFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TFocusFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TFocusFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TFocusFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TFocusFtdcRatioType	OTFeeAmt;
};

///Ͷ���߱�֤���ʲ�ѯ
struct CFocusFtdcQryInvestorMarginField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
};

///Ͷ���߱�֤����
struct CFocusFtdcRspInvestorMarginField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///��ͷռ�ñ�֤�𰴱���
	TFocusFtdcRatioType	LongMarginRate;
	///��ͷ��֤������
	TFocusFtdcRatioType	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	TFocusFtdcRatioType	ShortMarginRate;
	///��ͷ��֤������
	TFocusFtdcRatioType	ShortMarginAmt;
};

///Ͷ���߲�ѯ
struct CFocusFtdcQryInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///Ͷ����Ӧ��
struct CFocusFtdcRspInvestorField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///Ͷ��������
	TFocusFtdcInvestorNameType	InvestorName;
	///Ͷ��������
	TFocusFtdcInvestorTypeType	InvestorType;
	///Ͷ��������
	TFocusFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TFocusFtdcInvestorNameType	GroupName;
	///����
	TFocusFtdcAliasType	Alias;
	///��������
	TFocusFtdcLinkTypeType	LinkType;
	///�ʽ��˻����
	TFocusFtdcInvestorIDType	ParentInvestorID;
	///��¼����
	TFocusFtdcNumberType	LoginStatus;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TFocusFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TFocusFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TFocusFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TFocusFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TFocusFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TFocusFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TFocusFtdcDistributeTypeType	DistributeType;
};

///�˺ŷ���״����ѯ
struct CFocusFtdcQryAccountRiskField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///�˺ŷ���״��Ӧ��
struct CFocusFtdcRspAccountRiskField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TFocusFtdcAccountIDType	AccountID;
	///����׼����
	TFocusFtdcMoneyType	SetBalance;
	///���ֺ���
	TFocusFtdcMoneyType	OpenAvailable;
	///ƽ�ֺ���
	TFocusFtdcMoneyType	OffsetAvailable;
	///�˻�״̬
	TFocusFtdcAccountStatusType	AccountStatus;
	///��̬Ȩ��
	TFocusFtdcMoneyType	DynamicRights;
	///�˻�Ȩ��
	TFocusFtdcTradingRightType	TradingRight;
};

///�����û��Ự��ѯ
struct CFocusFtdcQryUserSessionField
{
	///�����û�����
	TFocusFtdcUserIDType	StartUserID;
	///�����û�����
	TFocusFtdcUserIDType	EndUserID;
};

///�����û��ỰӦ��
struct CFocusFtdcRspUserSessionField
{
	///���͹�˾����
	TFocusFtdcBrokerIDType	BrokerID;
	///�����û�����
	TFocusFtdcUserIDType	UserID;
	///�����û�����
	TFocusFtdcUserTypeType	UserType;
	///�Ự���
	TFocusFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TFocusFtdcFrontIDType	FrontID;
	///��¼ʱ��
	TFocusFtdcTimeType	LoginTime;
	///IP��ַ
	TFocusFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TFocusFtdcMacAddressType	MacAddress;
	///�û��˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TFocusFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TFocusFtdcProtocolInfoType	ProtocolInfo;
};

///�����ѯ
struct CFocusFtdcQryMarketDataField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///����Ӧ��
struct CFocusFtdcRspMarketDataField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///�����
	TFocusFtdcPriceType	PreSettlementPrice;
	///������
	TFocusFtdcPriceType	PreClosePrice;
	///��ֲ���
	TFocusFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TFocusFtdcRatioType	PreDelta;
	///����
	TFocusFtdcPriceType	OpenPrice;
	///��߼�
	TFocusFtdcPriceType	HighestPrice;
	///��ͼ�
	TFocusFtdcPriceType	LowestPrice;
	///������
	TFocusFtdcPriceType	ClosePrice;
	///��ͣ���
	TFocusFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TFocusFtdcPriceType	LowerLimitPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///����ʵ��
	TFocusFtdcRatioType	CurrDelta;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///����
	TFocusFtdcVolumeType	Volume;
	///�ɽ����
	TFocusFtdcMoneyType	Turnover;
	///�ֲ���
	TFocusFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TFocusFtdcPriceType	BidPrice1;
	///������һ
	TFocusFtdcVolumeType	BidVolume1;
	///������һ
	TFocusFtdcPriceType	AskPrice1;
	///������һ
	TFocusFtdcVolumeType	AskVolume1;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TFocusFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TFocusFtdcMillisecType	UpdateMillisec;
};

///��Ʒ��ѯ
struct CFocusFtdcQryProductField
{
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
};

///��ƷӦ��
struct CFocusFtdcRspProductField
{
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TFocusFtdcProductIDType	ProductID;
	///Ͷ���߷��еĲ�Ʒ����
	TFocusFtdcProductNameType	ProductName;
	///����
	TFocusFtdcCurrencyType	Currency;
	///����
	TFocusFtdcRatioType	ExchangeRate;
};

///�ڲ�������Ϣ
struct CFocusFtdcPingPongField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcSequenceNoType	SequenceNo;
	///�û��Զ�����
	TFocusFtdcCustomType	UserCustom;
};

///���ɽ���������ѯ����
struct CFocusFtdcQryMaxVolumeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
};

///���ɽ���������ѯӦ��
struct CFocusFtdcRspMaxVolumeField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��ƽ��־
	TFocusFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TFocusFtdcPriceType	LimitPrice;
	///����
	TFocusFtdcVolumeType	Volume;
};

///����������Ա��ѯ����
struct CFocusFtdcQryAdviceTraderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��¼���͹�˾���
	TFocusFtdcBrokerIDType	LogBrokerID;
	///��¼�û�����
	TFocusFtdcUserIDType	LogUserID;
};

///����������Ա��ѯӦ��
struct CFocusFtdcRspAdviceTraderField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///�û�����
	TFocusFtdcUserIDType	UserID;
	///�����û�����
	TFocusFtdcUserIDType	RelationUserID;
	///�����û�����
	TFocusFtdcUserNameType	RelationUserName;
};

///��ϳֲ���ϸ��ѯ����
struct CFocusFtdcQryCmbPositionDetailField
{
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
};

///��ϳֲ���ϸ��ѯӦ��
struct CFocusFtdcRspCmbPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	CmbInstrumentID;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///�������
	TFocusFtdcOrderSysIDType	OrderSysID;
	///��������
	TFocusFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///�ֲ���
	TFocusFtdcVolumeType	Position;
	///���ȱ��
	TFocusFtdcNumberType	LegQty;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯ����
struct CFocusFtdcQrySettlementInfoField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��������
	TFocusFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯӦ��
struct CFocusFtdcRspSettlementInfoField
{
	///��������
	TFocusFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���
	TFocusFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TFocusFtdcContentType	Content;
};

///��ѯ�������ҳ
struct CFocusFtdcQryResultPageField
{
	///��������
	TFocusFtdcSessionIDType	ResultID;
	///�ܼ�¼��
	TFocusFtdcNumberType	Count;
	///��ҳ��
	TFocusFtdcNumberType	Pages;
	///ʣ��ҳ��
	TFocusFtdcNumberType	Remain;
};

///��ѯ�ֲ���ϸ����
struct CFocusFtdcQryPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ֲ���ϸӦ��
struct CFocusFtdcRspPositionDetailField
{
	///���͹�˾���
	TFocusFtdcBrokerIDType	BrokerID;
	///����������
	TFocusFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TFocusFtdcInvestorIDType	InvestorID;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TFocusFtdcHedgeFlagType	HedgeFlag;
	///��������
	TFocusFtdcDirectionType	Direction;
	///��������
	TFocusFtdcDateType	OpenDate;
	///�ɽ����
	TFocusFtdcTradeIDType	TradeID;
	///����
	TFocusFtdcVolumeType	Volume;
	///���ּ�
	TFocusFtdcMoneyType	OpenPrice;
	///������
	TFocusFtdcDateType	TradingDay;
	///��������
	TFocusFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TFocusFtdcInstrumentIDType	CombInstrumentID;
	///���ն���ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TFocusFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TFocusFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TFocusFtdcMoneyType	Margin;
	///��������֤��
	TFocusFtdcMoneyType	ExchMargin;
	///��֤����
	TFocusFtdcMoneyType	MarginRateByMoney;
	///��֤����(������)
	TFocusFtdcMoneyType	MarginRateByVolume;
	///������
	TFocusFtdcPriceType	LastSettlementPrice;
	///�����
	TFocusFtdcPriceType	SettlementPrice;
	///ƽ����
	TFocusFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TFocusFtdcMoneyType	CloseAmount;
};

///���ۼ�����
struct CFocusFtdcTheoryPriceDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���ۼ�
	TFocusFtdcPriceType	TheoryPrice;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
	///������¼�
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///�����1��
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///�����1��
	TFocusFtdcPriceType	UnderlyingAskPrice1;
	///ʣ��ʱ��
	TFocusFtdcTimeValueType	RemainDay;
};

///��Ȩָ������
struct CFocusFtdcOptionIndexDataField
{
	///������
	TFocusFtdcTradingDayType	TradingDay;
	///��Լ����
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
	///��1�۲�����
	TFocusFtdcVolatilityType	BidVol;
	///��1�۲�����
	TFocusFtdcVolatilityType	AskVol;
	///�м�۲�����
	TFocusFtdcVolatilityType	MidVol;
	///���¼۲�����
	TFocusFtdcVolatilityType	LastVol;
	///���¼�
	TFocusFtdcPriceType	LastPrice;
	///��1��
	TFocusFtdcPriceType	BidPrice1;
	///��1��
	TFocusFtdcPriceType	AskPrice1;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
	///������¼�
	TFocusFtdcPriceType	UnderlyingLastPrice;
	///�����1��
	TFocusFtdcPriceType	UnderlyingBidPrice1;
	///�����1��
	TFocusFtdcPriceType	UnderlyingAskPrice1;
};

///���۲���
struct CFocusFtdcPricingParamField
{
	///��Ȩϵ��
	TFocusFtdcInstrumentIDType	OptionSeriesId;
	///һ���۸�
	TFocusFtdcPriceTypeType	PriceLevel1;
	///�����۸�
	TFocusFtdcPriceTypeType	PriceLevel2;
	///�����۸�
	TFocusFtdcPriceTypeType	PriceLevel3;
	///��������
	TFocusFtdcDateTypeType	CalcDayType;
	///��������
	TFocusFtdcVolumeType	YearTotalDay;
	///��ʱ��ʽ
	TFocusFtdcTimingPatternType	CalcTimeType;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingEngine;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///�����ʾ���
	TFocusFtdcToleranceType	VolTolerance;
};

///��Ȩ���۲�����
struct CFocusFtdcOptionTheoryVolField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///���۲�����
	TFocusFtdcVolatilityType	TheoryVol;
};

///���ۻ�������
struct CFocusFtdcBasePricingParamField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ŀ��
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///��ļ۸�
	TFocusFtdcPriceType	UnderlyingPrice;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///������
	TFocusFtdcDateType	TradingDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///������
	TFocusFtdcVolatilityType	Vol;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingModel;
	///��Ȩ��ֵ
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

///˫�ϰ���Ȩ���۲���
struct CFocusFtdcDoubleBarrierPricingParamField
{
	///��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID;
	///����Ŀ��
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType;
	///��ļ۸�
	TFocusFtdcPriceType	UnderlyingPrice;
	///ִ�м�
	TFocusFtdcPriceType	StrikePrice;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///ʣ������
	TFocusFtdcTimeValueType	RemainDay;
	///������
	TFocusFtdcDateType	TradingDate;
	///������
	TFocusFtdcDateType	ExpireDate;
	///������
	TFocusFtdcVolatilityType	Vol;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingModel;
	///��Ȩ��ֵ
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
	///�ϰ�����
	TFocusFtdcBarrierTypeType	BarrierType;
	///�ϰ�����ֵ
	TFocusFtdcRatioType	LowerBarrierRate;
	///�ϰ�����ֵ
	TFocusFtdcRatioType	UpperBarrierRate;
};

///��Ȩ��϶��۲���
struct CFocusFtdcCombinationParamField
{
	///����Ŀ��
	TFocusFtdcCalculateTypeType	CalculateTarget;
	///��Ȩ��ʽ
	TFocusFtdcExerciseTypeType	ExerciseType;
	///��ļ۸�
	TFocusFtdcPriceType	UnderlyingPrice;
	///�޷�������
	TFocusFtdcRatioType	RiskFreeRate;
	///��Ϣ��
	TFocusFtdcRatioType	Dividend;
	///������
	TFocusFtdcDateType	TradingDate;
	///����ģ��
	TFocusFtdcPricingMethodType	PricingModel;
	///��Ȩ��ϵļ۸�
	TFocusFtdcPriceType	CombinationPrice;
	///��1��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID_Leg1;
	///��1��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType_Leg1;
	///��1��������
	TFocusFtdcDirectionType	Direction_Leg1;
	///��1ִ�м�
	TFocusFtdcPriceType	StrikePrice_Leg1;
	///��1������
	TFocusFtdcDateType	ExpireDate_Leg1;
	///��1������
	TFocusFtdcVolatilityType	Vol_Leg1;
	///��1��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice_Leg1;
	///��1Delta
	TFocusFtdcGreekValueType	Delta_Leg1;
	///��1Gamma
	TFocusFtdcGreekValueType	Gamma_Leg1;
	///��1Vega
	TFocusFtdcGreekValueType	Vega_Leg1;
	///��1Theta
	TFocusFtdcGreekValueType	Theta_Leg1;
	///��1Rho
	TFocusFtdcGreekValueType	Rho_Leg1;
	///��1Vanna
	TFocusFtdcGreekValueType	Vanna_Leg1;
	///��1Valga
	TFocusFtdcGreekValueType	Valga_Leg1;
	///��2��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID_Leg2;
	///��2��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType_Leg2;
	///��2��������
	TFocusFtdcDirectionType	Direction_Leg2;
	///��2ִ�м�
	TFocusFtdcPriceType	StrikePrice_Leg2;
	///��2������
	TFocusFtdcDateType	ExpireDate_Leg2;
	///��2������
	TFocusFtdcVolatilityType	Vol_Leg2;
	///��2��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice_Leg2;
	///��2Delta
	TFocusFtdcGreekValueType	Delta_Leg2;
	///Gamma
	TFocusFtdcGreekValueType	Gamma_Leg2;
	///��2Vega
	TFocusFtdcGreekValueType	Vega_Leg2;
	///��2Theta
	TFocusFtdcGreekValueType	Theta_Leg2;
	///��2Rho
	TFocusFtdcGreekValueType	Rho_Leg2;
	///��2Vanna
	TFocusFtdcGreekValueType	Vanna_Leg2;
	///��2Valga
	TFocusFtdcGreekValueType	Valga_Leg2;
	///��3��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID_Leg3;
	///��3��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType_Leg3;
	///��3��������
	TFocusFtdcDirectionType	Direction_Leg3;
	///��3ִ�м�
	TFocusFtdcPriceType	StrikePrice_Leg3;
	///��3������
	TFocusFtdcDateType	ExpireDate_Leg3;
	///��3������
	TFocusFtdcVolatilityType	Vol_Leg3;
	///��3��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice_Leg3;
	///��3Delta
	TFocusFtdcGreekValueType	Delta_Leg3;
	///��3Gamma
	TFocusFtdcGreekValueType	Gamma_Leg3;
	///��3Vega
	TFocusFtdcGreekValueType	Vega_Leg3;
	///��3Theta
	TFocusFtdcGreekValueType	Theta_Leg3;
	///��3Rho
	TFocusFtdcGreekValueType	Rho_Leg3;
	///��3Vanna
	TFocusFtdcGreekValueType	Vanna_Leg3;
	///��3Valga
	TFocusFtdcGreekValueType	Valga_Leg3;
	///��4��Լ����
	TFocusFtdcInstrumentIDType	InstrumentID_Leg4;
	///��4��Ȩ����
	TFocusFtdcOptionsTypeType	OptionsType_Leg4;
	///��4��������
	TFocusFtdcDirectionType	Direction_Leg4;
	///��4ִ�м�
	TFocusFtdcPriceType	StrikePrice_Leg4;
	///��4������
	TFocusFtdcDateType	ExpireDate_Leg4;
	///��4������
	TFocusFtdcVolatilityType	Vol_Leg4;
	///��4��Ȩ��ֵ
	TFocusFtdcPriceType	OptionPrice_Leg4;
	///��4Delta
	TFocusFtdcGreekValueType	Delta;
	///Gamma
	TFocusFtdcGreekValueType	Gamma_Leg4;
	///��4Vega
	TFocusFtdcGreekValueType	Vega_Leg4;
	///��4Theta
	TFocusFtdcGreekValueType	Theta_Leg4;
	///��4Rho
	TFocusFtdcGreekValueType	Rho_Leg4;
	///��4Vanna
	TFocusFtdcGreekValueType	Vanna_Leg4;
	///��4Valga
	TFocusFtdcGreekValueType	Valga_Leg4;
};



#endif
