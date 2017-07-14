
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

enum class LogType {
    DBG,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    Logger(LogType);
    void put(std::string);
    static void setLogFile(std::string);
protected:
    Logger();
    void _log(std::ostream &, std::string &, bool);
    static std::ofstream fout;
    LogType logType;
};

#endif
