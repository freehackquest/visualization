
#include "inputThread.h"
#include <iostream>

void InputThread::run(){
	for (std::string line; std::getline(std::cin, line);) {
		std::cout << line << std::endl;
	}
};
