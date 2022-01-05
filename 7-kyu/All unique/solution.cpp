#include <string>
bool hasUniqueChars(std::string s) {
  for(size_t i = 0; i < s.length(); i++)
  {
    for(size_t j = i + 1; j < s.length(); j++)
    {
      if(s[i] == s[j]) return false;
    }
  }
  return true;
}
/*
#include <set>
bool hasUniqueChars(std::string s) {
  return std::set<char>(s.begin(), s.end()).size() == s.size();
}
#include<algorithm>
bool hasUniqueChars(std::string s) {
  std::sort(s.begin(), s.end());
  return std::unique(s.begin(), s.end()) == s.end();
}
*/