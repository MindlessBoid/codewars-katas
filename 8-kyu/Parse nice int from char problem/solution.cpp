#include <string>
int get_age(const std::string& she_said) {
    return she_said.front() - '0';
}