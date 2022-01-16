#include <string>
int solve(std::string s){
  std::string vowels = "aeiou";
  int count = 0;
  int max = 0;
  for(auto c: s)
  {
    count = (vowels.find_first_of(c) != std::string::npos) ? count + 1 : 0;
    max = (count > max) ? count : max;
  }
  return max;
}