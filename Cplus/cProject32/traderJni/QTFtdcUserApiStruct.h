/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file QTFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(QT_FTDCSTRUCT_H)
#define QT_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QTFtdcUserApiDataType.h"

///��Ϣ�ַ�
struct CQTFtdcDisseminationField
{
	///����ϵ�к�
	TQTFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQTFtdcSequenceNoType	SequenceNo;
};

///��Ӧ��Ϣ
struct CQTFtdcRspInfoField
{
	///�������
	TQTFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQTFtdcErrorMsgType	ErrorMsg;
};

///ͨѶ�׶�
struct CQTFtdcCommPhaseField
{
	///������
	TQTFtdcDateType	TradingDay;
	///ͨѶʱ�κ�
	TQTFtdcCommPhaseNoType	CommPhaseNo;
};

///������������
struct CQTFtdcExchangeTradingDayField
{
	///������
	TQTFtdcDateType	TradingDay;
	///����������
	TQTFtdcExchangeIDType	ExchangeID;
};

///����Ự
struct CQTFtdcSettlementSessionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
};

///��ǰʱ��
struct CQTFtdcCurrentTimeField
{
	///��ǰ����
	TQTFtdcDateType	CurrDate;
	///��ǰʱ��
	TQTFtdcTimeType	CurrTime;
	///��ǰʱ�䣨���룩
	TQTFtdcMillisecType	CurrMillisec;
};

///�û���¼����
struct CQTFtdcReqUserLoginField
{
	///������
	TQTFtdcDateType	TradingDay;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///����
	TQTFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQTFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQTFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQTFtdcProtocolInfoType	ProtocolInfo;
	///�������Ĵ���
	TQTFtdcDataCenterIDType	DataCenterID;
};

///�û���¼Ӧ��
struct CQTFtdcRspUserLoginField
{
	///������
	TQTFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TQTFtdcTimeType	LoginTime;
	///��󱾵ر�����
	TQTFtdcOrderLocalIDType	MaxOrderLocalID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///����ϵͳ����
	TQTFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQTFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQTFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQTFtdcSequenceNoType	UserFlowSize;
};

///�û��ǳ�����
struct CQTFtdcReqUserLogoutField
{
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
};

///�û��ǳ�Ӧ��
struct CQTFtdcRspUserLogoutField
{
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
};

///���뱨��
struct CQTFtdcInputOrderField
{
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�����۸�����
	TQTFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQTFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TQTFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TQTFtdcPriceType	LimitPrice;
	///����
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TQTFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQTFtdcDateType	GTDDate;
	///�ɽ�������
	TQTFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQTFtdcVolumeType	MinVolume;
	///��������
	TQTFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TQTFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQTFtdcForceCloseReasonType	ForceCloseReason;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///�Զ������־
	TQTFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///��������
struct CQTFtdcOrderActionField
{
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///����������־
	TQTFtdcActionFlagType	ActionFlag;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�۸�
	TQTFtdcPriceType	LimitPrice;
	///�����仯
	TQTFtdcVolumeType	VolumeChange;
	///�������ر��
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///OTC����
struct CQTFtdcOTCOrderField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///OTC�������
	TQTFtdcOTCOrderSysIDType	OTCOrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��������
	TQTFtdcDirectionType	Direction;
	///��ƽ��־
	TQTFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQTFtdcPriceType	Price;
	///����
	TQTFtdcVolumeType	Volume;
	///���ַ���Ա����
	TQTFtdcParticipantIDType	OtherParticipantID;
	///���ַ��ͻ�����
	TQTFtdcClientIDType	OtherClientID;
	///���ַ������û�����
	TQTFtdcUserIDType	OtherUserID;
	///���ַ���ƽ��־
	TQTFtdcOffsetFlagType	OtherOffsetFlag;
	///���ַ��ױ���־
	TQTFtdcHedgeFlagType	OtherHedgeFlag;
	///����OTC�������
	TQTFtdcOrderLocalIDType	OTCOrderLocalID;
	///OTC����״̬
	TQTFtdcOTCOrderStatusType	OTCOrderStatus;
	///����ʱ��
	TQTFtdcTimeType	InsertTime;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///���ַ������Ա���
	TQTFtdcParticipantIDType	OtherClearingPartID;
};

///���뱨��
struct CQTFtdcInputQuoteField
{
	///���۱��
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��������
	TQTFtdcVolumeType	BidVolume;
	///��������
	TQTFtdcVolumeType	AskVolume;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///���ر��۱��
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	TQTFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	TQTFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	TQTFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	TQTFtdcPriceType	AskPrice;
};

///���۲���
struct CQTFtdcQuoteActionField
{
	///���۱��
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///���ر��۱��
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///����������־
	TQTFtdcActionFlagType	ActionFlag;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�������ر��
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///����ִ������
struct CQTFtdcInputExecOrderField
{
	///��Լ���
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///����ִ��������
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///����
	TQTFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///ִ���������
struct CQTFtdcExecOrderActionField
{
	///ִ��������
	TQTFtdcExecOrderSysIDType	ExecOrderSysID;
	///����ִ��������
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������־
	TQTFtdcActionFlagType	ActionFlag;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�������ر��
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///�û���¼�˳�
struct CQTFtdcUserLogoutField
{
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
};

///�û������޸�
struct CQTFtdcUserPasswordUpdateField
{
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///������
	TQTFtdcPasswordType	OldPassword;
	///������
	TQTFtdcPasswordType	NewPassword;
};

///����Ǳ���ϱ���
struct CQTFtdcInputCombOrderField
{
	///��ϱ������
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�۸�
	TQTFtdcPriceType	LimitPrice;
	///����
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///���ر������
	TQTFtdcOrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///��Լ����1
	TQTFtdcInstrumentIDType	InstrumentID1;
	///��������1
	TQTFtdcDirectionType	Direction1;
	///���ȳ���1
	TQTFtdcLegMultipleType	LegMultiple1;
	///��ƽ��־1
	TQTFtdcOffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	TQTFtdcHedgeFlagType	HedgeFlag1;
	///��Լ����2
	TQTFtdcInstrumentIDType	InstrumentID2;
	///��������2
	TQTFtdcDirectionType	Direction2;
	///���ȳ���2
	TQTFtdcLegMultipleType	LegMultiple2;
	///��ƽ��־2
	TQTFtdcOffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	TQTFtdcHedgeFlagType	HedgeFlag2;
	///��Լ����3
	TQTFtdcInstrumentIDType	InstrumentID3;
	///��������3
	TQTFtdcDirectionType	Direction3;
	///���ȳ���3
	TQTFtdcLegMultipleType	LegMultiple3;
	///��ƽ��־3
	TQTFtdcOffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	TQTFtdcHedgeFlagType	HedgeFlag3;
	///��Լ����4
	TQTFtdcInstrumentIDType	InstrumentID4;
	///��������4
	TQTFtdcDirectionType	Direction4;
	///���ȳ���4
	TQTFtdcLegMultipleType	LegMultiple4;
	///��ƽ��־4
	TQTFtdcOffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	TQTFtdcHedgeFlagType	HedgeFlag4;
};

///ǿ���û��˳�
struct CQTFtdcForceUserExitField
{
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
};

///��Ա�ʽ��ʻ����
struct CQTFtdcAccountDepositField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	TQTFtdcAccountIDType	AccountID;
	///�����
	TQTFtdcMoneyType	Deposit;
	///�����ֻ�нⶳ�����ʹ��
	TQTFtdcMoneyType	Withdraw;
	///������
	TQTFtdcMoneyType	Fee;
	///�ʽ��������
	TQTFtdcAccountActionTypeType	ActionType;
	///��ע
	TQTFtdcComeFromType	Comments;
	///ҵ��ָ��ı�
	TQTFtdcTableNameType	BusinessTable;
	///ҵ���Ψһ����
	TQTFtdcOrderSysIDType	BusinessKey;
};

///������ѯ
struct CQTFtdcQryOrderField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼʱ��
	TQTFtdcTimeType	TimeStart;
	///����ʱ��
	TQTFtdcTimeType	TimeEnd;
};

///���۲�ѯ
struct CQTFtdcQryQuoteField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///���۱��
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
};

///�ɽ���ѯ
struct CQTFtdcQryTradeField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
	///�ɽ����
	TQTFtdcTradeIDType	TradeID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼʱ��
	TQTFtdcTimeType	TimeStart;
	///����ʱ��
	TQTFtdcTimeType	TimeEnd;
};

