#include <iostream>
#include <string.h>
#include <list>
#include <stdlib.h>
#include "logger.h"

using namespace std;

int argHandler(int argc, char* argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {
			cout << "Help\n";
			return -1;
		}else if (strcmp(argv[1], "-t") == 0) {
			return 2;
		}else {
			return 1;
		}
	} else {
		return 0;
	}

}

int main(int argc, char* argv[]) {
	Logger logger;
	string writeName;
	list<data_t> logMessages;	

	switch(argHandler(argc, argv)) {
		case -1:
			return 0;
		case 0:
			logger.addmsg(logMessages, "test.txt");
			logger.savelog(logMessages, "savelog.txt");
			cout << logger.getlog("savelog.txt");
			logger.clearlog(logMessages);
			break;
		case 1:
			writeName = argv[1];
			logger.addmsg(logMessages, "test.txt");
			logger.savelog(logMessages, writeName);
			cout << logger.getlog(writeName);
			logger.clearlog(logMessages);
			break;
		case 2:
			logger.addmsgDelayed(logMessages, "test.txt", atoi(argv[2]));
			logger.savelog(logMessages, "savelog.txt");
			cout << logger.getlog("savelog.txt");
			logger.clearlog(logMessages);
			break;
	}

	return 0;
}
