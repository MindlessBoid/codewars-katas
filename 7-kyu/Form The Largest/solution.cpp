#include <string>
#include <algorithm>

long long int maxNumber (long long int  number) 
{
    std::string str = std::to_string(number);
    std::sort(str.rbegin(), str.rend());
    return std::stoll(str);
}