///�����ѯ
struct CQTFtdcQryMarketDataField
{
	///��Ʒ����
	TQTFtdcProductIDType	ProductID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///�ͻ���ѯ
struct CQTFtdcQryClientField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TQTFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TQTFtdcClientIDType	ClientIDEnd;
};

///��Ա�ֲֲ�ѯ
struct CQTFtdcQryPartPositionField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///�ͻ��ֲֲ�ѯ
struct CQTFtdcQryClientPositionField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TQTFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TQTFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
	///�ͻ�����
	TQTFtdcClientTypeType	ClientType;
};

///�����ʽ��ѯ
struct CQTFtdcQryPartAccountField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�ʽ��ʺ�
	TQTFtdcAccountIDType	AccountID;
};

///��Լ��ѯ
struct CQTFtdcQryInstrumentField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	TQTFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ����
	TQTFtdcProductIDType	ProductID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///��Լ״̬��ѯ
struct CQTFtdcQryInstrumentStatusField
{
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///������״̬��ѯ
struct CQTFtdcQrySGDataSyncStatusField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///�û����߲�ѯ
struct CQTFtdcQryUserSessionField
{
	///��ʼ�����û�����
	TQTFtdcUserIDType	UserIDStart;
	///���������û�����
	TQTFtdcUserIDType	UserIDEnd;
};

///�û���ѯ
struct CQTFtdcQryUserField
{
	///��ʼ�����û�����
	TQTFtdcUserIDType	UserIDStart;
	///���������û�����
	TQTFtdcUserIDType	UserIDEnd;
};

///�����ѯ
struct CQTFtdcQryBulletinField
{
	///������
	TQTFtdcDateType	TradingDay;
	///�г�����
	TQTFtdcMarketIDType	MarketID;
	///������
	TQTFtdcBulletinIDType	BulletinID;
	///��������
	TQTFtdcNewsTypeType	NewsType;
	///�����̶�
	TQTFtdcNewsUrgencyType	NewsUrgency;
};

///��Ա��ѯ
struct CQTFtdcQryParticipantField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
};

///��ֵ��Ȳ�ѯ
struct CQTFtdcQryHedgeVolumeField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TQTFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TQTFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///��Լ��λ��ѯ
struct CQTFtdcQryMBLMarketDataField
{
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
	///��������
	TQTFtdcDirectionType	Direction;
};

///�����޶��ѯ
struct CQTFtdcQryCreditLimitField
{
	///���׻�Ա���
	TQTFtdcParticipantIDType	ParticipantID;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
};

///�Ǳ���ϱ�����ѯ
struct CQTFtdcQryCombOrderField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ϱ������
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
};

///��Ա�ʽ�Ӧ��
struct CQTFtdcRspPartAccountField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TQTFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TQTFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TQTFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TQTFtdcMoneyType	Premium;
	///�����
	TQTFtdcMoneyType	Deposit;
	///������
	TQTFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TQTFtdcMoneyType	Balance;
	///�����ʽ�
	TQTFtdcMoneyType	Available;
	///�ʽ��ʺ�
	TQTFtdcAccountIDType	AccountID;
	///����ı�֤��
	TQTFtdcMoneyType	FrozenMargin;
	///�����Ȩ����
	TQTFtdcMoneyType	FrozenPremium;
	///�ֻ��ʽ���֧
	TQTFtdcMoneyType	SpotMoney;
	///������ֻ��ʽ�
	TQTFtdcMoneyType	FrozenSpotMoney;
	///����������֧��
	TQTFtdcFeeType	Fee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenFee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenIPOMoney;
	///���¶����ʽ�
	TQTFtdcFeeType	FrozenMoney;
	///��ȡ�ʽ�
	TQTFtdcMoneyType	Useable;
	///���ɽ��ʽ�
	TQTFtdcMoneyType	SellMoney;
	///����׼����
	TQTFtdcMoneyType	BaseReserve;
};

///��Ա�ֲ�Ӧ��
struct CQTFtdcRspPartPositionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TQTFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TQTFtdcVolumeType	YdPosition;
	///���ճֲ�
	TQTFtdcVolumeType	Position;
	///��ͷ����
	TQTFtdcVolumeType	LongFrozen;
	///��ͷ����
	TQTFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TQTFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TQTFtdcVolumeType	YdShortFrozen;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TQTFtdcTradingRoleType	TradingRole;
};

///�ͻ��ֲ�Ӧ��
struct CQTFtdcRspClientPositionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TQTFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TQTFtdcVolumeType	YdPosition;
	///���ճֲ�
	TQTFtdcVolumeType	Position;
	///��ͷ����
	TQTFtdcVolumeType	LongFrozen;
	///��ͷ����
	TQTFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TQTFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TQTFtdcVolumeType	YdShortFrozen;
	///������ɽ���
	TQTFtdcVolumeType	BuyTradeVolume;
	///�������ɽ���
	TQTFtdcVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	TQTFtdcMoneyType	PositionCost;
	///���ճֲֳɱ�
	TQTFtdcMoneyType	YdPositionCost;
	///ռ�õı�֤��
	TQTFtdcMoneyType	UseMargin;
	///����ı�֤��
	TQTFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TQTFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQTFtdcMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	TQTFtdcMoneyType	FrozenPremium;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///������ֻ��ʽ�
	TQTFtdcMoneyType	FrozenSpotMoney;
	///�����������
	TQTFtdcMoneyType	FrozenFee;
	///���տ�ƽ����
	TQTFtdcVolumeType	AvailablePosition;
};

