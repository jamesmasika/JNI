/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file QdamFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Qdam_FTDCSTRUCT_H)
#define Qdam_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QdamFtdcUserApiDataType.h"

///��Ӧ��Ϣ
struct CQdamFtdcRspInfoField
{
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
};

///ϵͳ�û���¼����
struct CQdamFtdcReqUserLoginField
{
	///������
	TQdamFtdcDateType	TradingDay;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����
	TQdamFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdamFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TQdamFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TQdamFtdcIPAddressType	ClientIPAddress;
	///��Ȩ����
	TQdamFtdcAuthCodeType	AuthCode;
};

///ϵͳ�û���¼Ӧ��
struct CQdamFtdcRspUserLoginField
{
	///������
	TQdamFtdcDateType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TQdamFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TQdamFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TQdamFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQdamFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQdamFtdcSequenceNoType	UserFlowSize;
	///��¼������Ϣ
	TQdamFtdcLoginInfoType	LoginInfo;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
};

///�û��ǳ�����
struct CQdamFtdcReqUserLogoutField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
};

///�û��ǳ�����
struct CQdamFtdcRspUserLogoutField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
};

///ǿ���û��˳�
struct CQdamFtdcForceUserExitField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
};

///�û������޸�
struct CQdamFtdcUserPasswordUpdateField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///������
	TQdamFtdcPasswordType	OldPassword;
	///������
	TQdamFtdcPasswordType	NewPassword;
};

///���뱨��
struct CQdamFtdcInputOrderField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
};

///��������
struct CQdamFtdcOrderActionField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TQdamFtdcActionFlagType	ActionFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///�����仯
	TQdamFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
};

///�ڴ����
struct CQdamFtdcMemDBField
{
	///�ڴ����
	TQdamFtdcMemTableNameType	MemTableName;
};

///Ͷ�����ʽ��ʻ����������
struct CQdamFtdcReqAccountDepositField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�û�����
	TQdamFtdcUserIDType	UserID;
};

///Ͷ�����ʽ��ʻ������Ӧ��
struct CQdamFtdcRspAccountDepositField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///�û�����
	TQdamFtdcUserIDType	UserID;
};

///ʵʱ�ϳ�
struct CQdamFtdcTBCommandField
{
	///DB�������
	TQdamFtdcCommandNoType	CommandNo;
	///��������
	TQdamFtdcDateType	CommandDate;
	///����ʱ��
	TQdamFtdcTimeType	CommandTime;
	///DB��������
	TQdamFtdcCommandTypeType	CommandType;
	///�ֶ���
	TQdamFtdcFieldNameType	FieldName;
	///�ֶ�����
	TQdamFtdcFieldContentType	FieldContent;
};

///�������
struct CQdamFtdcInvestorAccountDepositResField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///�û�����
	TQdamFtdcUserIDType	UserID;
};

///��Լ״̬
struct CQdamFtdcInstrumentStatusField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdamFtdcProductIDType	ProductID;
	///Ʒ������
	TQdamFtdcProductNameType	ProductName;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdamFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdamFtdcYearType	DeliveryYear;
	///������
	TQdamFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdamFtdcPriceTickType	PriceTick;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdamFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdamFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdamFtdcDateType	CreateDate;
	///������
	TQdamFtdcDateType	OpenDate;
	///������
	TQdamFtdcDateType	ExpireDate;
	///��ʼ������
	TQdamFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdamFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdamFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdamFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdamFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdamFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdamFtdcOptionsTypeType	OptionsType;
	///����
	TQdamFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TQdamFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TQdamFtdcMarginCombTypeType	MarginCombType;
};

///����ģʽ��������
struct CQdamFtdcAdviceRunModeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�Զ������ֶ�
	TQdamFtdcAdviceRunModeType	RunMode;
};

///�����������
struct CQdamFtdcMarketDataBaseField
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
};

