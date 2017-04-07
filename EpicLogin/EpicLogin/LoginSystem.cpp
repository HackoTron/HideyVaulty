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
#include "NewAccount.h"
#include <time.h>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main();
bool wantLogon;

std::string username; //String variable in which inputted username is stored

std::string password; //String variable in which inputted password is stored

NewAccount account1; //NewAccount object "account1"

int option; //Integer variable in which the inputted option is stored (used in functions showOptions() and showOptionsAuth()) 

ifstream credentialFileRead; //Object that allows credential files to be read from

ofstream credentialFileWrite; //Object that allow credential files to be written to

std::string user; //String variable where the output from credentialFileRead is stored (used in usernameSystem)

std::string pass; //String variable where the output from credentialFileRead is stored (used in usernameSystem)

NewAccount::NewAccount() {
	username = "user";
	password = "user";
}

bool authenticated;


//Shows the login options
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

	//Options listed in function "showOptions"
	switch (option) {
	case 1:
		//Sets username to user input, and stores it in a file
		credentialFileWrite.open("username.txt");
		std::cout << "What would you like your username to be? > " << std::flush;
		std::cin >> username;
		credentialFileWrite << username;
		credentialFileWrite.close();

		//Sets password to user input, and stores in in a file
		credentialFileWrite.open("password.txt");
		std::cout << "What would you like your password to be? > " << std::flush;
		std::cin >> password;
		credentialFileWrite << password;
		credentialFileWrite.close();

		wantLogon = true;
		Sleep(1000);
		system("cls");
		break;

	case 2:
		//Loading text for login dialog
		std::cout << "Login service initializing ..." << std::endl;
		wantLogon = true;
		Sleep(1000);
		system("cls");
		break;


	case 3:
		//Text outputted when user selects the "About" option (temporary)
		std::cout << "Sorry, service not available\n" << std::endl;
		Sleep(1000);
		system("cls");
		wantLogon = false;
		break;

	case 4:
		//Code for quitting program
		std::cout << "Quitting program ..." << std::endl;
		Sleep(1000);
		system("taskkill /f /im EpicLogin.exe >nul");
		system("cls");


	default:
		//Code run if option is invalid
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

//Options for authenticated users
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
			//Text outputted when user selects the "About" option (temporary)
			std::cout << "Sorry, service currently not available" << std::endl;
			Sleep(1000);
			system("cls");
			break;

		case 2:
			//Loading text for logout dialog
			std::cout << "Logging out ... " << std::endl;
			authenticated = false;
			Sleep(1000);
			system("cls");
			break;

		case 3:
			//Code for quitting program
			std::cout << "Quitting program ..." << std::endl;
			Sleep(1000);
			system("taskkill /f /im EpicLogin.exe");
			system("cls");

		default:
			//Code run if option is invalid
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

//System for checking if password is correct
void passwordSystem() {

	std::string inputPassword;

	do {

		std::cout << "Enter your password > " << std::flush;
		std::cin >> inputPassword;

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

	std::string inputName;
	std::cout << "What would you like to be called? > " << std::flush;
	std::cin >> inputName;

	std::string name = inputName;

	system("cls");
	showOptionsAuth(name);
}

//System for checking if username is correct
void usernameSystem() {

	std::string inputUsername;
	do {
		std::cout << "Enter your username > " << std::flush;
		std::cin >> inputUsername;

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

