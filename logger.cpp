#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include <stdlib.h>
#include <unistd.h>
#include "logger.h"

using namespace std;

int Logger::addmsg (list <data_t> &logMessages, string fileName) {
	string line;
	char thisType;
	data_t thisMessage;
	time_t t;

	ifstream myFile;
	myFile.open(fileName.c_str());
	
	if (myFile.is_open()) {
		while(getline (myFile, line)){
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
		return -1;
	}

	return 0;
}

int Logger::addmsgDelayed (list <data_t> &logMessages, string fileName, int sec) {
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
		return -1;
	}

	return 0;
}

void Logger::clearlog(list <data_t> &logMessages){
	logMessages.clear();
}

string Logger::getlog(string fileName) {
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
		return "failed";
	}

	return log;
}

int Logger::savelog(list<data_t> logMessages, string fileName) {
	list<data_t>::iterator it;
	time_t t;
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
		return -1;	
	}

	return 0;
}

