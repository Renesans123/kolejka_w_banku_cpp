#ifndef PERMISIONS_H
#define PERMISIONS_H
#include <iostream>
#include <map>
#include <set>
using std::map; using std::set; using std::string;

enum permision{analitic,bank_assistant,cashier,director,financial_manager,data_specialist,account_manager};
enum responsibility {cash_withdraw,transfer,fast_transfer,deposit_cash,retrieve_user_data,change_user_data,check_account,credit_offer,account_offer,new_user_help};

string EnumToStr(permision p);
string EnumToStr(responsibility p);
extern map<permision, set<responsibility>> possibleResponsibilities;

permision StrToPermision(string p);
responsibility StrToResponsibility(string p);

#endif
