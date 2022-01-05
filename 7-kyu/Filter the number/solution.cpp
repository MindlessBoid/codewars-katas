#include <string>

long long filter_string(const std::string &value)
{
  std::string str;
  for(const auto& i: value)
  {
    if(isdigit(i)) str.push_back(i);
  }
  return std::stoll(str);
}