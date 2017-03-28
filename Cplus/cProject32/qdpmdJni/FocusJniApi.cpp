#include "FocusJniApi.h"
#include <string.h>

FocusJniApi::FocusJniApi(CFocusFtdcUserApi *userApi) {
	this->m_userApi = userApi;
}

//FocusJniApi::FocusJniSpi(CFocusFtdcUserApi *userApi,
//	const CFocusFtdcReqUserLoginField &pReqUserLogin,
//	JavaVM *vm, jobject jniTemplate)
//{
//
//}


int FocusJniApi::reqUserLogin(JNIEnv *env, jobject reqMap, int nRequestID)
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

	return this->m_userApi->ReqUserLogin(&request, nRequestID);

}




///计算单个期权请求
int FocusJniApi::reqCalcOneOption(JNIEnv *env, jobject reqMap, jint nRequestID)
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

	return this->m_userApi->ReqCalcOneOption(&request, nRequestID);

}

///计算障碍期权请求
int FocusJniApi::reqCalcBarrierOption(JNIEnv *env, jobject reqMap, jint nRequestID)
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

	return this->m_userApi->ReqCalcBarrierOption(&request, nRequestID);

}

///计算期权组合请求
int FocusJniApi::reqCalcCombinationOption(JNIEnv *env, jobject reqMap, jint nRequestID)
{
	char CalculateTarget = m_jniUtil.getCharByMap(env, reqMap,					"CalculateTarget"		);
	char ExerciseType = m_jniUtil.getCharByMap(env, reqMap,						"ExerciseType"			);
	double UnderlyingPrice = m_jniUtil.getDoubleByMap(env, reqMap,				"UnderlyingPrice"		);
	double RiskFreeRate = m_jniUtil.getDoubleByMap(env, reqMap,					"RiskFreeRate"			);
	double Dividend = m_jniUtil.getDoubleByMap(env, reqMap,						"Dividend"				);
	const char *TradingDate = m_jniUtil.getStringByMap(env, reqMap,				"TradingDate"			);
	char PricingModel = m_jniUtil.getCharByMap(env, reqMap,						"PricingModel"			);
	double CombinationPrice = m_jniUtil.getDoubleByMap(env, reqMap,				"CombinationPrice"		);
	const char *InstrumentID_Leg1 = m_jniUtil.getStringByMap(env, reqMap,		"InstrumentID_Leg1"		);
	char OptionsType_Leg1 = m_jniUtil.getCharByMap(env, reqMap,					"OptionsType_Leg1"		);
	char Direction_Leg1 = m_jniUtil.getCharByMap(env, reqMap,					"Direction_Leg1"		);
	double StrikePrice_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,				"StrikePrice_Leg1"		);
	const char *ExpireDate_Leg1 = m_jniUtil.getStringByMap(env, reqMap,			"ExpireDate_Leg1"		);
	double Vol_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,						"Vol_Leg1"				);
	double OptionPrice_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,				"OptionPrice_Leg1"		);
	double Delta_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Delta_Leg1"			);
	double Gamma_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Gamma_Leg1"			);
	double Vega_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vega_Leg1"				);
	double Theta_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Theta_Leg1"			);
	double Rho_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,						"Rho_Leg1"				);
	double Vanna_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vanna_Leg1"			);
	double Valga_Leg1 = m_jniUtil.getDoubleByMap(env, reqMap,					"Valga_Leg1"			);
	const char *InstrumentID_Leg2 = m_jniUtil.getStringByMap(env, reqMap,		"InstrumentID_Leg2"		);
	char OptionsType_Leg2 = m_jniUtil.getCharByMap(env, reqMap,					"OptionsType_Leg2"		);
	char Direction_Leg2 = m_jniUtil.getCharByMap(env, reqMap,					"Direction_Leg2"		);
	double StrikePrice_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,				"StrikePrice_Leg2"		);
	const char *ExpireDate_Leg2 = m_jniUtil.getStringByMap(env, reqMap,			"ExpireDate_Leg2"		);
	double Vol_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,						"Vol_Leg2"				);
	double OptionPrice_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,				"OptionPrice_Leg2"		);
	double Delta_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Delta_Leg2"			);
	double Gamma_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Gamma_Leg2"			);
	double Vega_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vega_Leg2"				);
	double Theta_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Theta_Leg2"			);
	double Rho_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,						"Rho_Leg2"				);
	double Vanna_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vanna_Leg2"			);
	double Valga_Leg2 = m_jniUtil.getDoubleByMap(env, reqMap,					"Valga_Leg2"			);
	const char *InstrumentID_Leg3 = m_jniUtil.getStringByMap(env, reqMap,		"InstrumentID_Leg3"		);
	char OptionsType_Leg3 = m_jniUtil.getCharByMap(env, reqMap,					"OptionsType_Leg3"		);
	char Direction_Leg3 = m_jniUtil.getCharByMap(env, reqMap,					"Direction_Leg3"		);
	double StrikePrice_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,				"StrikePrice_Leg3"		);
	const char *ExpireDate_Leg3 = m_jniUtil.getStringByMap(env, reqMap,			"ExpireDate_Leg3"		);
	double Vol_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,						"Vol_Leg3"				);
	double OptionPrice_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,				"OptionPrice_Leg3"		);
	double Delta_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Delta_Leg3"			);
	double Gamma_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Gamma_Leg3"			);
	double Vega_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vega_Leg3"				);
	double Theta_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Theta_Leg3"			);
	double Rho_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,						"Rho_Leg3"				);
	double Vanna_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vanna_Leg3"			);
	double Valga_Leg3 = m_jniUtil.getDoubleByMap(env, reqMap,					"Valga_Leg3"			);
	const char *InstrumentID_Leg4 = m_jniUtil.getStringByMap(env, reqMap,		"InstrumentID_Leg4"		);
	char OptionsType_Leg4 = m_jniUtil.getCharByMap(env, reqMap,					"OptionsType_Leg4"		);
	char Direction_Leg4 = m_jniUtil.getCharByMap(env, reqMap,					"Direction_Leg4"		);
	double StrikePrice_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,				"StrikePrice_Leg4"		);
	const char *ExpireDate_Leg4 = m_jniUtil.getStringByMap(env, reqMap,			"ExpireDate_Leg4"		);
	double Vol_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,						"Vol_Leg4"				);
	double OptionPrice_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,				"OptionPrice_Leg4"		);
	double Delta = m_jniUtil.getDoubleByMap(env, reqMap,						"Delta"					);
	double Gamma_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,					"Gamma_Leg4"			);
	double Vega_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vega_Leg4"				);
	double Theta_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,					"Theta_Leg4"			);
	double Rho_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,						"Rho_Leg4"				);
	double Vanna_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,					"Vanna_Leg4"			);
	double Valga_Leg4 = m_jniUtil.getDoubleByMap(env, reqMap,					"Valga_Leg4"			);

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

	return this->m_userApi->ReqCalcCombinationOption(&request, nRequestID);
}



///计算单个期权应答
void FocusJniSpi::OnRspCalcOneOption(CFocusFtdcBasePricingParamField *pBasePricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;

}

///计算障碍期权应答
void FocusJniSpi::OnRspCalcBarrierOption(CFocusFtdcDoubleBarrierPricingParamField *pDoubleBarrierPricingParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;

}

///计算期权组合应答
void FocusJniSpi::OnRspCalcCombinationOption(CFocusFtdcCombinationParamField *pCombinationParam, CFocusFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	if (pRspInfo == NULL) {
		m_jniUtil.print(m_env, m_jniTemplate, "pRspInfo is null");
		return;
	}
	jobject jmap = NULL;

}