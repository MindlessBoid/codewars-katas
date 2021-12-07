#include <string>

int deleteDigit(int n)
{
  int max = 0;
  const std::string str1 = std::to_string(n);
  for(size_t i = 0; i < str1.length(); i++)
  {
    std::string str2 = str1;
    str2.erase(i, 1);
    max = (std::stoi(str2) > max) ? std::stoi(str2) : max;
  }
  return max;
}