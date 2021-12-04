#include <iostream>
#include <string>

std::string encode(std::string text)
{
  std::string result;
  for(auto c: text)
  {
    std::string bin;
    for(int i = 0; i < 8; i++)
    {
      bin = std::string(1, (c&1) + '0') + bin;
      c = c>>1;
    }
    result += bin;
  }
  return result;
}
std::string decode(std::string bits)
{
  std::string result;
  for(size_t i = 0; i < bits.length()/24; i++)
  {
    //one character
    std::string charInBinary;
    for(size_t j = 0; j < 8; j++)
    {
      //sum for every 3 digits if sum < 2 => 0 else 1 (e.g. sum("100") = 1 => 0)
      int sum = 0;
      for(size_t k = 0; k < 3; k++)
      {
        sum += bits[24*i + 3*j + k] - '0';
      }
      charInBinary.push_back((sum<2) ? '0' : '1');
    }
    result.push_back(std::stoi(charInBinary, 0, 2));
  }
  return result;
}
