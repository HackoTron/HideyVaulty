#include "stdafx.h"
#include "HideyVaultyShell.h"
#include <iostream>

int main();
int mainAuth();

Shell *shell = new Shell();

// Places required files in the necessary locations
void Shell::setup() {
	int dirOutput = system("dir resources > nul 2> nul");

	if (dirOutput == 1) {
		std::cout << "It appears you haven't setup HideyVaulty! Would you like to set it up? (Y/N) > " << std::flush;
		getline(std::cin, userInput);
		if (userInput == "Y" || userInput == "y") {
			system("mkdir resources, files");
			std::cout << "Creating directories ... \n"
				"Done." << std::endl;
			std::cout << '\n';
			shell->showPrompt();
		}
		else if (userInput == "N" || userInput == "n") {
			std::cout << std::endl;
			shell->showPrompt();
			commandValidityChecker(userInput);
		}
		else {
			std::cout << '"' << userInput << '"' << " is not a valid option.\n" << std::endl;
			shell->setup();
		}
	}
	else if (dirOutput == 0) {
		shell->showPrompt();
	}
	std::cout << "An error has occurred! Please restart the program. \n" << std::endl;
}

// Function that outputs and ASCII based splash screen
void Shell::showSplash() {
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
void Shell::showPrompt() {
	std::cout << "HideyVaulty Shell > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "") std::cout << std::endl;
	commandValidityChecker(userInput);
}

// System for checking if command is valid
void Shell::commandValidityChecker(std::string userInput) {
	if (userInput == "help") {
		shell->helpOutput();
		commandValidityChecker(userInput);
	}
	else if (userInput == "") {
		shell->showPrompt();
		commandValidityChecker(userInput);
	}
	else if (userInput == "about") {
		shell->aboutOutput();
		commandValidityChecker(userInput);
	}
	else if (userInput == "clear") {
		system("cls");
		shell->showPrompt();
		commandValidityChecker(userInput);
	}
	else if (userInput == "quit") {
		shell->quitProgram();
	}
	else if (userInput == "account --create") {
		shell->createAccount();
		commandValidityChecker(userInput);
	}
	else if (userInput == "account --login") {
		shell->accountLogin();
		commandValidityChecker(userInput);
	}
	else {
		std::cout << '"' << userInput << '"' << " is not a valid command.\n" << std::endl;
		shell->showPrompt();
		commandValidityChecker(userInput);
	}
}

// System for creating a user account
void Shell::createAccount() {
	//Sets username and password to user input, and stores it in a file
	credentialFileWrite.open("resources/credentials.txt");

	std::cout << "What would you like your username to be? > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "") {
		std::cout << "You must enter a username!\n" << std::endl;
		shell->createAccount();
	}
	credentialFileWrite << userInput << std::endl;

	while (true) {
		std::cout << "What would you like your password to be? > " << std::flush;
		getline(std::cin, userInput);
		if (userInput == "") {
			std::cout << "You must enter a password!\n" << std::endl;
		}
		else {
			break;
		}
	}
	credentialFileWrite << userInput;

	credentialFileWrite.close();

	system("cd ..");
	system("cls");
	shell->showSplash();
	shell->showPrompt();

}

// System for initializing the account login process
void Shell::loginInit() {
	int dirOutput = system(" dir resources | findstr credentials.txt >nul");
	if (dirOutput == 0) {
		shell->usernameSystem();
	}
	std::cout << "You have not created an account. Type \"account --create\" to fix this.\n" << std::endl;
	shell->showPrompt();
}

// System for checking if username is correct
void Shell::usernameSystem() {
	std::string inputUsername;

	do {
		std::cout << "Enter your username > " << std::flush;
		getline(std::cin, inputUsername);

		credentialFileRead.open("resources/credentials.txt");
		credentialFileRead >> user;

		if (inputUsername == user) {
			credentialFileRead.close();
			break;
		}
		else {
			std::cout << "Enter a valid username > " << std::endl;
		}
	} while (true);

	shell->passwordSystem();
}

// System for checking if password is correct
void Shell::passwordSystem() {
	std::string inputPassword;
	std::string line;

	do {

		std::cout << "Enter your password > " << std::flush;
		getline(std::cin, inputPassword);

		credentialFileRead.open("resources/credentials.txt");
		credentialFileRead.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(credentialFileRead, pass);

		if (inputPassword == pass) {
			credentialFileRead.close();
			delete shell;
			break;
		}
		else {
			std::cout << "Password incorrect" << std::endl;
		}
	} while (true);

	authenticated = true;

	shell->authenticationChecker();
}

// System for checking if user is authenticated
void Shell::authenticationChecker() {
	if (authenticated = true) {
		mainAuth();
	}
}

// Account login system
void Shell::accountLogin() {
	shell->loginInit();
	commandValidityChecker(userInput);
}

// Function for the "help" command
void Shell::helpOutput() {
	std::cout << "help - Displays all possible commands.\n"
		"account - Takes an account option parameter, useless on its own.\n"
		"\t--create\n"
		"\t--login\n"
		"clear - Clears the screen.\n"
		"quit - Quits the program.\n"
		"\n";
	shell->showPrompt();
}

// Function for the "about" command
void Shell::aboutOutput() {
	//Text outputted when user selects the "About" option (temporary)
	std::cout << "Sorry, service not available\n" << std::endl;
	shell->showPrompt();
}

// Function for the "quit" command
void Shell::quitProgram() {
	std::cout << "Are you sure you want to quit? (Y/N) > " << std::flush;
	getline(std::cin, userInput);
	if (userInput == "Y" || userInput == "y") {
		delete shell;
		exit(0);
	}
	else if (userInput == "N" || userInput == "n") {
		std::cout << std::endl;
		shell->showPrompt();
		commandValidityChecker(userInput);
	}
	else {
		std::cout << '"' << userInput << '"' << " is not a valid option.\n" << std::endl;
		shell->quitProgram();
	}
}