///��Լ��ѯӦ��
struct CQTFtdcRspInstrumentField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TQTFtdcProductIDType	ProductID;
	///��Ʒ�����
	TQTFtdcProductGroupIDType	ProductGroupID;
	///������Ʒ����
	TQTFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TQTFtdcProductClassType	ProductClass;
	///�ֲ�����
	TQTFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQTFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQTFtdcOptionsTypeType	OptionsType;
	///��Լ��������
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TQTFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQTFtdcInstrumentNameType	InstrumentName;
	///�������
	TQTFtdcYearType	DeliveryYear;
	///������
	TQTFtdcMonthType	DeliveryMonth;
	///��ǰ�·�
	TQTFtdcAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	TQTFtdcBoolType	IsTrading;
	///������
	TQTFtdcDateType	CreateDate;
	///������
	TQTFtdcDateType	OpenDate;
	///������
	TQTFtdcDateType	ExpireDate;
	///��ʼ������
	TQTFtdcDateType	StartDelivDate;
	///��󽻸���
	TQTFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQTFtdcPriceType	BasisPrice;
	///�м۵�����µ���
	TQTFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQTFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TQTFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQTFtdcVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	TQTFtdcPriceType	PriceTick;
	///��������Ȼ�˿���
	TQTFtdcMonthCountType	AllowDelivPersonOpen;
	///���ֱ�����С�µ��䶯����
	TQTFtdcVolumeType	OpenVolumeTick;
	///ƽ�ֱ�����С�µ��䶯����
	TQTFtdcVolumeType	CloseVolumeTick;
	///��Ϸ�ʽ
	TQTFtdcTradingModelType	TradingModel;
	///����֮����ƽ�ֵĽ�������
	TQTFtdcDurationType	OffsetDays;
};

///��Ϣ��ѯ
struct CQTFtdcQryInformationField
{
	///��ʼ��Ϣ����
	TQTFtdcInformationIDType	InformationIDStart;
	///������Ϣ����
	TQTFtdcInformationIDType	InformationIDEnd;
};

///��Ϣ��ѯ
struct CQTFtdcInformationField
{
	///��Ϣ���
	TQTFtdcInformationIDType	InformationID;
	///���к�
	TQTFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TQTFtdcContentType	Content;
	///���ĳ���
	TQTFtdcContentLengthType	ContentLength;
	///�Ƿ����
	TQTFtdcBoolType	IsAccomplished;
};

///�����޶�
struct CQTFtdcCreditLimitField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TQTFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TQTFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TQTFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TQTFtdcMoneyType	Premium;
	///�����
	TQTFtdcMoneyType	Deposit;
	///������
	TQTFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TQTFtdcMoneyType	Balance;
	///�����ʽ�
	TQTFtdcMoneyType	Available;
	///���׻�Ա���
	TQTFtdcParticipantIDType	ParticipantID;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///����ı�֤��
	TQTFtdcMoneyType	FrozenMargin;
	///�����Ȩ����
	TQTFtdcMoneyType	FrozenPremium;
	///�ֻ��ʽ���֧
	TQTFtdcMoneyType	SpotMoney;
	///������ֻ��ʽ�
	TQTFtdcMoneyType	FrozenSpotMoney;
	///����������֧��
	TQTFtdcFeeType	Fee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenFee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenIPOMoney;
	///���¶����ʽ�
	TQTFtdcFeeType	FrozenMoney;
};

///�ͻ���ѯӦ��
struct CQTFtdcRspClientField
{
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�ͻ�����
	TQTFtdcPartyNameType	ClientName;
	///֤������
	TQTFtdcIdCardTypeType	IdentifiedCardType;
	///ԭ֤������
	TQTFtdcIdentifiedCardNoV1Type	UseLess;
	///���׽�ɫ
	TQTFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TQTFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TQTFtdcBoolType	IsActive;
	///��Ա��
	TQTFtdcParticipantIDType	ParticipantID;
	///֤������
	TQTFtdcIdentifiedCardNoType	IdentifiedCardNo;
};

///����������
struct CQTFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TQTFtdcSequenceSeriesType	SequenceSeries;
	///������
	TQTFtdcDateType	TradingDay;
	///�������Ĵ���
	TQTFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TQTFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TQTFtdcSequenceNoType	EndSequenceNo;
};

///��Ա
struct CQTFtdcParticipantField
{
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TQTFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TQTFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TQTFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TQTFtdcBoolType	IsActive;
};

///�û�
struct CQTFtdcUserField
{
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�����û�����
	TQTFtdcUserTypeType	UserType;
	///����
	TQTFtdcPasswordType	Password;
	///����ԱȨ��
	TQTFtdcUserActiveType	IsActive;
};

///�ͻ�
struct CQTFtdcClientField
{
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�ͻ�����
	TQTFtdcPartyNameType	ClientName;
	///֤������
	TQTFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TQTFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	TQTFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TQTFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TQTFtdcBoolType	IsActive;
	///�ͻ���������
	TQTFtdcHedgeFlagType	HedgeFlag;
};

///�û��Ự
struct CQTFtdcUserSessionField
{
	///ǰ�ñ��
	TQTFtdcFrontIDType	FrontID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�����û�����
	TQTFtdcUserTypeType	UserType;
	///�Ự���
	TQTFtdcSessionIDType	SessionID;
	///��¼ʱ��
	TQTFtdcTimeType	LoginTime;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///IP��ַ
	TQTFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TQTFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQTFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQTFtdcProtocolInfoType	ProtocolInfo;
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
};

///��Ʒ��
struct CQTFtdcProductGroupField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	TQTFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ������
	TQTFtdcProductGroupNameType	ProductGroupName;
	///��Ʒ����
	TQTFtdcCommodityIDType	CommodityID;
};

///��Ʒ
struct CQTFtdcProductField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TQTFtdcProductIDType	ProductID;
	///��Ʒ�����
	TQTFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ����
	TQTFtdcProductNameType	ProductName;
	///��Ʒ����
	TQTFtdcProductClassType	ProductClass;
};

///��Լ
struct CQTFtdcInstrumentField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TQTFtdcProductIDType	ProductID;
	///��Ʒ�����
	TQTFtdcProductGroupIDType	ProductGroupID;
	///������Ʒ����
	TQTFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TQTFtdcProductClassType	ProductClass;
	///�ֲ�����
	TQTFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQTFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQTFtdcOptionsTypeType	OptionsType;
	///��Լ��������
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TQTFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQTFtdcInstrumentNameType	InstrumentName;
	///�������
	TQTFtdcYearType	DeliveryYear;
	///������
	TQTFtdcMonthType	DeliveryMonth;
	///��ǰ�·�
	TQTFtdcAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	TQTFtdcBoolType	IsTrading;
};

///��Ͻ��׺�Լ�ĵ���
struct CQTFtdcCombinationLegField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ϻ�Լ����
	TQTFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TQTFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TQTFtdcInstrumentIDType	LegInstrumentID;
	///��������
	TQTFtdcDirectionType	Direction;
	///���ȳ���
	TQTFtdcLegMultipleType	LegMultiple;
	///�Ƶ�����
	TQTFtdcImplyLevelType	ImplyLevel;
};

///�˻��ʽ���Ϣ
struct CQTFtdcAccountInfoField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TQTFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TQTFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TQTFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TQTFtdcMoneyType	Premium;
	///�����
	TQTFtdcMoneyType	Deposit;
	///������
	TQTFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TQTFtdcMoneyType	Balance;
	///�����ʽ�
	TQTFtdcMoneyType	Available;
	///��������
	TQTFtdcDateType	DateAccountOpen;
	///�ϴν��������
	TQTFtdcDateType	PreDate;
	///�Ͻ���ı��
	TQTFtdcSettlementIDType	PreSettlementID;
	///�ϴα�֤���ܶ�
	TQTFtdcMoneyType	PreMargin;
	///�ڻ���֤��
	TQTFtdcMoneyType	FuturesMargin;
	///��Ȩ��֤��
	TQTFtdcMoneyType	OptionsMargin;
	///�ֲ�ӯ��
	TQTFtdcMoneyType	PositionProfit;
	///����ӯ��
	TQTFtdcMoneyType	Profit;
	///��Ϣ����
	TQTFtdcMoneyType	Interest;
	///������
	TQTFtdcMoneyType	Fee;
	///����Ѻ���
	TQTFtdcMoneyType	TotalCollateral;
	///����Ѻ�ֵı�֤����
	TQTFtdcMoneyType	CollateralForMargin;
	///�ϴ��ʽ���Ϣ����
	TQTFtdcMoneyType	PreAccmulateInterest;
	///�ʽ���Ϣ����
	TQTFtdcMoneyType	AccumulateInterest;
	///��Ѻ�����ѻ���
	TQTFtdcMoneyType	AccumulateFee;
	///�����ʽ�
	TQTFtdcMoneyType	ForzenDeposit;
	///�ʻ�״̬
	TQTFtdcAccountStatusType	AccountStatus;
	///�ʽ��ʺ�
	TQTFtdcAccountIDType	AccountID;
};

