#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
  std::vector<int> result;
  size_t pos = word.find_first_of("aeiouyAEIOUY");
  while(pos != std::string::npos)
  {
    result.push_back(pos + 1);
    pos = word.find_first_of("aeiouyAEIOUY", pos + 1);
  }
  return result;
}