/*
#include <string>

int calc(const std::string& x) {
  long long result = 0;
  for(auto c: x)
  {
    while(c > 0)
    {
      result += (c%10 == 7) ? 6 : 0; 
      c/=10;
    }
  }
  return result;
}
*/
#include <string>

int calc(const std::string& x) {
  long long result = 0;
  for(auto c: x)
  {
    result += (c%10 == 7 ? 6 : 0) + (c/10 == 7 ? 6 :0);
  }
  return result;
}