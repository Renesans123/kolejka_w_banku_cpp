#include <iostream>
#include <map>

#include "permission.h"
using std::string; using std::map;

map<permission, set <responsibility>> possibleResponsibilities = {
		{analitic,{fast_transfer,check_account,credit_offer}},
		{bank_assistant,{retrieve_user_data,check_account,new_user_help}},
		{cashier,{cash_withdraw,deposit_cash,check_account}},
		{director,{transfer,fast_transfer,retrieve_user_data,change_user_data,check_account}},
		{financial_manager,{cash_withdraw,transfer,fast_transfer,deposit_cash,check_account,credit_offer,account_offer}},
		{data_specialist,{retrieve_user_data,change_user_data,check_account}},
		{account_manager,{cash_withdraw,transfer,deposit_cash,change_user_data,check_account,account_offer,new_user_help}}
};

string EnumToStr(permission p){
static const char *enum_str[] = {"analitic","bank_assistant","cashier","director","financial_manager","data_specialist","account_manager"};
return enum_str[(int)(p)];
}
string EnumToStr(responsibility p){
static const char *enum_str[] = {"cash_withdraw","transfer","fast_transfer","deposit_cash","retrieve_user_data","change_user_data","check_account","present_credit_offer","present_account_offer","new_user_help"};
return enum_str[(int)(p)];
}

permission StrTopermission(string p) {
	permission ret;
	static const char *enum_str[] = {"analitic","bank_assistant","cashier,director","financial_manager","data_specialist","account_manager"};
	for (int i = 0; i<20; i++){
		if (enum_str[i]==p){
			ret = static_cast<permission>(i);
		}
	}
	return ret;
}

responsibility StrToResponsibility(string p) {
	responsibility ret;
	static const char *enum_str[] = {"analitic","bank_assistant","cashier,director","financial_manager","data_specialist","account_manager"};
	for (int i = 0; i<20; i++){
		if (enum_str[i]==p){
			ret = static_cast<responsibility>(i);
		}
	}
	return ret;
}
