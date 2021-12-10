#include <string>
#include <vector>
#include <algorithm>
std::string mix(const std::string &s1, const std::string &s2)
{
  //count characters frequency for s1
  int charFreq1['z' - 'a' + 1] = {0};
  for(const auto& c: s1) if(islower(c)) charFreq1[c - 'a']++;
  
   //count characters frequency for s1
  int charFreq2['z' - 'a' + 1] = {0};
  for(const auto& c: s2) if(islower(c)) charFreq2[c - 'a']++;

  //getting the chars that have freq > 1
  std::vector<std::string> strs;
  for(size_t i = 0; i < 26; i++)
  {
    if(charFreq1[i] > 1 || charFreq2[i] > 1)
    {
      std::string substr;
      if(charFreq1[i] > charFreq2[i]) substr = "1:" + std::string(charFreq1[i], i + 'a');
      else if(charFreq1[i] == charFreq2[i]) substr = "=:" + std::string(charFreq1[i], i + 'a');
      else substr = "2:" + std::string(charFreq2[i], i + 'a');
      strs.push_back(substr);
    }
  }
  //sort by frequency, if same freq sort lexicographical order
  std::sort(strs.begin(), strs.end(), [](std::string str1, std::string str2)
  {
    std::string sub1 = str1;
    std::string sub2 = str2;
    return sub1.length() == sub2.length() ? sub1 < sub2 : sub1.length() > sub2.length();
  });
  
  std::string result;
  for(const auto s: strs) result += s + "/";
  if(!result.empty()) result.pop_back();
  return result;
}
