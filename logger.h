#ifndef LOGGER_H
#define LOGGER_H

#include <list>
#include <string>

struct data_t {
	time_t time;
	char type;
	std::string message;
};
class Logger {
	public:
		Logger () {
		}
		int addmsg(std::list<data_t> &, std::string);
		int addmsgDelayed(std::list<data_t> &, std::string, int sec);
		void clearlog();
		std::string getlog(std::string);
		int savelog(std::list<data_t>, std::string);
};
#endif
