#include <vector>
#include <string>
std::vector<int> wordValue(std::vector <std::string> arr){
  std::vector<int> result;
  for(size_t i = 0; i < arr.size(); i++)
  {
    int strVal = 0;
    for(size_t j = 0; j < arr[i].size(); j++)
    {
      strVal += (arr[i][j] == ' ') ? 0 : arr[i][j] - 'a' + 1;
    }
    result.push_back(strVal * (i + 1));
  }
  return result;
}