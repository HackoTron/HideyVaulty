
#ifndef HIDEYVAULTYSHELL_H
#define HIDEYVAULTYSHELL_H
#define NOMINMAX

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::getline;

class Shell {
private:
	std::string user; 
	std::string pass; 
	std::string splashScreen;
	std::string line;
	std::string CLI_input;

public:
	std::string userInput;
	std::string globalUsername;
	
private:
	ifstream credentialFileRead; 
	ofstream credentialFileWrite;

	bool authenticated;
	bool wantLogon;
	bool validCommand;

public:
	Shell() {}
	void setup();
	void showSplash();
	void showPrompt();
	void commandValidityChecker(std::string userInput);
	void helpOutput();
	void aboutOutput();
	void quitProgram();
	void createAccount();
	void passwordSystem();
	void usernameSystem();
	void accountLogin();
	void authenticationChecker();
	void loginInit();
};

class ShellAuth : public Shell {
public:
	ShellAuth() {}
	void showSplashAuth();
	void loginInitAuth();
	void accountLoginAuth();
	void helpOutputAuth();
	void showPromptAuth();
	void commandValidityCheckerAuth(std::string userInput);
	void dirCommand();
	void aboutOutputAuth();
	void quitProgramAuth();
};
#endif /* HIDEYVAULTYSHELL_H */
