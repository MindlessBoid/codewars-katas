#include <vector>
#include <string>
#include <numeric>

/*
std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
{
 std::vector<std::pair<std::string, std::string>> result;
  for(size_t i = 0; i < arr.size() - 1; i++)
  {
      std::string str1 = arr[0];
      for(size_t i1 = 1; i1 <= i; i1++)
      {
        str1 += " " + arr[i1];
      }
      
      std::string str2 = arr[i + 1];
      for(size_t i2 = i + 2; i2 < arr.size(); i2++)
      {
        str2 += " " + arr[i2];
      }
      
      result.push_back(std::make_pair(str1, str2));
  }
  return result;
}
*/

/*Using numeric*/
std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
{
 std::vector<std::pair<std::string, std::string>> result;
 auto comp = [](std::string s1, std::string s2){return s1 + " " + s2;};
  for(size_t i = 1; i < arr.size(); i++)
  {
      result.push_back(std::make_pair(
        std::accumulate(arr.begin() + 1, arr.begin() + i, arr[0], comp),
        std::accumulate(arr.begin() + i + 1, arr.end(), arr[i], comp)
      ));
  }
  return result;
}