///��Ա��Լ�ֲ�
struct CQTFtdcPartPositionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TQTFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TQTFtdcVolumeType	YdPosition;
	///���ճֲ�
	TQTFtdcVolumeType	Position;
	///��ͷ����
	TQTFtdcVolumeType	LongFrozen;
	///��ͷ����
	TQTFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TQTFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TQTFtdcVolumeType	YdShortFrozen;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TQTFtdcTradingRoleType	TradingRole;
};

///�ͻ���Լ�ֲ�
struct CQTFtdcClientPositionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TQTFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TQTFtdcVolumeType	YdPosition;
	///���ճֲ�
	TQTFtdcVolumeType	Position;
	///��ͷ����
	TQTFtdcVolumeType	LongFrozen;
	///��ͷ����
	TQTFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TQTFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TQTFtdcVolumeType	YdShortFrozen;
	///������ɽ���
	TQTFtdcVolumeType	BuyTradeVolume;
	///�������ɽ���
	TQTFtdcVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	TQTFtdcMoneyType	PositionCost;
	///���ճֲֳɱ�
	TQTFtdcMoneyType	YdPositionCost;
	///ռ�õı�֤��
	TQTFtdcMoneyType	UseMargin;
	///����ı�֤��
	TQTFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TQTFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQTFtdcMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	TQTFtdcMoneyType	FrozenPremium;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///������ֻ��ʽ�
	TQTFtdcMoneyType	FrozenSpotMoney;
	///�����������
	TQTFtdcMoneyType	FrozenFee;
	///���տ�ƽ����
	TQTFtdcVolumeType	AvailablePosition;
};

///��ֵ�����
struct CQTFtdcHedgeVolumeField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��ͷ��ֵ������������
	TQTFtdcVolumeType	LongVolumeOriginal;
	///��ͷ��ֵ������������
	TQTFtdcVolumeType	ShortVolumeOriginal;
	///��ͷ��ֵ���
	TQTFtdcVolumeType	LongVolume;
	///��ͷ��ֵ���
	TQTFtdcVolumeType	ShortVolume;
};

///�г�����
struct CQTFtdcMarketDataField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///���¼�
	TQTFtdcPriceType	LastPrice;
	///�����
	TQTFtdcPriceType	PreSettlementPrice;
	///������
	TQTFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///����
	TQTFtdcPriceType	OpenPrice;
	///��߼�
	TQTFtdcPriceType	HighestPrice;
	///��ͼ�
	TQTFtdcPriceType	LowestPrice;
	///����
	TQTFtdcVolumeType	Volume;
	///�ɽ����
	TQTFtdcMoneyType	Turnover;
	///�ֲ���
	TQTFtdcLargeVolumeType	OpenInterest;
	///������
	TQTFtdcPriceType	ClosePrice;
	///�����
	TQTFtdcPriceType	SettlementPrice;
	///��ͣ���
	TQTFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQTFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TQTFtdcRatioType	PreDelta;
	///����ʵ��
	TQTFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TQTFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQTFtdcMillisecType	UpdateMillisec;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///����г�����
struct CQTFtdcDepthMarketDataField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///���¼�
	TQTFtdcPriceType	LastPrice;
	///�����
	TQTFtdcPriceType	PreSettlementPrice;
	///������
	TQTFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///����
	TQTFtdcPriceType	OpenPrice;
	///��߼�
	TQTFtdcPriceType	HighestPrice;
	///��ͼ�
	TQTFtdcPriceType	LowestPrice;
	///����
	TQTFtdcVolumeType	Volume;
	///�ɽ����
	TQTFtdcMoneyType	Turnover;
	///�ֲ���
	TQTFtdcLargeVolumeType	OpenInterest;
	///������
	TQTFtdcPriceType	ClosePrice;
	///�����
	TQTFtdcPriceType	SettlementPrice;
	///��ͣ���
	TQTFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQTFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TQTFtdcRatioType	PreDelta;
	///����ʵ��
	TQTFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TQTFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQTFtdcMillisecType	UpdateMillisec;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�����һ
	TQTFtdcPriceType	BidPrice1;
	///������һ
	TQTFtdcVolumeType	BidVolume1;
	///������һ
	TQTFtdcPriceType	AskPrice1;
	///������һ
	TQTFtdcVolumeType	AskVolume1;
	///����۶�
	TQTFtdcPriceType	BidPrice2;
	///��������
	TQTFtdcVolumeType	BidVolume2;
	///�����۶�
	TQTFtdcPriceType	AskPrice2;
	///��������
	TQTFtdcVolumeType	AskVolume2;
	///�������
	TQTFtdcPriceType	BidPrice3;
	///��������
	TQTFtdcVolumeType	BidVolume3;
	///��������
	TQTFtdcPriceType	AskPrice3;
	///��������
	TQTFtdcVolumeType	AskVolume3;
	///�������
	TQTFtdcPriceType	BidPrice4;
	///��������
	TQTFtdcVolumeType	BidVolume4;
	///��������
	TQTFtdcPriceType	AskPrice4;
	///��������
	TQTFtdcVolumeType	AskVolume4;
	///�������
	TQTFtdcPriceType	BidPrice5;
	///��������
	TQTFtdcVolumeType	BidVolume5;
	///��������
	TQTFtdcPriceType	AskPrice5;
	///��������
	TQTFtdcVolumeType	AskVolume5;
	///��Ʒ����
	TQTFtdcInstrumentNameType	InstrumentName;
};

///�ּ۱�
struct CQTFtdcMBLMarketDataField
{
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��������
	TQTFtdcDirectionType	Direction;
	///�۸�
	TQTFtdcPriceType	Price;
	///����
	TQTFtdcVolumeType	Volume;
};

///��������
struct CQTFtdcAliasDefineField
{
	///��ʼλ��
	TQTFtdcStartPosType	StartPos;
	///����
	TQTFtdcAliasType	Alias;
	///ԭ��
	TQTFtdcOriginalTextType	OriginalText;
};

///�����������
struct CQTFtdcMarketDataBaseField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�����
	TQTFtdcPriceType	PreSettlementPrice;
	///������
	TQTFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQTFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQTFtdcRatioType	PreDelta;
	///��Ʒ����
	TQTFtdcInstrumentNameType	InstrumentName;
};

