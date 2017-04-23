/*
* LoginSystem.cpp
*
*  Created on: 26/03/2017
*      Author: HackoTron
*/
#include "stdafx.h"
#include "targetver.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "HideyVaultyFunctions.h"
#include <time.h>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main();
bool wantLogon;

NewAccount account1; //NewAccount object "account1"

ifstream credentialFileRead; //Object that allows credential files to be read from

std::string user; //String variable where the output from credentialFileRead is stored (used in usernameSystem)

std::string pass; //String variable where the output from credentialFileRead is stored (used in usernameSystem)

NewAccount::NewAccount() {
	username = "user";
	password = "user";
}

bool authenticated;

void authenticationChecker() {
	if (authenticated = true) {
		mainAuth();
	}
}

//System for checking if username is correct
void usernameSystem() {

	std::string inputUsername;
	do {
		std::cout << "Enter your username > " << std::flush;
		getline(std::cin, inputUsername);

		credentialFileRead.open("username.txt");
		credentialFileRead >> user;

		if (inputUsername == user) {
			credentialFileRead.close();
			break;
		}
		else {
			std::cout << "Enter a valid username > " << std::endl;
		}
	} while (true);

	passwordSystem();
}

//System for checking if password is correct
void passwordSystem() {

	std::string inputPassword;

	do {

		std::cout << "Enter your password > " << std::flush;
		getline(std::cin, inputPassword);

		credentialFileRead.open("password.txt");
		credentialFileRead >> pass;

		if (inputPassword == pass) {
			credentialFileRead.close();
			break;
		}
		else {
			std::cout << "Password incorrect" << std::endl;
		}
	} while (true);

	std::cout << "Password accepted" << std::endl;
	authenticated = true;
    
	authenticationChecker();
}

