#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include <stdlib.h>
#include <unistd.h>
#include "logger.h"

using namespace std;

int Logger::addmsg (list <data_t> &logMessages, string fileName, string execName){	//adds messages from text file to list of data_t structs
	string line;
	char thisType;
	data_t thisMessage;
	time_t t;

	ifstream myFile;
	myFile.open(fileName.c_str());
	
	if (myFile.is_open()) {
		while(getline (myFile, line)){
			thisType = line.substr(0, line.find(" "))[0];			//takes first letter for error type
			line = line.substr(line.find(" ") + 1);				//remaining line
			thisMessage.type = thisType;
			thisMessage.message = line;
			time(&t);
			thisMessage.time = t;
			logMessages.push_back(thisMessage);
		}
		myFile.close();
	} else {									//send error to perror
		execName.append(": could not open file to read\n");
		const char *c = execName.c_str();
		perror (c);
		return -1;
	}

	return 0;
}

int Logger::addmsgDelayed (list <data_t> &logMessages, string fileName, int sec, string execName) {	//same as above, but with custom time delay
	string line;
	char thisType;
	data_t thisMessage;
	time_t t;

	int delay;
	srand (time(NULL));

	ifstream myFile;
	myFile.open(fileName.c_str());
	
	if (myFile.is_open()) {
		while(getline (myFile, line)){
			delay = rand() % (2 * sec);
			sleep(delay);

			thisType = line.substr(0, line.find(" "))[0];
			line = line.substr(line.find(" ") + 1);
			thisMessage.type = thisType;
			thisMessage.message = line;
			time(&t);
			thisMessage.time = t;
			logMessages.push_back(thisMessage);
		}
		myFile.close();
	} else {
		execName.append(": could not open file to read\n");
		const char *c = execName.c_str();
		perror(c);
		return -1;
	}

	return 0;
}

void Logger::clearlog(list <data_t> &logMessages){			//clears list
	logMessages.clear();
}

string Logger::getlog(string fileName, string execName) {		//takes output file and makes a string from text
	string log;
	string line;

	ifstream myFile;
	myFile.open(fileName.c_str());

	if (myFile.is_open()) {
		while(getline (myFile, line)) {
			log.append(line);
			log.append("\n");
		}
		myFile.close();
	} else {
		execName.append(": could not open file to read\n");
		const char *c = execName.c_str();
		perror(c);
		return "failed";
	}

	return log;
}

int Logger::savelog(list<data_t> logMessages, string fileName, string execName) {	//writes data from data_t list to output file
	list<data_t>::iterator it;
	time_t t;									//time used to conver data_t.time to readable format
	struct tm *localTime;
	ofstream myFile;
	myFile.open(fileName.c_str());

	if (myFile.is_open()) {
		for(it = logMessages.begin(); it != logMessages.end(); ++it) {	
			t = it->time;
			localTime = localtime(&t);

			int hour = localTime->tm_hour;
			int minute = localTime->tm_min;
			int second = localTime->tm_sec;

			myFile << it->type << " " << it->message << " ";
			myFile << hour << ":" << minute << ":" << second << "\n";
		}
		myFile.close();
	} else {
		execName.append(": could not open file to write\n");
		const char *c = execName.c_str();
		perror(c);
		return -1;	
	}

	return 0;
}