///���龲̬����
struct CQTFtdcMarketDataStaticField
{
	///����
	TQTFtdcPriceType	OpenPrice;
	///��߼�
	TQTFtdcPriceType	HighestPrice;
	///��ͼ�
	TQTFtdcPriceType	LowestPrice;
	///������
	TQTFtdcPriceType	ClosePrice;
	///��ͣ���
	TQTFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQTFtdcPriceType	LowerLimitPrice;
	///�����
	TQTFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQTFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CQTFtdcMarketDataLastMatchField
{
	///���¼�
	TQTFtdcPriceType	LastPrice;
	///����
	TQTFtdcVolumeType	Volume;
	///�ɽ����
	TQTFtdcMoneyType	Turnover;
	///�ֲ���
	TQTFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CQTFtdcMarketDataBestPriceField
{
	///�����һ
	TQTFtdcPriceType	BidPrice1;
	///������һ
	TQTFtdcVolumeType	BidVolume1;
	///������һ
	TQTFtdcPriceType	AskPrice1;
	///������һ
	TQTFtdcVolumeType	AskVolume1;
};

///�����������������
struct CQTFtdcMarketDataBid23Field
{
	///����۶�
	TQTFtdcPriceType	BidPrice2;
	///��������
	TQTFtdcVolumeType	BidVolume2;
	///�������
	TQTFtdcPriceType	BidPrice3;
	///��������
	TQTFtdcVolumeType	BidVolume3;
};

///������������������
struct CQTFtdcMarketDataAsk23Field
{
	///�����۶�
	TQTFtdcPriceType	AskPrice2;
	///��������
	TQTFtdcVolumeType	AskVolume2;
	///��������
	TQTFtdcPriceType	AskPrice3;
	///��������
	TQTFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CQTFtdcMarketDataBid45Field
{
	///�������
	TQTFtdcPriceType	BidPrice4;
	///��������
	TQTFtdcVolumeType	BidVolume4;
	///�������
	TQTFtdcPriceType	BidPrice5;
	///��������
	TQTFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CQTFtdcMarketDataAsk45Field
{
	///��������
	TQTFtdcPriceType	AskPrice4;
	///��������
	TQTFtdcVolumeType	AskVolume4;
	///��������
	TQTFtdcPriceType	AskPrice5;
	///��������
	TQTFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CQTFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQTFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQTFtdcMillisecType	UpdateMillisec;
};

///����
struct CQTFtdcQuoteField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///���۱��
	TQTFtdcQuoteSysIDType	QuoteSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��������
	TQTFtdcVolumeType	BidVolume;
	///��������
	TQTFtdcVolumeType	AskVolume;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///���ر��۱��
	TQTFtdcOrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	TQTFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	TQTFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	TQTFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	TQTFtdcPriceType	AskPrice;
	///����ʱ��
	TQTFtdcTimeType	InsertTime;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///�ɽ�ʱ��
	TQTFtdcTimeType	TradeTime;
	///�򷽱������
	TQTFtdcOrderSysIDType	BidOrderSysID;
	///�����������
	TQTFtdcOrderSysIDType	AskOrderSysID;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
};

///�ɽ�
struct CQTFtdcTradeField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ɽ����
	TQTFtdcTradeIDType	TradeID;
	///��������
	TQTFtdcDirectionType	Direction;
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///���׽�ɫ
	TQTFtdcTradingRoleType	TradingRole;
	///�ʽ��ʺ�
	TQTFtdcAccountIDType	AccountID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��ƽ��־
	TQTFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQTFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQTFtdcPriceType	Price;
	///����
	TQTFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TQTFtdcTimeType	TradeTime;
	///�ɽ�����
	TQTFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TQTFtdcPriceSourceType	PriceSource;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///������
	TQTFtdcFeeType	Fee;
	///����ӯ��
	TQTFtdcMoneyType	CloseProfit;
};

///����
struct CQTFtdcOrderField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�����۸�����
	TQTFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQTFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TQTFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TQTFtdcPriceType	LimitPrice;
	///����
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TQTFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQTFtdcDateType	GTDDate;
	///�ɽ�������
	TQTFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQTFtdcVolumeType	MinVolume;
	///��������
	TQTFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TQTFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQTFtdcForceCloseReasonType	ForceCloseReason;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///�Զ������־
	TQTFtdcBoolType	IsAutoSuspend;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///����״̬
	TQTFtdcOrderStatusType	OrderStatus;
	///��������
	TQTFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TQTFtdcVolumeType	VolumeTraded;
	///ʣ������
	TQTFtdcVolumeType	VolumeTotal;
	///��������
	TQTFtdcDateType	InsertDate;
	///����ʱ��
	TQTFtdcTimeType	InsertTime;
	///����ʱ��
	TQTFtdcTimeType	ActiveTime;
	///����ʱ��
	TQTFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TQTFtdcTimeType	UpdateTime;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///����޸Ľ����û�����
	TQTFtdcUserIDType	ActiveUserID;
	///����Ȩ
	TQTFtdcPriorityType	Priority;
	///��ʱ���Ŷӵ����
	TQTFtdcTimeSortIDType	TimeSortID;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
};

///ִ������
struct CQTFtdcExecOrderField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///��Լ���
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///����ִ��������
	TQTFtdcOrderLocalIDType	ExecOrderLocalID;
	///����
	TQTFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///ִ��������
	TQTFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TQTFtdcDateType	InsertDate;
	///����ʱ��
	TQTFtdcTimeType	InsertTime;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///ִ�н��
	TQTFtdcExecResultType	ExecResult;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
};

///�Ǳ���ϱ���
struct CQTFtdcCombOrderField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///��ϱ������
	TQTFtdcOrderSysIDType	CombOrderSysID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�۸�
	TQTFtdcPriceType	LimitPrice;
	///����
	TQTFtdcVolumeType	VolumeTotalOriginal;
	///���ر������
	TQTFtdcOrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	TQTFtdcBusinessUnitType	BusinessUnit;
	///��Լ����1
	TQTFtdcInstrumentIDType	InstrumentID1;
	///��������1
	TQTFtdcDirectionType	Direction1;
	///���ȳ���1
	TQTFtdcLegMultipleType	LegMultiple1;
	///��ƽ��־1
	TQTFtdcOffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	TQTFtdcHedgeFlagType	HedgeFlag1;
	///��Լ����2
	TQTFtdcInstrumentIDType	InstrumentID2;
	///��������2
	TQTFtdcDirectionType	Direction2;
	///���ȳ���2
	TQTFtdcLegMultipleType	LegMultiple2;
	///��ƽ��־2
	TQTFtdcOffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	TQTFtdcHedgeFlagType	HedgeFlag2;
	///��Լ����3
	TQTFtdcInstrumentIDType	InstrumentID3;
	///��������3
	TQTFtdcDirectionType	Direction3;
	///���ȳ���3
	TQTFtdcLegMultipleType	LegMultiple3;
	///��ƽ��־3
	TQTFtdcOffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	TQTFtdcHedgeFlagType	HedgeFlag3;
	///��Լ����4
	TQTFtdcInstrumentIDType	InstrumentID4;
	///��������4
	TQTFtdcDirectionType	Direction4;
	///���ȳ���4
	TQTFtdcLegMultipleType	LegMultiple4;
	///��ƽ��־4
	TQTFtdcOffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	TQTFtdcHedgeFlagType	HedgeFlag4;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///��ɽ�����
	TQTFtdcVolumeType	VolumeTraded;
	///ʣ������
	TQTFtdcVolumeType	VolumeTotal;
	///��������
	TQTFtdcDateType	InsertDate;
	///����ʱ��
	TQTFtdcTimeType	InsertTime;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
};

