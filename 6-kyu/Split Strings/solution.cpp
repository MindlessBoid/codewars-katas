#include <string>
#include <vector>
#include <regex>

std::vector<std::string> solution(const std::string &s)
{
  //Should use regex_token_iterator instead of regex_iterator
  // regex_iterator dereferrence -> match_results object which doesnt not contain iterators to construct string
  // regex_token_iterator dereferrence -> sub_match object does contain iterators
  // regex_token_iterator can be used to access sub matches which are captured by ()
  // regex_iterator only allows access to matches not what within them
  std::regex re("..");
  auto str = s + (s.length()%2 == 0 ? "" : "_");  
  auto begin = std::sregex_token_iterator(str.begin(), str.end(), re);
  auto end = std::sregex_token_iterator();
  return {begin, end};
}