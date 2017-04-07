/*
* NewAccount.h
*
*  Created on: 26/03/2017
*      Author: JackEliteBook
*/

#ifndef NEWACCOUNT_H_
#define NEWACCOUNT_H_

#include "stdafx.h"

#include <iostream>

void showOptions();
void showOptionsAuth(std::string name);
void passwordSystem();
void usernameSystem();

class NewAccount {
private:
	std::string username;
	std::string password;
public:
	NewAccount();
	std::string getUsername();
	std::string getPassword();
	void setCredentials(std::string inputUsername, std::string inputPassword);
};

#endif /* NEWACCOUNT_H_ */
