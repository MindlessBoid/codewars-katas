#include <string>
#include <algorithm>

/*
class MaxRotate
{
public:
  static long long maxRot(long long n);
  static std::string rot(const std::string& str);
};

std::string MaxRotate::rot(const std::string& str)
{
  return str.substr(1) + str.front();
}

long long MaxRotate::maxRot(long long n)
{
  long long max = n;
  std::string str = std::to_string(n);
  for(size_t i = 0; i < str.length() - 2 && n > 1; i++)
  {
    str = str.substr(0, i) + rot(str.substr(i));
    max = (std::stoll(str) > max) ? std::stoll(str) : max;
  }
  return max;
}
*/
class MaxRotate
{
public:
  static long long maxRot(long long n);
};


long long MaxRotate::maxRot(long long n)
{
  
  std::string str = std::to_string(n);
  std::string max = str;
  for(size_t i = 0; i < str.length() - 1; i++)
  {
    std::rotate(str.begin() + i, str.begin() + i + 1, str.end());
    max = (str > max) ? str : max;
  }
  return std::stoll(max);