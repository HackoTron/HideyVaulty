/*
* NewAccount.cpp
*
*  Created on: 26/03/2017
*      Author: JackEliteBook
*/
#include "stdafx.h"
#include "targetver.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "NewAccount.h"
#include <time.h>

int main();
bool wantLogon;
std::string username;
std::string password;
NewAccount account1;

NewAccount::NewAccount() {
	username = "user";
	password = "user";
}

std::string NewAccount::getUsername() {
	return username;
}

std::string NewAccount::getPassword() {
	return password;
}

void NewAccount::setCredentials(std::string inputUsername, std::string inputPassword) {
	username = inputUsername;
	password = inputPassword;

}

bool authenticated;

void showOptions() {

	std::cout << "Welcome to EpicLogin" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "1. Create an account" << std::endl;
	std::cout << "2. Login" << std::endl;
	std::cout << "3. About" << std::endl;
	std::cout << "4. Quit" << std::endl;

	std::cout << "\nEnter your selection here > " << std::flush;

	int option;
	std::cin >> option;

	switch (option) {
	case 1: 
		std::cout << "What would you like your username to be? > " << std::flush;
		std::cin >> username;

		std::cout << "What would you like your password to be? > " << std::flush;
		std::cin >> password;

		if (password == " ") {
			std::cout << "What would you like your password to be? > " << std::flush;
			std::cin >> password;
		}

		account1.setCredentials(username, password);
		wantLogon = true;
		Sleep(1000);
		system("cls");
		break;

	case 2: 
		std::cout << "Login service initializing ..." << std::endl;
		wantLogon = true;
		Sleep(1000);
		system("cls");
		break;
	

	case 3: 
		std::cout << "Sorry, service not available\n" << std::endl;
		Sleep(1000);
		system("cls");
		wantLogon = false;
		break;
	
	case 4: 
		std::cout << "Quitting program ..." << std::endl;
		Sleep(1000);
		system("taskkill /f /im BatchGenie.exe >nul");
		system("cls");
	

	default: 
		std::cout << '"' << option << '"' << " is not a valid option\n" << std::endl;
		Sleep(1000);
		system("cls");
		showOptions();
	}

	if (wantLogon == true) {
		usernameSystem();
	}
	else {
		main();
	}
}

void showOptionsAuth(std::string name) {
	std::cout << "Hello " << name << ", Welcome to EpicLogin" << std::endl;

	for (unsigned int i = 0; i < name.length(); i++) {
		std::cout << "=" << std::flush;

		std::cout << "============================" << std::endl;
		std::cout << "1. About" << std::endl;
		std::cout << "2. Logout" << std::endl;
		std::cout << "3. Quit" << std::endl;

		std::cout << "\nEnter your selection here > " << std::flush;

		int option;
		std::cin >> option;

		switch (option) {
		case 1: 
			std::cout << "Sorry, service currently not available" << std::endl;
			Sleep(1000);
			system("cls");
			break;
		
		case 2: 
			std::cout << "Logging out ... " << std::endl;
			authenticated = false;
			Sleep(1000);
			system("cls");
			break;
		
		case 3: 
			std::cout << "Quitting program ..." << std::endl;
			Sleep(1000);
			system("taskkill /f /im Password.exe >nul");
			system("cls");
		
		default: 
			std::cout << '"' << option << '"' << " is not a valid option\n" << std::endl;
			Sleep(1000);
			system("cls");
			showOptionsAuth(name);
		}

		if (authenticated == true) {
			showOptionsAuth(name);
		}
		else {
			showOptions();
		}
	}
}

void passwordSystem() {

	std::string inputPassword;

	do {

		std::cout << "Enter your password > " << std::flush;
		std::cin >> inputPassword;

		if (inputPassword == account1.getPassword()) {
			break;
		}
		else {
			std::cout << "Password incorrect" << std::endl;
		}
	} while (true);

	std::cout << "Password accepted" << std::endl;
	authenticated = true;

	std::string inputName;
	std::cout << "What would you like to be called? > " << std::flush;
	std::cin >> inputName;

	std::string name = inputName;

	system("cls");
	showOptionsAuth(name);
}

void usernameSystem() {

	std::string inputUsername;
	do {
		std::cout << "Enter your username > " << std::flush;
		std::cin >> inputUsername;

		if (inputUsername == account1.getUsername()) {
			break;
		}
		else {
			std::cout << "Enter a valid username > " << std::endl;
		}
	} while (true);

	passwordSystem();
}

