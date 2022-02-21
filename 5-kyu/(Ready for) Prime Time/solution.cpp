#include <vector>

/*
std::vector<unsigned> prime(unsigned n){
  //this can be solve by the fact every composite number can be written as product of one or more prime
  std::vector<unsigned> result = {2};
  for(unsigned i = 2; i <= n; i++)
  {
    bool isPrime = true;
    for(auto p: result)
    {
      if(i % p == 0) isPrime = false;
    }
    if(isPrime) result.push_back(i);
  }
  return n > 1 ? result : std::vector<unsigned>{};
  
}  
*/

std::vector<unsigned> prime(unsigned n){
  std::vector<bool> sieve(n+1, true);
  //only need to check up to sqrt(p) since the pattern repeat after sqrt(p)
  for(int p = 2; p*p <= n; p++)
  {
    if(sieve[p])
    {  
      //all multiple of p that that smaller than p^2 is already crossed out
      //so the smallest multiple of p that is not crossed out should be p^2
      for(int i = p*p; i <= n; i += p)
        sieve[i] = false;
    }
  }
  std::vector<unsigned> result;
  for(int i = 2; i <= n; i++)
  {
    if(sieve[i] == true) result.push_back(i);
  }
  return result;
}