#include <string>

std::string solve(std::string a, std::string b) {
  std::string result;
  for(auto c: a) if(b.find_first_of(c) == std::string::npos) result.push_back(c);
  for(auto c: b) if(a.find_first_of(c) == std::string::npos) result.push_back(c);
  return result;
}

/* //Bad solution
std::string diff(std::string s1, std::string s2)
{
  std::string result;
  size_t pos = s1.find_first_not_of(s2);
  while(pos != std::string::npos)
  {
    result.push_back(s1[pos]);
    pos = s1.find_first_not_of(s2, pos + 1);
  }
  return result;
  
}
std::string solve(std::string a, std::string b) {
  return diff(a, b) + diff(b, a);
}
*/