#include <vector>
std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  std::vector<int> v;
  for(auto i: arr)
  {
    if(i%2 == 0) v.push_back(i);
  }
  return std::vector<int>(v.begin() + v.size() - n, v.end());
}