///���龲̬����
struct CQdamFtdcMarketDataStaticField
{
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CQdamFtdcMarketDataLastMatchField
{
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CQdamFtdcMarketDataBestPriceField
{
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
};

///�����������������
struct CQdamFtdcMarketDataBid23Field
{
	///����۶�
	TQdamFtdcPriceType	BidPrice2;
	///��������
	TQdamFtdcVolumeType	BidVolume2;
	///�������
	TQdamFtdcPriceType	BidPrice3;
	///��������
	TQdamFtdcVolumeType	BidVolume3;
};

///������������������
struct CQdamFtdcMarketDataAsk23Field
{
	///�����۶�
	TQdamFtdcPriceType	AskPrice2;
	///��������
	TQdamFtdcVolumeType	AskVolume2;
	///��������
	TQdamFtdcPriceType	AskPrice3;
	///��������
	TQdamFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CQdamFtdcMarketDataBid45Field
{
	///�������
	TQdamFtdcPriceType	BidPrice4;
	///��������
	TQdamFtdcVolumeType	BidVolume4;
	///�������
	TQdamFtdcPriceType	BidPrice5;
	///��������
	TQdamFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CQdamFtdcMarketDataAsk45Field
{
	///��������
	TQdamFtdcPriceType	AskPrice4;
	///��������
	TQdamFtdcVolumeType	AskVolume4;
	///��������
	TQdamFtdcPriceType	AskPrice5;
	///��������
	TQdamFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CQdamFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
};

///�������
struct CQdamFtdcDepthMarketDataField
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
	///����۶�
	TQdamFtdcPriceType	BidPrice2;
	///��������
	TQdamFtdcVolumeType	BidVolume2;
	///�������
	TQdamFtdcPriceType	BidPrice3;
	///��������
	TQdamFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdamFtdcPriceType	AskPrice2;
	///��������
	TQdamFtdcVolumeType	AskVolume2;
	///��������
	TQdamFtdcPriceType	AskPrice3;
	///��������
	TQdamFtdcVolumeType	AskVolume3;
	///�������
	TQdamFtdcPriceType	BidPrice4;
	///��������
	TQdamFtdcVolumeType	BidVolume4;
	///�������
	TQdamFtdcPriceType	BidPrice5;
	///��������
	TQdamFtdcVolumeType	BidVolume5;
	///��������
	TQdamFtdcPriceType	AskPrice4;
	///��������
	TQdamFtdcVolumeType	AskVolume4;
	///��������
	TQdamFtdcPriceType	AskPrice5;
	///��������
	TQdamFtdcVolumeType	AskVolume5;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///����������
	TQdamFtdcVolumeType	VolumeAskLot;
	///����������
	TQdamFtdcVolumeType	VolumeBidLot;
};

///���ĺ�Լ�������Ϣ
struct CQdamFtdcSpecificInstrumentField
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///Ͷ����Ȩ��
struct CQdamFtdcInvestorRightField
{
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TQdamFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TQdamFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TQdamFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TQdamFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TQdamFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TQdamFtdcDistributeTypeType	DistributeType;
};

///����������
struct CQdamFtdcMarketDataExchangeIDField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
};

///�����ڴ������ѯ
struct CQdamFtdcShmDepthMarketDataField
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///���ĺ�
	TQdamFtdcTopicIDType	TopicID;
};

///TOPIC��ѯ
struct CQdamFtdcTopicSearchField
{
	///���ĺ�
	TQdamFtdcTopicIDType	TopicID;
};

///�ּ�����
struct CQdamFtdcMBLMarketDataField
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///�۸�
	TQdamFtdcPriceType	Price;
	///����
	TQdamFtdcVolumeType	Volume;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
};

///������Լ��������
struct CQdamFtdcMarketDataCMBVolumeField
{
	///����������
	TQdamFtdcVolumeType	VolumeAskLot;
	///����������
	TQdamFtdcVolumeType	VolumeBidLot;
};

