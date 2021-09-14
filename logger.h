#ifndef LOGGER_H
#define LOGGER_H

#include <list>
#include <string>

struct data_t {			//used as nodes for a list that holds each line of a text file
	time_t time;
	char type;
	std::string message;
};
class Logger {
	public:
		Logger () {
		}
		int addmsg(std::list<data_t> &, std::string, std::string);			
		int addmsgDelayed(std::list<data_t> &, std::string, int sec, std::string);
		void clearlog(std::list<data_t> &);
		std::string getlog(std::string, std::string);
		int savelog(std::list<data_t>, std::string, std::string);
};
#endif
