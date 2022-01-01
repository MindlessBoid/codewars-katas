#include <string>
std::string pattern(int n){
  std::string result;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      result += std::to_string(i);
    }
    result +=  i < n ? "\n" : "" ;
  }
  return result;
}