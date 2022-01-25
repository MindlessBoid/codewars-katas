#include <vector>
std::vector<int> incrementer(std::vector<int> nums){
  int i = 1;
  for(auto& n: nums) n = (n + (i++))%10;
  return nums;
}