///��Լ״̬
struct CQdamFtdcQmdInstrumentStateField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
};

///�ɽ�
struct CQdamFtdcTradeField
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�ɽ��۸�
	TQdamFtdcPriceType	TradePrice;
	///�ɽ�����
	TQdamFtdcVolumeType	TradeVolume;
	///�ɽ�ʱ��
	TQdamFtdcTimeType	TradeTime;
	///�����Ա���
	TQdamFtdcParticipantIDType	ClearingPartID;
	///�ɽ����
	TQdamFtdcMoneyType	TradeAmnt;
	///��������
	TQdamFtdcTradeTypeType	TradeType;
};

///����
struct CQdamFtdcOrderField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
};

///����������
struct CQdamFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///������
	TQdamFtdcDateType	TradingDay;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TQdamFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TQdamFtdcSequenceNoType	EndSequenceNo;
};

///��Ϣ�ַ�
struct CQdamFtdcDisseminationField
{
	///����ϵ�к�
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQdamFtdcSequenceNoType	SequenceNo;
};

///������Ϣ֪ͨ
struct CQdamFtdcMessageNotifyField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ۼӴ���
	TQdamFtdcTotalNumsType	Nums;
	///���漶��
	TQdamFtdcErrorLevelType	WarnLevel;
	///������
	TQdamFtdcErrorIDType	WarnID;
	///������Ϣ
	TQdamFtdcLargeErrorMsgType	WarnMsg;
	///����ʱ��
	TQdamFtdcTimeType	WarnTime;
};

///������ָ��֪ͨ
struct CQdamFtdcAdviceOrderField
{
	///Ͷ���û�����
	TQdamFtdcUserIDType	InvestorAdvicer;
	///Ͷ�ʾ���
	TQdamFtdcUserIDType	InvestorManager;
	///����Ա
	TQdamFtdcUserIDType	UserTrader;
	///��������
	TQdamFtdcVolumeType	VolumeFrozen;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
};

///������ѯ
struct CQdamFtdcQryOrderField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///�ɽ���ѯ
struct CQdamFtdcQryTradeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯ
struct CQdamFtdcQryInstrumentField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯӦ��
struct CQdamFtdcRspInstrumentField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdamFtdcProductIDType	ProductID;
	///Ʒ������
	TQdamFtdcProductNameType	ProductName;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdamFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdamFtdcYearType	DeliveryYear;
	///������
	TQdamFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdamFtdcPriceTickType	PriceTick;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdamFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdamFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdamFtdcDateType	CreateDate;
	///������
	TQdamFtdcDateType	OpenDate;
	///������
	TQdamFtdcDateType	ExpireDate;
	///��ʼ������
	TQdamFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdamFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdamFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdamFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdamFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdamFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdamFtdcOptionsTypeType	OptionsType;
	///����
	TQdamFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TQdamFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TQdamFtdcMarginCombTypeType	MarginCombType;
};

///Ͷ�����ʽ��ѯ
struct CQdamFtdcQryInvestorAccountField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
};

///Ͷ�����ʽ�Ӧ��
struct CQdamFtdcRspInvestorAccountField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ϴν���׼����
	TQdamFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TQdamFtdcMoneyType	PreAvailable;
	///�����
	TQdamFtdcMoneyType	Deposit;
	///������
	TQdamFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TQdamFtdcMoneyType	Premium;
	///������
	TQdamFtdcMoneyType	Fee;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///����������
	TQdamFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TQdamFtdcMoneyType	DynamicRights;
	///���ն�
	TQdamFtdcRatioType	Risk;
	///��������
	TQdamFtdcMoneyType	OtherFee;
	///��Ѻ���
	TQdamFtdcMoneyType	Mortgage;
	///����
	TQdamFtdcCurrencyType	Currency;
};

///����Ͷ���߲�ѯ
struct CQdamFtdcQryUserInvestorField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
};

