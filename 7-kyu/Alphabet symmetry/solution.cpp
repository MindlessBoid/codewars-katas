#include <vector>
#include <string>
#include <algorithm>

std::vector<int> solve(const std::vector<std::string>& arr) {  
    std::vector<int> result;
    for(auto& str:  arr)
    {
      int count = 0;
      for(size_t i = 0; i <= str.length(); i++)
      {
        if(tolower(str[i]) - 'a' == i) count++;
      }
      result.push_back(count);
    }
    return result;
};

/* nah
std::vector<int> solve(const std::vector<std::string>& arr) {  
  std::vector<int> result;
  for(auto& str: arr)
  {
    size_t i = 0;
    result.push_back(std::count_if(str.begin(), str.end(),
                    [&](char c)
                    {
                      return (tolower(c) - 'a' == i++);
                    }));
  }
  return result;
}
*/