///������
struct CQTFtdcAdminOrderField
{
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///����������
	TQTFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///���׻�Ա���
	TQTFtdcParticipantIDType	ParticipantID;
	///���
	TQTFtdcMoneyType	Amount;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///����������
struct CQTFtdcInputAdminOrderField
{
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///����������
	TQTFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	TQTFtdcParticipantIDType	ClearingPartID;
	///���׻�Ա���
	TQTFtdcParticipantIDType	ParticipantID;
	///���
	TQTFtdcMoneyType	Amount;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
};

///����
struct CQTFtdcBulletinField
{
	///������
	TQTFtdcDateType	TradingDay;
	///������
	TQTFtdcBulletinIDType	BulletinID;
	///���к�
	TQTFtdcSequenceNoType	SequenceNo;
	///��������
	TQTFtdcNewsTypeType	NewsType;
	///�����̶�
	TQTFtdcNewsUrgencyType	NewsUrgency;
	///����ʱ��
	TQTFtdcTimeType	SendTime;
	///��ϢժҪ
	TQTFtdcAbstractType	Abstract;
	///��Ϣ��Դ
	TQTFtdcComeFromType	ComeFrom;
	///��Ϣ����
	TQTFtdcContentType	Content;
	///WEB��ַ
	TQTFtdcURLLinkType	URLLink;
	///�г�����
	TQTFtdcMarketIDType	MarketID;
};

///����������ͬ��״̬
struct CQTFtdcExchangeDataSyncStatusField
{
	///������
	TQTFtdcDateType	TradingDay;
	///����������
	TQTFtdcExchangeIDType	ExchangeID;
	///����������ͬ��״̬
	TQTFtdcExchangeDataSyncStatusType	ExchangeDataSyncStatus;
};

///����������ͬ��״̬
struct CQTFtdcSGDataSyncStatusField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcDateType	TradingDay;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///����������ͬ��״̬
	TQTFtdcSGDataSyncStatusType	SGDataSyncStatus;
};

///��Լ״̬
struct CQTFtdcInstrumentStatusField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQTFtdcInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TQTFtdcTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TQTFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TQTFtdcInstStatusEnterReasonType	EnterReason;
};

///�ͻ��ֲֲ�ѯ
struct CQTFtdcQryClientPositionV1Field
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TQTFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TQTFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstIDEnd;
};

///ѯ��
struct CQTFtdcInputReqForQuoteField
{
	///ѯ�۱��
	TQTFtdcQuoteSysIDType	ReqForQuoteID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��������
	TQTFtdcTradingDayType	TradingDay;
	///ѯ��ʱ��
	TQTFtdcTimeType	ReqForQuoteTime;
};

///�����ڴ��
struct CQTFtdcDumpMemTableField
{
	///�ڴ������
	TQTFtdcTableNameType	TableName;
};

///��Լ״̬����
struct CQTFtdcIPOOrderField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�������
	TQTFtdcDateSeqNoType	OrderSysID;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�깺����
	TQTFtdcPurchaseTypeType	PurchaseType;
	///����״̬
	TQTFtdcOrderStatusType	OrderStatus;
	///��������
	TQTFtdcCancelTypeType	CancelType;
	///�۸�
	TQTFtdcPriceType	OrderPrice;
	///����
	TQTFtdcVolumeType	OrderVolume;
	///����
	TQTFtdcVolumeType	TradeVolume;
	///������
	TQTFtdcMoneyType	OrderFrozenMoney;
	///Ԥ��������
	TQTFtdcMoneyType	PrePayFee;
	///����������
	TQTFtdcMoneyType	ReturnFee;
	///ί������
	TQTFtdcDateType	OrderDate;
	///ί��ʱ��
	TQTFtdcTimeType	InsertTime;
	///��������
	TQTFtdcDateType	CancelDate;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///��ʼ���
	TQTFtdcIPOSeqNoType	StartSeqNo;
	///�������
	TQTFtdcIPOSeqNoType	EndSeqNo;
	///��������
	TQTFtdcDateType	SettleDate;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///�������
	TQTFtdcMoneyType	ReturnMoney;
};

///IPO��Լ��Ϣ
struct CQTFtdcIPOInstrumentField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ʒ����
	TQTFtdcInstrumentNameType	InstrumentName;
	///���м�
	TQTFtdcPriceType	LaunchPrice;
	///��������
	TQTFtdcVolumeType	LaunchAmt;
	///�깺��ʼ����
	TQTFtdcDateType	StartPurchaseDate;
	///�깺��������
	TQTFtdcDateType	EndPurchaseDate;
	///��Ʒ״̬
	TQTFtdcPorductStatusType	InstrumentStatus;
	///����깺����
	TQTFtdcVolumeType	MaxPurchaseAmt;
	///��С�깺����
	TQTFtdcVolumeType	MinPurchaseAmt;
	///��С�䶯����
	TQTFtdcVolumeType	MinChangeAmt;
	///�깺ÿ��������
	TQTFtdcRatioType	PurchaseFeeAmt;
	///�깺��������
	TQTFtdcRatioType	PurchaseFeeRate;
	///�깺��ʼʱ��
	TQTFtdcTimeType	StartPurchaseTime;
	///�깺����ʱ��
	TQTFtdcTimeType	EndPurchaseTime;
	///��Լ����
	TQTFtdcVolumeMultipleType	VolumeMultiple;
	///��������
	TQTFtdcVolumeType	QtyUnit;
};

///IPO��Լ��Ϣ��ѯ
struct CQTFtdcQryIPOInstrumentField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO�ͻ��깺��������
struct CQTFtdcIPORightField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO�����޸�
struct CQTFtdcIPOActionField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�������
	TQTFtdcDateSeqNoType	OrderSysID;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TQTFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�깺����
	TQTFtdcPurchaseTypeType	PurchaseType;
	///����״̬
	TQTFtdcOrderStatusType	OrderStatus;
	///��������
	TQTFtdcCancelTypeType	CancelType;
	///�۸�
	TQTFtdcPriceType	OrderPrice;
	///����
	TQTFtdcVolumeType	OrderVolume;
	///����
	TQTFtdcVolumeType	TradeVolume;
	///������
	TQTFtdcMoneyType	OrderFrozenMoney;
	///Ԥ��������
	TQTFtdcMoneyType	PrePayFee;
	///����������
	TQTFtdcMoneyType	ReturnFee;
	///ί������
	TQTFtdcDateType	OrderDate;
	///ί��ʱ��
	TQTFtdcTimeType	InsertTime;
	///��������
	TQTFtdcDateType	CancelDate;
	///����ʱ��
	TQTFtdcTimeType	CancelTime;
	///��ʼ���
	TQTFtdcIPOSeqNoType	StartSeqNo;
	///�������
	TQTFtdcIPOSeqNoType	EndSeqNo;
	///��������
	TQTFtdcDateType	SettleDate;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///�������
	TQTFtdcMoneyType	ReturnMoney;
};

///IPO��ǩ�����ѯ
struct CQTFtdcIPOTradeField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�������
	TQTFtdcDateSeqNoType	OrderSysID;
	///�ɽ����
	TQTFtdcTradeIDType	TradeID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�ɽ�����
	TQTFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TQTFtdcTimeType	TradeTime;
	///�깺����
	TQTFtdcPurchaseTypeType	PurchaseType;
	///�ɽ��۸�
	TQTFtdcPriceType	TradePrice;
	///�ɽ�����
	TQTFtdcVolumeType	Volume;
	///�ɽ����
	TQTFtdcMoneyType	TradeMoney;
	///�ɽ�����
	TQTFtdcIPOTradeTypeType	IPOTradeType;
	///������
	TQTFtdcMoneyType	Fee;
	///ί������
	TQTFtdcDateType	InsertDate;
};

