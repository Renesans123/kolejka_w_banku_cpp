#pragma once

#include "Client.h"
#include "Counter.h"
#include "Employee.h"
#include "Bank.h"


void removeAllSpaces(std::string& s);
void removeEndSpaces(std::string& s);
bool compareStrings(std::string s1, std::string s2);

void runSimulation(int m, int n, std::string filename = "BankLogs.txt");