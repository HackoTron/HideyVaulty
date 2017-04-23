#include "stdafx.h"
#include <iostream>
#include "HideyVaultyFunctions.h"
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;

std::string CLI_input;

bool validCommand;

std::string username; //String variable in which inputted username is stored

std::string password; //String variable in which inputted password is stored

ofstream credentialFileWrite; //Object that allow credential files to be written to

// Outputs a list of all possible commands
void helpOutput() {
	std::cout << "help - Outputs all possible commands\n"
		"account - Takes an account option parameter, useless on its own\n"
		"\t--create\n"
		"\t--login\n"
		"clear - Clears the screen\n"
		"quit - Quits the program\n"
		"\n";
	showPrompt();
}

void aboutOutput() {
	//Text outputted when user selects the "About" option (temporary)
	std::cout << "Sorry, service not available\n" << std::endl;
	showPrompt();
}

// Function for quitting program
void quitProgram() {
	std::cout << "Are you sure you want to quit? (Y/N) > " << std::flush;
	getline(std::cin, CLI_input);
	if (CLI_input == "Y" || CLI_input == "y") {
		system("@echo off taskkill /f /im HideyVaulty.exe >nul");
	}
	else if (CLI_input == "N" || CLI_input == "n") {
		std::cout << std::endl;
		showPrompt();
		commandValidityChecker();
	}
	else {
		std::cout << '"' << CLI_input << '"' << " is not a valid option\n" << std::endl;
		quitProgram();
	}
}

void createAccount() {
	//Sets username to user input, and stores it in a file
	credentialFileWrite.open("username.txt");
	std::cout << "What would you like your username to be? > " << std::flush;
	getline(std::cin, username);
	credentialFileWrite << username;
	credentialFileWrite.close();

	//Sets password to user input, and stores in in a file
	credentialFileWrite.open("password.txt");
	std::cout << "What would you like your password to be? > " << std::flush;
	getline(std::cin, password);
	credentialFileWrite << password;
	credentialFileWrite.close();
	
	main();
}

void accountLogin() {
	usernameSystem();
	commandValidityChecker();
}
