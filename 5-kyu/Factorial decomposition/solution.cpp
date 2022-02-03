#include <string>
#include <vector>
std::string decomp(int n)
{
  /*
    Same ideal as primes decomposition
    Or using Sieve 
  */
  std::string result;
  std::vector<int> v;
  for(int i = 1; i <= n; i++) v.push_back(i);
  for(auto i: v) //should not be reference since refernce will be changed by changing j
  {
    if(i > 1)
    {
      int count = 0;
      for(auto& j: v)
      {
        while((j > 1) && (j%i == 0))
        {
          j /= i;
          count++;
        }
      }
      result += std::to_string(i) + (count == 1 ? "" : "^" + std::to_string(count)) + " * ";
    }
  }
  return result.substr(0, result.length() - 3);
}