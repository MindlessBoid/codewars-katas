#include <string>
#include <vector>

std::vector<int> digitize(int n) {
  std::vector<int> result;
  if(n == 0) result.push_back(0);
  while(n != 0)
  {
    result.push_back(n%10);
    n/=10;
  }
  return std::vector<int>(result.rbegin(), result.rend());
}

/* Using string
std::vector<int> digitize(const int& n) {
  std::string str = std::to_string(n);
  std::vector<int> result;
  for(auto c : str) result.push_back(c - '0');
  return result;
}
*/