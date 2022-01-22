#include <string>
#include <vector>
std::string capitalize(std::string s, std::vector<int> idxs)
{
  for(auto i: idxs)
    s[i] = toupper(s[i]);
  return s;
  
}