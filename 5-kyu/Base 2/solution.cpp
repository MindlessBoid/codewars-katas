#include <string>

class Negabinary{
public:
  static std::string ToNegabinary(int i);
  static int ToInt(std::string s); 
};
std::string Negabinary::ToNegabinary(int i)
{
  //https://en.wikipedia.org/wiki/Negative_base
  // a = (-r)c + d, where r = 2 is base, c is quotient, and d is remainder which CANT be negative
  // a = (−r)c + d − r + r = (−r)(c + 1) + (d + r). since |d| < r, d + r > 0 
  std::string result;
  while(i != 0)
  {
    int remainder = i%(-2);
    i /= -2;
    if(remainder < 0)
    {
      remainder += 2;
      i += 1;
    }
    result = std::string(1, remainder + '0') + result;
  }
  return result.empty() ? "0" : result;
}
int Negabinary::ToInt(std::string s)
{
  int result = 0;
  int n = 1;
  for(auto it = s.rbegin(); it != s.rend(); it++)
  {
    result += (*it - '0') * n;
    n *= -2;
  }
  return result;
}