#include <vector>

/*
int pairs(std::vector<int>arr){
  int count = 0;
  for(size_t i = 0; i < arr.size() / 2; i++)
  {
    int diff = arr[i*2] - arr[i*2 + 1];
    if(diff == -1 || diff == 1)  count++;
  }
  return count;
}
*/
int pairs(std::vector<int>arr){
  auto count = 0;
  for(size_t i = 0; i < arr.size() - 1; i += 2)
  {
    int diff = arr[i] - arr[i+1];
    if(diff == 1 || diff == -1) count++;
  }
  return count;
}