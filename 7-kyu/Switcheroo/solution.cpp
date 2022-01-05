#include <string>
#include <algorithm>
/*
std::string switcheroo(const std::string &s) {
  std::string result(s);
  for(auto& c: result)
    c = c == 'a' ? c + 1
       :c == 'b' ? c - 1
       :c;
  return result;
}
*/

std::string switcheroo(const std::string &s) {
  std::string result(s);
  std::transform(s.begin(), s.end(), result.begin(), [](char c)
                 {
                   return c == 'b' ? 'a'
                         :c == 'a' ? 'b'
                         :c;
                 });
  return result;
  
}