///IPO������ѯ
struct CQTFtdcQryIPOOrderField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�������
	TQTFtdcDateSeqNoType	OrderSysID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼ����
	TQTFtdcDateType	TimeStart;
	///��������
	TQTFtdcDateType	TimeEnd;
};

///IPO�깺Ȩ�޲�ѯ
struct CQTFtdcQryIPORightField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
};

///IPO�ɽ���ѯ
struct CQTFtdcQryIPOTradeField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///�ɽ����
	TQTFtdcTradeIDType	TradeID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼʱ��
	TQTFtdcDateType	TimeStart;
	///����ʱ��
	TQTFtdcDateType	TimeEnd;
	///�������
	TQTFtdcDateSeqNoType	OrderSysID;
};

///�ʽ��˻������������Ϣ
struct CQTFtdcInvestorDepositField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	TQTFtdcAccountIDType	AccountID;
	///�����
	TQTFtdcMoneyType	Deposit;
	///�����ֻ�нⶳ�����ʹ��
	TQTFtdcMoneyType	Withdraw;
	///������
	TQTFtdcMoneyType	Fee;
	///�ʽ��������
	TQTFtdcAccountActionTypeType	ActionType;
	///��ע
	TQTFtdcComeFromType	Comments;
	///ҵ��ָ��ı�
	TQTFtdcTableNameType	BusinessTable;
	///ҵ���Ψһ����
	TQTFtdcOrderSysIDType	BusinessKey;
};

///�ʽ��˻������Ӧ����Ϣ
struct CQTFtdcInvestorDepositResField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TQTFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TQTFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TQTFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TQTFtdcMoneyType	Premium;
	///�����
	TQTFtdcMoneyType	Deposit;
	///������
	TQTFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TQTFtdcMoneyType	Balance;
	///�����ʽ�
	TQTFtdcMoneyType	Available;
	///�ʽ��ʺ�
	TQTFtdcAccountIDType	AccountID;
	///����ı�֤��
	TQTFtdcMoneyType	FrozenMargin;
	///�����Ȩ����
	TQTFtdcMoneyType	FrozenPremium;
	///�ֻ��ʽ���֧
	TQTFtdcMoneyType	SpotMoney;
	///������ֻ��ʽ�
	TQTFtdcMoneyType	FrozenSpotMoney;
	///����������֧��
	TQTFtdcFeeType	Fee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenFee;
	///���������Ѷ���
	TQTFtdcFeeType	FrozenIPOMoney;
	///���¶����ʽ�
	TQTFtdcFeeType	FrozenMoney;
	///��ȡ�ʽ�
	TQTFtdcMoneyType	Useable;
	///���ɽ��ʽ�
	TQTFtdcMoneyType	SellMoney;
};

///���볡��ɽ���
struct CQTFtdcInputOTCTradeField
{
	///�ɽ����
	TQTFtdcOrderSysIDType	TradeID;
	///�򷽻�Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�ɽ��Ա��ر��
	TQTFtdcOrderLocalIDType	TradeLocalID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�۸�
	TQTFtdcPriceType	Price;
	///����
	TQTFtdcVolumeType	Volume;
	///�򷽻�Ա����
	TQTFtdcParticipantIDType	BuyParticipantID;
	///�򷽿ͻ�����
	TQTFtdcClientIDType	BuyClientID;
	///�򷽽����û�����
	TQTFtdcUserIDType	BuyUserID;
	///�򷽱��ر������
	TQTFtdcOrderLocalIDType	BuyOrderLocalID;
	///����Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	BuyCombOffsetFlag;
	///�����Ͷ���ױ���־
	TQTFtdcCombHedgeFlagType	BuyCombHedgeFlag;
	///��������Ա����
	TQTFtdcParticipantIDType	SellParticipantID;
	///�����ͻ�����
	TQTFtdcClientIDType	SellClientID;
	///���������û�����
	TQTFtdcUserIDType	SellUserID;
	///������Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	SellCombOffsetFlag;
	///��������ױ���־
	TQTFtdcCombHedgeFlagType	SellCombHedgeFlag;
	///�������ر������
	TQTFtdcOrderLocalIDType	SellOrderLocalID;
	///OTC����
	TQTFtdcOTCTypeType	OTCType;
	///״̬
	TQTFtdcOTCStatusType	Status;
	///�������
	TQTFtdcErrorIDType	OTCErrorID;
	///������Ϣ
	TQTFtdcErrorMsgType	OTCErrorMsg;
	///��ע
	TQTFtdcComeFromType	Comments;
	///�ɽ����
	TQTFtdcMoneyType	TradeMoney;
};

///����ɽ���
struct CQTFtdcOTCTradeField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///�ɽ����
	TQTFtdcOrderSysIDType	TradeID;
	///�򷽻�Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�ɽ��Ա��ر��
	TQTFtdcOrderLocalIDType	TradeLocalID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///�۸�
	TQTFtdcPriceType	Price;
	///����
	TQTFtdcVolumeType	Volume;
	///�򷽻�Ա����
	TQTFtdcParticipantIDType	BuyParticipantID;
	///�򷽿ͻ�����
	TQTFtdcClientIDType	BuyClientID;
	///�򷽽����û�����
	TQTFtdcUserIDType	BuyUserID;
	///�򷽱��ر������
	TQTFtdcOrderLocalIDType	BuyOrderLocalID;
	///����Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	BuyCombOffsetFlag;
	///�����Ͷ���ױ���־
	TQTFtdcCombHedgeFlagType	BuyCombHedgeFlag;
	///��������Ա����
	TQTFtdcParticipantIDType	SellParticipantID;
	///�����ͻ�����
	TQTFtdcClientIDType	SellClientID;
	///���������û�����
	TQTFtdcUserIDType	SellUserID;
	///������Ͽ�ƽ��־
	TQTFtdcCombOffsetFlagType	SellCombOffsetFlag;
	///��������ױ���־
	TQTFtdcCombHedgeFlagType	SellCombHedgeFlag;
	///�������ر������
	TQTFtdcOrderLocalIDType	SellOrderLocalID;
	///OTC����
	TQTFtdcOTCTypeType	OTCType;
	///״̬
	TQTFtdcOTCStatusType	Status;
	///�������
	TQTFtdcErrorIDType	OTCErrorID;
	///������Ϣ
	TQTFtdcErrorMsgType	OTCErrorMsg;
	///��ע
	TQTFtdcComeFromType	Comments;
	///�ɽ����
	TQTFtdcMoneyType	TradeMoney;
	///����������
	TQTFtdcMoneyType	OpenFee;
	///ƽ��������
	TQTFtdcMoneyType	OffsetFee;
	///ת��ӯ��
	TQTFtdcMoneyType	OpenProfit;
	///ת��ӯ��
	TQTFtdcMoneyType	OffsetProfit;
	///ί������
	TQTFtdcDateType	OrderDate;
	///ί��ʱ��
	TQTFtdcTimeType	InsertTime;
};