///����Ͷ����Ӧ��
struct CQdamFtdcRspUserInvestorField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///Ĭ���û�����
	TQdamFtdcUserIDType	NextUserID;
	///�Ƿ���µ�
	TQdamFtdcAdviceUserOrderModeType	OrderMode;
	///�Զ������ֶ�
	TQdamFtdcAdviceRunModeType	RunMode;
	///���������ߴ����ʾ��
	TQdamFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
};

///Ͷ���߹�ϵ��ѯ
struct CQdamFtdcQryInvestorRelationField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
};

///Ͷ���߹�ϵӦ��
struct CQdamFtdcRspInvestorRelationField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Ͷ���߱��
	TQdamFtdcInvestorIDType	ParentInvestorID;
};

///��������ѯ����
struct CQdamFtdcQryExchangeField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
};

///��������ѯӦ��
struct CQdamFtdcRspExchangeField
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///����������
	TQdamFtdcExchangeNameType	ExchangeName;
};

///Ͷ���ֲֲ߳�ѯ����
struct CQdamFtdcQryInvestorPositionField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲֲ߳�ѯӦ��
struct CQdamFtdcRspInvestorPositionField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TQdamFtdcVolumeType	Position;
	///�ֲֳܳɱ�
	TQdamFtdcPriceType	PositionCost;
	///��ʼ��ֲ���(���ղ���)
	TQdamFtdcVolumeType	YdPosition;
	///��ʼ���ճֲֳɱ�(���ղ���)
	TQdamFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenClosing;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TQdamFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TQdamFtdcOrderLocalIDType	LastOrderLocalID;
	///�ֲֿܳ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	PositionClose;
	///��ֲֿ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	YdPositionClose;
	///��ֲ�ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	YdFrozenClosing;
	///���տ�������(����������)
	TQdamFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TQdamFtdcVolumeType	CloseVolume;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
};

///�û���ѯ
struct CQdamFtdcQryUserField
{
	///�����û�����
	TQdamFtdcUserIDType	StartUserID;
	///�����û�����
	TQdamFtdcUserIDType	EndUserID;
};

///�û�
struct CQdamFtdcRspUserField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û���¼����
	TQdamFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TQdamFtdcIsActiveType	IsActive;
	///�û�����
	TQdamFtdcUserNameType	UserName;
	///�û�����
	TQdamFtdcUserTypeType	UserType;
	///Ӫҵ��
	TQdamFtdcDepartmentType	Department;
	///��Ȩ���ܼ�
	TQdamFtdcGrantFuncSetType	GrantFuncSet;
	///���������
	TQdamFtdcNumberType	MaxOnline;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�Ƿ������Ӳ�Ʒ
	TQdamFtdcBoolType	CheckProductInfo;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�Ƿ���IP��MAC
	TQdamFtdcBoolType	CheckIPMacAddr;
	///�����½��������
	TQdamFtdcNumberType	LoginErrorLimit;
	///Ŀǰ�����½����
	TQdamFtdcNumberType	LoginErrorCount;
};

///Ͷ�����������ʲ�ѯ
struct CQdamFtdcQryInvestorFeeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///Ͷ������������
struct CQdamFtdcRspInvestorFeeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeAmt;
};

///Ͷ���߱�֤���ʲ�ѯ
struct CQdamFtdcQryInvestorMarginField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
};

///Ͷ���߱�֤����
struct CQdamFtdcRspInvestorMarginField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��ͷռ�ñ�֤�𰴱���
	TQdamFtdcRatioType	LongMarginRate;
	///��ͷ��֤������
	TQdamFtdcRatioType	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	TQdamFtdcRatioType	ShortMarginRate;
	///��ͷ��֤������
	TQdamFtdcRatioType	ShortMarginAmt;
};

///Ͷ���߲�ѯ
struct CQdamFtdcQryInvestorField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
};

