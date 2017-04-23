#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "HideyVaultyFunctions.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::getline;
std::string splashScreen;
std::string line;

std::string userInput;

void showSplash() { 
	std::cout <<
		" _   _ _     _            _   _             _ _                   \n"
		"| | | (_)   | |          | | | |           | | |                  \n"
		"| |_| |_  __| | ___ _   _| | | | __ _ _   _| | |_ _   _           \n"
		"|  _  | |/ _` |/ _ \\ | | | | | |/ _` | | | | | __| | | |         \n"
		"| | | | | (_| |  __/ |_| \\ \\_/ / (_| | |_| | | |_| |_| |        \n"
		"\\_| |_/_|\\__,_|\\___|\\__, |\\___/ \\__,_|\\__,_|_|\\__|\\__, |  \n"
		"                     __/ |                         __/ | * Built by Jack Williams 2017 \n";
	std::cout << "                    |___/                         |___/  * For a list of commands, type " << '"' << "help" << '"' << std::endl;
}

void showPrompt() {
	std::cout << "HideyVaulty Shell > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "") std::cout << std::endl;
}

void commandValidityChecker() {
	if (userInput == "help") {
		helpOutput();
		commandValidityChecker();
	}
	else if (userInput == "") {
		showPrompt();
		commandValidityChecker();
	}
	else if (userInput == "about") {
		aboutOutput();
		commandValidityChecker();
	}
	else if (userInput == "clear") {
		system("cls");
		showPrompt();
		commandValidityChecker();
	}
	else if (userInput == "quit") {
		quitProgram();
	}
	else if (userInput == "account --create") {
		createAccount();
		commandValidityChecker();
	}
	else if (userInput == "account --login") {
		accountLogin();
		commandValidityChecker();
	}
	else {
		std::cout << '"' << userInput << '"' << " is not a valid command\n" << std::endl;
		showPrompt();
		commandValidityChecker();
	}
}

void commandValidityCheckerAuth() {
	commandValidityChecker();
}

int main() {
	system("cls");
	system("title = HideyVaulty - Alpha 0.4");
	showSplash();

	for (int i = 0; i < 95; i++) {
		std::cout << "=" << std::flush;
	}

	std::cout << std::endl;

	showPrompt();
	commandValidityChecker();
	

	return 0;
}

int mainAuth() {
	system("cls");
	system("title = HideyVaulty - Alpha 0.4");
	showSplash();

	for (int i = 0; i < 95; i++) {
		std::cout << "=" << std::flush;
	}

	std::cout << std::endl;

	showPrompt();

	commandValidityCheckerAuth();

	return 0;
}