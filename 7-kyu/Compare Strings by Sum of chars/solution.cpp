#include <string>
#include <ctype.h>

bool compare(std::string s1, std::string s2)
{
  int sum = 0;
  for(auto c: s1)
  {
    if(isalpha(c)) sum += toupper(c);
    else
    {
      sum = 0;
      break;
    }
  }
  for(auto c: s2)
  {
    if(isalpha(c)) sum -= toupper(c);
    else
    {
      sum = 0;
      break;
    }
  }
  return sum == 0;
}