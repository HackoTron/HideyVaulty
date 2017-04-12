#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "NewAccount.h"

using namespace std;

int main() {
	std::cout << " _____      _      _                 _       \n"
	             "|  ___|    (_)    | |               (_)      \n" 
		         "| |__ _ __  _  ___| |     ___   __ _ _ _ __  \n" 
		         "|  __| '_ \\| |/ __| |    / _ \\ / _` | | '_ \\ \n"
		         "| |__| |_) | | (__| |___| (_) | (_| | | | | |\n"
		         "\\____/ .__/|_|\\___\\_____/\\___/ \\__, |_|_| |_|\n"
		         "     | |                        __/ |        \n"
		         "     |_|                       |___/         \n" << std::endl;
	
	Sleep(5000);
	system("cls");
	
	showOptions();

	return 0;
}
