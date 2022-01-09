#include<vector>

/*
#include <set>
#include <numeric>
int solve (std::vector<int> v){
  std::set s(v.begin(), v.end());
  return std::accumulate(s.begin(), s.end(), 0);
}
*/

#include <algorithm>
#include <numeric>
#include <cmath>
int solve (std::vector<int> v){
    //sum + 1 if positive, - 1 if positive, the pair will cancel themselves out, the rest is the count of single-positive/negative
    return std::accumulate(v.begin(), v.end(), 0) / abs(std::accumulate(v.begin(), v.end(), 0, [](int i, int j){return i + (j > 0 ? 1 : -1);}));
}