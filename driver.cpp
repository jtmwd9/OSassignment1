/*
James Markus
9/13/2021
Operating Systems

Driver for a logging utility. Takes info from a text file, logs it to another text file.
To be used later as an error logging tool

logger.h, logger.cpp, test.txt
 */

#include <iostream>
#include <string.h>
#include <list>
#include <stdlib.h>
#include "logger.h"

using namespace std;

int argHandler(int argc, char* argv[]) {		//codes the types of arguments for use later
	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {	//help
			cout << "Help\n";
			return -1;
		}else if (strcmp(argv[1], "-t") == 0) {	//custom time delay
			return 2;
		}else {					//custom file name
			return 1;
		}
	} else {					//no arguments
		return 0;
	}

}

int main(int argc, char* argv[]) {
	Logger logger;
	string writeName;
	list<data_t> logMessages;
	string execName = argv[0];	

	switch(argHandler(argc, argv)) {		//decides what to do in case of each argument type
		case -1:
			return 0;
		case 0:
			logger.addmsg(logMessages, "test.txt", execName);
			logger.savelog(logMessages, "savelog.txt", execName);
			cout << logger.getlog("savelog.txt", execName);
			logger.clearlog(logMessages);
			break;
		case 1:
			writeName = argv[1];
			logger.addmsg(logMessages, "test.txt", execName);
			logger.savelog(logMessages, writeName, execName);
			cout << logger.getlog(writeName, execName);
			logger.clearlog(logMessages);
			break;
		case 2:
			logger.addmsgDelayed(logMessages, "test.txt", atoi(argv[2]), execName);
			logger.savelog(logMessages, "savelog.txt", execName);
			cout << logger.getlog("savelog.txt", execName);
			logger.clearlog(logMessages);
			break;
	}

	return 0;
}
