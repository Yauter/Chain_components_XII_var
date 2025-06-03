#include "Logger.hpp"
#include <fstream>

void Logger::log(const std::string& message) {
    std::ofstream log("log.txt", std::ios::app);
    log << message << std::endl;
}
