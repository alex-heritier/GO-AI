
#include <iostream>
#include <fstream>
#include <ctime>

#include "Utility.h"

std::ofstream Logger::fout;

Logger::Logger(LogType logType): logType(logType) {}

// sets the log file to use in Log::show
void Logger::setLogFile(std::string filename)
{
    Logger::fout.open(filename, std::ios::out | std::ios::app);
}

// calls _log with the appropriate data
void Logger::put(std::string msg)
{
    bool shouldWriteToFile = false;
    std::ostream *out = &std::cout;
    switch (logType) {
        case LogType::DBG:
            msg.insert(0, "DEBUG: ");
            break;
        case LogType::INFO:
            msg.insert(0, "INFO: ");
            break;
        case LogType::WARN:
            msg.insert(0, "WARN: ");
            break;
        case LogType::ERROR:
            out = &std::cerr;
            msg = "ERROR: Log::show template parameter must be of type Log::Type.";
            shouldWriteToFile = true;
            break;
        default:
            break;
    }
    _log(*out, msg, shouldWriteToFile);
}

// writes logging data to the screen and to logging file
void Logger::_log(std::ostream &out, std::string &msg, bool shouldWriteToFile)
{
    time_t rawtime;
    struct tm *timeinfo;
    constexpr int buffer_size = 64;
    char buffer[buffer_size] = {'\0'};

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, buffer_size, "%X", timeinfo);

    std::string logMsg(buffer, buffer_size);
    logMsg += " ";
    logMsg += msg;

    out << logMsg << std::endl;
    if (shouldWriteToFile) {
        Logger::fout << logMsg << std::endl;
    }
}