///Ͷ����Ӧ��
struct CQdamFtdcRspInvestorField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	InvestorName;
	///Ͷ��������
	TQdamFtdcInvestorTypeType	InvestorType;
	///Ͷ��������
	TQdamFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	GroupName;
	///����
	TQdamFtdcAliasType	Alias;
	///��������
	TQdamFtdcLinkTypeType	LinkType;
	///�ʽ��˻����
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///��¼����
	TQdamFtdcNumberType	LoginStatus;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TQdamFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TQdamFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TQdamFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TQdamFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TQdamFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TQdamFtdcDistributeTypeType	DistributeType;
};

///�˺ŷ���״����ѯ
struct CQdamFtdcQryAccountRiskField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
};

///�˺ŷ���״��Ӧ��
struct CQdamFtdcRspAccountRiskField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///����׼����
	TQdamFtdcMoneyType	SetBalance;
	///���ֺ���
	TQdamFtdcMoneyType	OpenAvailable;
	///ƽ�ֺ���
	TQdamFtdcMoneyType	OffsetAvailable;
	///�˻�״̬
	TQdamFtdcAccountStatusType	AccountStatus;
	///��̬Ȩ��
	TQdamFtdcMoneyType	DynamicRights;
	///�˻�Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
};

///�����û��Ự��ѯ
struct CQdamFtdcQryUserSessionField
{
	///�����û�����
	TQdamFtdcUserIDType	StartUserID;
	///�����û�����
	TQdamFtdcUserIDType	EndUserID;
};

///�����û��ỰӦ��
struct CQdamFtdcRspUserSessionField
{
	///���͹�˾����
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///�����û�����
	TQdamFtdcUserTypeType	UserType;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///��¼ʱ��
	TQdamFtdcTimeType	LoginTime;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�û��˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdamFtdcProtocolInfoType	ProtocolInfo;
};

///�����ѯ
struct CQdamFtdcQryMarketDataField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
};

///����Ӧ��
struct CQdamFtdcRspMarketDataField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
};

///��Ʒ��ѯ
struct CQdamFtdcQryProductField
{
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
};

///��ƷӦ��
struct CQdamFtdcRspProductField
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
	///Ͷ���߷��еĲ�Ʒ����
	TQdamFtdcProductNameType	ProductName;
	///����
	TQdamFtdcCurrencyType	Currency;
	///����
	TQdamFtdcRatioType	ExchangeRate;
};

///�ڲ�������Ϣ
struct CQdamFtdcPingPongField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcSequenceNoType	SequenceNo;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
};

///���ɽ���������ѯ����
struct CQdamFtdcQryMaxVolumeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
};

///���ɽ���������ѯӦ��
struct CQdamFtdcRspMaxVolumeField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
};

///����������Ա��ѯ����
struct CQdamFtdcQryAdviceTraderField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��¼���͹�˾���
	TQdamFtdcBrokerIDType	LogBrokerID;
	///��¼�û�����
	TQdamFtdcUserIDType	LogUserID;
};

///����������Ա��ѯӦ��
struct CQdamFtdcRspAdviceTraderField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�����û�����
	TQdamFtdcUserIDType	RelationUserID;
};

///��ϳֲ���ϸ��ѯ����
struct CQdamFtdcQryCmbPositionDetailField
{
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
};

///��ϳֲ���ϸ��ѯӦ��
struct CQdamFtdcRspCmbPositionDetailField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���Ⱥ�Լ����
	TQdamFtdcInstrumentIDType	CmbInstrumentID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�ֲ���
	TQdamFtdcVolumeType	Position;
	///���ȱ��
	TQdamFtdcNumberType	LegQty;
	///��������
	TQdamFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯ����
struct CQdamFtdcQrySettlementInfoField
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��������
	TQdamFtdcTradingDayType	TradingDay;
};

///Ͷ���߽�������ѯӦ��
struct CQdamFtdcRspSettlementInfoField
{
	///��������
	TQdamFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TQdamFtdcContentType	Content;
};



#endif
