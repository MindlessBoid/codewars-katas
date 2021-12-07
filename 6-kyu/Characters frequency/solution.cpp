#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <ctype.h> //for tolower
std::vector<std::pair<char, std::size_t>> letter_frequency(const std::string& input) 
{
  //table for keep track of lower case characters
  int counts['z'-'a'+1] = {0};
  for(auto c: input)
  {
    c = tolower(c);
    if(c >= 'a' && c <= 'z') counts[c - 'a']++;
  }

  std::vector<std::pair<char, std::size_t>> result;
  for(int i = 0; i < 2; i++)
  {
    if(counts[i] != 0)
      result.push_back(std::make_pair(i + 'a', counts[i]));
  }
  std::sort(result.begin(), result.end(), [](auto p1, auto p2)
                                            {
                                              return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
                                            });
  return result;
}