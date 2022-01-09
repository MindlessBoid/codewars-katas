#include <string>

std::string pattern(int n){
  std::string result;
  std::string buff;
  for(int i = n; i > 0; i--)
  {
    buff += std::to_string(i);
    result = (i > 1 ? "\n" : "") + buff + result;
  }
  return result;