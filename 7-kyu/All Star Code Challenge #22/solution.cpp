#include <string>

std::string to_time(unsigned seconds) {
    //return std::to_string(seconds/3600) + " hour(s) and " + std::to_string(seconds/60%60) + " minute(s)";
    return std::to_string(seconds/3600) + " hour(s) and " + std::to_string(seconds%3600/60) + " minute(s)";
}

