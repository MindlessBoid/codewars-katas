#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
int maxTriSum (std::vector <int> numbers)
{
  std::set<int> s(numbers.begin(), numbers.end());
  return std::accumulate(s.rbegin(), std::next(s.rbegin(), 3), 0);
}

/*
int maxTriSum (std::vector <int> numbers)
{
  std::sort(numbers.rbegin(), numbers.rend());
  std::unique(numbers.begin(), numbers.end());
return std::accumulate(numbers.begin(), numbers.begin() + 3, 0);
}
*/