#include <string>
#include <vector>
#include <set>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst);
    static std::set<int> findPrimeFactors(std::vector<int>& nums);
};
std::set<int> SumOfDivided::findPrimeFactors(std::vector<int>& nums)
{
  std::set<int> result;
  for(auto n: nums)
  {
    n = (n>0) ? n : -n;
    std::vector<int> factors;

    //deal with 2
    if(n%2 == 0) factors.push_back(2);
    while(n%2 == 0) n/=2;

    //deal with odd factors
    for(int i = 3; i*i <= n; i+=2)
    {
      if(n%i == 0) factors.push_back(i);
      while(n%i == 0) n/=i;
    }
    
    //border case
    if(n > 2) factors.push_back(n);

    for(auto f: factors) result.insert(f);
  }
  return result;
}

std::string SumOfDivided::sumOfDivided(std::vector<int> &lst)
{
  std::set<int> primes = findPrimeFactors(lst);
  std::string result;
  for(auto p: primes)
  {
    int sum = 0;
    for(auto i: lst)
    {
      if(i%p == 0) sum += i;
    }
    result += "(" + std::to_string(p) + " " + std::to_string(sum) + ")";
  }
  return result;
}
