#include <vector>
#include <numeric>
//use numeric
std::vector<int> between(int start, int end) {
  if(end >= start)
  {
    std::vector<int> result(end - start + 1);
    std::iota(result.begin(), result.end(), start);
    return result;
  }
  return {};
}  
//not using numeric
/*std::vector<int> between(int start, int end) {
  std::vector<int> result;
  for(int i = start; i <= end; i++)
    result.push_back(i);
  return result;
}*/  