///�ֲֻ�ת
struct CQTFtdcPositionChangeField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��Լ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��ת����
	TQTFtdcVolumeType	TransVolume;
	///ҵ������
	TQTFtdcBusinessTypeType	TransType;
	///���ر������
	TQTFtdcOrderLocalIDType	OrderLocalID;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///���������
	TQTFtdcPasswordType	DepotPwd;
	///�ֵ�ƾ֤
	TQTFtdcDateSeqNoType	WarrantID;
	///����״̬
	TQTFtdcTransStatusType	TransStatus;
	///������,�����ע��ʱΪ�����ʽ�
	TQTFtdcMoneyType	TransFrozenMoney;
	///������,�����ȡ��ʱΪע����
	TQTFtdcMoneyType	PrePayFee;
	///ί������
	TQTFtdcDateType	OrderDate;
	///ί��ʱ��
	TQTFtdcTimeType	InsertTime;
	///�������
	TQTFtdcOrderSysIDType	OrderSysID;
	///ҵ��ָ��ı�
	TQTFtdcTableNameType	BusinessTable;
	///ҵ���Ψһ����
	TQTFtdcOrderSysIDType	BusinessKey;
	///�ֲִ���ʽ
	TQTFtdcPosDealTypeType	PosDealType;
	///�ʽ���ʽ
	TQTFtdcAccountActionTypeType	AccountActionType;
	///��ע
	TQTFtdcComeFromType	Comments;
};

///�ֵ�ע��
struct CQTFtdcPickRequestField
{
	///������
	TQTFtdcDateType	TradingDay;
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQTFtdcSettlementIDType	SettlementID;
	///��Ʒ����
	TQTFtdcInstrumentIDType	InstrumentID;
	///��������
	TQTFtdcVolumeType	DeliveryVolume;
	///�ֿ���
	TQTFtdcSerialNoType	HouseID;
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�������
	TQTFtdcVolumeType	DeliveryUnits;
	///�������
	TQTFtdcDateType	PickDate;
	///���յ�λ
	TQTFtdcQuantityUnitType	Unit;
	///�����״̬
	TQTFtdcWarrantStatusType	RequestStat;
	///�ֵ�ƾ֤
	TQTFtdcDateSeqNoType	PickRequestID;
	///ע������
	TQTFtdcDateType	RegDate;
	///ί��ʱ��
	TQTFtdcTimeType	RequestTime;
	///������Դ
	TQTFtdcOrderSourceType	OrderSource;
	///�ִ���
	TQTFtdcFeeType	StoreFee;
	///���շ�
	TQTFtdcFeeType	InsuranceFee;
	///�йܷ�
	TQTFtdcFeeType	CustodyFee;
	///ע���
	TQTFtdcFeeType	RegFee;
	///ע����
	TQTFtdcFeeType	CancelFee;
	///������
	TQTFtdcFeeType	TransferFee;
	///���ͷ�
	TQTFtdcFeeType	DeliveryFee;
	///���ռ۸�
	TQTFtdcPriceType	DeliveryPrice;
	///����������
	TQTFtdcExchangeIDType	ExchID;
	///����������
	TQTFtdcVolumeType	WrongPwdCount;
	///�����������
	TQTFtdcDateType	WrongPwdDate;
	///ע������
	TQTFtdcDateType	CancelDate;
	///ע��ʱ��
	TQTFtdcTimeType	CancelTime;
	///���������
	TQTFtdcPasswordType	PickPwd;
	///�������
	TQTFtdcWarrantTypeType	PickType;
	///���������
	TQTFtdcClientNameType	PickerName;
	///�Ա�
	TQTFtdcSexTypeType	Gender;
	///֤������
	TQTFtdcIdCardTypeType	CertType;
	///֤������
	TQTFtdcIdentifiedCardNoType	CertCode;
	///��������
	TQTFtdcWarrantOperType	OperateType;
	///����״̬
	TQTFtdcWarrantStatusType	DeliveryStatus;
	///�绰����
	TQTFtdcTelphoneNumType	Phone;
	///�ջ���ַ
	TQTFtdcAddressType	Addr;
	///�ʱ�
	TQTFtdcPostNumType	PostCode;
	///�ջ���λ
	TQTFtdcDescriptionType	ReceiveCom;
	///���Ա����
	TQTFtdcOperatorIDType	VerifierID;
	///��������
	TQTFtdcDateType	DeliveryDate;
};

///�ֵ���ѯ
struct CQTFtdcQryPickRequestField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�����״̬
	TQTFtdcWarrantStatusType	RequestStat;
	///�ֵ�ƾ֤
	TQTFtdcDateSeqNoType	PickRequestID;
	///ע�Ὺʼ����
	TQTFtdcDateType	TimeStart;
	///ע���������
	TQTFtdcDateType	TimeEnd;
};

///�ֲֻ�ת
struct CQTFtdcQryPositionChangeField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///ע�Ὺʼ����
	TQTFtdcDateType	TimeStart;
	///ע���������
	TQTFtdcDateType	TimeEnd;
};

///���ڽ��ס��ֲֹ�����ѯ
struct CQTFtdcQryOTCTradeField
{
	///��ʼ��Ա����
	TQTFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TQTFtdcParticipantIDType	PartIDEnd;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///�ɽ����
	TQTFtdcOrderSysIDType	TradeID;
};

///������ѯ
struct CQTFtdcQryAccountDepositDetailField
{
	///�ʽ��˺�
	TQTFtdcAccountIDType	AccountID;
	///�������ˮ���
	TQTFtdcSequenceNoType	SequenceNo;
	///ί�п�ʼ����
	TQTFtdcDateType	TimeStart;
	///ί�п�ʼ����
	TQTFtdcDateType	TimeEnd;
};

///�����
struct CQTFtdcAccountDepositDetailField
{
	///���������
	TQTFtdcSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	TQTFtdcAccountIDType	AccountID;
	///�����
	TQTFtdcMoneyType	Deposit;
	///�����ֻ�нⶳ�����ʹ��
	TQTFtdcMoneyType	Withdraw;
	///������
	TQTFtdcMoneyType	Fee;
	///�ʽ��������
	TQTFtdcAccountActionTypeType	ActionType;
	///��ע
	TQTFtdcComeFromType	Comments;
	///ҵ��ָ��ı�
	TQTFtdcTableNameType	BusinessTable;
	///ҵ���Ψһ����
	TQTFtdcOrderSysIDType	BusinessKey;
	///�������ˮ���
	TQTFtdcSequenceNoType	SequenceNo;
	///������
	TQTFtdcTransStatusType	Status;
	///ί������
	TQTFtdcDateType	OrderDate;
	///ί��ʱ��
	TQTFtdcTimeType	InsertTime;
};

///�����û��޸�
struct CQTFtdcUserActionField
{
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///�����û�����
	TQTFtdcUserTypeType	UserType;
	///����
	TQTFtdcPasswordType	Password;
	///����ԱȨ��
	TQTFtdcUserActiveType	IsActive;
	///�޸�ģʽ
	TQTFtdcUserActionTypeType	UserActionType;
	///������
	TQTFtdcPasswordType	OldPassword;
};

///���ڽ��ס��ֲֹ�����ѯ
struct CQTFtdcQryOtherTradeField
{
	///��Ա����
	TQTFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQTFtdcClientIDType	ClientID;
	///�����û�����
	TQTFtdcUserIDType	UserID;
	///��ʼ��Լ����
	TQTFtdcInstrumentIDType	InstrumentIDStart;
	///������Լ����
	TQTFtdcInstrumentIDType	InstrumentIDEnd;
	///�ɽ����
	TQTFtdcOrderSysIDType	TradeID;
};



#endif
