#include <vector>

// ideal: "Counting the Change Combination" kata
using ull = unsigned long long;

ull exp_sum(unsigned int n) {
  std::vector<ull> ways(n + 1);
  ways[0] = 1; //base condition
  for(int i = 1; i <=n; i++)
  {
    for(size_t j = 0; j < ways.size(); j++)
    {
      if(i <= j) ways[j] += ways[j - i];
    }
  }
  return ways.back();
}