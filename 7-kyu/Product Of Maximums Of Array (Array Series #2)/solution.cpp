#include <vector>
#include <numeric>
#include <algorithm>

int maxProduct (std::vector<int>numbers , int sub_size)
{
  std::sort(numbers.begin(), numbers.end());
  return std::accumulate(numbers.rbegin(), std::next(numbers.rbegin(), sub_size), 1,
                        [](int init, int x)
                          {
                            return init *= x;
                          });
}