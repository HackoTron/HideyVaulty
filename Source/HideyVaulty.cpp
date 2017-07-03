//---------------------------------------------------\\
// Name - HideyVaulty - Open-source File-hider       \\
// Description - Software for hiding files on a      \\
// remote system                                     \\
// Author - Jack Williams (HackoTron)	             \\
// Note - If this software is used for any immoral   \\
// or malicious purpose, I (Jack Williams) will not  \\
// be reponsible. Enjoy!                             \\
//---------------------------------------------------\\

#include "HideyVaultyShell.h"

Shell *shellMain = new Shell();

std::string userInput;

int main() {
	system("cls");
	system("title HideyVaulty - Beta 0.7");
	system("mode con: lines=40 cols=108");

	shellMain->showSplash();
	shellMain->setup();
	
	return 0;
}

int mainAuth() {
	ShellAuth *shellMainAuth = new ShellAuth();

	system("cls");
	system("title HideyVaulty - Beta 0.7");


	shellMainAuth->showSplash();
	shellMainAuth->showPromptAuth();

	return 0;
}
