#include <vector>
#include <algorithm>
std::vector<int> solve(const std::vector<int> &vec) 
{
  std::vector<int> result(vec);
  std::sort(result.begin(), result.end(), [&](int x, int y)
                                            {
                                              //can use one loop to find both countX and countY
                                              int countX = std::count(vec.begin(), vec.end(), x);
                                              int countY = std::count(vec.begin(), vec.end(), y);
                                             
                                              if(countX == countY) return x < y;
                                              return countX > countY;
                                            });
  return result;  
}
