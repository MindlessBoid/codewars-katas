#include <cstdint>
#include <algorithm>
#include <vector>
uint64_t hamber(int n)
{
  std::vector<uint64_t> v(n, 0);
  v[0] = 1;
  // index_n stores index where the value at this index is a previous min
  // and hasnt been multiplied with n at CURRENT iteration
  // for each index_n * n and find the min
  // e,g. index_2 = 1 , index_3 = 1, index_5 = 0, v = {1, 2}
  // v[index_2]*2 = 4 < v[index_5]*5 = 5 < v[index_3]*3 = 6
  // Hence v = {1, 2, 4}
  
  // This is better than using one variable to store min => may occrur: current min > last min * n , where n = 2,3,5

  size_t index_2 = 0, index_3 = 0, index_5 = 0;

  for(size_t i = 1; i < n; i++)
  {
    // find min
    uint64_t val_2 = v[index_2] * 2;
    uint64_t val_3 = v[index_3] * 3;
    uint64_t val_5 = v[index_5] * 5;
    v[i] = std::min(std::min(val_2, val_3), val_5);
    // should be if not else-if -> prevent duplicate 2*3 = 3*2
    if(v[i] == val_2) index_2++;
    if(v[i] == val_3) index_3++;
    if(v[i] == val_5) index_5++;
  }
  return v[n-1];
}