#include <vector>
#include <unordered_set>

/*
std::vector<int> solve(std::vector<int> vec){    
  std::vector<int> result;
  for(auto it = vec.rbegin(); it != vec.rend(); it++)
  {
    bool isAdded = false;
    for(auto i: result)
    {
      if(*it == i)
      {
        isAdded = true;
        break;
      }  
    }
    if(!isAdded) result.push_back(*it);
  }
  return {result.rbegin(), result.rend()};
}
*/

std::vector<int> solve(std::vector<int> vec){    
  std::unordered_set<int> set(vec.rbegin(), vec.rend());
  return {set.begin(), set.end()};
}