#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls)
    {
      if(ls.size() < k) return -1;
      
      std::vector<int> bitmask(k, 1);
      bitmask.resize(ls.size(), 0);
      int bestSum = -1;
      do
      {
        int sum = 0;
        for(size_t i = 0; i < ls.size(); i++)
        {
          sum += (bitmask[i] == 1) ? ls[i] : 0;
        }
        bestSum = (sum > bestSum && sum <= t) ? sum : bestSum;
      }while(std::prev_permutation(bitmask.begin(), bitmask.end()));
      return bestSum;
    }
  
};

/* Different ways to generate combinations*/
// Using std::prev_permutation
void genCombinations(const std::string& str, int k)
{
  // bitmask size k and filled with 1, each bit represents the states (used or not) of each character of str 
  std::string bitmask(k, 1);
  //resize to n and filled the rest with 0
  bitmask.resize(str.length(), 0);
  //using prev_permuation because the 1st combination for example 11100 the largest in lexicographical order
  std::vector<std::string> combs;
  do
  {
    std::string comb;
    for(size_t i = 0; i < str.length(); i++)
    {
      if(bitmask[i] == 1) comb.push_back(str[i]);
    }
    combs.push_back(comb);
    std::cout<<comb<<", ";
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
  std::cout<<"\nNum combinations: "<<combs.size()<<'\n';
}

// Recursion
void genCombinations(std::string lhs, std::string rhs, int k, std::vector<std::string>& result)
{
  /* 
    comb({abcd}, 3) = {a, comb({bcd}, 2)} and {b, comb({cd}, 2)} and {c, comb({d}, 2)} = ...
                       lhs, rhs                lhs, rhs               lhs, rhs 
  */
  //base condidtion
  if(k==1)
  {
    for(auto i: rhs) result.push_back(lhs + i);
  }
  else
  {
    for(size_t i = 0; i <= rhs.length() - k; i++)
    {
      genCombinations(lhs + rhs[i], rhs.substr(i+1), k-1, result);
    }
  }
}
