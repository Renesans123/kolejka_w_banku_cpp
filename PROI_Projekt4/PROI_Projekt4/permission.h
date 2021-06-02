#ifndef permissionS_H
#define permissionS_H
#include <iostream>
#include <map>
#include <set>
using std::map; using std::set; using std::string;

enum permission
{
	analitic,bank_assistant,cashier,director,financial_manager,data_specialist,account_manager,
	lastPermission
};
enum responsibility
{
	cash_withdraw, transfer, fast_transfer, deposit_cash, retrieve_user_data, change_user_data, check_account, credit_offer, account_offer, new_user_help,
	lastResponsibilty
};

string EnumToStr(permission p);
string EnumToStr(responsibility p);
extern map<permission, set<responsibility>> possibleResponsibilities;

permission StrTopermission(string p);
responsibility StrToResponsibility(string p);

#endif
