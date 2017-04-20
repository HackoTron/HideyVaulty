/*
* NewAccount.h
*
*  Created on: 26/03/2017
*      Author: HackoTron
*/

#ifndef NEWACCOUNT_H_
#define NEWACCOUNT_H_

#include "stdafx.h"
#include <iostream>

void showPrompt();
void commandValidityChecker();
void helpOutput();
void aboutOutput();
void quitProgram();
void createAccount();
void showOptionsAuth(std::string name);
void passwordSystem();
void usernameSystem();
int main();
int mainAuth();
void accountLogin();

class NewAccount {
private:
	std::string username;
	std::string password;
public:
	NewAccount();
};

#endif /* NEWACCOUNT_H_ */
