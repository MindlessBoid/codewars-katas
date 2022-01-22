#include <vector>
#include <string>
#include <algorithm>


std::vector<float> to_float_array(const std::vector<std::string>& arr) {
  std::vector<float> result;
  for(const auto& str: arr)
  {
    result.push_back(std::stof(str));
  }
  return result;
}
/* using algorithm
std::vector<float> to_float_array(const std::vector<std::string>& arr) {
  std::vector<float> result(arr.size());
  std::transform(arr.begin(), arr.end(), result.begin(), [](std::string str)
                 {
                   return stof(str);
                 });
  return result;
}
*/